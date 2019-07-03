package za.co.wethinkcode.swingy.helpers;

import za.co.wethinkcode.swingy.models.Hero;

import javax.persistence.EntityManager;
import javax.persistence.EntityTransaction;

public class addHero {

  public static void addHero(
    EntityManager em,
    int id,
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
  ) throws Exception {

    EntityTransaction et = em.getTransaction();
    et.begin();
    Hero newHero = new Hero
  }
}
