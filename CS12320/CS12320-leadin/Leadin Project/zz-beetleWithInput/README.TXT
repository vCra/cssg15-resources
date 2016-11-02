About the BJBeetle
----------------
The BJBeetle can draw lines on a screen if you give it instructions in Java.
The BJBeetle uses whole numbers only, and its units are its own.  
The space it draws on is 500 BJBeetle units square.
If you don't set a starting position it starts in the middle of the space
facing up.

It understands the following instructions:
* setTitle( theTitle );
    This allows the user to set a title for the drawing where  theTitle
    stands for the text for the title.
    
* public void start(); 
    Draws a beetle in the middle of the drawing space, facing up with the 
    pen down.
    
* public void start(  theXPos,  theYPos, theDirection, isUp );
    This allows the user to set a starting position, where
       theXPos is the distance from the left edge of the beetle's space.
       theYPos is the distance from the top of the beetle's space.
       theDirection is a string:   "North", "South", "East" or "West".
       isUp is the pen position. For pen up the value of  isUp should be  true.
                                 For pen down the value of  isUp should be false
       
* moveForward( distance );
    Makes the BJBeetle move forward by an amount given by  distance.
* moveBackward( distance );
    Makes the BJBeetle move backward by an amount given by  distance.
* turnRight();
    Changes the direction the BJBeetle is facing by 90 degrees to the right.
* turnLeft();
    Changes the direction the BJBeetle is facing by 90 degrees to the left
* setPenUp(true) and setPenUp(false);
    When the pen is up (i.e. the setPenUp(true)  instruction has been issued.)
    the beetle will move as usual but it will not draw lines.  To make it 
    start drawing again use the   setPenUp( false )   instruction.
    When the beetle first starts the pen is down until you tell it otherwise.


    

