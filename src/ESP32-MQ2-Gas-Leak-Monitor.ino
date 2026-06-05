/*************************************************
 * ESP32 MQ-2 Gas Leak Monitoring System
 * Author : Milad Mohseni
 * Board  : ESP32 (30-pin)
 *************************************************/

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

// MQ-2 Sensor
#define MQ2_PIN 34

// LEDs
#define GREEN_LED 15
#define ORANGE_LED 2
#define BLUE_LED 4

// Buzzer
#define BUZZER_PIN 14

int gasValue = 0;

void setup()
{
  Serial.begin(115200);

  Wire.begin(21, 22);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(ORANGE_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);

  pinMode(BUZZER_PIN, OUTPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
  {
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0,0);
  display.println("MQ-2 GAS MONITOR");

  display.setCursor(0,20);
  display.println("Sensor Warming");

  display.setCursor(0,35);
  display.println("Please Wait...");

  display.display();

  delay(30000);
}

void loop()
{
  gasValue = analogRead(MQ2_PIN);

  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  // -----------------------------
  // SAFE
  // -----------------------------
  if(gasValue < 300)
  {
    digitalWrite(GREEN_LED, HIGH);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(BLUE_LED, LOW);

    noTone(BUZZER_PIN);

    display.clearDisplay();
    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("MQ-2 GAS MONITOR");

    display.setCursor(0,20);
    display.print("Gas: ");
    display.println(gasValue);

    display.setCursor(0,45);
    display.println("STATUS: SAFE");

    display.display();
  }

  // -----------------------------
  // WARNING
  // -----------------------------
  else if(gasValue < 500)
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(ORANGE_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);

    noTone(BUZZER_PIN);

    display.clearDisplay();
    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("MQ-2 GAS MONITOR");

    display.setCursor(0,20);
    display.print("Gas: ");
    display.println(gasValue);

    display.setCursor(0,45);
    display.println("STATUS: WARNING");

    display.display();
  }

  // -----------------------------
  // DANGER
  // -----------------------------
  else
  {
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(ORANGE_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);

    tone(BUZZER_PIN, 2500);

    display.clearDisplay();
    display.setTextSize(1);

    display.setCursor(0,0);
    display.println("MQ-2 GAS MONITOR");

    display.setCursor(0,20);
    display.print("Gas: ");
    display.println(gasValue);

    display.setCursor(0,45);
    display.println("STATUS: DANGER");

    display.display();
  }

  delay(300);
}