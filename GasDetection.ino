
//Change Blynk Authenticaation Details
#define BLYNK_TEMPLATE_ID "your blynk template id"
#define BLYNK_TEMPLATE_NAME "your blynk template name"
#define BLYNK_AUTH_TOKEN "your blynk auth token"

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2); // Set the LCD address to 0x27 for a 16 chars and 2 line display

 
char auth[] = BLYNK_AUTH_TOKEN;

char ssid[] = "your wifi ssid";  // Enter your wifi name
char pass[] = "your wifi pass";  // Enter your wifi password
int smokeA0 = A0;
int data = 0;
#define LED_GREEN D5
#define LED_RED D6
#define BUZZER_PIN D4


BlynkTimer timer;

void sendSensor(){
 int data = analogRead(smokeA0);
 Blynk.virtualWrite(V0, data);
  Serial.print("Pin A0: ");
  Serial.println(data);
  lcd.setCursor(0, 0);               // Set the cursor to the first column and first row
  lcd.print("Gas Value:");     // Print some text
  lcd.setCursor(0,1);
  lcd.print(data);

  if(data > 700)     // Change the Trashold value
  {
    digitalWrite(LED_GREEN, LOW);
    digitalWrite(LED_RED, HIGH);
    digitalWrite(BUZZER_PIN, HIGH);
    Blynk.email("tt7738459463@gmail.com", "Alert", "Gas Leakage Detected!");
    Blynk.logEvent("gas_alert","Gas Leakage Detected");
  }
  else 
  {
    digitalWrite(LED_GREEN, HIGH);
    digitalWrite(LED_RED, LOW);
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void setup(){
  pinMode(smokeA0, INPUT);
  pinMode(LED_GREEN, OUTPUT);
  pinMode(LED_RED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(LED_RED, LOW);
  digitalWrite(BUZZER_PIN, LOW);
  Serial.begin(115200);
  lcd.begin();                       // Initialize the LCD
  lcd.backlight();                  // Turn on the backlight
  lcd.clear();                      // Clear the LCD screen
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(2500L, sendSensor); //after every 2.5 sec sendSensor function will be  executed L stands for long  int 
}

void loop(){
  Blynk.run();
  timer.run(); 
}