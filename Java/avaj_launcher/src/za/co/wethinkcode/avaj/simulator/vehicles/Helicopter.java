package za.co.wethinkcode.avaj.simulator.vehicles;

import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;
import za.co.wethinkcode.avaj.simulator.weather.WeatherTower;

public class Helicopter extends Aircraft implements Flyable {

  private WeatherTower weatherTower;

  private void unregisterAircraft() {

    this.weatherTower.unregisterAircraft(this);
  }

  Helicopter(String name, Coordinates coordinates) {

    super(name, coordinates);

    if (this.coordinates.getHeight() > 100) {

      this.coordinates.setHeight(100);
    }
  }

  @Override
  public void updateConditions() {

    String weather = this.weatherTower.getWeather(this.coordinates);

    switch (weather) {

      case "SUN":
        this.coordinates.setLongitude(this.coordinates.getLongitude() + 10);
        this.coordinates.setHeight(this.coordinates.getHeight() + 2);
        break;
      case "RAIN":
        this.coordinates.setLongitude(this.coordinates.getLongitude() + 5);
        break;
      case "FOG":
        this.coordinates.setLongitude(this.coordinates.getLongitude() + 1);
        break;
      case "SNOW":
        this.coordinates.setHeight(this.coordinates.getHeight() - 12);
        break;
    }

    if (this.coordinates.getHeight() <= 0) {

      this.weatherTower.unregister(this);
    }

    if (this.coordinates.getHeight() > 100) {

      this.coordinates.setHeight(100);
    }
  }

  // TODO: Call this when after vehicles spawned.
  @Override
  public void registerTower(WeatherTower weatherTower) {

    this.weatherTower = weatherTower;
  }
}
