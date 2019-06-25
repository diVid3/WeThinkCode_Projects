package za.co.wethinkcode.avaj.simulator;

import za.co.wethinkcode.avaj.simulator.exceptions.InvalidInputException;
import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;
import za.co.wethinkcode.avaj.simulator.vehicles.AircraftFactory;

import java.io.IOException;
import java.util.LinkedList;

public class Simulator {

  private static void simulate(LinkedList<String> data) throws
      IOException {

    WeatherTower tower = new WeatherTower();

    int simulatorCycles = Integer.parseInt(data.removeLast());
    int dataSize = data.size();

    String type;
    String name;
    int longitude;
    int latitude;
    int height;

    Flyable newAircraft;

    for (int i = 0; i < dataSize; i++) {

      String[] splitLine = data.removeLast().split(" ");

      type = splitLine[0];
      name = splitLine[1];
      longitude = Integer.parseInt(splitLine[2]);
      latitude = Integer.parseInt(splitLine[3]);
      height = Integer.parseInt(splitLine[4]);

      newAircraft = AircraftFactory.newAircraft(
          type, name, longitude, latitude, height);

      tower.register(newAircraft);
      newAircraft.registerTower(tower);
    }

    for (int i = 0; i < simulatorCycles; i++) {

      tower.changeWeather();
    }
  }

  public static void main(String[] args) {

    LinkedList<String> data;
    CustomFileReader fr = new CustomFileReader();

    try {

      fr.readData(args[0]);
      fr.validateData();
      data = fr.getData();

      simulate(data);
    }
    catch (
      InvalidInputException |
      IOException |
      NumberFormatException |
      ArrayIndexOutOfBoundsException |
      NullPointerException e
    ) {

      e.printStackTrace(System.out);
    }
  }
}
