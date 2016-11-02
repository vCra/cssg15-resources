
/**
      This class demonstrates using the Beetle from a main program
      also loops and if statements
 */
public class Test
{
    public static void main(String args[]) {
        //how many times thru loop        
        InputGetter readNumber=new InputGetter();
        readNumber.getInputFromUser("How many times to run");
        int number=Integer.parseInt(readNumber.getCurrentValue());

        InputGetter reader=new InputGetter();
        BJBeetle bob=new BJBeetle();
        for (int i=0;i<number;i++) { 
            reader.getInputFromUser ( "Type Username or Shape (star or circle)" );
            String option=reader.getCurrentValue();
            //circle
            if (option.equals("circle")) {
                for (int j=0; j<36;j++) {
                    bob.moveForward(10);
                    bob.turn(10);
                }
                System.out.println("done circle");
            }
            //star
            else if (option.equals("star")){
                for (int j=0;j<5;j++){
                    bob.turn(720/5);
                    bob.moveForward(50);
                }
                System.out.println("done star");
            }
            //my uid
            else if (option.equals("ltt")){
                System.out.println("if I could be bothered I'd draw LTT");
            }
            //anything else
            else {
                System.out.println("Sorry, cannot understand");
            }

            //change bob's position using i
            bob.position(200+i*20, 200+i*20,0,false);
        }
    }
}

