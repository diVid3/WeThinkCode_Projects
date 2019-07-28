package za.co.wethinkcode.swingy.views;

import javax.swing.*;
import java.awt.event.WindowEvent;

public class GuiDriver {

  private JFrame frame;
  private JLabel[] gameStateLabels;

  public GuiDriver() {

    this.frame = new JFrame("Swingy");

    // Needs to be 5 because gamePlayPanel.
    this.gameStateLabels = new JLabel[5];

    this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    this.frame.setResizable(false);
  }

  public JLabel[] getGameStateLabels() {

    return this.gameStateLabels;
  }

  public void refreshWindow(JPanel panel) {

    this.frame.setContentPane(panel);
    this.frame.pack();
    this.frame.setLocationRelativeTo(null);
    this.frame.revalidate();
    this.frame.repaint();

    if (!this.frame.isVisible()) {

      this.frame.setVisible(true);
    }
  }

  public void displayLoadedHeroSuccess() {

    JOptionPane.showMessageDialog(
      null,
      "Your hero was successfully loaded.",
      "Success",
      JOptionPane.INFORMATION_MESSAGE
    );
  }

  public void displayCreatedHeroSuccess() {

    JOptionPane.showMessageDialog(
      null,
      "Your hero was successfully created.",
      "Success",
      JOptionPane.INFORMATION_MESSAGE
    );
  }

  public void displayGameOver() {

    JOptionPane.showMessageDialog(
      null,
      "Game Over.",
      "Fail",
      JOptionPane.INFORMATION_MESSAGE
    );

    this.frame.dispose();
    System.exit(0);
  }

  public void displayGameWon() {

    JOptionPane.showMessageDialog(
      null,
      "Congratulations! You Won!",
      "Success",
      JOptionPane.INFORMATION_MESSAGE
    );

    this.frame.dispose();
    System.exit(0);
  }

  public void displayStuffGained(String message) {

    JOptionPane.showMessageDialog(
      null,
      message,
      "Success",
      JOptionPane.INFORMATION_MESSAGE
    );
  }

  public int displayGuiInputCollided() {

    String[] options = {"Run", "Fight"};
    int choice;

    choice = JOptionPane.showOptionDialog(
      null,
      "You've collided with an enemy, run or fight.",
      "Enemy Found",
      JOptionPane.DEFAULT_OPTION,
      JOptionPane.INFORMATION_MESSAGE,
      null,
      options,
      options[0]
    );

    return choice;
  }

  // public void closeGuiApplication() {
  //
  //   // this.frame.dispatchEvent(new WindowEvent(this.frame, WindowEvent.WINDOW_CLOSING));
  //   // System.exit(0);
  //   System.out.println("closeGuiApplication called!");
  //   this.frame.dispose();
  // }
}
