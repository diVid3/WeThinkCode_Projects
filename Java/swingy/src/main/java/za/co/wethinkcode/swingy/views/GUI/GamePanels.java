package za.co.wethinkcode.swingy.views.GUI;

import javax.swing.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.concurrent.BlockingQueue;

public class GamePanels {

  // TODO: Pass in required fields for create the actionListeners.
  public static JPanel getStartGamePanel(final BlockingQueue<String> blockingQueue) {

    JButton createHeroButton = new JButton("Create Hero");
    JButton loadHeroButton = new JButton("Load Hero");

    createHeroButton.addActionListener(
        new ActionListener() {

          @Override
          public void actionPerformed(ActionEvent e) {

            if (blockingQueue.size() == 0) {

              blockingQueue.add("N");
            }
          }
        }
    );

    loadHeroButton.addActionListener(
        new ActionListener() {

          @Override
          public void actionPerformed(ActionEvent e) {

            if (blockingQueue.size() == 0) {

              blockingQueue.add("L");
            }
          }
        }
    );

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
