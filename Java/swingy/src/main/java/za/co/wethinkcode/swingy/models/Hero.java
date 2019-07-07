package za.co.wethinkcode.swingy.models;

import za.co.wethinkcode.swingy.Interfaces.ViewDisplayable;

import javax.validation.constraints.*;

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
  private int OldX;
  private int OldY;

  public Hero(
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
  ) {

    this.heroName = heroName;
    this.heroClass = heroClass;
    this.heroLevel = heroLevel;
    this.heroExperience = heroExperience;
    this.heroAttack = heroAttack;
    this.heroDefence = heroDefence;
    this.heroHitPoints = heroHitPoints;
    this.heroWeapon = heroWeapon;
    this.heroArmor = heroArmor;
    this.heroHelm = heroHelm;

    int pos = ((heroLevel - 1) * 5 + 10 - (heroLevel % 2)) / 2;

    this.x = pos;
    this.y = pos;
    this.OldX = pos;
    this.OldY = pos;

    // TODO: Remove enemies that the hero might spawn on, mark first, then del.
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

  public int getOldX() { return this.OldX; }

  public int getOldY() { return this.OldY; }

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

  public void setX(int x) {

    this.OldX = this.x;
    this.x = x;
  }

  public void setY(int y) {

    this.OldY = this.y;
    this.y = y;
  }
}
