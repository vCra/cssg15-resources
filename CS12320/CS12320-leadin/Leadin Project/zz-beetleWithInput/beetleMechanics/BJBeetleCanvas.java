package beetleMechanics;

import java.awt.*;
import java.util.*;
import java.util.concurrent.*;  //note this deals with occasional concurrentmodifications
import javax.swing.*;
import java.awt.event.*;
  /** This class creates an ArrayList of Beetles and keeps them up to date
    * Adapted from the original BeetleCanvas so as to make the beetle work in BlueJay
    * Then readapted for multiple Beetles and any turn and MVC
    * 
    *Originally author Ann Robertson    *@version 31/8/07 
    *@author Lynda Thomas
    *@version 6/11 
    */

public class BJBeetleCanvas implements Observer
{
        public static final int SCREEN_SIZE_X = 500;    
        public static final int SCREEN_SIZE_Y = 500; 
        private Dimension canvasSize;    //Overall size of the drawing surface. 
        
        private static BJBeetleCanvas theCanvas;
        private BJBeetleFrame beetleFrame;        //Frame to display the canvas
        private CanvasPanel panel;
        
        private ArrayList<BJModel> allBeetles;  //all Beetles to be drawn and their tracks
        
       /**
         * Method to create and get a single canvas object
         */
        public static BJBeetleCanvas getCanvas()
        {
           if (theCanvas == null)  {
               theCanvas = new BJBeetleCanvas(SCREEN_SIZE_X, SCREEN_SIZE_Y);
           }
           return theCanvas;
        }     
    
        /**
         * Constructor is private, to ensure only one is created
         */  
        private BJBeetleCanvas(int theWidth, int theHeight)
        {
            super();
            allBeetles = new ArrayList<BJModel>();
            canvasSize = new Dimension(theWidth, theHeight);
            panel = new CanvasPanel();
            panel.setMinimumSize( canvasSize );          
            beetleFrame = new BJBeetleFrame( this );
        }
    

        /**
         * add this beetle as one you are using
         */
        public void addBeetle(BJModel mod) {
            allBeetles.add(mod);
        }
        

        /**
         * Clear the screen and the track if we need to start again.
         * 
         */
        public void clear()
        {
            allBeetles.clear();
            panel.repaint();
        }
            
            
        /**
          * Returns the preferred size in terms of the screen size given by
          * the Beetle class.  Needed by the layout manager.
          */ 
        public Dimension getPreferredSize ()
        {
            return canvasSize; 
        }

        /**
          * Returns the beetles
          */ 
        public ArrayList<BJModel> getBeetles ()
        {
            return allBeetles; 
        }
       
        /**
          * Allows the title to be set by the Beetle
          */
        public void setTitle(String theTitle)
        {
            beetleFrame.setTitle(theTitle);
        }
        
          /**
         * update needed by MVC - there has been a change so redraw
         */
        public void update(Observable aBeetle, Object blank){          
            panel.repaint();  //draws all bettles but this one has been updated           
        }

             
        /**
          * Draw the track if the pen is down.
          * @param g The Graphics context.
          */
        private void drawAllTracks(Graphics g, JPanel pan)
        {
            //for all Beetles
           for (BJModel m:allBeetles) {
               BJBeetlePosn p0 = null;   //  temporary var to hold previous posn 
               ArrayList<BJBeetlePosn> track=m.getTrack();
               //for all points on this beetles track
               for(BJBeetlePosn p : track) {
                    if (p0 == null) {
                       p0 = p;
                    }
                    else {
                        if ( !p.getPenUp() )
                        {
                            g.setColor(m.getColor());
                            g.drawLine(p0.getX(), p0.getY(), p.getX(), p.getY());
                        }
                        p0=p;
                    }
                                               
                //draw beetle at end
                   BJBeetlePosn end = track.get(track.size() - 1);
                   drawBeetle(end.getX(), end.getY(), end.getDirection(), g, end.getColor(), pan);
               }
            }
          }
        

        
        /**
          * Draws a beetle at the given point, facing in sort of the given direction
          *
          *@param bx  The x coordinate, i.e the distance in pixels from the
          * left hand edge.
          *@param by  The y coordinate, i.e the distance in pixels from the
          * top of the drawingarea. (American coordinate system);
          *@param d  The direction the beetle is facing.  A number of degrees
          */
        
        public void drawBeetle(int bx, int by, int d, Graphics g, Color c, JPanel pan)
        {
            String fn="beetle"; String suffix="";
            if (d>349 || d<11) suffix="0.gif";
            else if (d<33) suffix="022.gif";
            else if (d<56) suffix="045.gif";
            else if (d<79) suffix="067.gif";
            else if (d<101) suffix="090.gif";
            else if (d<123) suffix="112.gif";
            else if (d<146) suffix="135.gif";
            else if (d<168) suffix="157.gif";
            else if (d<191) suffix="180.gif";
            else if (d<213) suffix="202.gif";
            else if (d<236) suffix="225.gif";
            else if (d<259) suffix="247.gif";
            else if (d<281) suffix="270.gif";
            else if (d<303) suffix="292.gif";
            else if (d<326) suffix="315.gif";
            else if (d<349) suffix="337.gif";
                  
            fn+=suffix;
            Image image=Toolkit.getDefaultToolkit().getImage(fn);
            g.drawImage(image, bx-20, by-20, 40, 40, pan);
            g.setColor(c);
            g.fillOval(bx-2,by-2,5,5);
        }

///////////////////////////////////////////////////////////////////
        /**
         * The actual component to carry the drawing.
         */
        private class CanvasPanel extends JPanel
        {
          /** 
          * If nothing has been drawn yet, draw a beetle at the point and
          * facing in the direction given by the first element in the track.
          * Otherwise draw the track and then draw a beetle.
          * @param g is the Graphics context for the drawing
          */
            public void paintComponent(Graphics theG)
            {
               // make a copy of the Graphics object, clear the screen and draw the
               // track with this copy.
               Graphics g = theG.create();
               super.paintComponent(g);
               Color original = g.getColor();
               g.setColor(Color.pink);
               g.fillRect(0, 0, canvasSize.width, canvasSize.height);
               g.setColor(original);
            
               if ( !allBeetles.isEmpty() )
               {
                  drawAllTracks(g, this);
               }
               g.dispose();
               
            }
        }
                

////////////////////////////////////////////////////////////////////////
/**
 *  Inner class to define the frame.
 *  A window with the usual window controls which provides a framework for a
 *  drawing canvas.
 *  Adapted from the original BeetleFrame for this BlueJay version.
 *  The constructor is private (We do not want it available in BlueJay) so a
 *  method to get a frame object is provided.
 *@author  Ann Robertson
 *@version 31/8/07  adapted from version 17/11/00
 */

public class BJBeetleFrame extends JFrame
{
    
    BJBeetleCanvas canvas;
    private JLabel topLabel = new JLabel(" ");
   
    /**
      * Constructs the Frame with  a  title panel at the top and the canvas
      * in the middle.
      * 
      * @param theCanvas is the canvas to be displayed.
      */
    private BJBeetleFrame ( BJBeetleCanvas theCanvas ) {

        super(" UW Aberystwyth Computer Science Dept. Beetles in Blue Jay");
        canvas = theCanvas;
        setPreferredSize(canvasSize);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);        
        getContentPane().setLayout(new BorderLayout());
        getContentPane().setBackground(Color.pink);
                
        //Create the top panel
        JPanel topPanel = new JPanel();
        topLabel.setBackground(Color.pink);
        topPanel.add(topLabel);
     
        // add the top panel and the canvas to the frame 
        this.add(topPanel, BorderLayout.NORTH);
        this.add(panel, BorderLayout.CENTER);
        
        pack();      //makes the frame fit the given canvas   
        setVisible(true);   // Display the window
    }  // End of Constructor
    
    /**
     * Allow the user to set a title for the drawing
     */
    public void setTitle(String theTitle)
    {
        topLabel.setText(theTitle);
    }
    
   
    
   
}          
}
