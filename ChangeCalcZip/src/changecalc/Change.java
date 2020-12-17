/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package changecalc;

/**
 *
 * @author camdenbarta
 */
public class Change {
    private double amPurchased;
    private double amPaid;
    
    public Change(double amPurchased, double amPaid){
        this.amPurchased = amPurchased;
        this.amPaid = amPaid;
    }
    
    public int getBill20(){
        if ((amPaid-amPurchased)<20)
            return 0;
        return (int)((amPaid - amPurchased) / 20);
    }
    public int getBill10(){
        double left = amPaid - amPurchased - 20*getBill20();
        if ((left)<10)
            return 0;
        return (int)(left / 10);
    }
    public int getBill5(){
        double left = (amPaid - amPurchased) - 20*getBill20() - 10*getBill10();
        if ((left)<5)
            return 0;
        return (int)(left / 5);
    }
    public int getBill1(){
        double left = (amPaid - amPurchased) - 20*getBill20() - 10*getBill10() -5*getBill5();
        if ((left)<1)
            return 0;
        return (int)(left / 1);
    }
    public int getCents(){
        double left = ((amPaid - amPurchased) - 20*getBill20() - 10*getBill10() - 5*getBill5()- 1*getBill1())*100;
        if ((left)<.01)
            return 0;
        return (int)(left);
    }
}
