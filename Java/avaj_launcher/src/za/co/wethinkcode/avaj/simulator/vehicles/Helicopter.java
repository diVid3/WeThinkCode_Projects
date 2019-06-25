package za.co.wethinkcode.avaj.simulator.vehicles;

import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;
import za.co.wethinkcode.avaj.simulator.WeatherTower;

import java.io.*;

public class Helicopter extends Aircraft implements Flyable {

  private WeatherTower weatherTower;

  Helicopter(String name, Coordinates coordinates) {

    super(name, coordinates);

    if (this.coordinates.getHeight() > 100) {

      this.coordinates.setHeight(100);
    }
  }

  @Override
  public void updateConditions() throws IOException {

    String weather = this.weatherTower.getWeather(this.coordinates);

    File file = new File("simulation.txt");
    FileWriter fw = new FileWriter(file, true);

    if (!file.exists()) {

      file.createNewFile();
    }

    BufferedWriter writer = new BufferedWriter(fw);

    String baseString = "Helicopter#" + this.name + "(" + this.id + ")";

    switch (weather) {

      case "SUN":
        this.coordinates.setLongitude(this.coordinates.getLongitude() + 10);
        this.coordinates.setHeight(this.coordinates.getHeight() + 2);
        writer.write( baseString + ": Sun's out, guns out!\n");
        break;
      case "RAIN":
        this.coordinates.setLongitude(this.coordinates.getLongitude() + 5);
        writer.write(baseString + ": I can't see through the rain!\n");
        break;
      case "FOG":
        this.coordinates.setLongitude(this.coordinates.getLongitude() + 1);
        writer.write(baseString + ": I hope we don't crash in this fog.\n");
        break;
      case "SNOW":
        this.coordinates.setHeight(this.coordinates.getHeight() - 12);
        writer.write(baseString + ": I need to go lower in the snow!\n");
        break;
    }

    if (this.coordinates.getHeight() <= 0) {

      this.coordinates.setHeight(0);

      writer.write(baseString + ": Landing.\n");
      writer.write("WeatherTower: " + baseString + " unregistered!\n");
      writer.write("Coordinates of " + baseString + ": " +
          "Longitude - " + this.coordinates.getLongitude() + ", " +
          "Latitude - " + this.coordinates.getLatitude() + ", " +
          "Height - " + this.coordinates.getHeight() + "\n");

      this.weatherTower.unregister(this);
    }

    if (this.coordinates.getHeight() > 100) {

      this.coordinates.setHeight(100);
    }

    writer.close();
  }

  @Override
  public void registerTower(WeatherTower weatherTower) throws IOException {

    this.weatherTower = weatherTower;

    File file = new File("simulation.txt");
    FileWriter fw = new FileWriter(file, true);

    if (!file.exists()) {

      file.createNewFile();
    }

    BufferedWriter writer = new BufferedWriter(fw);

    String baseString = "Helicopter#" + this.name + "(" + this.id + ")";

    writer.write("WeatherTower: " + baseString + " registered!\n");
    writer.close();
  }
}
