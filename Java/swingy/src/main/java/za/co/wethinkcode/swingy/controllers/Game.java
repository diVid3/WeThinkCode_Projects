package za.co.wethinkcode.swingy.controllers;

import za.co.wethinkcode.swingy.exceptions.InvalidInputException;
import za.co.wethinkcode.swingy.helpers.DbHelper;
import za.co.wethinkcode.swingy.helpers.Debugging;
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
  private Hero hero;
  private String viewType;
  private Queue<String> input;
  private List<Enemy> enemies;
  private int mapSize;

  private String getConsoleInput() {

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
    }
    else if (viewType.equals("gui")) {

      throw new InvalidInputException("No GUI logic present. Exiting.");

      // TODO: Maybe enable this at a later stage.
      // this.startGameGui(); <-------------------------- This needs to load or create hero.
      // this.mapSize = (hero.getHeroLevel() - 1) * 5 + 10 - (hero.getHeroLevel() % 2);
      // this.spawnEnemies(this.mapSize);
    }
  }

  public void drawGameView() {

    if (this.viewType.equals("console")) {

      Console console = new Console();

      console.displayGameBoard(
        this.mapSize,
        this.hero,
        this.enemies
      );

      console.displayHeroState(this.hero);
      Console.displayGameInput();
    }
    else if (this.viewType.equals("gui")) {

      // TODO: Maybe implement this.
    }
  }

  public void getGameInput() {

    // TODO: Prompt for user input here. this might be skippable depending on
    // whether the view will have key hooks / events, e.g. a gui. Prompt once.

    if (this.viewType.equals("console")) {

      this.input.add(this.getConsoleInput());
    }
    else if (this.viewType.equals("gui")) {

      // TODO: Maybe implement this.
      // If input == exit, return false.
    }
  }

  public boolean updateGameState() {

    // TODO: Update game state based upon user input.
    // Check for a viewType switch first.
    // This needs to be done generically, i.e. independent of view.

    // TODO: Check for object collision.
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

    // TODO: Very important, handle the display case when hero is on enemy.
    // Could possibly add "Collision" to use input queue.

    String input = this.input.poll();

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
      }

      if (input.equals("p")) {

        return false;
      }

      // TODO: Remember to do the switch here.
    }
    return true;
  }

  public void farewell() {

    if (this.viewType.equals("console")) {

      System.out.println("Good job! Bye now.");
    }
    else if (this.viewType.equals("gui")) {

      // TODO: Maybe implement this.
      // Perhaps some final exit screen?
    }
  }
}
