package za.co.wethinkcode.swingy.models;

import java.util.HashMap;
import java.util.Map;
import java.util.concurrent.ThreadLocalRandom;

public class Enemy {

  private Boolean enemyAlive;
  private int enemyHitPoints;
  private int enemyAttackPoints;
  private int enemyLevel;
  private String loot;
  private int x;
  private int y;

  private String generateLoot(String type) {

    Map<String, String> lootCollection = new HashMap<String, String>();
    String choice = Integer.toString(ThreadLocalRandom.current().nextInt(1, 3 + 1));

    lootCollection.put("1", "Sword");
    lootCollection.put("2", "Armor");
    lootCollection.put("3", "Helm");

    return (type + " " + lootCollection.get(choice));
  }

  public Enemy(int mapSize) {

    int shouldDropLoot;

    this.enemyAlive = true;
    this.enemyHitPoints = ThreadLocalRandom.current().nextInt(1, 2500 + 1);
    this.enemyAttackPoints = ThreadLocalRandom.current().nextInt(1, 2500 + 1);

    int enemyStrength = this.enemyHitPoints + this.enemyAttackPoints;

    if (enemyStrength > 4000) {
      this.enemyLevel = 5;
    }
    else if (enemyStrength > 3000) {
      this.enemyLevel = 4;
    }
    else if (enemyStrength > 2000) {
      this.enemyLevel = 3;
    }
    else if (enemyStrength > 1000) {
      this.enemyLevel = 2;
    }
    else if (enemyStrength > 0) {
      this.enemyLevel = 1;
    }

    switch (enemyLevel) {

      case 5:
        this.loot = this.generateLoot("Platinum");
        break;
      case 4:
        this.loot = this.generateLoot("Gold");
        break;
      case 3:
        this.loot = this.generateLoot("Silver");
        break;
      case 2:
        this.loot = this.generateLoot("Bronze");
        break;
      case 1:
        this.loot = this.generateLoot("Wooden");
        break;
    }

    shouldDropLoot = ThreadLocalRandom.current().nextInt(0, 1 + 1);

    if (shouldDropLoot == 1) {

      this.loot = "None";
    }

    this.x = ThreadLocalRandom.current().nextInt(0, mapSize);
    this.y = ThreadLocalRandom.current().nextInt(0, mapSize);
  }

  public int getEnemyHitPoints() {
    return this.enemyHitPoints;
  }

  public int getEnemyAttackPoints() {
    return this.enemyAttackPoints;
  }

  public String getLoot() {
    return this.loot;
  }

  public int getX() {
    return this.x;
  }

  public int getY() {
    return this.y;
  }

  public void reduceEnemyHitPoints(int hitPoints) {

    this.enemyHitPoints -= hitPoints;

    if (this.enemyHitPoints <= 0) {
      this.enemyAlive = false;
    }
  }
}
