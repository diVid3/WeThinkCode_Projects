package za.co.wethinkcode.avaj.simulator.vehicles;

import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;
import za.co.wethinkcode.avaj.simulator.WeatherTower;

import java.io.*;

public class JetPlane extends Aircraft implements Flyable {

  private WeatherTower weatherTower;

  JetPlane(String name, Coordinates coordinates) {

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

    String baseString = "JetPlane#" + this.name + "(" + this.id + ")";

    switch (weather) {

      case "SUN":
        this.coordinates.setLongitude(this.coordinates.getLongitude() + 2);
        this.coordinates.setHeight(this.coordinates.getHeight() + 4);
        writer.write( baseString + ": Weather clear, moving quite steadily.\n");
        break;
      case "RAIN":
        this.coordinates.setHeight(this.coordinates.getHeight() - 5);
        writer.write( baseString + ": Need to watch-out for lightning!\n");
        break;
      case "FOG":
        this.coordinates.setHeight(this.coordinates.getHeight() - 3);
        writer.write( baseString + ": This speed with fog, not good.\n");
        break;
      case "SNOW":
        this.coordinates.setHeight(this.coordinates.getHeight() - 15);
        writer.write( baseString + ": Can't see a thing!\n");
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

    String baseString = "JetPlane#" + this.name + "(" + this.id + ")";

    writer.write("WeatherTower: " + baseString + " registered!\n");
    writer.close();
  }
}
