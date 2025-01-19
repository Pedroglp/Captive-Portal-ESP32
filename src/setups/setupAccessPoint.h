#ifndef SETUPACCESSPOINT_H
#define SSETUPACCESSPOINT_H
#include <Arduino.h>  //not needed in the arduino ide

void startSoftAccessPoint(const IPAddress &localIP, const IPAddress &gatewayIP);

#endif