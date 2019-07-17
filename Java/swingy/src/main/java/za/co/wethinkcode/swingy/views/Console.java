package za.co.wethinkcode.swingy.views;

import za.co.wethinkcode.swingy.helpers.DisplayFormatter;
import za.co.wethinkcode.swingy.models.Enemy;
import za.co.wethinkcode.swingy.models.Hero;

import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.List;

public class Console {

  private int oldMapSize;
  private char[][] gameBoard;

  private void placeHero(Hero hero) {

    this.gameBoard[hero.getY()][hero.getX()] = 'H';
  }

  private void placeEnemies(List<Enemy> enemies) {

    int enemyAmount = enemies.size();
    Enemy enemy;

    for (int i = 0; i < enemyAmount; i++) {

      enemy = enemies.get(i);
      this.gameBoard[enemy.getY()][enemy.getX()] = 'X';
    }
  }

  private void initGameBoard(int mapSize) {

    if (this.gameBoard == null || mapSize != this.oldMapSize) {

      this.gameBoard = new char[mapSize][mapSize];
      this.oldMapSize = mapSize;

      for (int i = 0; i < mapSize; i++) {

        for (int j = 0; j < mapSize; j++) {

          this.gameBoard[i][j] = '.';
        }
      }
    }
  }

  public Console() {

  }

  public static void displayGameOver() {

    System.out.println("Game Over!");
    System.out.println("Thanks for playing!");
    System.out.println("Now go away.");
  }

  public static void displaySelectHero() {

    System.out.println("[ N ] - Create New Hero.");
    System.out.println("[ L ] - Load Hero.");
  }

  public static void displayInvalidInput() {

    System.out.println("Invalid input, try again.");
  }

  public static void displayNoHeroes() {

    System.out.println("No heroes saved, create a new one.");
  }

  public static void displayHeroes(ResultSet rs) throws SQLException {

    while (rs.next()) {

      System.out.println("----------------------------------------");
      System.out.println(rs.getString("heroName") + "");
      System.out.println(DisplayFormatter.formatHeroLevel(rs.getInt("heroLevel")) + "");
      System.out.println(DisplayFormatter.formatHeroExperience(rs.getInt("heroExperience")) + "");
      System.out.println(DisplayFormatter.formatHeroHitPoints(rs.getInt("heroHitPoints")) + "");
      System.out.println(DisplayFormatter.formatHeroAttack(rs.getInt("heroAttack")) + "");
      System.out.println(DisplayFormatter.formatHeroDefence(rs.getInt("heroDefence")) + "");
      System.out.println(DisplayFormatter.formatHeroWeapon(rs.getString("heroWeapon")) + "");
      System.out.println(DisplayFormatter.formatHeroArmor(rs.getString("heroArmor")) + "");
      System.out.println(DisplayFormatter.formatHeroHelm(rs.getString("heroHelm")) + "");
    }

    System.out.println("----------------------------------------");
  }

  public static void displayPickHero() {

    System.out.println("Pick your hero from the list above by typing in their name:");
  }

  public static void displayCreateHeroName() {

    System.out.println("Pick a name for your hero:");
  }

  public static void displayCreateHeroClass() {

    System.out.println("Pick a class for you hero:");
  }

  public static void displayHeroTypes() {

    System.out.println("[ O ] - Orc");
    System.out.println("[ B ] - Barbarian");
    System.out.println("[ A ] - Assassin");
  }

  public static void displayCreatedHeroSuccessfully() {

    System.out.println("You have successfully created your hero.");
    System.out.println("Let the games begin!");
  }

  public static void displayHeroLoaded() {

    System.out.println("Your hero was successfully loaded.");
    System.out.println("Let the games begin!");
  }

  public void displayGameBoard(int mapSize, Hero hero, List<Enemy> enemies) {

    this.initGameBoard(mapSize);
    this.placeEnemies(enemies);
    this.placeHero(hero);

    System.out.println();
    for (int i = 0; i < mapSize; i++) {

      for (int j = 0; j < mapSize; j++) {

        System.out.print(this.gameBoard[i][j]);
        System.out.print("    ");
      }
      System.out.println();
      System.out.println();
    }
  }

  public void displayHeroState(Hero hero) {

    System.out.println("Name        - " + hero.getHeroName());
    System.out.println("Life        - " + hero.getHeroHitPoints());
    System.out.println("Level       - " + hero.getHeroLevel());
    System.out.println("Experience  - " + hero.getHeroExperience());
    System.out.println("Coordinates - " + hero.getX() + ", " + hero.getY());
    System.out.println();
  }

  public static void displayGameInputWalking() {

    System.out.println("[ w ] - North");
    System.out.println("[ d ] - East");
    System.out.println("[ s ] - South");
    System.out.println("[ a ] - West");
    System.out.println("[ p ] - Exit");
    System.out.println();
  }

  public static void displayGameInputCollided() {

    System.out.println("You encountered an enemy! Make a choice.");
    System.out.println();
    System.out.print("[ f ] - Fight OR ");
    System.out.println("[ r ] - Run");
    System.out.println();
  }

  public static void displayExperienceGained(int experience) {

    System.out.println("XP gained - " + experience);
  }

  public static void displayLootGained(String loot) {

    System.out.println("Loot gained - " + loot);
  }
}
