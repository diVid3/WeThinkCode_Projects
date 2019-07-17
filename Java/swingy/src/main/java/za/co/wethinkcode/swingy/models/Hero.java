package za.co.wethinkcode.swingy.models;

import za.co.wethinkcode.swingy.Interfaces.ViewDisplayable;

import javax.validation.constraints.*;
import java.util.LinkedList;
import java.util.List;

public class Hero implements ViewDisplayable {

  // Given via user input.
  @NotNull(message = "heroName null.")
  @NotEmpty(message = "heroName empty.")
  @Size(min = 3, max = 20, message = "heroName invalid size.")
  private String heroName;

  // Given via user input, but chosen from list.
  @NotNull(message = "heroClass null.")
  @NotEmpty(message = "heroClass empty.")
  private String heroClass;

  // Calculated.
  @NotNull(message = "heroLevel null.")
  @Min(value = 0, message = "heroLevel below 0.")
  private int heroLevel;

  // TODO: Set min to 450.
  // Calculated.
  @NotNull(message = "heroExperience null.")
  @Min(value = 0, message = "heroExperience below 0.")
  private int heroExperience;

  // Calculated.
  @NotNull(message = "heroAttack null.")
  private int heroAttack;

  // Calculated.
  @NotNull(message = "heroDefence null.")
  @Min(value = 0, message = "heroDefence below 0.")
  private int heroDefence;

  // Calculated.
  @NotNull(message = "heroHitPoints null.")
  private int heroHitPoints;

  // Calculated.
  @NotNull(message = "heroWeapon null.")
  @NotEmpty(message = "heroWeapon empty.")
  private String heroWeapon;

  // Calculated.
  @NotNull(message = "heroArmor null.")
  @NotEmpty(message = "heroArmor empty.")
  private String heroArmor;

  // Calculated.
  @NotNull(message = "heroHelm null.")
  @NotEmpty(message = "heroHelm empty.")
  private String heroHelm;

  private int x;
  private int y;
  private int mapSize;
  private List<int[]> oldMovements;

  // This is to store only unique coordinates when clamping movement
  // to mapSize. So by going up, you don't store 0 (x), 5 (y) twice.
  private boolean canAddCurrentCoordinates() {

    int listSize = this.oldMovements.size();

    if (listSize > 0) {

      int[] lastCoordinates = this.oldMovements.get(listSize - 1);

      if (lastCoordinates[0] == this.x && lastCoordinates[1] == this.y) {

        return false;
      }
    }

    return true;
  }

  private void storeCoordinates() {

    int[] currentCoordinates = new int[2];

    currentCoordinates[0] = this.x;
    currentCoordinates[1] = this.y;

    if (this.canAddCurrentCoordinates()) {

      this.oldMovements.add(currentCoordinates);
    }
  }

  private void updateHeroLevel() {

    double exp;
    double discriminant;
    double levelDouble;

    exp = this.heroExperience;
    discriminant = Math.sqrt(2 * (-4000 + (9 * exp)));
    levelDouble = (-10 + discriminant) / 90;

    this.heroLevel = (int)Math.floor(levelDouble);
  }

  private void updateHeroHitPoints() {

    switch (this.heroWeapon) {

      case "Wooden Sword":
        this.heroAttack = 200;
        break;
      case "Bronze Sword":
        this.heroAttack = 300;
        break;
      case "Silver Sword":
        this.heroAttack = 500;
        break;
      case "Gold Sword":
        this.heroAttack = 800;
        break;
      case "Platinum Sword":
        this.heroAttack = 1200;
        break;
    }

    switch (this.heroArmor) {

      case "Wooden Armor":
        this.heroDefence = 100;
        break;
      case "Bronze Armor":
        this.heroDefence = 200;
        break;
      case "Silver Armor":
        this.heroDefence = 300;
        break;
      case "Gold Armor":
        this.heroDefence = 400;
        break;
      case "Platinum Armor":
        this.heroDefence = 500;
        break;
    }

    switch (this.heroHelm) {

      case "Wooden Helm":
        this.heroDefence += 50;
        break;
      case "Bronze Helm":
        this.heroDefence += 100;
        break;
      case "Silver Helm":
        this.heroDefence += 150;
        break;
      case "Gold Helm":
        this.heroDefence += 200;
        break;
      case "Platinum Helm":
        this.heroDefence += 250;
        break;
    }

    this.heroHitPoints = (this.heroLevel + 1) * 500 + this.heroDefence;
  }

  private void updateMapSize() {

    this.mapSize = (this.heroLevel - 1) * 5 + 10 - (this.heroLevel % 2);
  }

  private void updateHeroPosition() {

    int pos = this.mapSize / 2;

    this.x = pos;
    this.y = pos;
  }

  private void updateOldHeroMovements() {

    this.oldMovements = new LinkedList<>();
    this.storeCoordinates();
  }

  private void addExperience(int newExperience) {

    // TODO: Remember to increase mapSize when leveling.

    this.heroExperience += newExperience;
  }

  private void addLoot(String loot) {

    if (loot.equals("None")) {

      return;
    }

    if (loot.contains("Sword")) {

      this.heroWeapon = loot;
    }
    else if (loot.contains("Armor")) {

      this.heroArmor = loot;
    }
    else if (loot.contains("Helm")) {

      this.heroHelm = loot;
    }

    // TODO: Might need to recalculate stats.
  }

  public Hero(
    String heroName,
    String heroClass,
    int heroExperience,
    String heroWeapon,
    String heroArmor,
    String heroHelm
  ) {

    this.heroName = heroName;
    this.heroClass = heroClass;
    this.heroExperience = heroExperience;
    this.heroWeapon = heroWeapon;
    this.heroArmor = heroArmor;
    this.heroHelm = heroHelm;

    this.updateHeroLevel();
    this.updateHeroHitPoints();
    this.updateMapSize();
    this.updateHeroPosition();
    this.updateOldHeroMovements();
  }

  public String getHeroName() {
    return this.heroName;
  }

  public String getHeroClass() {
    return this.heroClass;
  }

  public int getHeroLevel() {
    return this.heroLevel;
  }

  public int getHeroExperience() {
    return this.heroExperience;
  }

  public int getHeroAttack() {
    return this.heroAttack;
  }

  public int getHeroDefence() {
    return this.heroDefence;
  }

  public int getHeroHitPoints() {
    return this.heroHitPoints;
  }

  public String getHeroWeapon() {
    return this.heroWeapon;
  }

  public String getHeroArmor() {
    return this.heroArmor;
  }

  public String getHeroHelm() {
    return this.heroHelm;
  }

  public int getX() {
    return this.x;
  }

  public int getY() {
    return this.y;
  }

  public void setHeroName(String heroName) {
    this.heroName = heroName;
  }

  public void setHeroClass(String heroClass) {
    this.heroClass = heroClass;
  }

  public void setHeroLevel(int heroLevel) {
    this.heroLevel = heroLevel;
  }

  public void setHeroExperience(int heroExperience) {
    this.heroExperience = heroExperience;
  }

  public void setHeroAttack(int heroAttack) {
    this.heroAttack = heroAttack;
  }

  public void setHeroDefence(int heroDefence) {
    this.heroDefence = heroDefence;
  }

  public void setHeroHitPoints(int heroHitPoints) {
    this.heroHitPoints = heroHitPoints;
  }

  public void setHeroWeapon(String heroWeapon) {
    this.heroWeapon = heroWeapon;
  }

  public void setHeroArmor(String heroArmor) {
    this.heroArmor = heroArmor;
  }

  public void setHeroHelm(String heroHelm) {
    this.heroHelm = heroHelm;
  }

  public void reduceHeroHitPoints(int hitPoints) {

    this.heroHitPoints -= hitPoints;
  }

  // x's are rows.
  // y's are columns.

  public void moveUp() {

    if (this.y - 1 >= 0) {

      this.y -= 1;
      this.storeCoordinates();
    }
  }

  public void moveLeft() {

    if (this.x - 1 >= 0) {

      this.x -= 1;
      this.storeCoordinates();
    }
  }

  public void moveDown() {

    if (this.y + 1 < mapSize) {

      this.y += 1;
      this.storeCoordinates();
    }
  }

  public void moveRight() {

    if (this.x + 1 < mapSize) {

      this.x += 1;
      this.storeCoordinates();
    }
  }

  // Returns true if successfully moved back.
  public boolean moveBack() {

    int listSize = this.oldMovements.size();

    if (listSize > 0) {

      int[] oldCoordinates = this.oldMovements.remove(listSize - 1);
      this.x = oldCoordinates[0];
      this.y = oldCoordinates[1];
      return true;
    }

    return false;
  }

  public void takeLootExperience(String loot, int experience) {

    this.addLoot(loot);
    this.addExperience(experience);

    this.updateHeroLevel();
    this.updateHeroHitPoints();
    this.updateMapSize();
    this.updateHeroPosition();
    this.updateOldHeroMovements();
  }
}
