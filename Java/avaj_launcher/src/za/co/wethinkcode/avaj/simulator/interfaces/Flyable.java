package za.co.wethinkcode.avaj.simulator.interfaces;

import za.co.wethinkcode.avaj.simulator.weather.WeatherTower;

public interface Flyable {

  public void updateConditions();
  public void registerTower(WeatherTower weatherTower);
}
