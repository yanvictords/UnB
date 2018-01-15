package AdvancedWeatherApp;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.BoxLayout;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.event.ListSelectionListener;

import weatherforecast.FetchWeatherForecast;

public class MainFrame extends JFrame implements ListSelectionListener {

private boolean initialized = false;
private Actions actions = new Actions();

private javax.swing.JScrollPane jspFavouritesList = new javax.swing.JScrollPane();
private javax.swing.DefaultListModel<String> listModel = new javax.swing.DefaultListModel<String>();
private javax.swing.JList<String> favouritesList = new javax.swing.JList<String>(
        listModel);

private javax.swing.JLabel lblAcknowledgement = new javax.swing.JLabel();
private javax.swing.JLabel lblTitle = new javax.swing.JLabel();

private javax.swing.JButton btnAdd = new javax.swing.JButton();
private javax.swing.JButton btnRemove = new javax.swing.JButton();

public void initialize() {
    initializeGui();
    initializeEvents();
    this.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
}

/**
 * 
 */
private void initializeGui() {
    if (initialized)
        return;
    initialized = true;
    this.setSize(500, 400);

    Dimension windowSize = this.getSize();
    Dimension screenSize = Toolkit.getDefaultToolkit().getScreenSize();
    this.setLocation(screenSize.width / 2 - windowSize.width / 2,
            screenSize.height / 2 - windowSize.height / 2);
    Container pane = this.getContentPane();
    pane.setLayout(new BorderLayout());
    setLayout(new BorderLayout());
    setTitle("Favourite Weather Locations");

    JPanel jpSouth = new JPanel();
    jpSouth.setLayout(new FlowLayout());

    JPanel jpNorth = new JPanel();
    jpNorth.setLayout(new FlowLayout());

    JPanel jpCenter = new JPanel();
    jpCenter.setLayout(new BoxLayout(jpCenter, BoxLayout.PAGE_AXIS));

    JPanel jpEast = new JPanel();
    JPanel jpWest = new JPanel();

    getContentPane().setBackground(Color.WHITE);
    jpEast.setBackground(Color.WHITE);
    jpWest.setBackground(Color.WHITE);
    jpCenter.setBackground(Color.WHITE);

    getContentPane().add(jspFavouritesList);
    jpCenter.add(jspFavouritesList);
    jspFavouritesList.setViewportView(favouritesList);
    favouritesList
            .setSelectionMode(javax.swing.ListSelectionModel.SINGLE_SELECTION);
    favouritesList.addListSelectionListener(this);

    jpCenter.add(btnAdd);
    jpCenter.add(btnRemove);
    jpCenter.setAlignmentY(CENTER_ALIGNMENT);
    btnAdd.setText("Add Location");
    btnAdd.setAlignmentX(Component.CENTER_ALIGNMENT);
    btnAdd.setFont(new Font("Calibri", Font.PLAIN, 18));

    jpCenter.add(btnRemove);
    btnRemove.setText("Remove Location");
    btnRemove.setAlignmentX(Component.CENTER_ALIGNMENT);
    btnRemove.setFont(new Font("Calibri", Font.PLAIN, 18));

    getContentPane().add(jpEast, BorderLayout.EAST);
    getContentPane().add(jpWest, BorderLayout.WEST);

    getContentPane().add(jpSouth);
    jpSouth.add(lblAcknowledgement);
    add(lblAcknowledgement, BorderLayout.SOUTH);
    lblAcknowledgement.setText(FetchWeatherForecast.getAcknowledgement());
    lblAcknowledgement.setHorizontalAlignment(SwingConstants.CENTER);
    lblAcknowledgement.setFont(new Font("Tahoma", Font.ITALIC, 12));

    getContentPane().add(jpNorth);
    jpNorth.add(lblTitle);
    add(lblTitle, BorderLayout.NORTH);
    lblTitle.setText("Your Favourite Locations");
    lblTitle.setHorizontalAlignment(SwingConstants.CENTER);
    lblTitle.setFont(new Font("Calibri", Font.PLAIN, 32));
    lblTitle.setForeground(Color.DARK_GRAY);

    getContentPane().add(jpCenter);

}

private void initializeEvents() {
    // TODO: Add action listeners, etc
}

public class Actions implements ActionListener {
    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();
        command = command == null ? "" : command;
        // TODO: add if...if else... for action commands

    }
}

public void dispose() {
    // TODO: Save settings
    // super.dispose();
    System.exit(0);
}

public void setVisible(boolean b) {
    initialize();
    super.setVisible(b);
}

public static void main(String[] args) {

    new MainFrame().setVisible(true);
}

public void actionPerformed(ActionEvent evt){

    if (evt.getSource() == btnAdd) {
        showNewFrame();
        //OPEN THE SEARCH WINDOW    

        }

    }

private void showNewFrame() {
    JFrame frame = new JFrame("Search Window" );
    frame.setSize( 500,120 );
    frame.setLocationRelativeTo( null );
    frame.setVisible( true );   

}
}