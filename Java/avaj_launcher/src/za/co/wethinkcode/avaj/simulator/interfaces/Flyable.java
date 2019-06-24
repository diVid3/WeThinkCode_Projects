package za.co.wethinkcode.avaj.simulator.interfaces;

import za.co.wethinkcode.avaj.simulator.weather.WeatherTower;

import java.io.IOException;

public interface Flyable {

  public void updateConditions() throws IOException;
  public void registerTower(WeatherTower weatherTower) throws IOException;
}
