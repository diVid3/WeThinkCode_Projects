package za.co.wethinkcode.swingy.controllers;

import za.co.wethinkcode.swingy.exceptions.InvalidInputException;
import za.co.wethinkcode.swingy.helpers.DbHelper;
import za.co.wethinkcode.swingy.helpers.InputHelper;
import za.co.wethinkcode.swingy.models.Enemy;
import za.co.wethinkcode.swingy.models.Hero;
import za.co.wethinkcode.swingy.views.Console;

import java.sql.Connection;
import java.sql.ResultSet;

import java.sql.SQLException;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.List;

public class Game {

  private Connection connection;
  private Hero hero;
  private String viewType;
  private Queue<String> input;
  private List<Enemy> enemies;
  private int mapSize;

  public Game(Connection connection, String viewType) {

    this.connection = connection;
    this.viewType = viewType;
    this.input = new PriorityQueue<String>();
  }

  public void selectHero() throws
    InvalidInputException,
    SQLException {

    if (!this.viewType.equals("console") && !this.viewType.equals("gui")) {

      throw new InvalidInputException("Invalid CLI arguments.");
    }

    // TODO: Draw view based upon viewType.
    // TODO: Get input.
    // TODO: Get hero, set to non-null.
    // TODO: Save hero if newly created.
    // TODO: Set mapSize. (heroLevel - 1) * 5 + 10 - (heroLevel % 2).
    // TODO: Generate enemies using mapSize.

    if (viewType.equals("console")) {

      String input;

      Console.displaySelectHero();
      input = InputHelper.getInput();

      while (!input.equals("L") && !input.equals("N")) {

        Console.displayInvalidInput();
        input = InputHelper.getInput();
      }

      if (input.equals("L")) {

        ResultSet rs = DbHelper.getHeroes(this.connection);

        if (!rs.next()) {

          Console.displayNoHeroes();
          // TODO Create new hero here.
        }

        Console.displayHeroes(rs);
        Console.displayPickHero();
        input = InputHelper.getInput();

        while (true) {

          if (!InputHelper.hasIllegalChars(input)) {
            rs = DbHelper.getHero(this.connection, input);

            // TODO: Might need to set another condition if no heroes available.
            if (rs.next()) {
              break;
            }
          }

          Console.displayInvalidInput();
          input = InputHelper.getInput();
        }


      }
      else if (input.equals("N")) {

        // TODO: Display name, take input.
        // TODO: Display class, take input from list.
        // TODO: Set hero and save to db.
      }
    }
    else if (viewType.equals("gui")) {

      // TODO: Do something here.
    }
  }

  public void drawGameView() throws InvalidInputException {

    if (!this.viewType.equals("console") && !this.viewType.equals("gui")) {

      throw new InvalidInputException("Invalid CLI arguments.");
    }

    // TODO: Draw view here.
  }

  public void getGameInput() {

    // TODO: Prompt for user input here. this might be skippable depending on
    // whether the view will have key hooks / events, e.g. a gui. Prompt once.
  }

  public void updateGameState() {

    // TODO: Update game state based upon user input.
    // Check for a viewType switch first.
  }
}
