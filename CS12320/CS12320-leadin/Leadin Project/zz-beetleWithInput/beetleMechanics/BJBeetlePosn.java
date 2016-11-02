package beetleMechanics;

import java.awt.*;
/**
  * A class to hold the details of a beetle's position and direction
  * at any particular moment. Also whether the pen is up.
  * Part of BJBeetle.
  *@author Ann Robertson
  *@version October 2000
  */

public class BJBeetlePosn
{
    private int x, y;
    private int d;
    private boolean up;
    private Color colour;

    /**
      * Accepts all the details about one position of a beetle.
      *@param theX  The x coordinate, i.e the distance in pixels
      *from the left hand edge of the window.
      *@param theY  The y coordinate, i.e the distance in pixels
      *from the top of the drawing area. (American coordinate system);
      *@param theD  The direction the beetle is facing: one of "North",
      *"South","East" or "West".
      *@param theUp  Whether the pen is up or not.  Beetle only draws if
      *the pen is down
      */
    public BJBeetlePosn(int theX, int theY, int theD, boolean theUp, Color c)
    {
        x = theX;
        y = theY;
        d = theD;
        up = theUp;
        colour=c;
    }
    
     public BJBeetlePosn(BJBeetlePosn old)
    {
        x = old.x;
        y = old.y;
        d = old.d;
        up = old.up;
        colour=old.colour;
    }
    
    /**
    *@return  the x coordinate in pixels
    */  
    public int getX()
    {
        return x;
    }
    
    /**
    *@return  the y coordinate in pixels
    */    
    public int getY()
    {
        return y;
    }
    
    /**
    *@return  A string representing the direction the beetle is facing.
    */  
    public int getDirection()
    {
        return d;
    }
    
 
    /**
     * @return color
     */
    public Color getColor() {
        return colour;
    }
    
    /**
    *@return Whether the pen is up.
    */
    public boolean getPenUp()
    {
        return up;
    }
    
    /**
     * sets penUp
     */
    public void setPen(boolean value) {
        up=value;
    }
    
    /**
     * sets penUp
     */
    public void setColor(Color c) {
        colour=c;
    }
    
    /**
     * adds a distance 
     */
    public void add(int distance) {
        if (d>=0 && d <=90) {
                //sine(90-d)=updatey/distance
                double radians=(90-d)*Math.PI/180;
                int updateY=(int) (distance*Math.sin(radians));
                y-=updateY;
                int updateX=(int) (distance*Math.cos(radians));
                x+=updateX;
            }
            else   if (d>90 && d <=180) {
                
                double radians=(d-90)*Math.PI/180;
                int updateY=(int) (distance*Math.sin(radians));
                y+=updateY;
                int updateX=(int) (distance*Math.cos(radians));
                x+=updateX;
            }
            else   if (d>180 && d <=270) {
                
                double radians=(270-d)*Math.PI/180;
                int updateY=(int) (distance*Math.sin(radians));
                y+=updateY;
                int updateX=(int) (distance*Math.cos(radians));
                x-=updateX;
            }
            else {
                double radians=(d-270)*Math.PI/180;
                int updateY=(int) (distance*Math.sin(radians));
                y-=updateY;
                int updateX=(int) (distance*Math.cos(radians));
                x-=updateX;
            }
        }
        
     /**
     * turns an updateDegrees number of degrees
     */
    public void turn(int updateDegrees) {
        while (updateDegrees<0) updateDegrees+=360;
        d=  ( d+updateDegrees)%360;
    }
}
