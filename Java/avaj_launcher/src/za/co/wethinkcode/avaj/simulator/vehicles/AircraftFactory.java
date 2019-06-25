package za.co.wethinkcode.avaj.simulator.vehicles;

import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;

public abstract class AircraftFactory {

  public static Flyable newAircraft(
      String type,
      String name,
      int longitude,
      int latitude,
      int height
  ) {

    Coordinates coordinates = new Coordinates(longitude, latitude, height);
    Flyable aircraft = null;

    switch (type) {
      case "Helicopter":
        aircraft = new Helicopter(name, coordinates);
        break;
      case "JetPlane":
        aircraft = new JetPlane(name, coordinates);
        break;
      case "Baloon":
        aircraft = new Baloon(name, coordinates);
        break;
    }

    return aircraft;
  }
}
