package za.co.wethinkcode.avaj.simulator.weather;

import za.co.wethinkcode.avaj.simulator.vehicles.Coordinates;

public class WeatherProvider {

  private static WeatherProvider weatherProvider = null;
  private String[] weather;

  private WeatherProvider() {

    weather = new String[4];

    weather[0] = "SUN";
    weather[1] = "RAIN";
    weather[2] = "FOG";
    weather[3] = "SNOW";
  }

  public static WeatherProvider getProvider() {

    if (weatherProvider == null) {

      weatherProvider = new WeatherProvider();
    }

    return weatherProvider;
  }

  public String getCurrentWeather(Coordinates coordinates) {

  // TODO: Take in current flyable coordinates, calc. new weather, return it.


  }
}
