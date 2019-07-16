package za.co.wethinkcode.swingy.helpers;

import za.co.wethinkcode.swingy.models.Enemy;
import za.co.wethinkcode.swingy.models.Hero;

import java.util.List;

public class EnemyHelpers {

  // This completely dependent on enemy positions being unique.
  public static void deleteEnemy(List<Enemy> enemies, Enemy enemy) {

    int enemyX = enemy.getX();
    int enemyY = enemy.getY();
    int listSize = enemies.size();

    int enemyToDelIndex = 0;

    for (int i = 0; i < listSize; i++) {

      Enemy enemyToCheckAgainst = enemies.get(i);

      if (
        enemyX == enemyToCheckAgainst.getX() &&
        enemyY == enemyToCheckAgainst.getY()
      ) {

        enemyToDelIndex = i;
      }
    }

    enemies.remove(enemyToDelIndex);
  }

  public static Enemy findCollidedEnemy(List<Enemy> enemies, Hero hero) {

    int heroX = hero.getX();
    int heroY = hero.getY();

    Enemy enemy;
    int listSize = enemies.size();

    for (int i = 0; i < listSize; i++) {

      enemy = enemies.get(i);

      if (enemy.getX() == heroX && enemy.getY() == heroY) {

        return enemy;
      }
    }

    return null;
  }
}
