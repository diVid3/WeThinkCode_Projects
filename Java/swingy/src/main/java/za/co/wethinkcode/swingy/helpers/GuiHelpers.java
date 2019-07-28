package za.co.wethinkcode.swingy.helpers;

import za.co.wethinkcode.swingy.models.Hero;

import javax.swing.*;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;

public class GuiHelpers {

  public static HashMap<String, Hero> getHeroDictionary(ResultSet heroes) throws
    SQLException {

    HashMap<String, Hero> heroDict = new HashMap<>();
    Hero heroToAdd;

    String heroName;
    String heroClass;
    int heroExperience;
    String heroWeapon;
    String heroArmor;
    String heroHelm;

    while (heroes.next()) {

      heroName = heroes.getString("heroName");
      heroClass = heroes.getString("heroClass");
      heroExperience = heroes.getInt("heroExperience");
      heroWeapon = heroes.getString("heroWeapon");
      heroArmor = heroes.getString("heroArmor");
      heroHelm = heroes.getString("heroHelm");

      heroToAdd = new Hero(
        heroName,
        heroClass,
        heroExperience,
        heroWeapon,
        heroArmor,
        heroHelm
      );

      heroDict.put(heroName, heroToAdd);
    }

    return heroDict;
  }

  public static String[] getHeroNameArray(ResultSet heroes) throws
    SQLException {

    List<String> heroesList = new LinkedList<>();

    int heroCount = 0;
    while (heroes.next()) {

      heroesList.add(heroes.getString("heroName"));
      heroCount++;
    }

    String[] heroNameList = new String[heroCount];

    for (int i = 0; i < heroCount; i++) {

      heroNameList[i] = heroesList.get(i);
    }

    return heroNameList;
  }

  public static void assignGameStateLabels(
    JLabel[] gameStateLabelInfo,
    String gameState
  ) {

    String[] gameStateInfo = gameState.split("\\|");

    gameStateLabelInfo[0].setText(gameStateInfo[0]);
    gameStateLabelInfo[1].setText("Life - " + gameStateInfo[1]);
    gameStateLabelInfo[2].setText("Level - " + gameStateInfo[2]);
    gameStateLabelInfo[3].setText("Experience - " + gameStateInfo[3]);
    gameStateLabelInfo[4].setText("Coordinates - " + gameStateInfo[4]  + ", " + gameStateInfo[5]);
  }
}
