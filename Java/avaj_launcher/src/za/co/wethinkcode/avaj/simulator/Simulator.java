package za.co.wethinkcode.avaj.simulator;

import za.co.wethinkcode.avaj.simulator.exceptions.InvalidInputException;

import java.io.IOException;
import java.util.LinkedList;

public class Simulator {

  public static void main(String[] args) {

    int simulatorCycles;
    LinkedList<String> data;
    CustomFileReader fr = new CustomFileReader();

    try {

      fr.readData(args[0]);
      fr.validateData();
      data = fr.getData();
      simulatorCycles = Integer.parseInt(data.removeLast());
    }
    catch (
      InvalidInputException |
      IOException |
      NumberFormatException |
      ArrayIndexOutOfBoundsException |
      NullPointerException e
    ) {

      e.printStackTrace(System.out);
    }
  }
}
