package za.co.wethinkcode.swingy.views.GUI;

import javax.swing.*;

public class GamePanels {

  public static JPanel getStartGamePanel() {

    JButton createHeroButton = new JButton("Create Hero");
    JButton loadHeroButton = new JButton("Load Hero");

    JPanel panel = new JPanel();

    GroupLayout layout = new GroupLayout(panel);
    panel.setLayout(layout);

    layout.setAutoCreateGaps(true);
    layout.setAutoCreateContainerGaps(true);

    layout.setHorizontalGroup(
        layout.createSequentialGroup()
        .addComponent(createHeroButton)
        .addComponent(loadHeroButton)
    );

    layout.setVerticalGroup(
        layout.createSequentialGroup()
        .addGroup(
            layout.createParallelGroup(GroupLayout.Alignment.BASELINE)
            .addComponent(createHeroButton)
            .addComponent(loadHeroButton)
        )
    );

    return panel;
  }
}
