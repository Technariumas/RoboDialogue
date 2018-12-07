#include <SerialCommand.h>
SerialCommand sCmd;

//indicator LEDs

#define LED_PIN 13
#define BUZZER 3
int series = 1;
int currentSeries = 0;

void setup() {
  // put your setup code here, to run once:

pinMode(LED_PIN, OUTPUT); 
sCmd.addCommand("COUNT", count);      
Serial.begin(9600);
Serial.println("COUNT 1");
}

void blink() {
    for (int i=0; series < i; i++){
      digitalWrite(LED_PIN, HIGH);
      Serial.println(i);
      delay(200);
      digitalWrite(LED_PIN, LOW);
    }
}

void count() {
      delay(1000);
      int v;
      char *arg;
      arg = sCmd.next();
      if (arg != NULL) {
        currentSeries = atoi(arg);   
        series+=currentSeries;
          for (int i=0; i<series; i++){
          digitalWrite(LED_PIN, HIGH);
          Serial.println(i);
          tone(BUZZER, 1000, 300);
          //noTone(BUZZER);
          delay(800);
          digitalWrite(LED_PIN, LOW);
        }
        Serial.print("COUNT ");
        Serial.println(series);
        delay(2000);
      }
      else {Serial.println("NO ARG");}
    }  

void loop() {
  sCmd.readSerial();
          if (series == 1) {
          digitalWrite(LED_PIN, HIGH);
          Serial.println("first");
          tone(BUZZER, 1000, 300);
          //noTone(BUZZER);
          delay(800);
          digitalWrite(LED_PIN, LOW);
          }
          delay(2000);

  //Serial.println("PING");
  //delay(3000);
  // put your main code here, to run repeatedly:

}
