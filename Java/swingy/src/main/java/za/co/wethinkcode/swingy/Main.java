package za.co.wethinkcode.swingy;

import java.sql.Connection;
import java.sql.SQLException;

import za.co.wethinkcode.swingy.helpers.DbHelper;

public class Main {

  public static void main( String[] args ) {

    try {

      Connection dbCon = DbHelper.getDbConnection();

      // TODO: Do stuff here.

      dbCon.close();
    }
    catch (SQLException e) {

      e.printStackTrace(System.out);
    }
  }
}
