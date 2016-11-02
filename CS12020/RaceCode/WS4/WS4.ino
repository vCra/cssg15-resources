void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  runprogram();
}

void runprogram(){
  long results[3][3] = {{ 0, 0, 0 },
                     { 0, 0, 0 },
                     { 0, 0, 0 }};
  int x;
  int y;
  int temp;
  long totalseconds [] = {0,0,0};
  const int secondsInMin = 60
  const int SecondsInHour = 3600
  const String names[] = {"Swim","Bike","Run","Total"};
  const String units[] = {"Seconds ", "Minuets ", "Hours "};
}
String numberToRace(race){
  return names[race]
}

String numberToUnits(unit){
  return units[unit]
}

String getInput(unit,race){
  Serial.println("Enter " ++ unit ++ "for " ++ race ++ " Race: ");
  output = getInput()
  return output
}

void getAllInput(names,units){
  int x
  int y
  for (x = 0; x < 3; x++){
    for (y = 0; y < 3; y++){
      results[x][y] = getInput(names[x],units[y]
    }
  }
}      
//  Serial.println("Enter Seconds for race one");
//  results[0][0] = getInput();
//  Serial.println("Enter Minutes for race one");
//  results[0][1] = getInput();
//  Serial.println("Enter Hours for race one");
//  results[0][2] = getInput();
//  Serial.println("Enter Seconds for race two");
//  results[1][0] = getInput();
//  Serial.println("Enter Minutes for race two");
//  results[1][1] = getInput();
//  Serial.println("Enter Hours for race two");
//  results[1][2] = getInput();
//  Serial.println("Enter Seconds for race three");
//  results[2][0] = getInput();
//  Serial.println("Enter Minutes for race three");
//  results[2][1] = getInput();
//  Serial.println("Enter Hours for race three");
//  results[2][2] = getInput();
  


  totalseconds[0] = results[0][0]+(results[0][1] * secondsInMin) + (results[0][2] * SecondsInHour);
  totalseconds[1] = results[1][0]+(results[1][1] * secondsInMin) + (results[1][2] * SecondsInHour);
  totalseconds[2] = results[2][1]+(results[2][1] * secondsInMin) + (results[2][2] * SecondsInHour);
  


  for( x = 0; x < 3; x = x + 1){
    results[x][2] = totalseconds[x] /3600;
    temp = totalseconds[x]%3600;
    results[x][1] = temp /60;
    results[x][0] = temp %60;
    Serial.println(totalseconds[x]);
  
  }
  for( x = 0; x < 3; x = x + 1){
    Serial.println();
    Serial.println(names[x] + " Times");
    for( y = 0; y < 3; y = y + 1){
       Serial.print(units[y] + results[x][y]+ ", ");
    }
  }   
  Serial.println();
  for( x = 0; x < 3; x = x + 1){
  temp = 0;
  for( y = 0; y < 3; y = y + 1){
    temp = temp + results[y][x];
 
  }
   Serial.println("Total " +units[x] + temp);
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



