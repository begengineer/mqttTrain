#include <Arduino.h>
#include <WiFiS3.h>
#include <ArduinoMqttClient.h>
#include "secret.h"

// ポート番号の設定
#define PORT 1883

// wifiの設定
const char* WIFI_SSID     = SECRET_SSID;
const char* WIFI_PASSWORD = SECRET_PASSWORD;
const char* BROKER_HOST   = SECRET_BROKER;

WiFiClient wifiClient;
MqttClient mqttClient(wifiClient);

void setup(){
  Serial.begin(115200);
  Serial.println("Project Start!");
  while(!Serial);

  // WiFiへの接続
  Serial.println("Connecting to wifi");
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.println("Connecting to wifi");
  }

  // MQTT接続
  mqttClient.setId("arduino-test");
  Serial.println("connecting MQTT...");
  while(!mqttClient.connect(BROKER_HOST, PORT)){
    delay(2000);
    Serial.println("connecting MQTT..");
  }
  Serial.println("connected!");
}

void loop(){
  mqttClient.poll();

  static unsigned long lastTime = 0;
  if(millis() - lastTime > 5000){
    lastTime = millis();
    float fakeTemp = 22.0 + random(-20,20) / 10.0;
    String msg = String(fakeTemp,1);
    mqttClient.beginMessage("home/room/tempereture");
    mqttClient.print(msg);
    mqttClient.endMessage();
    Serial.println("送信" + msg);
  }
}
