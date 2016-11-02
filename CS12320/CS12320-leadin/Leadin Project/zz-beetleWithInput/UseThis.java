
/**
This class is a convenience that can be copied to run your code
When you want to copy it pick the 'New Class' button, BlueJ will give you
a new class and ask you for the name - suppose you call it  'Test' 
then double click on it
replace all its code with this code 
except where this class says 'UseThis' replace with 'Test'
Then compile
Then right click on the *class* and pick 'void main(String args[])'
 */
public class UseThis{
    public static void main(String args[]) {
        InputGetter reader=new InputGetter();
        reader.getInputFromUser();
        String name=reader.getCurrentValue();
        if (name.equals("fred")) {
            System.out.println("found fred");
        }
        else {
            System.out.println("not  Fred");
        }

    }
}
