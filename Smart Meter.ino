#define BLYNK_TEMPLATE_ID "TMPL6nxurva3R"
#define BLYNK_TEMPLATE_NAME "Smart Meter"
#define BLYNK_AUTH_TOKEN "JXBN3RD7dovfU8RD9ngMn4IaueQVSdyI"



#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>  
#include <BlynkSimpleEsp8266.h>
const int analogPin = A0;  // Pin connected to the TMP36 sensor
const int fanPin = D1;    // Pin connected to the fan


char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Pixel_7466";  
char pass[] = "123456789"; 

BLYNK_WRITE(VO)
{
  int value = param.asInt();
  Serial.println(value);
  if(value ==1)
  {
    digitalWrite(D5,LOW);
  Serial.println("LED ON");
  }
  if(value ==0)
  {
    digitalWrite(D5,HIGH);
 Serial.println("LED OFF");
  }
}
BLYNK_WRITE(V1)
{
  int value = param.asInt();
Serial.println(value);
  if(value ==1)
  {
    digitalWrite(D6,LOW);
 Serial.println("LED ON");
  }
  if(value ==0)
  {
    digitalWrite(D6,HIGH);
  Serial.println("LED OFF");
  }
}
BLYNK_WRITE(V2)
{
  int value = param.asInt();
Serial.println(value);
  if(value ==1)
  {
    digitalWrite(D7,LOW);
 Serial.println("LED ON");
  }
  if(value ==0)
  {
    digitalWrite(D7,HIGH);
   Serial.println("LED OFF");
  }
}
BLYNK_WRITE(V3)
{
  int value = param.asInt();
Serial.println(value);
  if(value ==1)
  {
    digitalWrite(D8,LOW);
    Serial.println("LED ON");
  }
  if(value ==0)
  {
    digitalWrite(D8,HIGH);
Serial.println("LED OFF");
  }
}
  
  void setup()

{
Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);
  pinMode (D5,OUTPUT);
  pinMode (D6,OUTPUT);
  pinMode (D7,OUTPUT);
  pinMode (D8,OUTPUT);
  Serial.begin(115200);
  pinMode(fanPin, OUTPUT);
  
}
void loop()
{
  Blynk.run(); 
}




void loop1() {
  float temperature = getTemperature();
  Serial.print("Temperature: ");
  Serial.println(temperature);

  if (temperature > 25.0) {
    // If temperature is above 25.0 degrees Celsius, turn on the fan
    digitalWrite(fanPin, HIGH);
    Serial.println("Fan ON");
  } else {
    // If temperature is 25.0 degrees Celsius or below, turn off the fan
    digitalWrite(fanPin, LOW);
    Serial.println("Fan OFF");
  }
  delay(5000);  // Adjust the delay based on how often you want to read and control the temperature
}

float getTemperature() {
  int sensorValue = analogRead(analogPin);
  float voltage = sensorValue * (3.3 / 1024.0);
  float temperatureCelsius = voltage * 100.0;  // LM35 linear temperature conversion
  return temperatureCelsius;
}
#include <DHT.h>

#define DHTPIN 2  // Replace with the actual pin your DHT sensor is connected to
#define DHTTYPE DHT22  // Change this to DHT11 if you are using that model

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  delay(2000);  // Wait for 2 seconds between readings

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature();

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print("%\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println("°C");
}

