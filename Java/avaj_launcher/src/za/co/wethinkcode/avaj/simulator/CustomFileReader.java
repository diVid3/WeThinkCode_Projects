package za.co.wethinkcode.avaj.simulator;

import za.co.wethinkcode.avaj.simulator.exceptions.InvalidInputException;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.LinkedList;

class CustomFileReader {

  private LinkedList<String> data;

  CustomFileReader() {

    this.data = new LinkedList<String>();
  }

  void readData(String path) throws IOException, NullPointerException {

    BufferedReader bufReader = new BufferedReader(new FileReader(path));
    String line;

    while ((line = bufReader.readLine()) != null) {
      this.data.push(line);
    }

    bufReader.close();
  }

  void validateData() throws
      InvalidInputException,
      NumberFormatException {

    LinkedList<String> listClone = (LinkedList<String>)data.clone();
    String line;
    int listSize;

    line = listClone.removeLast();
    int simulatorCycles = Integer.parseInt(line);

    if (simulatorCycles < 0) {
      throw new InvalidInputException("Simulator cycles < 0!");
    }

    listSize = listClone.size();

    for (int i = 0; i < listSize; i++) {

      int testMe;
      int lineNr = i + 2;
      line = listClone.removeLast();
      String[] splitLine = line.split(" ");

      if (splitLine.length != 5) {
        throw new InvalidInputException("Line " + lineNr + " invalid length!");
      }

      if (
        !splitLine[0].equals("Baloon") &&
        !splitLine[0].equals("JetPlane") &&
        !splitLine[0].equals("Helicopter")
      ) {

        throw new InvalidInputException("Line " + lineNr +
            " invalid aircraft type!");
      }

      for (int j = 2; j < 5; j++) {

        testMe = Integer.parseInt(splitLine[j]);

        if (testMe < 0) {

          throw new InvalidInputException("Line " + lineNr +
              " invalid coordinates!");
        }
      }
    }
  }

  LinkedList<String> getData() {

    return this.data;
  }
}
