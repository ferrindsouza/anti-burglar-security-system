/* This simple project describes how to make an ultrasonic alarm system using 
LED, Ultasonic Sensor(HC-SR04) and a buzzer.*/ 

//Firstly the connections of ultrasonic Sensor.Connect +5v and GND normally and trigger pin to 12 & echo pin to 13. 
#include<Keypad.h>
#define trigPin 12
#define echoPin 13
int Buzzer = 8; // Connect buzzer pin to 8
int ledPin= 9;  //Connect LEd pin to 9
int duration, distance; //to measure the distance and time taken
String password="1247";
String tempPassword;
boolean activated=false;
boolean isActivated;
boolean activateAlarm=false;
boolean alarmActivated=false;
boolean enteredPassword; 
boolean passChangeMode=false;
boolean passChanged=false;

const byte ROWS=4;
const byte COLS=4;
char keypressed;
char keyMap[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte rowPins[ROWS] = {7, 6, 5, 4}; //Row pinouts of the keypad
byte colPins[COLS] = {3, 2, 1, 0}; //Column pinouts of the keypad
Keypad myKeypad = Keypad( makeKeymap(keyMap), rowPins, colPins, ROWS, COLS); 
void setup() {
        Serial.begin (9600); 
        //Define the output and input objects(devices)
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(Buzzer, OUTPUT);
        pinMode(ledPin, OUTPUT);
}

void loop() {
    
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    //when distance is greater than or equal to 200 OR less than or equal to 0,the buzzer and LED are off
  if (distance >= 50 || distance <= 0) 
        {
        Serial.println("no object detected");
        digitalWrite(Buzzer,LOW);
        digitalWrite(ledPin,LOW);
        }
  else {
        Serial.print("Alarm will be activated in: ");
        int countdown=5;
        while(countdown!=0)
        {
          Serial.print(countdown);
          countdown--;
          tone(Buzzer,700,100);
          delay(1000);
        }
        Serial.println("\nAlarm Activated!\n");
        activateAlarm=false;
        alarmActivated=true;
        activated=true;
        Serial.print("distance= ");              
        Serial.print(distance);        //prints the distance if it is between the range 0 to 200
        tone(Buzzer,1000);              // play tone of 1000Hz for 500 ms
        digitalWrite(ledPin,HIGH);
        enterPassword();
        digitalWrite(ledPin,LOW);
        delay(10000000);
        
  }
}
void enterPassword()
{
  int k=5;
  tempPassword = "";
  activated = true;
  Serial.print(" *** ALARM *** ");
  //lcd.setCursor(0,1);
  Serial.print("Pass>");
      while(activated) {
      keypressed = myKeypad.getKey();
      if (keypressed != NO_KEY){
        if (keypressed == '0' || keypressed == '1' || keypressed == '2' || keypressed == '3' ||
            keypressed == '4' || keypressed == '5' || keypressed == '6' || keypressed == '7' ||
            keypressed == '8' || keypressed == '9' ) {
          tempPassword += keypressed;
          //lcd.setCursor(k,1);
          Serial.print("*");
          k++;
        }
      }
      if (k > 9 || keypressed == '#') {
        tempPassword = "";
        k=5;
        //lcd.clear();
        //lcd.setCursor(0,0);
        Serial.print(" *** ALARM *** ");
        //lcd.setCursor(0,1);
        Serial.print("Pass>");
      }
      if ( keypressed == '*') {
        if ( tempPassword == password ) {
          activated = false;
          alarmActivated = false;
          noTone(Buzzer);
          //screenOffMsg = 0; 
        }
        else if (tempPassword != password) {
          //lcd.setCursor(0,1);
          Serial.print("Wrong! Try Again");
          delay(2000);
          //lcd.clear();
          //lcd.setCursor(0,0);
          Serial.print(" *** ALARM *** ");
          //lcd.setCursor(0,1);
          Serial.print("Pass>");
        }
      }    
    }
}
