#include <Arduino.h>  //not needed in the arduino ide
#include <DNSServer.h>
#include <settings.h>
#include <pages/getPage.h>
#include <setups/setUpWebServer.h>
#include <setups/setUpDNSSServer.h>
#include <setups/setupAccessPoint.h>

const IPAddress localIP(LOCAL_IP);		   // the IP address the web server, Samsung requires the IP to be in public space
const IPAddress gatewayIP(GATEWAY_IP);		   // IP address of the network should be the same as the local IP for captive portals
const IPAddress subnetMask(SUBNET_MASK);  // no need to change: https://avinetworks.com/glossary/subnet-mask/

DNSServer dnsServer;
AsyncWebServer server(WEB_SERVER_PORT);

void setup() {
	// Set the transmit buffer size for the Serial object and start it with a baud rate of 115200.
	Serial.setTxBufferSize(1024);
	Serial.begin(115200);

	// Wait for the Serial object to become available.
	while (!Serial)
		;

	// Print a welcome message to the Serial port.
	Serial.println("\n\nCaptive Test, V0.5.0 compiled " __DATE__ " " __TIME__ "\n");
	Serial.printf("%s-%d\n\r", ESP.getChipModel(), ESP.getChipRevision());

	startSoftAccessPoint(localIP, gatewayIP);
	setUpDNSServer(dnsServer, localIP);
	setUpWebServer(server, localIP);

	server.begin();

	Serial.print("Startup Time:");
	Serial.println(millis());
	Serial.print("\n");
}

void loop() {
	dnsServer.processNextRequest();
	delay(DNS_INTERVAL);	// seems to help with stability, if you are doing other things in the loop this may not be needed
}