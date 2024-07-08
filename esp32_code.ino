#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL31DODWVYE"
#define BLYNK_TEMPLATE_NAME "scoreboard107"
#define BLYNK_AUTH_TOKEN "T4siqdKw2lDOgwLSlAPFyxCUjCGYDfiz"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "DigitLedDisplay.h"

/* ESP32 Pin to Display Pin
   GPIO18 to DIN,
   GPIO5 to CS,
   GPIO19 to CLK */
#define DIN 18
#define CS 5
#define CLK 19
DigitLedDisplay ld = DigitLedDisplay(DIN, CS, CLK);

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "OnePlus 6";
char pass[] = "12345678";

int homeScore=0;
int guestScore=0;

// Enter your Auth token
char auth[] = "T4siqdKw2lDOgwLSlAPFyxCUjCGYDfiz";
void setup()
{
  // Debug console
  Serial.begin(9600);

  // Connect to Wi-Fi
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Connect to Blynk
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

// Initialize the display
  ld.setBright(6);
  ld.setDigitLimit(8);
}

BLYNK_WRITE(V0) { // Home score increase
  homeScore++;
  updateScoreDisplay();
}

BLYNK_WRITE(V1) { // Home score decrease
  if (homeScore > 0) {
    homeScore--;
    updateScoreDisplay();
  }
}

BLYNK_WRITE(V2) { // Guest score increase
  guestScore++;
  updateScoreDisplay();
}

BLYNK_WRITE(V3) { // Guest score decrease
  if (guestScore > 0) {
    guestScore--;
    updateScoreDisplay();
  }
}

BLYNK_WRITE(V4){
  guestScore=0;
  homeScore=0;
  updateScoreDisplay();
}

void updateScoreDisplay(){

  ld.printDigit(homeScore%10,4);
  ld.printDigit(homeScore/10,5);
  ld.printDigit(homeScore/100,6);
  ld.printDigit(homeScore/1000,7);
  ld.printDigit(guestScore%10,0);
  ld.printDigit(guestScore/10,1);
  ld.printDigit(guestScore/100,2);
  ld.printDigit(guestScore/1000,3);
}

void loop()
{
  Blynk.run();
}


