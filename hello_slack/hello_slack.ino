#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>

const char* ssid     = "WoloxHQ";
const char* password = "WoloxHQ1189";

String server = "www.example.net"; // http://www.example.com

#define FINGERPRINT "AC 95 5A 58 B8 4E 0B CD B3 97 D2 88 68 F5 CA C1 0A 81 E3 6E"

void setup() {
 Serial.begin(115200);
  delay(10);
 // We start by connecting to a WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  
}

void loop() {
  HTTPClient http;

  http.begin("https://hooks.slack.com/services/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", FINGERPRINT);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  http.POST("{\"text\": \"Hola!\"}");
  http.end();
  Serial.print("test");
  delay(10000);
}
