package za.co.wethinkcode.swingy.helpers;

import za.co.wethinkcode.swingy.models.Hero;

import javax.validation.ConstraintViolation;
import javax.validation.Validation;
import javax.validation.Validator;
import javax.validation.ValidatorFactory;
import java.sql.*;
import java.util.Set;

public class DbHelper {

  private static Connection dbCon = null;

  public static Connection getSqliteConnection() throws SQLException {

    if (dbCon == null) {

      dbCon = DriverManager.getConnection("jdbc:sqlite:swingy.db");
    }

    return dbCon;
  }

  public static void setUpDatabase(Connection connection) throws SQLException {

    Statement statement = connection.createStatement();

    statement.setQueryTimeout(30);
    statement.executeUpdate("CREATE TABLE IF NOT EXISTS heroes (" +
        "heroName TEXT NOT NULL UNIQUE," +
        "heroClass TEXT NOT NULL," +
        "heroLevel INTEGER NOT NULL," +
        "heroExperience INTEGER NOT NULL," +
        "heroAttack INTEGER NOT NULL," +
        "heroDefence INTEGER NOT NULL," +
        "heroHitPoints INTEGER NOT NULL," +
        "heroWeapon TEXT NOT NULL," +
        "heroArmor TEXT NOT NULL," +
        "heroHelm TEXT NOT NULL);"
    );
  }

  public static void addHero(Connection connection, Hero hero)
    throws SQLException {

    ValidatorFactory factory = Validation.buildDefaultValidatorFactory();
    Validator validator = factory.getValidator();

    Set<ConstraintViolation<Hero>> violations = validator.validate(hero);

    if (violations.size() > 0) {

      throw new SQLException(violations.toString());
    }

    Statement statement = connection.createStatement();

    statement.executeUpdate("INSERT INTO heroes (" +
        "heroName," +
        "heroClass," +
        "heroLevel," +
        "heroExperience," +
        "heroAttack," +
        "heroDefence," +
        "heroHitPoints," +
        "heroWeapon," +
        "heroArmor," +
        "heroHelm" +
        ") VALUES (" +
        "'" + hero.getHeroName() + "'" + "," +
        "'" + hero.getHeroClass() + "'" + "," +
        hero.getHeroLevel() + "," +
        hero.getHeroExperience() + "," +
        hero.getHeroAttack() + "," +
        hero.getHeroDefence() + "," +
        hero.getHeroHitPoints() + "," +
        "'" + hero.getHeroWeapon() + "'" + "," +
        "'" + hero.getHeroArmor() + "'" + "," +
        "'" + hero.getHeroHelm() + "'" + ");"
    );
  }

  public static ResultSet getHeroes(Connection connection) throws SQLException {

    Statement statement = connection.createStatement();
    return statement.executeQuery("SELECT * FROM heroes;");
  }

  public static boolean doHeroesExist(Connection connection) throws SQLException {

    ResultSet rs = getHeroes(connection);

    if (!rs.next()) {
      return false;
    }

    return true;
  }

  public static ResultSet getHero(Connection connection, String heroName)
    throws SQLException {

    String heroNameToFind = "'" + heroName + "'";

    Statement statement = connection.createStatement();

    return statement.executeQuery(
    "SELECT * FROM heroes WHERE heroName LIKE " + heroNameToFind + ";");
  }

  public static boolean doesHeroExist(Connection connection, String heroName)
    throws SQLException {

    ResultSet rs;

    rs = getHero(connection, heroName);

    if (!rs.next()) {
      return false;
    }

    return true;
  }
}
