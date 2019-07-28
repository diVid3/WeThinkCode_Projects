package za.co.wethinkcode.swingy.helpers;

import java.util.Scanner;
import java.util.regex.Pattern;

public class InputHelper {

  public InputHelper() {

  }

  public static String getInput() {

    String input = "";

    Scanner inputScanner = new Scanner(System.in);

    if (inputScanner.hasNext()) {
      input = inputScanner.nextLine();
    }

    return input;
  }

  // This validates whether the string passed in is correct in terms of
  // characters allowed.
  public static boolean hasIllegalChars(String testMe) {

    if (testMe.equals("")) {

      return true;
    }

    return Pattern.matches("[^\\w]+", testMe);
  }
}
