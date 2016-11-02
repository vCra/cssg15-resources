long seconds [] = {0, 0, 0};
const String names[] = {"Swim", "Bike", "Run", "Total"};
const String units[] = {"Seconds", "Minutes", "Hours"};
const long numberOfRaces = 3;
const long numberOfUnits = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  long x;
  long y;
  long fastestTime = 0;
  bool cont = true;
  int athleteNumber = 0;
  int fastestAthlete = 0;

  while (cont) {
    athleteNumber = athleteNumber + 1;
    Serial.println("You are athlete number " + String(athleteNumber));
    long totalseconds [] = {0, 0, 0};
    long inputNums [] = {0, 0, 0};
    long totalTime = 0;
    for (x = 0; x < numberOfRaces; ++x) {
      if (cont == true) {
        Serial.print(names[x] + " Race - ");
        for (y = 0; y < numberOfUnits; ++y) {
          inputNums[y] = getInput(units[y]);
          if ((x == 0) && (y == 0) && (inputNums[y] < 0)) {
            cont = false;
            break;
          }
        }
        seconds[x]  = convToSecs(inputNums[0], inputNums[1], inputNums[2]);
#ifdef debug
        Serial.print("total seconds - ");
        Serial.println(seconds[x]);
#endif
      }
    }
    if (cont == true) {
      Serial.println();
      for (x = 0; x < numberOfRaces; x++) {
        showResults(seconds[x], names[x]);
      }
      totalTime = seconds[0] + seconds[1] + seconds[2];
      showTotal(totalTime);
      if (totalTime < fastestTime) {
        Serial.println("You are the fastest Athlete!") ;
        fastestTime = totalTime;
        fastestAthlete = athleteNumber;
      }
    }
  }
  Serial.println("Athlete number " + String(fastestAthlete) + " is the fastest athlete");
  Serial.print("They completed the race");
  convToTime(fastestTime);
}

void showResults(long seconds, String race) {
  Serial.print("For the " + race);
  convToTime(seconds);
}
void showTotal(long seconds) {
  Serial.print("For all of the races");
  convToTime(seconds);
}

long getInput(String unit) {
  Serial.println("Enter " + unit + ": ");

  long iValue;
  while (!Serial.available()) {
    //wait for a the user to enter a value
    ;
  }
  iValue = Serial.parseInt();
  Serial.println(iValue);
  return iValue;
}

long convToSecs(long secs, long mins, long hours) {
#ifdef debug
  Serial.println("convToSecs input");
  Serial.println(secs);
  Serial.println(mins);
  Serial.println(hours);
#endif
  long seconds = 0;


  const long SecondsInHour = 3600;
  const long SecondsInMin = 60;
  seconds = (hours * SecondsInHour) + (mins * SecondsInMin) + secs;

  return seconds;
}

long convToTime(long seconds) {
  long hours;
  long mins;
  long temp;
  hours = seconds / 3600;
  temp = seconds % 3600;
  mins = temp / 60;
  seconds = temp % 60;
  Serial.println(", the total time was " + String(hours) + " hours, " + String(mins) + " minuets and " + String(seconds) + " seconds.");
}

void loop() {
  // put your main code here, to run repeatedly:

}
