#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "Smart Meter"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>

// WiFi credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "YOUR_WIFI_SSID";  
char pass[] = "YOUR_WIFI_PASSWORD"; 

// Pin definitions
const int analogPin = A0;  // TMP36 sensor pin
const int fanPin = D1;     // Fan control pin

void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  
  // Output pins for appliance control
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  pinMode(D8, OUTPUT);
  pinMode(fanPin, OUTPUT);
  
  // Set all outputs HIGH (OFF) initially
  digitalWrite(D5, HIGH);
  digitalWrite(D6, HIGH);
  digitalWrite(D7, HIGH);
  digitalWrite(D8, HIGH);
}

void loop() {
  Blynk.run();
  
  // Temperature based fan control
  float temperature = getTemperature();
  Serial.print("Temperature: ");
  Serial.println(temperature);
  
  if (temperature > 25.0) {
    digitalWrite(fanPin, HIGH);
    Serial.println("Fan ON");
  } else {
    digitalWrite(fanPin, LOW);
    Serial.println("Fan OFF");
  }
  
  delay(5000);
}

// Appliance 1 control
BLYNK_WRITE(V0) {
  int value = param.asInt();
  digitalWrite(D5, value == 1 ? LOW : HIGH);
  Serial.println(value == 1 ? "Appliance 1 ON" : "Appliance 1 OFF");
}

// Appliance 2 control
BLYNK_WRITE(V1) {
  int value = param.asInt();
  digitalWrite(D6, value == 1 ? LOW : HIGH);
  Serial.println(value == 1 ? "Appliance 2 ON" : "Appliance 2 OFF");
}

// Appliance 3 control
BLYNK_WRITE(V2) {
  int value = param.asInt();
  digitalWrite(D7, value == 1 ? LOW : HIGH);
  Serial.println(value == 1 ? "Appliance 3 ON" : "Appliance 3 OFF");
}

// Appliance 4 control
BLYNK_WRITE(V3) {
  int value = param.asInt();
  digitalWrite(D8, value == 1 ? LOW : HIGH);
  Serial.println(value == 1 ? "Appliance 4 ON" : "Appliance 4 OFF");
}

// Temperature reading function
float getTemperature() {
  int sensorValue = analogRead(analogPin);
  float voltage = sensorValue * (3.3 / 1024.0);
  float temperatureCelsius = voltage * 100.0;
  return temperatureCelsius;
}
