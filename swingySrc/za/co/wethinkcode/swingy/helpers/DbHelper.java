package za.co.wethinkcode.swingy.helpers;

// import za.co.wethinkcode.swingy.models.Hero;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;

import org.sqlite.JDBC;

public class DbHelper {

  private static Connection dbCon = null;

  public static Connection getDbConnection() throws
    SQLException,
    ClassNotFoundException {

    if (dbCon == null) {

      dbCon = DriverManager.getConnection("jdbc:sqlite:swingy.db");

      System.out.println("SQLite Connection established!");
    }

    return dbCon;
  }

  public static void addHero(
    int id,
    String heroName,
    String heroClass,
    int heroLevel,
    int heroExperience,
    int heroAttack,
    int heroDefence,
    int heroHitPoints,
    String heroWeapon,
    String heroArmor,
    String heroHelm
  ) throws Exception {

    // TODO: Add new hero to db.
  }
}