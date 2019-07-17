package za.co.wethinkcode.swingy.controllers;

import za.co.wethinkcode.swingy.exceptions.InvalidInputException;
import za.co.wethinkcode.swingy.exceptions.NoEnemyException;
import za.co.wethinkcode.swingy.helpers.DbHelper;
import za.co.wethinkcode.swingy.helpers.Debugging;
import za.co.wethinkcode.swingy.helpers.EnemyHelpers;
import za.co.wethinkcode.swingy.helpers.InputHelper;
import za.co.wethinkcode.swingy.models.Enemy;
import za.co.wethinkcode.swingy.models.Hero;
import za.co.wethinkcode.swingy.views.Console;

import java.sql.Connection;
import java.sql.ResultSet;

import java.sql.SQLException;
import java.util.*;
import java.util.concurrent.ThreadLocalRandom;

public class Game {

  private Connection connection;
  private boolean gameOver = false;
  private Hero hero;
  private String viewType;
  private Queue<String> input;
  private List<Enemy> enemies;
  private int mapSize;
  private boolean heroCollidedEnemy;
  private int experienceGained;
  private String lootGained;

  private void calculateFight() throws NoEnemyException {

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
      // TODO: If hero leveled, update mapSize, respawn enemies. Use a variable.
      // this.mapSize = (hero.getHeroLevel() - 1) * 5 + 10 - (hero.getHeroLevel() % 2);
      // this.spawnEnemies(this.mapSize);
      this.heroCollidedEnemy = false;
      EnemyHelpers.deleteEnemy(this.enemies, enemy);
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

        // TODO: Signal Game Over when the Hero dies.
        this.gameOver = true;
        return;
      }
    }

    this.experienceGained = enemyExperience;
    this.lootGained = enemyLoot;
    this.hero.takeLootExperience(this.lootGained, this.experienceGained);
    // TODO: If hero leveled, update mapSize, respawn enemies. Use a variable.
    // this.mapSize = (hero.getHeroLevel() - 1) * 5 + 10 - (hero.getHeroLevel() % 2);
    // this.spawnEnemies(this.mapSize);
    this.heroCollidedEnemy = false;
    EnemyHelpers.deleteEnemy(this.enemies, enemy);
  }

  private void calculateRun() {


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

    // If input == exit, return false.
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

    int enemyAmount = ThreadLocalRandom.current().nextInt(1, hero.getHeroLevel() + 2);

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
    while (InputHelper.hasIllegalChars(input)) {

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

  private void startGameGui() {




    // TODO: Maybe implement this.
    // This needs to follow the same creation / loading logic as the console,
    // but using a gui, basically:
    // N - Create new hero.
    // L - Load hero, go to create window if no heroes exist.
  }

  public Game(Connection connection, String viewType) {

    this.connection = connection;
    this.viewType = viewType;
    this.input = new PriorityQueue<String>();
  }

  // This is called first.
  public void startGame() throws
    InvalidInputException,
    SQLException {

    if (!this.viewType.equals("console") && !this.viewType.equals("gui")) {

      throw new InvalidInputException("Invalid CLI arguments.");
    }

    if (viewType.equals("console")) {

      this.startGameConsole();
      this.mapSize = (hero.getHeroLevel() - 1) * 5 + 10 - (hero.getHeroLevel() % 2);
      this.spawnEnemies(this.mapSize);
      this.heroCollidedEnemy = false;
    }
    else if (viewType.equals("gui")) {
      throw new InvalidInputException("No GUI logic present. Exiting.");




    }
  }

  public void drawGameView() {

    if (this.viewType.equals("console")) {

      if (this.gameOver) {

        Console.displayGameOver();
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

        // TODO: Add if-statement here to display loot / xp gained after defeating enemy, check if loot / xp available.

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




    }
  }

  public void getGameInput() {

    // TODO: Prompt for user input here. this might be skippable depending on
    // whether the view will have key hooks / events, e.g. a gui. Prompt once.

    if (this.viewType.equals("console")) {

      if (!this.heroCollidedEnemy && !this.gameOver) {

        this.input.add(this.getConsoleInputWalking());
      }
      else if (this.heroCollidedEnemy && !this.gameOver) {

        this.input.add(this.getConsoleInputCollided());
      }
    }
    else if (this.viewType.equals("gui")) {




    }
  }


  // Check for a viewType switch first.
  // This needs to be done generically, i.e. independent of view.
  //
  // If collision is found, prompt user to either fight or run.
  // if fight, calculate fight, signal fight ongoing, after fight,
  // signal results.
  //
  // If run, do 50% chance calc, if run back, run back, if fight,
  // fight.
  //
  // After fight, drop loot, if loot non-none, add better stats, add
  // to hero, delete enemy by using unique positions, or unique id.
  //
  // If collision is found, calculate fight, before calculation, signal
  // view to output that fight is ongoing, after fight, signal results
  // of fight.
  //
  // If the fight is successful, call drop loot, get loot, delete enemy at
  // that position, positions are unique.
  //
  // If fight fails,
  //
  public boolean updateGameState() throws NoEnemyException {

    if (this.gameOver) {

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

        // switch (input) {
        //
        //   // TODO: Remember to set hasHeroCollidedEnemy to false after the enemy has been defeated or when the the hero ran from the enemy.
        //   case "f":
        //     // TODO: Calculate fight outcome, set the flag to display items / xp gained, display on next non-collide iteration.
        //     this.calculateFight();
        //     break;
        //   case "r":
        //     // TODO: Calculate chance to run, if not, fight.
        //     this.calculateRun();
        //     break;
        // }
      }
    }

    return true;
  }

  public void farewell() {

    if (this.viewType.equals("console")) {

      System.out.println("Good job! Bye now.");
    }
    else if (this.viewType.equals("gui")) {




    }
  }
}
