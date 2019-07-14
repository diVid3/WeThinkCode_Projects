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

  private boolean canAddEnemy(Enemy newEnemy) {

    int newEnemyX = newEnemy.getX();
    int newEnemyY = newEnemy.getY();
    int heroX = this.hero.getX();
    int heroY = this.hero.getY();

    Enemy enemyToCheckAgainst;
    int enemyToCheckAgainstX;
    int enemyToCheckAgainstY;

    if (this.enemies.size() == 0) {

      return true;
    }

    // TODO: Replace with forEach.
    for (int i = 0; i < this.enemies.size(); i++) {

      enemyToCheckAgainst = this.enemies.get(i);
      enemyToCheckAgainstX = enemyToCheckAgainst.getX();
      enemyToCheckAgainstY = enemyToCheckAgainst.getY();

      if (
        (newEnemyX == enemyToCheckAgainstX &&
        newEnemyY == enemyToCheckAgainstY) ||
        (newEnemyX == heroX &&
        newEnemyY == heroY)
      ) {

        return false;
      }
    }

    return true;
  }

  private void spawnEnemies() {

    int heroLevel = this.hero.getHeroLevel();
    int mapSize = (heroLevel - 1) * 5 + 10 - (heroLevel % 2);
    int enemyAmount = ThreadLocalRandom.current().nextInt(1, heroLevel + 2);

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
      this.spawnEnemies();
    }
    else if (viewType.equals("gui")) {

      throw new InvalidInputException("No GUI logic present. Exiting.");

      // TODO: Maybe enable this at a later stage.
      // this.startGameGui();
    }
  }

  public void drawGameView() {

    if (this.viewType.equals("console")) {

      Debugging.displayEnemyPositionsConsole(this.enemies);
    }
    else if (this.viewType.equals("gui")) {

      // TODO: Maybe implement this.
    }
  }

  public boolean getGameInput() {

    // TODO: Prompt for user input here. this might be skippable depending on
    // whether the view will have key hooks / events, e.g. a gui. Prompt once.

    if (this.viewType.equals("console")) {

      // If input == exit, return false.
      // TODO: Change this. This is only for testing purposes.
      return false;
    }
    else if (this.viewType.equals("gui")) {

      // TODO: Maybe implement this.
      // If input == exit, return false.
    }

    return true;
  }

  public void updateGameState() {

    // TODO: Update game state based upon user input.
    // Check for a viewType switch first.
  }

  public void farewell() {

    if (this.viewType.equals("console")) {

      System.out.println("Good job! Bye now.");
    }
    else if (this.viewType.equals("gui")) {

      // TODO: Maybe implement this.
    }
  }
}
