package beetleMechanics;

import java.util.*;
import java.util.concurrent.*; //note this deals with occasional concurrentmodifications
import java.awt.Color;
/**
 * This class was added when it became obvious we needed more than one Beetle.
 * It models the data about the detail, basically where it is now and where it has
 * been as a list of points
 * 
 * @author Lynda Thomas 
 * @version 6/2011
 */
public class BJModel extends Observable
{
    private BJBeetlePosn currentPosition;       //where the beetle is
        private ArrayList<BJBeetlePosn> track;    //List of points for this Beetle
    
    /**
     * Constructor for objects of class BJModel
     * 
     */
    public BJModel()
    {
        track=new ArrayList<BJBeetlePosn>();
    }

    /**
     * updates whenever BJBeetle changes its position
     * @param pos new position
     */
    public void update(BJBeetlePosn pos)
    {
        currentPosition = pos;
        track.add(pos);
        setChanged();
        notifyObservers();
    }

        
    /**
     * resets BJBeetle to a position
     */
    public void reset(BJBeetlePosn pos)
    {
        track=new ArrayList<BJBeetlePosn>();
        currentPosition = pos;
        track.add(pos);
        setChanged();
        notifyObservers();
    }
    
    /**
     * updates  the pen - adds as new point 
     */
    public void setPen(boolean value) {
        int last=track.size()-1;
        BJBeetlePosn lastOne=track.get(last);
        BJBeetlePosn newOne=new BJBeetlePosn(lastOne);
        newOne.setPen(value);
        track.add(newOne);
        currentPosition=newOne;
        setChanged();
        notifyObservers();   
    }
    
    /**
     * updates the colour  - adds as new point
     */
    public void setColor(Color c) {
        int last=track.size()-1;
        BJBeetlePosn lastOne=track.get(last);
        BJBeetlePosn newOne=new BJBeetlePosn(lastOne);
        newOne.setColor(c);
        track.add(newOne);
        currentPosition=newOne;
        setChanged();
        notifyObservers();   
    }
    
    /**
     * moves forward distance - adds new position to the track
     * @param distance amount to move
     */
    public void moveForward(int distance) {
        int last=track.size()-1;
        BJBeetlePosn lastOne=track.get(last);
        BJBeetlePosn newOne=new BJBeetlePosn(lastOne);
        newOne.add(distance);
        track.add(newOne);
        currentPosition=newOne;
        setChanged();
        notifyObservers();  
    }

    /**
     * turns by number of degrees - adds new position to the track
     */
    public void turn(int updateDegrees) {
        int last=track.size()-1;
        BJBeetlePosn lastOne=track.get(last);
        BJBeetlePosn newOne=new BJBeetlePosn(lastOne);
        newOne.turn(updateDegrees);
        track.add(newOne);
        currentPosition=newOne;
        setChanged();
        notifyObservers(); 
    }
    
    /**
     * remove last thing in track and update currrent position (restores one before)
     */
    public void oops()  {
            int lastOne=track.size()-1;
            if (lastOne!=0){              
                track.remove(lastOne);
                lastOne=track.size()-1;
                currentPosition=track.get(lastOne);
                setChanged();
                notifyObservers(); 
            }
            else
                System.out.println("cannot oops past the beginning");
                  
        }
    
    /**
     * return the track for this Beetle
     */
    public ArrayList<BJBeetlePosn> getTrack()
    {
        return track;
    }
    
    /**
     * returns the colour
     */
    public Color getColor() {
        return currentPosition.getColor();
    }
    
    /**
     * return the position for  this Beetle
     */
     public BJBeetlePosn getPosition(){
         return currentPosition;
     }
     
    
}
