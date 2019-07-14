package za.co.wethinkcode.swingy.views;

import za.co.wethinkcode.swingy.helpers.DisplayFormatter;

import java.sql.ResultSet;
import java.sql.SQLException;

public class Console {

  public Console() {

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
}
