package za.co.wethinkcode.swingy.models;

import java.io.Serializable;

public class Hero {

  // private static final long serialVersionUID = 1L;

  private int id;

  private String heroName;

  private String heroClass;

  private int heroLevel;

  private int heroExperience;

  private int heroAttack;

  private int heroDefence;

  private int heroHitPoints;

  private String heroWeapon;

  private String heroArmor;

  private String heroHelm;

  public int getId() {
    return this.id;
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

  public void setId(int id) {
    this.id = id;
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
}
