package za.co.wethinkcode.avaj.simulator.weather;

import za.co.wethinkcode.avaj.simulator.vehicles.Coordinates;

public class WeatherTower extends Tower {

  public WeatherTower() {

    super();
  }

  public String getWeather(Coordinates coordinates) {

    WeatherProvider weatherProvider = WeatherProvider.getProvider();
    return weatherProvider.getCurrentWeather(coordinates);
  }

  // This is called simulatorCycles amount of times.
  void changeWeather() {

    // This will let all the flyables update to new weather.
    this.conditionsChanged();
  }
}
