#ifndef WIFIUTILS_H
#define WIFIUTILS_H

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include "LedUtils.h"

extern const char *ssid;
extern const char *password;
extern IPAddress local_IP;
extern ESP8266WebServer server;

void handleRoot();
void handleUpdate();
void setupWifi();

#endif // WIFIUTILS_H