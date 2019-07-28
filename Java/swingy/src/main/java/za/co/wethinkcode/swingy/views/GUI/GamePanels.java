package za.co.wethinkcode.swingy.views.GUI;

import za.co.wethinkcode.swingy.helpers.DbHelper;
import za.co.wethinkcode.swingy.helpers.DisplayFormatter;
import za.co.wethinkcode.swingy.helpers.GuiHelpers;
import za.co.wethinkcode.swingy.helpers.InputHelper;
import za.co.wethinkcode.swingy.models.Hero;

import javax.swing.*;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.PrintWriter;
import java.io.StringWriter;
import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.HashMap;
import java.util.concurrent.BlockingQueue;

public class GamePanels {

  private static ActionListener getGameButton(
    final BlockingQueue<String> guiInputQueue,
    final String buttonChar
  ) {

    return new ActionListener() {

      @Override
      public void actionPerformed(ActionEvent e) {

        // This will let the main thread update game state.
        if (guiInputQueue.size() == 0) {

          guiInputQueue.add(buttonChar);
        }
      }
    };
  }

  private static void mapHeroStatsToLabels(JLabel[] heroStats, Hero hero) {

    heroStats[0].setText(hero.getHeroName());
    heroStats[1].setText(DisplayFormatter.formatHeroLevel(hero.getHeroLevel()));
    heroStats[2].setText(DisplayFormatter.formatHeroExperience(hero.getHeroExperience()));
    heroStats[3].setText(DisplayFormatter.formatHeroHitPoints(hero.getHeroHitPoints()));
    heroStats[4].setText(DisplayFormatter.formatHeroAttack(hero.getHeroAttack()));
    heroStats[5].setText(DisplayFormatter.formatHeroDefence(hero.getHeroDefence()));
    heroStats[6].setText(DisplayFormatter.formatHeroWeapon(hero.getHeroWeapon()));
    heroStats[7].setText(DisplayFormatter.formatHeroArmor(hero.getHeroArmor()));
    heroStats[8].setText(DisplayFormatter.formatHeroHelm(hero.getHeroHelm()));
  }

  public static JPanel getStartGamePanel(
    final BlockingQueue<String> blockingQueue
  ) {

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

  public static JPanel getCreateHeroPanel(
    final Connection connection,
    final BlockingQueue<String> blockingQueue
  ) {

    JButton orcButton = new JButton("Orc");
    JButton barbarianButton = new JButton("Barbarian");
    JButton assassinButton = new JButton("Assassin");

    JLabel enterHeroName = new JLabel("Hero name:");
    JLabel pickHeroClass = new JLabel("Hero class:");

    final JTextField heroNameField = new JTextField();

    orcButton.addActionListener(
        new ActionListener() {

          @Override
          public void actionPerformed(ActionEvent e) {

            if (blockingQueue.size() == 0) {

              Boolean isHeroNameIllegal = InputHelper.hasIllegalChars(heroNameField.getText());
              Boolean doesTheHeroExist = false;

              try {

                doesTheHeroExist = DbHelper.doesHeroExist(connection, heroNameField.getText());
              }
              catch (SQLException ex) {

                if (blockingQueue.size() == 0) {

                  StringWriter sw = new StringWriter();
                  PrintWriter pw = new PrintWriter(sw);
                  ex.printStackTrace(pw);
                  String eStackTrace = sw.toString();

                  blockingQueue.add("Exception");
                  blockingQueue.add(eStackTrace);
                }

                return;
              }

              if (
                isHeroNameIllegal ||
                doesTheHeroExist
              ) {

                JOptionPane.showMessageDialog(
                  null,
                  "Invalid hero name, or the hero might exist. Enter again.",
                  "Input Error",
                  JOptionPane.ERROR_MESSAGE
                );

                return;
              }

              blockingQueue.add(heroNameField.getText());
              blockingQueue.add("O");
            }
          }
        }
    );

    barbarianButton.addActionListener(
        new ActionListener() {

          @Override
          public void actionPerformed(ActionEvent e) {

            if (blockingQueue.size() == 0) {

              Boolean isHeroNameIllegal = InputHelper.hasIllegalChars(heroNameField.getText());
              Boolean doesTheHeroExist = false;

              try {

                doesTheHeroExist = DbHelper.doesHeroExist(connection, heroNameField.getText());
              }
              catch (SQLException ex) {

                if (blockingQueue.size() == 0) {

                  StringWriter sw = new StringWriter();
                  PrintWriter pw = new PrintWriter(sw);
                  ex.printStackTrace(pw);
                  String eStackTrace = sw.toString();

                  blockingQueue.add("Exception");
                  blockingQueue.add(eStackTrace);
                }

                return;
              }

              if (
                isHeroNameIllegal ||
                doesTheHeroExist
              ) {

                JOptionPane.showMessageDialog(
                  null,
                  "Invalid hero name, or the hero might exist. Enter again.",
                  "Input Error",
                  JOptionPane.ERROR_MESSAGE
                );

                return;
              }

              blockingQueue.add(heroNameField.getText());
              blockingQueue.add("B");
            }
          }
        }
    );

    assassinButton.addActionListener(
        new ActionListener() {

          @Override
          public void actionPerformed(ActionEvent e) {

            if (blockingQueue.size() == 0) {

              Boolean isHeroNameIllegal = InputHelper.hasIllegalChars(heroNameField.getText());
              Boolean doesTheHeroExist = false;

              try {

                doesTheHeroExist = DbHelper.doesHeroExist(connection, heroNameField.getText());
              }
              catch (SQLException ex) {

                if (blockingQueue.size() == 0) {

                  StringWriter sw = new StringWriter();
                  PrintWriter pw = new PrintWriter(sw);
                  ex.printStackTrace(pw);
                  String eStackTrace = sw.toString();

                  blockingQueue.add("Exception");
                  blockingQueue.add(eStackTrace);
                }

                return;
              }

              if (
                isHeroNameIllegal ||
                doesTheHeroExist
              ) {

                JOptionPane.showMessageDialog(
                  null,
                  "Invalid hero name, or the hero might exist. Enter again.",
                  "Input Error",
                  JOptionPane.ERROR_MESSAGE
                );

                return;
              }

              blockingQueue.add(heroNameField.getText());
              blockingQueue.add("A");
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
        .addGroup(layout.createParallelGroup()
            .addComponent(enterHeroName)
            .addComponent(pickHeroClass)
            .addComponent(orcButton)
        )
        .addGroup(layout.createParallelGroup()
            .addComponent(heroNameField)
            .addComponent(barbarianButton)
        )
        .addComponent(assassinButton)
    );

    layout.setVerticalGroup(
        layout.createSequentialGroup()
        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.BASELINE)
            .addComponent(enterHeroName)
            .addComponent(heroNameField)
        )
        .addComponent(pickHeroClass)
        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.BASELINE)
            .addComponent(orcButton)
            .addComponent(barbarianButton)
            .addComponent(assassinButton)
        )
    );

    return panel;
  }

  public static JPanel getLoadHeroPanel(
    final Connection connection,
    final BlockingQueue<String> blockingQueue
  ) throws SQLException {

    String[] heroNames = GuiHelpers.getHeroNameArray(DbHelper.getHeroes(connection));
    final HashMap<String, Hero> heroDictionary = GuiHelpers.getHeroDictionary(DbHelper.getHeroes(connection));

    JScrollPane scrollPane = new JScrollPane();
    scrollPane.setMinimumSize(new Dimension(200, 1));
    final JList<String> heroNameList = new JList<>(heroNames);

    scrollPane.setViewportView(heroNameList);

    heroNameList.setSelectedIndex(0);
    final JLabel[] heroStats = new JLabel[9];

    // Initializing heroStats labels.
    for (int i = 0; i < heroStats.length; i++) {

      heroStats[i] = new JLabel();
    }

    mapHeroStatsToLabels(heroStats, heroDictionary.get(heroNames[0]));

    // JList listener
    heroNameList.addListSelectionListener(new ListSelectionListener() {
      @Override
      public void valueChanged(ListSelectionEvent e) {
        String selectedHeroName = heroNameList.getSelectedValue();
        mapHeroStatsToLabels(heroStats, heroDictionary.get(selectedHeroName));
      }
    });

    JButton loadHeroButton = new JButton("Load Hero");

    loadHeroButton.addActionListener(new ActionListener() {
      @Override
      public void actionPerformed(ActionEvent e) {

        // System.out.println(heroNameList.getSelectedValue());
        blockingQueue.add(heroNameList.getSelectedValue());
      }
    });

    // Panel for hero stats / labels.
    JPanel heroStatsPanel = new JPanel();
    heroStatsPanel.setMinimumSize(new Dimension(200, 1));
    GroupLayout statsLayout = new GroupLayout(heroStatsPanel);
    heroStatsPanel.setLayout(statsLayout);

    statsLayout.setAutoCreateGaps(true);
    statsLayout.setAutoCreateContainerGaps(true);

    statsLayout.setHorizontalGroup(
      statsLayout.createSequentialGroup()
      .addGroup(
        statsLayout.createParallelGroup()
        .addComponent(heroStats[0])
        .addComponent(heroStats[1])
        .addComponent(heroStats[2])
        .addComponent(heroStats[3])
        .addComponent(heroStats[4])
        .addComponent(heroStats[5])
        .addComponent(heroStats[6])
        .addComponent(heroStats[7])
        .addComponent(heroStats[8])
      )
    );

    statsLayout.setVerticalGroup(
      statsLayout.createSequentialGroup()
        .addComponent(heroStats[0])
        .addComponent(heroStats[1])
        .addComponent(heroStats[2])
        .addComponent(heroStats[3])
        .addComponent(heroStats[4])
        .addComponent(heroStats[5])
        .addComponent(heroStats[6])
        .addComponent(heroStats[7])
        .addComponent(heroStats[8])
    );

    // Final panel
    JPanel panel = new JPanel();

    GroupLayout layout = new GroupLayout(panel);
    panel.setLayout(layout);

    layout.setAutoCreateGaps(true);
    layout.setAutoCreateContainerGaps(true);

    layout.setHorizontalGroup(
        layout.createSequentialGroup()
        .addComponent(scrollPane)
        .addGroup(layout.createParallelGroup()
            .addComponent(heroStatsPanel)
            .addComponent(loadHeroButton)
        )
    );

    layout.setVerticalGroup(
        layout.createSequentialGroup()
        .addGroup(layout.createParallelGroup(GroupLayout.Alignment.BASELINE)
            .addComponent(scrollPane)
            .addComponent(heroStatsPanel)
        )
        .addComponent(loadHeroButton)
    );

    return panel;
  }

  public static JPanel getGamePlayPanel(
    final BlockingQueue<String> guiInputQueue,
    final String gameStateInitial,
    final JLabel[] mainGameStateLabels
  ) {

    JLabel[] gameStateLabelInfo = new JLabel[5];

    // Initializing labels.
    for (int i = 0; i < gameStateLabelInfo.length; i++) {

      gameStateLabelInfo[i] = new JLabel();
    }

    for (int j = 0; j < gameStateLabelInfo.length; j++) {

      mainGameStateLabels[j] = gameStateLabelInfo[j];
    }

    // assignGameStateLabels(gameStateLabelInfo, gameStateInitial);
    GuiHelpers.assignGameStateLabels(gameStateLabelInfo, gameStateInitial);

    JButton northButton = new JButton("North");
    JButton eastButton = new JButton("East");
    JButton southButton = new JButton("South");
    JButton westButton = new JButton("West");

    northButton.addActionListener(getGameButton(guiInputQueue, "w"));
    eastButton.addActionListener(getGameButton(guiInputQueue, "d"));
    southButton.addActionListener(getGameButton(guiInputQueue, "s"));
    westButton.addActionListener(getGameButton(guiInputQueue, "a"));

    JPanel gameStatePanel = new JPanel();

    GroupLayout gameStateLayout = new GroupLayout(gameStatePanel);
    gameStatePanel.setLayout(gameStateLayout);

    gameStateLayout.setHorizontalGroup(
        gameStateLayout.createSequentialGroup()
        .addGroup(
            gameStateLayout.createParallelGroup(GroupLayout.Alignment.CENTER)
            .addComponent(gameStateLabelInfo[0])
            .addComponent(gameStateLabelInfo[1])
            .addComponent(gameStateLabelInfo[2])
            .addComponent(gameStateLabelInfo[3])
            .addComponent(gameStateLabelInfo[4])
        )
    );

    gameStateLayout.setVerticalGroup(
        gameStateLayout.createSequentialGroup()
            .addComponent(gameStateLabelInfo[0])
            .addComponent(gameStateLabelInfo[1])
            .addComponent(gameStateLabelInfo[2])
            .addComponent(gameStateLabelInfo[3])
            .addComponent(gameStateLabelInfo[4])
    );

    JPanel buttonPanel = new JPanel();

    GroupLayout buttonLayout = new GroupLayout(buttonPanel);
    buttonPanel.setLayout(buttonLayout);

    buttonLayout.setHorizontalGroup(
        buttonLayout.createSequentialGroup()
        .addComponent(westButton)
        .addGroup(
            buttonLayout.createParallelGroup()
            .addComponent(northButton)
            .addComponent(southButton)
        )
        .addComponent(eastButton)
    );

    buttonLayout.setVerticalGroup(
        buttonLayout.createSequentialGroup()
        .addComponent(northButton)
        .addGroup(
            buttonLayout.createParallelGroup(GroupLayout.Alignment.BASELINE)
            .addComponent(westButton)
            .addComponent(eastButton)
        )
        .addComponent(southButton)
    );

    JPanel panel = new JPanel();

    GroupLayout layout = new GroupLayout(panel);
    panel.setLayout(layout);

    layout.setAutoCreateGaps(true);
    layout.setAutoCreateContainerGaps(true);

    layout.setHorizontalGroup(
        layout.createSequentialGroup()
        .addGroup(
            layout.createParallelGroup(GroupLayout.Alignment.CENTER)
            .addComponent(gameStatePanel)
            .addComponent(buttonPanel)
        )
    );

    layout.setVerticalGroup(
        layout.createSequentialGroup()
        .addComponent(gameStatePanel)
        .addComponent(buttonPanel)
    );

    return panel;
  }
}
