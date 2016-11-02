import javax.swing.*;
import java.awt.event.*;
/**
 * This class produces a very simple way to get text into your program
 */

public class InputGetter extends JFrame{
    private String str; //the text
  /**
   * constructor for class InputGetter default string loaded
   */
  public InputGetter() {
      str="no input yet";
    }
    
   /**
   * brings up a window you can use to get data into the object
   */
  public void getInputFromUser() {
      str=JOptionPane.showInputDialog("Enter Input:");
    }

    /**
   * brings up a window with message you can use to get data into the object
   */
  public void getInputFromUser(String message) {
      str=JOptionPane.showInputDialog(message);
    }
      
  /**
   * returns input as a String 
   */
  public String getCurrentValue(){
      //JOptionPane.showMessageDialog(null,"Current value of text : " + str);
      return str;
  }
  
  /**
   * returns input as an array of characters
  
   public char[] getCurrentValueAsArray(){
      //JOptionPane.showMessageDialog(null,"Current value of text : " + str);
      byte[] value=str.getBytes();
      char valueReturned[]=new char[value.length];
      for (int i=0;i<value.length;i++)
        valueReturned[i]=(char)value[i];
      return valueReturned;
  }
   */
 } 
