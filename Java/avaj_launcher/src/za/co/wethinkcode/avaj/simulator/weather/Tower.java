package za.co.wethinkcode.avaj.simulator.weather;

import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;

import java.util.ArrayList;

// TODO: Make this class abstract.
public class Tower {

  private ArrayList<Flyable> observers;

  Tower() {

    this.observers = new ArrayList<Flyable>();
  }

  public void register(Flyable flyable) {

    observers.add(flyable);
  }

  public void unregister(Flyable flyable) {

    observers.remove(flyable);
  }

  protected void conditionsChanged() {

    for (Flyable flyable: observers) {

      flyable.updateConditions();
    }
  }
}
