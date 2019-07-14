package za.co.wethinkcode.swingy.helpers;

import java.util.Scanner;
import java.util.regex.Pattern;

public class InputHelper {

  public InputHelper() {

  }

  public static String getInput() {

    Scanner inputScanner = new Scanner(System.in);

    String input = inputScanner.nextLine();
    // System.out.println("\n");

    return input;
  }

  // This validates whether the string passed in is correct in terms of
  // characters allowed.
  public static boolean hasIllegalChars(String testMe) {

    return Pattern.matches("[^\\w]+", testMe);
  }
}
