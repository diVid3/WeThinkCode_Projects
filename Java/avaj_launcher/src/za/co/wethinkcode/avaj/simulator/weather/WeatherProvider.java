package za.co.wethinkcode.avaj.simulator.weather;

import za.co.wethinkcode.avaj.simulator.vehicles.Coordinates;

public class WeatherProvider {

  private static WeatherProvider weatherProvider = null;
  private static String[] weather = {"SUN", "RAIN", "FOG", "SNOW"};

  private WeatherProvider() {

  }

  public static WeatherProvider getProvider() {

    if (weatherProvider == null) {

      weatherProvider = new WeatherProvider();
    }

    return weatherProvider;
  }

  public String getCurrentWeather(Coordinates coordinates) {

    int modMe = coordinates.getLongitude() + coordinates.getLatitude() + coordinates.getHeight();
    int remainder = modMe % 4;

    return this.weather[remainder];
  }
}
