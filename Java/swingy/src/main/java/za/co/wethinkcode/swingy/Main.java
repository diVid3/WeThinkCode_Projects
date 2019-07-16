package za.co.wethinkcode.swingy;

import za.co.wethinkcode.swingy.controllers.Game;
import za.co.wethinkcode.swingy.exceptions.InvalidInputException;
import za.co.wethinkcode.swingy.exceptions.NoEnemyException;
import za.co.wethinkcode.swingy.helpers.DbHelper;

import java.sql.Connection;
import java.sql.SQLException;

public class Main {

  public static void main( String[] args ) {

    Game game = null;
    Connection dbCon = null;

    try {

      dbCon = DbHelper.getSqliteConnection();
      DbHelper.setUpDatabase(dbCon);

      game = new Game(dbCon, args[0]);
      game.startGame();

      while (true) {

        game.drawGameView();
        game.getGameInput();
        if (!game.updateGameState()) break;
      }

      game.farewell();
    }
    catch (
      SQLException |
      InvalidInputException |
      NoEnemyException e
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
