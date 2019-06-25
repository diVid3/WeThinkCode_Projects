package za.co.wethinkcode.avaj.simulator.vehicles;

import za.co.wethinkcode.avaj.simulator.exceptions.InvalidInputException;
import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;

public abstract class AircraftFactory {

  public static Flyable newAircraft(String type, String name, int longitude, int latitude, int height) throws InvalidInputException {

    Coordinates coordinates = new Coordinates(longitude, latitude, height);

    if (
      !type.equals("Helicopter") &&
      !type.equals("JetPlane") &&
      !type.equals("Baloon")
    ) {

      throw new InvalidInputException("Incorrect aircraft type for spawning, exiting.");
    }

    switch (type) {
      case "Helicopter":
        return new Helicopter(name, coordinates);
      case "JetPlane":
        return new JetPlane(name, coordinates);
      case "Baloon":
        return new Baloon(name, coordinates);
    }

    return null;
  }
}
