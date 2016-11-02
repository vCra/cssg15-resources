/**
 * demonstrates nested control structures and also main programs
 */

public class Nested{
    public static void main(String args[]) {
        InputGetter reader=new InputGetter();
        reader.getInputFromUser("how many students");
        int number=Integer.parseInt(reader.getCurrentValue());
        for (int i=0;i<number;i++) {
            System.out.print("student "+i +" ");
            //process a student
            //read name
            InputGetter nameReader=new InputGetter();
            nameReader.getInputFromUser("enter name");
            String name=nameReader.getCurrentValue();
            //read gender
            InputGetter genderReader=new InputGetter();
            genderReader.getInputFromUser("what is your gender (male or female)");
            String answer=genderReader.getCurrentValue();
            //process and print
            if (answer.equals("male")) {
                System.out.println("Mr. "+name);
            }
            else {
                System.out.println("Ms. "+name);
            }
        }

        
    }
}
