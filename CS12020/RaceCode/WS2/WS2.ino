void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  runprogram();
}

void runprogram(){
  int seconds1;
  int minuets1;
  int hours1;
  int seconds2;
  int minuets2;
  int hours2;
  int seconds3;
  int minuets3;
  int hours3;
 
  Serial.println("Enter Seconds for race one");
  seconds1 = getInput();
  Serial.println("Enter Minutes for race one");
  minuets1 = getInput();
  Serial.println("Enter Hours for race one");
  hours1 = getInput();
  Serial.println("Enter Seconds for race two");
  seconds2 = getInput();
  Serial.println("Enter Minutes for race two");
  minuets2 = getInput();
  Serial.println("Enter Hours for race two");
  hours2 = getInput();
  Serial.println("Enter Seconds for race three");
  seconds3 = getInput();
  Serial.println("Enter Minutes for race three");
  minuets3 = getInput();
  Serial.println("Enter Hours for race three");
  hours3 = getInput();
  
  int newseconds;
  int newminuets;
  int newhours;
  int seconds;
  int minuets;
  int hours;
  seconds = seconds1+seconds2+seconds3;
  minuets = minuets1+minuets2+minuets3;
  hours = hours1+hours2+hours3;
 
   
  newseconds = seconds % 60;
  newminuets = minuets + (seconds/60);
  newminuets = newminuets + (hours % 60);
  newminuets = newminuets % 60;
  newhours = hours + (minuets/60);
    
  String total;
  int total1;
  int total2;
  int total3;
  total1 = newseconds;
  total2 = newminuets;
  total3 = newhours;
  total = String(total1) + ":" + String(total2) + ":" + String(total3);
  Serial.print(total);
}
int getInput(){
  int iValue;
  while (!Serial.available()) {
  //wait for a the user to enter a value
  ;
  }
  iValue = Serial.parseInt();
  return iValue;
}



