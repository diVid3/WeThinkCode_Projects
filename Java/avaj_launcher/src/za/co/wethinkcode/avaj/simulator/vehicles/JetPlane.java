package za.co.wethinkcode.avaj.simulator.vehicles;

import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;
import za.co.wethinkcode.avaj.simulator.weather.WeatherTower;

import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStreamWriter;

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

    FileOutputStream outStream = new FileOutputStream("simulation.txt");
    OutputStreamWriter outStreamWriter = new OutputStreamWriter(outStream);
    BufferedWriter writer = new BufferedWriter(outStreamWriter);

    String baseString = "JetPlane#" + this.name + "(" + this.id + ")";

    switch (weather) {

      case "SUN":
        this.coordinates.setLongitude(this.coordinates.getLongitude() + 2);
        this.coordinates.setHeight(this.coordinates.getHeight() + 4);
        writer.write( baseString + ": Weather clear, moving quite steadily.");
        break;
      case "RAIN":
        this.coordinates.setHeight(this.coordinates.getHeight() - 5);
        writer.write( baseString + ": Need to watch-out for lightning!");
        break;
      case "FOG":
        this.coordinates.setHeight(this.coordinates.getHeight() - 3);
        writer.write( baseString + ": This speed with fog, not good.");
        break;
      case "SNOW":
        this.coordinates.setHeight(this.coordinates.getHeight() - 15);
        writer.write( baseString + ": Can't see a thing!");
        break;
    }

    if (this.coordinates.getHeight() <= 0) {

      this.weatherTower.unregister(this);

      writer.write("WeatherTower: " + baseString + " unregistered!");
      writer.write("Coordinates of " + baseString + ": " +
          "Longitude - " + this.coordinates.getLongitude() +
          "Latitude - " + this.coordinates.getLatitude() +
          "Height - " + this.coordinates.getHeight());
    }

    if (this.coordinates.getHeight() > 100) {

      this.coordinates.setHeight(100);
    }

    writer.close();
  }

  // TODO: Call this when after vehicles spawned.
  @Override
  public void registerTower(WeatherTower weatherTower) throws IOException {

    this.weatherTower = weatherTower;

    FileOutputStream outStream = new FileOutputStream("simulation.txt");
    OutputStreamWriter outStreamWriter = new OutputStreamWriter(outStream);
    BufferedWriter writer = new BufferedWriter(outStreamWriter);

    String baseString = "JetPlane#" + this.name + "(" + this.id + ")";

    writer.write("WeatherTower: " + baseString + " registered!");
    writer.close();
  }
}