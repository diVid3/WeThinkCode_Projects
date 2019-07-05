package za.co.wethinkcode.swingy;

import za.co.wethinkcode.swingy.helpers.DbHelper;

import java.sql.Connection;
import java.sql.SQLException;

public class Main {

  public static void main( String[] args ) {

    Connection dbCon = null;

    try {

      dbCon = DbHelper.getDbConnection();

      // TODO: Do more things here.
    }
    catch (
      SQLException e
    ) {

      e.printStackTrace(System.out);
    }
    finally {

      try {

        dbCon.close();
      }
      catch (SQLException e) {

        e.printStackTrace(System.out);
      }
    }
  }
}
