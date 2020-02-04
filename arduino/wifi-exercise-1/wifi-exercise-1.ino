/*
    WiFi Exercise 1 - connecting ESP8266 to WiFi. 
*/
#include <ESP8266WiFi.h>    // Include the Wi-Fi library

const char* ssid     = "SSID";         // The SSID (name) of the Wi-Fi network you want to connect to
const char* password = "PASSWORD";     // The password of the Wi-Fi network

void setup() {
    // Start the Serial communication to send messages to the computer
    Serial.begin(115200);
    delay(10);
    Serial.println("");

    // Connect to the WiFi network
    WiFi.begin(ssid, password);
    Serial.print("Connecting to ");
    Serial.print(ssid); Serial.println(" ...");

    while (WiFi.status() != WL_CONNECTED) { // Wait for the Wi-Fi to connect
        delay(1000);
        Serial.print('.');
    }

    Serial.println("");
    Serial.println("Connection established!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());         // Send the IP address of the ESP8266 to the computer
}

void loop() {
    // empty
}
