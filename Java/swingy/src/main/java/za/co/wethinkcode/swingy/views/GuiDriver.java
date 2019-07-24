package za.co.wethinkcode.swingy.views;

import javax.swing.*;

public class GuiDriver {

  private JFrame frame;

  // public void startGameGui() {
  //
  //   JFrame jFrame;
  //   JPanel jPanel;
  //   GroupLayout layout;
  //   JButton button1;
  //   JButton button2;
  //
  //   jFrame = new JFrame("Swingy");
  //
  //   jFrame.setSize(640, 480);
  //   jFrame.setLocationRelativeTo(null);
  //   jFrame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
  //   jFrame.setResizable(false);
  //
  //   jPanel = new JPanel();
  //   layout = new GroupLayout(jPanel);
  //
  //   jPanel.setLayout(layout);
  //
  //   jFrame.setVisible(true);
  // }

  public GuiDriver() {

    this.frame = new JFrame("Swingy");

    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setLocationRelativeTo(null);
    frame.setSize(640, 480);
    frame.setResizable(false);
  }

  public void refreshWindow(JPanel panel) {

    this.frame.setContentPane(panel);
    this.frame.pack();
    this.frame.revalidate();
    this.frame.repaint();

    if (!this.frame.isVisible()) {

      this.frame.setVisible(true);
    }
  }
}
