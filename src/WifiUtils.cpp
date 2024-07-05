#include "WiFiUtils.h"
#include "htmlPage.h"

const char *ssid = "MyWemosAP";
const char *password = "password";
IPAddress local_IP(192, 168, 4, 1);

ESP8266WebServer server(80);

void handleRoot()
{
    server.send(200, "text/html", htmlPage);
}

void handleUpdate()
{
    String slider1Value = server.arg("slider1");
    String slider2Value = server.arg("slider2");
    String slider3Value = server.arg("slider3");
    Serial.println("Slider 1 value: " + slider1Value);
    Serial.println("Slider 2 value: " + slider2Value);
    Serial.println("Slider 3 value: " + slider3Value);
    server.send(200, "text/plain", "OK");

    ledsFillSolid(slider1Value.toInt(), slider2Value.toInt(), slider3Value.toInt());
}

void setupWifi()
{
    Serial.begin(115200);

    WiFi.softAPConfig(local_IP, local_IP, IPAddress(255, 255, 255, 0));
    WiFi.softAP(ssid, password);

    Serial.println();
    Serial.print("Access Point \"");
    Serial.print(ssid);
    Serial.println("\" started");
    Serial.print("IP address: ");
    Serial.println(WiFi.softAPIP());

    server.on("/", handleRoot);
    server.on("/update", handleUpdate);

    server.begin();
    Serial.println("HTTP server started");
}