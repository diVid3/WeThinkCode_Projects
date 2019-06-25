package za.co.wethinkcode.avaj.simulator;

import za.co.wethinkcode.avaj.simulator.interfaces.Flyable;

import java.io.IOException;
import java.util.ArrayList;

public abstract class Tower {

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

  protected void conditionsChanged() throws IOException {

    for (Flyable flyable: observers) {

      flyable.updateConditions();
    }
  }
}
