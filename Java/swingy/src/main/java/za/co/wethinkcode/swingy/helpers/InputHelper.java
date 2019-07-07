package za.co.wethinkcode.swingy.helpers;

import java.util.Scanner;

public class InputHelper {

  public InputHelper() {

  }

  public static String getInput() {

    Scanner inputScanner = new Scanner(System.in);
    String input = inputScanner.nextLine();

    return input;
  }
}
