package za.co.wethinkcode.swingy.views;

import za.co.wethinkcode.swingy.helpers.DisplayFormatter;

import java.sql.ResultSet;
import java.sql.SQLException;

public class Console {

  public Console() {

  }

  public static void displaySelectHero() {

    System.out.println("\n");

    System.out.println("[ N ] - Create New Hero.\n");
    System.out.println("[ L ] - Load Hero.\n");
    System.out.println("\n");
  }

  public static void displayInvalidInput() {

    System.out.println("Invalid input, try again.\n");
    System.out.println("\n");
  }

  public static void displayNoHeroes() {

    System.out.println("No heroes saved, create a new one.\n");
    System.out.println("\n");
  }

  public static void displayHeroes(ResultSet rs) throws SQLException {

    while(rs.next()) {

      System.out.println(rs.getString("heroName") + "\n");
      System.out.println(DisplayFormatter.formatHeroLevel(rs.getInt("heroLevel")) + "\n");
      System.out.println(DisplayFormatter.formatHeroExperience(rs.getInt("heroExperience")) + "\n");
      System.out.println(DisplayFormatter.formatHeroAttack(rs.getInt("heroAttack")) + "\n");
      System.out.println(DisplayFormatter.formatHeroDefence(rs.getInt("heroDefence")) + "\n");
      System.out.println(DisplayFormatter.formatHeroWeapon(rs.getString("heroWeapon")) + "\n");
      System.out.println(DisplayFormatter.formatHeroArmor(rs.getString("heroArmor")) + "\n");
      System.out.println(DisplayFormatter.formatHeroHelm(rs.getString("heroHelm")) + "\n");
      System.out.println("\n");
    }
  }

  public static void displayPickHero() {

    System.out.println("Pick your hero from the list above by typing in their name:\n");
    System.out.println("\n");
  }

  public static void displayCreateHeroName() {

    System.out.println("Pick a name for your hero:\n");
    System.out.println("\n");
  }

  public static void displayCreateHeroClass() {

    System.out.println("Pick a class for you hero:\n");
    System.out.println("\n");
  }

  public static void displayHeroTypes() {

    System.out.println("[ O ] - Orc\n");
    System.out.println("[ B ] - Barbarian\n");
    System.out.println("[ A ] - Assassin\n");
    System.out.println("\n");
  }
}
