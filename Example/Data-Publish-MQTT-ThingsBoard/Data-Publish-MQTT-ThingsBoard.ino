#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <WiFi.h>
#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
//Connection Details Hotspot Name and Password
#define WIFI_AP "YOUR_NETWORK_SSID"
#define WIFI_PASSWORD "YOUR_NETWORK_PASSWORD"

//Server Details [Host and Aaccess Token as username]
char eNlightServer[] = "THINGSBOARD_HOST";
#define TOKEN "DEVICE_ACCESS_TOKEN" //Token for Test Device

#define DATA_PUBLISH_TOPIC "v1/devices/me/telemetry"

WiFiClient wifiClient;

PubSubClient client(wifiClient);

int status = WL_IDLE_STATUS;

void setup()
{
  Serial.begin(115200);
  delay(10);
  InitWiFi();
  client.setServer(eNlightServer, 1883 );
  dht.begin();
}

void loop()
{
  if (!client.connected())
  {
    reconnect();
  }
  publish_data();
  client.loop();
}

void publish_data()
{
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  Serial.println("Sending the data to SERVER...");
  
  String data_payload_publish = String("{\"temperature\":") + t +
                                ",\"humidity\":" + h + "}";

  client.publish(DATA_PUBLISH_TOPIC, data_payload_publish.c_str());
  Serial.println("Data Published Successfully.");
  delay(1000);
}

void InitWiFi()
{
  Serial.println("Connecting to Access Point ...");

  WiFi.begin(WIFI_AP, WIFI_PASSWORD);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("Connected to AP");
}

void reconnect()
{
  while (!client.connected())
  {
    status = WiFi.status();
    if ( status != WL_CONNECTED)
    {
      WiFi.begin(WIFI_AP, WIFI_PASSWORD);
      while (WiFi.status() != WL_CONNECTED)
      {
        delay(500);
        Serial.print(".");
      }
      Serial.println("Connected to Access Point.");
    }
    Serial.print("Connecting to ThingsBoard IoT Server node ...");
    if ( client.connect("ESP32 Device", TOKEN, NULL) )
    {
      Serial.println( "[DONE]" );
    }
    else
    {
      Serial.print( "[FAILED] [ rc = " );
      Serial.print( client.state() );
      Serial.println( " : retrying in 5 seconds]" );
      // Wait 5 seconds before retrying
      delay( 5000 );
    }
  }
}
