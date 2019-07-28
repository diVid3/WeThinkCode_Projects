package za.co.wethinkcode.swingy.controllers;

import za.co.wethinkcode.swingy.exceptions.GuiException;
import za.co.wethinkcode.swingy.exceptions.InvalidInputException;
import za.co.wethinkcode.swingy.exceptions.NoEnemyException;
import za.co.wethinkcode.swingy.helpers.DbHelper;
import za.co.wethinkcode.swingy.helpers.EnemyHelpers;
import za.co.wethinkcode.swingy.helpers.GuiHelpers;
import za.co.wethinkcode.swingy.helpers.InputHelper;
import za.co.wethinkcode.swingy.models.Enemy;
import za.co.wethinkcode.swingy.models.Hero;
import za.co.wethinkcode.swingy.views.Console;
import za.co.wethinkcode.swingy.views.GUI.GamePanels;
import za.co.wethinkcode.swingy.views.GuiDriver;

import java.sql.Connection;
import java.sql.ResultSet;

import java.sql.SQLException;
import java.util.*;
import java.util.concurrent.BlockingQueue;
import java.util.concurrent.LinkedBlockingDeque;
import java.util.concurrent.ThreadLocalRandom;

public class Game {

  private Connection connection;
  private boolean gameOver = false;
  private boolean gameWon = false;
  private Hero hero;
  private String viewType;
  private Queue<String> input;
  private List<Enemy> enemies;
  private int mapSize;
  private int oldHeroLevel;
  private boolean heroCollidedEnemy;
  private int experienceGained;
  private String lootGained;
  private GuiDriver guiDriver;
  private BlockingQueue<String> guiInputQueue;

  private String getGameStateInfoString() {

    String gameStateInfo;

    // Example string: "Derp|650|0|450|12|12"

    gameStateInfo = this.hero.getHeroName() + "|" +
        this.hero.getHeroHitPoints() + "|" +
        this.hero.getHeroLevel() + "|" +
        this.hero.getHeroExperience() + "|" +
        this.hero.getX() + "|" +
        this.hero.getY();

    return gameStateInfo;
  }

  private void calculateFight() throws
      NoEnemyException,
      SQLException {

    Enemy enemy = EnemyHelpers.findCollidedEnemy(this.enemies, this.hero);

    if (enemy == null) {

      throw new NoEnemyException("No enemy collided with hero.");
    }

    int enemyExperience = enemy.dropExperience();
    String enemyLoot = enemy.getLoot(this.hero);

    int enemyInstantDeath = ThreadLocalRandom.current().nextInt(0, 1 + 1);

    if (enemyInstantDeath == 1) {

      this.experienceGained = enemyExperience;
      this.lootGained = enemyLoot;
      this.hero.takeLootExperience(this.lootGained, this.experienceGained);
      this.heroCollidedEnemy = false;
      EnemyHelpers.deleteEnemy(this.enemies, enemy);

      // Remove this condition if you wish to set another winning condition.
      if (this.hero.getHeroLevel() >= 8) {

        this.gameWon = true;
        return;
      }

      if (this.oldHeroLevel != this.hero.getHeroLevel()) {

        this.mapSize = (hero.getHeroLevel() - 1) * 5 + 10 - (hero.getHeroLevel() % 2);
        this.spawnEnemies(this.mapSize);
        DbHelper.saveHero(connection, this.hero);
      }

      return;
    }

    // Dangerous??? Dragons here. Careful.
    while (true) {

      enemy.reduceEnemyHitPoints(this.hero.getHeroAttack());

      if (enemy.getEnemyHitPoints() <= 0) {

        break;
      }

      this.hero.reduceHeroHitPoints(enemy.getEnemyAttackPoints());

      if (this.hero.getHeroHitPoints() <= 0) {

        this.gameOver = true;
        return;
      }
    }

    this.experienceGained = enemyExperience;
    this.lootGained = enemyLoot;
    this.hero.takeLootExperience(this.lootGained, this.experienceGained);
    this.heroCollidedEnemy = false;
    EnemyHelpers.deleteEnemy(this.enemies, enemy);

    // Remove this condition if you wish to set another winning condition.
    if (this.hero.getHeroLevel() >= 8) {

      this.gameWon = true;
      return;
    }

    if (this.oldHeroLevel != this.hero.getHeroLevel()) {

      this.mapSize = (hero.getHeroLevel() - 1) * 5 + 10 - (hero.getHeroLevel() % 2);
      this.spawnEnemies(this.mapSize);
      DbHelper.saveHero(connection, this.hero);
    }
  }

  private void calculateRun() throws
      NoEnemyException,
      SQLException {

    int shouldRun = ThreadLocalRandom.current().nextInt(0, 1 + 1);

    if (shouldRun == 1) {

      this.hero.moveBack();
      this.heroCollidedEnemy = false;
      return;
    }

    this.calculateFight();
  }

  private boolean hasHeroCollidedEnemy() {

    int heroX = this.hero.getX();
    int heroY = this.hero.getY();
    int listSize = this.enemies.size();

    Enemy enemyToCheckAgainst;

    for (int i = 0; i < listSize; i++) {

      enemyToCheckAgainst = this.enemies.get(i);

      if (
        heroX == enemyToCheckAgainst.getX() &&
        heroY == enemyToCheckAgainst.getY()
      ) {

        return true;
      }
    }

    return false;
  }

  private String getConsoleInputWalking() {

    String input;

    input = InputHelper.getInput();
    while (
      !input.equals("w") &&
      !input.equals("d") &&
      !input.equals("s") &&
      !input.equals("a") &&
      !input.equals("p")
    ) {

      Console.displayInvalidInput();
      input = InputHelper.getInput();
    }

    return input;
  }

  private String getConsoleInputCollided() {

    String input;

    input = InputHelper.getInput();
    while (
      !input.equals("f") &&
      !input.equals("r")
    ) {

      Console.displayInvalidInput();
      input = InputHelper.getInput();
    }

    return input;
  }

  private boolean canAddEnemy(Enemy newEnemy) {

    int newEnemyX = newEnemy.getX();
    int newEnemyY = newEnemy.getY();
    int heroX = this.hero.getX();
    int heroY = this.hero.getY();

    Enemy enemyToCheckAgainst;
    int enemyToCheckAgainstX;
    int enemyToCheckAgainstY;

    if (newEnemyX == heroX && newEnemyY == heroY) {

      return false;
    }

    for (int i = 0; i < this.enemies.size(); i++) {

      enemyToCheckAgainst = this.enemies.get(i);
      enemyToCheckAgainstX = enemyToCheckAgainst.getX();
      enemyToCheckAgainstY = enemyToCheckAgainst.getY();

      if (
        newEnemyX == enemyToCheckAgainstX &&
        newEnemyY == enemyToCheckAgainstY
      ) {

        return false;
      }
    }

    return true;
  }

  private void spawnEnemies(int mapSize) {

    int heroLevel = this.hero.getHeroLevel() + 1;
    int enemyAmount = heroLevel * heroLevel;

    this.enemies = new LinkedList<>();
    Enemy newEnemy;

    for (int i = 0; i < enemyAmount; i++) {

      newEnemy = new Enemy(mapSize);

      if (!this.canAddEnemy(newEnemy)) {

        i--;
        continue;
      }

      this.enemies.add(newEnemy);
    }
  }

  private void createHeroConsole() throws SQLException {

    String input;
    String newHeroClass;
    String newHeroName;
    Hero newHero;

    Console.displayCreateHeroName();

    input = InputHelper.getInput();

    while (
      InputHelper.hasIllegalChars(input) ||
      DbHelper.doesHeroExist(this.connection, input)
    ) {

      Console.displayInvalidInput();
      input = InputHelper.getInput();
    }

    newHeroName = input;

    Console.displayHeroTypes();
    Console.displayCreateHeroClass();
    input = InputHelper.getInput();

    while (!input.equals("O") && !input.equals("B") && !input.equals("A")) {

      Console.displayInvalidInput();
      input = InputHelper.getInput();
    }

    switch (input) {

      case "O":
        newHeroClass = "Orc";
        break;
      case "B":
        newHeroClass = "Barbarian";
        break;
      default:
        newHeroClass = "Assassin";
    }

    newHero = new Hero(
      newHeroName,
      newHeroClass,
      450,
      "Wooden Sword",
      "Wooden Armor",
      "Wooden Helm"
    );

    this.hero = newHero;

    DbHelper.addHero(this.connection, newHero);

    Console.displayCreatedHeroSuccessfully();
  }

  private void loadHeroConsole(String name) throws SQLException {

    ResultSet heroRow;
    String heroName;
    String heroClass;
    int heroExperience;
    String heroWeapon;
    String heroArmor;
    String heroHelm;

    heroRow = DbHelper.getHero(this.connection, name);

    heroName = heroRow.getString("heroName");
    heroClass = heroRow.getString("heroClass");
    heroExperience = heroRow.getInt("heroExperience");
    heroWeapon = heroRow.getString("heroWeapon");
    heroArmor = heroRow.getString("heroArmor");
    heroHelm = heroRow.getString("heroHelm");

    this.hero = new Hero(
      heroName,
      heroClass,
      heroExperience,
      heroWeapon,
      heroArmor,
      heroHelm
    );

    Console.displayHeroLoaded();
  }

  private void startGameConsole() throws
    SQLException {

    String input;

    Console.displaySelectHero();
    input = InputHelper.getInput();

    while (!input.equals("L") && !input.equals("N")) {

      Console.displayInvalidInput();
      input = InputHelper.getInput();
    }

    if (input.equals("L")) {

      if (!DbHelper.doHeroesExist(this.connection)) {

        Console.displayNoHeroes();
        this.createHeroConsole();
      }
      else {

        Console.displayHeroes(DbHelper.getHeroes(this.connection));
        Console.displayPickHero();

        input = InputHelper.getInput();
        while (
          InputHelper.hasIllegalChars(input) ||
          !DbHelper.doesHeroExist(this.connection, input)
        ) {
          
          Console.displayInvalidInput();
          input = InputHelper.getInput();
        }

        this.loadHeroConsole(input);
      }
    }
    else if (input.equals("N")) {

      this.createHeroConsole();
    }
  }

  private void createHeroGui() throws
    GuiException,
    SQLException,
    InterruptedException {

    String queueItem1;
    String queueItem2;
    Hero newHero;

    this.guiDriver.refreshWindow(GamePanels.getCreateHeroPanel(
      this.connection,
      this.guiInputQueue
    ));

    queueItem1 = this.guiInputQueue.take();
    queueItem2 = this.guiInputQueue.take();

    if (queueItem1.equals("Exception")) {

      throw new GuiException(queueItem2);
    }

    newHero = new Hero(
      queueItem1,
      queueItem2,
      450,
      "Wooden Sword",
      "Wooden Armor",
      "Wooden Helm"
    );

    this.hero = newHero;

    DbHelper.addHero(this.connection, newHero);

    this.guiDriver.displayCreatedHeroSuccess();
  }

  private void loadHeroGui(String name) throws SQLException {

    ResultSet heroRow;
    String heroName;
    String heroClass;
    int heroExperience;
    String heroWeapon;
    String heroArmor;
    String heroHelm;

    heroRow = DbHelper.getHero(this.connection, name);

    heroName = heroRow.getString("heroName");
    heroClass = heroRow.getString("heroClass");
    heroExperience = heroRow.getInt("heroExperience");
    heroWeapon = heroRow.getString("heroWeapon");
    heroArmor = heroRow.getString("heroArmor");
    heroHelm = heroRow.getString("heroHelm");

    this.hero = new Hero(
      heroName,
      heroClass,
      heroExperience,
      heroWeapon,
      heroArmor,
      heroHelm
    );

    this.guiDriver.displayLoadedHeroSuccess();
  }

  private void startGameGui() throws
    SQLException,
    GuiException,
    InterruptedException {

    this.guiDriver = new GuiDriver();
    this.guiDriver.refreshWindow(GamePanels.getStartGamePanel(this.guiInputQueue));

    String queueItem = this.guiInputQueue.take();

    if (queueItem.equals("N")) {

      this.createHeroGui();
    }
    else if (queueItem.equals("L")) {

      if (!DbHelper.doHeroesExist(this.connection)) {

        this.createHeroGui();
      }
      else {

        this.guiDriver.refreshWindow(GamePanels.getLoadHeroPanel(this.connection, this.guiInputQueue));
        queueItem = this.guiInputQueue.take();
        this.loadHeroGui(queueItem);
      }
    }
  }

  private void prepGameState() {

    this.oldHeroLevel = this.hero.getHeroLevel();
    this.mapSize = (hero.getHeroLevel() - 1) * 5 + 10 - (hero.getHeroLevel() % 2);
    this.spawnEnemies(this.mapSize);
    this.heroCollidedEnemy = false;
  }

  public Game(Connection connection, String viewType) {

    this.connection = connection;
    this.viewType = viewType;
    this.input = new PriorityQueue<String>();

    // This queue receives the input from the gui.
    this.guiInputQueue = new LinkedBlockingDeque<>(2);
  }

  // This is called first.
  public void startGame() throws
    InvalidInputException,
    SQLException,
    GuiException,
    InterruptedException {

    if (!this.viewType.equals("console") && !this.viewType.equals("gui")) {

      throw new InvalidInputException("Invalid CLI arguments.");
    }

    if (viewType.equals("console")) {

      this.startGameConsole();
      this.prepGameState();
    }
    else if (viewType.equals("gui")) {

      this.startGameGui();
      this.prepGameState();

      // This needs to be done after game prep.
      this.guiDriver.refreshWindow(GamePanels.getGamePlayPanel(
        this.guiInputQueue,
        this.getGameStateInfoString(),
        this.guiDriver.getGameStateLabels()
      ));
    }
  }

  public void drawGameView() {

    if (this.viewType.equals("console")) {

      if (this.gameOver) {

        Console.displayGameOver();
        return;
      }

      if (this.gameWon) {

        Console.displayGameWon();
        return;
      }

      Console console = new Console();

      console.displayGameBoard(
          this.mapSize,
          this.hero,
          this.enemies
      );

      console.displayHeroState(this.hero);

      if (!this.heroCollidedEnemy) {

        if (this.experienceGained != 0) {

          Console.displayExperienceGained(this.experienceGained);
          this.experienceGained = 0;
        }

        if (this.lootGained != null) {

          Console.displayLootGained(this.lootGained);
          this.lootGained = null;
        }

        Console.displayGameInputWalking();
      }
      else if (this.heroCollidedEnemy) {

        Console.displayGameInputCollided();
      }
    }
    else if (this.viewType.equals("gui")) {

      if (this.gameOver) {

        this.guiDriver.displayGameOver();
        return;
      }

      if (this.gameWon) {

        this.guiDriver.displayGameWon();
        return;
      }

      // This is only for debugging reasons.
      Console console = new Console();

      console.displayGameBoard(
          this.mapSize,
          this.hero,
          this.enemies
      );

      // Default render.
      GuiHelpers.assignGameStateLabels(
        this.guiDriver.getGameStateLabels(),
        this.getGameStateInfoString()
      );

      if (!this.heroCollidedEnemy) {

        if (this.experienceGained != 0) {

          this.guiDriver.displayStuffGained("XP gained: " + this.experienceGained);
          this.experienceGained = 0;
        }

        if (this.lootGained != null) {

          this.guiDriver.displayStuffGained("Loot gained: " + this.lootGained);
          this.lootGained = null;
        }
      }
      else if (this.heroCollidedEnemy) {

        int choice = this.guiDriver.displayGuiInputCollided();

        if (choice == 0) {

          this.input.add("r");
        }
        else if (choice == 1) {

          this.input.add("f");
        }
      }
    }
  }

  // If the gameOver flag is set, this will simply not get input.
  public void getGameInput() throws InterruptedException {

    if (this.viewType.equals("console")) {

      if (!this.heroCollidedEnemy && !this.gameOver && !this.gameWon) {

        this.input.add(this.getConsoleInputWalking());
      }
      else if (this.heroCollidedEnemy && !this.gameOver && !this.gameWon) {

        this.input.add(this.getConsoleInputCollided());
      }
    }
    else if (this.viewType.equals("gui")) {

      if (!this.heroCollidedEnemy && !this.gameOver && !this.gameWon) {

        this.input.add(this.guiInputQueue.take());
      }
      else if (this.heroCollidedEnemy && !this.gameOver && !this.gameWon) {

        // No need to prompt for input here as the gui input is given
        // when the JOptionPane is displayed in the drawGameView() method.
      }
    }
  }

  public boolean updateGameState() throws
    NoEnemyException,
    SQLException {

    // Game exit condition.
    if (this.gameOver || this.gameWon) {

      return false;
    }

    String input = this.input.poll();

    if (!this.heroCollidedEnemy) {

      boolean shouldExit = false;

      if (input != null) {

        switch (input) {

          case "w":
            this.hero.moveUp();
            break;
          case "d":
            this.hero.moveRight();
            break;
          case "s":
            this.hero.moveDown();
            break;
          case "a":
            this.hero.moveLeft();
            break;
          case "p":
            shouldExit = true;
            break;
        }

        if (shouldExit) {

          return false;
        }

        if (this.hasHeroCollidedEnemy()) {

          this.heroCollidedEnemy = true;
        }
      }
    }
    else if (this.heroCollidedEnemy) {

      if (input != null) {

        if (input.equals("f")) {

          this.calculateFight();
        }
        else if (input.equals("r")) {

          this.calculateRun();
        }
      }
    }

    return true;
  }

  public void farewell() {

    if (this.viewType.equals("console")) {

      System.out.println("Bye now.");
    }
    else if (this.viewType.equals("gui")) {

      // Not applicable.
    }
  }
}
