
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
        <div style="display:flex; justify-content: center;">
          <svg fill="#000000" height="72px" width="72px" version="1.1" id="Capa_1" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewBox="0 0 365.892 365.892" xml:space="preserve"><g id="SVGRepo_bgCarrier" stroke-width="0"></g><g id="SVGRepo_tracerCarrier" stroke-linecap="round" stroke-linejoin="round"></g><g id="SVGRepo_iconCarrier"> <g> <circle cx="182.945" cy="286.681" r="41.494"></circle> <path d="M182.946,176.029c-35.658,0-69.337,17.345-90.09,46.398c-5.921,8.288-4.001,19.806,4.286,25.726 c3.249,2.321,6.994,3.438,10.704,3.438c5.754,0,11.423-2.686,15.021-7.724c13.846-19.383,36.305-30.954,60.078-30.954 c23.775,0,46.233,11.571,60.077,30.953c5.919,8.286,17.437,10.209,25.726,4.288c8.288-5.92,10.208-17.438,4.288-25.726 C252.285,193.373,218.606,176.029,182.946,176.029z"></path> <path d="M182.946,106.873c-50.938,0-99.694,21.749-133.77,59.67c-6.807,7.576-6.185,19.236,1.392,26.044 c3.523,3.166,7.929,4.725,12.32,4.725c5.051-0.001,10.082-2.063,13.723-6.116c27.091-30.148,65.849-47.439,106.336-47.439 s79.246,17.291,106.338,47.438c6.808,7.576,18.468,8.198,26.043,1.391c7.576-6.808,8.198-18.468,1.391-26.043 C282.641,128.621,233.883,106.873,182.946,106.873z"></path> <path d="M360.611,112.293c-47.209-48.092-110.305-74.577-177.665-74.577c-67.357,0-130.453,26.485-177.664,74.579 c-7.135,7.269-7.027,18.944,0.241,26.079c3.59,3.524,8.255,5.282,12.918,5.281c4.776,0,9.551-1.845,13.161-5.522 c40.22-40.971,93.968-63.534,151.344-63.534c57.379,0,111.127,22.563,151.343,63.532c7.136,7.269,18.812,7.376,26.08,0.242 C367.637,131.238,367.745,119.562,360.611,112.293z"></path> </g> </g></svg>
        </div>
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