package za.co.wethinkcode.swingy.views;

import za.co.wethinkcode.swingy.views.GUI.*;

import javax.swing.*;
import java.awt.*;

public class DriverGUI {

  // private static JButton getJButton(String buttonTitle) {
  //
  //   JButton button;
  //
  //   button = new JButton(buttonTitle);
  //   return button
  // }

  public static void startGameGui() {

    JFrame gameWindow;
    Container gameContainer;
    GroupLayout gameLayout;
    JButton button;

    gameWindow = new JFrame("Swingy");
    gameWindow.setSize(640, 480);
    gameWindow.setLocationRelativeTo(null);
    gameWindow.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
    gameWindow.setResizable(false);
    gameWindow.setVisible(true);

    gameContainer = gameWindow.getContentPane();
    gameLayout = new GroupLayout(gameContainer);
    gameContainer.setLayout(gameLayout);

    button = new JButton("Click Me!");
    button.addActionListener((event) -> System.out.println());

    gameLayout.setAutoCreateContainerGaps(true);
    gameLayout.setHorizontalGroup(gameLayout.createSequentialGroup().addComponent(button));
  }
}
