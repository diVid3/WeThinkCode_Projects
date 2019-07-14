package za.co.wethinkcode.swingy.helpers;

public class DisplayFormatter {

  public DisplayFormatter() {

  }

  public static String formatHeroLife(int heroHitPoints) {

    return (Integer.toString(heroHitPoints) + " HP");
  }

  public static String formatHeroLevel(int heroLevel) {

    return ("Level: " + Integer.toString(heroLevel));
  }

  public static String formatHeroExperience(int heroExperience) {

    return ("Experience: " + Integer.toString(heroExperience));
  }

  public static String formatHeroAttack(int heroAttack) {

    return ("Attack: " + Integer.toString(heroAttack));
  }

  public static String formatHeroDefence(int heroDefence) {

    return ("Defence: " + Integer.toString(heroDefence));
  }

  public static String formatHeroWeapon(String heroWeapon) {

    return ("Weapon: " + heroWeapon);
  }

  public static String formatHeroArmor(String heroArmor) {

    return ("Armor: " + heroArmor);
  }

  public static String formatHeroHelm(String heroHelm) {

    return ("Helm: " + heroHelm);
  }
}
