package za.co.wethinkcode.avaj.simulator;

import za.co.wethinkcode.avaj.simulator.vehicles.Coordinates;
import za.co.wethinkcode.avaj.simulator.weather.WeatherProvider;

import java.io.IOException;

public class WeatherTower extends Tower {

  public WeatherTower() {

    super();
  }

  public String getWeather(Coordinates coordinates) {

    WeatherProvider weatherProvider = WeatherProvider.getProvider();
    return weatherProvider.getCurrentWeather(coordinates);
  }

  void changeWeather() throws IOException {

    this.conditionsChanged();
  }
}
