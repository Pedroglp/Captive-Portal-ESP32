
#include <pages/getPage.h>
#include <pages/getStyle.h>
#include <cstring>
#include <Arduino.h>

const String mainPage = 
R"=====(
    <head>
      <title>ESP32 Captive Portal</title>
      <meta name="viewport" content="width=device-width, initial-scale=1.0">
    </head>
    <body>
      <div class="container">
        <div class="header">
          <h1>Welcome to Wifi-Name</h1>
        </div>
        <div class="content">
          <p>To access this network login using one othe methods below:</p>
        </div>
      </div>
    </body>
)=====";

const char* getPage() {
  const String pageBody = mainPage;

  const String pageStyle = getStyle();

  const String fullPage = "<!DOCTYPE html><html>" + pageBody + pageStyle + "</html>";

  char* result = new char[fullPage.length() + 1];
  strcpy(result, fullPage.c_str());

  return result;
}