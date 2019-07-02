package za.co.wethinkcode.swingy.models;

import java.io.Serializable;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "heroes")
public class Hero implements Serializable {

  private static final long serialVersionUID = 1L;

  // TODO: Change DB settings to not auto-increment id.

  @Id
  @Column(name = "id", unique = true)
  private int id;

  @Column(name = "heroName", nullable = false)
  private String heroName;

  @Column(name = "heroClass", nullable = false)
  private String heroClass;

  @Column(name = "heroLevel", nullable = false)
  private int heroLevel;

  @Column(name = "heroExperience", nullable = false)
  private int heroExperience;

  @Column(name = "heroAttack", nullable = false)
  private int heroAttack;

  @Column(name = "heroDefence", nullable = false)
  private int heroDefence;

  @Column(name = "heroHitPoints", nullable = false)
  private int heroHitPoints;

  @Column(name = "heroWeapon", nullable = false)
  private String heroWeapon;

  @Column(name = "heroArmor", nullable = false)
  private String heroArmor;

  @Column(name = "heroHelm", nullable = false)
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
