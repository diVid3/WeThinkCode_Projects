package za.co.wethinkcode.swingy.helpers;

import za.co.wethinkcode.swingy.models.Enemy;

import java.util.List;

public class Debugging {

  private static void displayEnemyPosition(Enemy enemy, int index) {

    System.out.println("Enemy " + index + ":");
    System.out.println("x - " + enemy.getX() + ".");
    System.out.println("y - " + enemy.getY() + ".");
  }

  public static void displayEnemyPositionsConsole(List<Enemy> enemies) {

    for (int i = 0; i < enemies.size(); i++) {

      Enemy printMe = enemies.get(i);
      displayEnemyPosition(printMe, i);
    }
  }
}
