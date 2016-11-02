 import beetleMechanics.*;
import java.util.*;
import java.awt.*;
import javax.swing.*;


/** A Robot Beetle.  This version is adapted from an earlier one, to work
 * better in BlueJay.  It can turn through any amount.
 * 
 * originally Ann Robertson
 * @author Lynda Thomas
 * @version 6/11
 */

public class BJBeetle 
{    
    static BJBeetleCanvas canvas; // a reference to the canvas where the track is displayed
                                                          
    private BJModel model;        //the model (a place to hold the data about this Beetle)
        
    /** 
     * Sets the starting position to mid-screen facing up with the pen down.
     * Creates an instance of BJBeetleCanvas and updates the model to start
     * This then updates the screen
     */

    public BJBeetle()
    {       
        // Create a single canvas of the required size. 
        canvas =  BJBeetleCanvas.getCanvas(); 
        // Set the position etc
        int xPos = (canvas.getPreferredSize().width)/2; 
        int yPos = (canvas.getPreferredSize().height)/2;  
        //update model
        BJBeetlePosn position=new BJBeetlePosn(xPos,yPos,0,false,Color.black);
        model=new BJModel();
        canvas.addBeetle(model);
        model.addObserver(canvas);
        model.update(position);
    }
    
      
    /**
     * Positions the beetle anywhere on the screen with new information
     * (lifts pen to do so, then puts pen into correct setting - so this is actually 2 moves)
     * @param theXPos The distance from the left edge of the beetle's space.
     * @param theYPos The distance from the top of the beetle's space.
     * @param theDirection an angle clockwise from 0 at true north
     * @param penUp whether pen ends up up or down
    */
    public void position(int theXPos, int theYPos, int degrees, boolean penUp )
    {
        Color current=model.getColor();
        BJBeetlePosn position=new BJBeetlePosn(theXPos, theYPos, degrees, true, current);
        model.update(position);
        BJBeetlePosn nextPosition=new BJBeetlePosn(theXPos, theYPos, degrees, penUp, current);
        model.update(nextPosition);
    }
    
        
    /**
      * Sets the penUp attribute
      * @param up If the value is true the pen will be up and will not draw.
      *           If the value is false the pen will go down and will draw.
      */
    public void setPenUp(boolean up)
    {
        model.setPen(up);
    }
    
    /**
     * Sets the colour of the Beetle track and centre spot from a chooser
     * 
     */
   public void setColour() { 
       JColorChooser chooser=new JColorChooser();
       // Just this should have worked to remove preview but apparently a Java bug
       //chooser.setPreviewPanel(null);
       model.setColor(chooser.showDialog(null,"Choose Color",Color.black));
        }
 
       /**
     * Sets the colour of the Beetle track and centre 
     * @param colour new color - in form java.awt.Color.red  no quotes
     */
   public void setColour(Color colour) {
         model.setColor(colour);
       }
 
    /**
      * Calculates the new position reached by moving forward
      * @param distance is the distance to move (remember there is a direction)
      */
    public void moveForward(int distance)
    {
            model.moveForward(distance);
    }
    
     /**
      * Calculates the new position reached by moving backward
      * @param distance is the distance to move (remember there is a direction)
      */
    public void moveBackward(int distance)
    {
        moveForward(-distance);
    }

    /**
      * Changes the direction attribute - a number added to current direction (clockwise)
      * @param updateDegrees amount to add to current direction
      */
    public void turn(int updateDegrees)
    {
        model.turn(updateDegrees);
     }

   
     /**
     * removes the last move 
     */
    public void oops() {
        model.oops();
    }
        
         
     /**
     * clears this beetle's path and sets to start
     */
    public void reset()
    {
        int xPos = (canvas.getPreferredSize().width)/2; 
        int yPos = (canvas.getPreferredSize().height)/2;  
        BJBeetlePosn position=new BJBeetlePosn(xPos,yPos,0,false,Color.black);
        model.reset(position);
    }
    
}

