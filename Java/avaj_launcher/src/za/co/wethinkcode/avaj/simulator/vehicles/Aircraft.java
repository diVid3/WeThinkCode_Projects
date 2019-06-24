package za.co.wethinkcode.avaj.simulator.vehicles;

// TODO: Make this class abstract.
public class Aircraft {

  private static long idCounter = 0;

  protected long id;
  protected String name;
  protected Coordinates coordinates;

  protected Aircraft(String name, Coordinates coordinates) {

    this.name = name;
    this.coordinates = coordinates;
    this.id = this.nextId();
  }

  private long nextId() {

    return ++idCounter;
  }
}
