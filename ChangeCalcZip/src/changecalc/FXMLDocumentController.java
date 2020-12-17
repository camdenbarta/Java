/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package changecalc;

import java.net.URL;
import java.util.ResourceBundle;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.Initializable;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.TextField;

/**
 *
 * @author camdenbarta
 */
public class FXMLDocumentController implements Initializable {
    
    @FXML
    private TextField tbPurchased;
    @FXML
    private TextField tbPaid;
    @FXML
    private TextField tb20;
    @FXML
    private Label amPurchased;
    @FXML
    private Label amPaid;
    @FXML
    private Button calc;
    @FXML
    private Button reset;
    @FXML
    private Label bill20;
    @FXML
    private TextField tb10;
    @FXML
    private TextField tb5;
    @FXML
    private Label bill10;
    @FXML
    private Label bill5;
    @FXML
    private Label bill1;
    @FXML
    private TextField tb1;
    @FXML
    private TextField tbCents;
    @FXML
    private Label cents;
    private Change change;
    
    private void handleButtonAction(ActionEvent event) {
        
    }
    
    @Override
    public void initialize(URL url, ResourceBundle rb) {
        // TODO
    }    
    public void validateData(){
        try{
            float amPurchased = Float.parseFloat(tbPurchased.getText());
            float amPaid = Float.parseFloat(tbPaid.getText());
            change = new Change(amPurchased, amPaid);
        }
        catch(NumberFormatException e){
            System.out.println("Only numbers are allowed");
        }
    }
    @FXML
    private void calc(ActionEvent event) {
        validateData();
        int bill20 = change.getBill20();
        int bill10 = change.getBill10();
        int bill5 = change.getBill5();
        int bill1 = change.getBill1();
        int cent = change.getCents();
        tb20.setText(""+bill20);
        tb10.setText(""+bill10);
        tb5.setText(""+bill5);
        tb1.setText(""+bill1);
        tbCents.setText(""+cent);
    }

    @FXML
    private void reset(ActionEvent event){
        tbPurchased.setText("");
        tbPaid.setText("");
        tb20.setText("");
        tb10.setText("");
        tb5.setText("");
        tb1.setText("");
        tbCents.setText("");
    }
    
}
