#define BLYNK_TEMPLATE_ID   "user13"
#define BLYNK_TEMPLATE_NAME "user13@server.wyns.it"
#define BLYNK_AUTH_TOKEN "eAPSDQGiW7YEtrLvrbiWX9LYDEDHd_k6"

#define BLYNK_PRINT Serial
#include <WiFi.h> 
#include <BlynkSimpleEsp32.h>

char auth[] = "eAPSDQGiW7YEtrLvrbiWX9LYDEDHd_k6";
char ssid[] = "SasHome_5GHz";
char pass[] = "Quint4Willem5";

int relaypin = 4;
int ventilatorStatus = 0; // Variabele om de status van de ventilator bij te houden

void setup() {
    Serial.begin(115200);
    Blynk.begin(auth, ssid, pass, "server.wyns.it", 8081);
    pinMode(relaypin, OUTPUT);
}

void loop() {
    Blynk.run();
}

BLYNK_WRITE(V1) { // Functie die wordt aangeroepen wanneer de knopstatus verandert
    ventilatorStatus = param.asInt(); // Lees de nieuwe status van de knop
    digitalWrite(relaypin, ventilatorStatus); // Schakel de ventilator in of uit op basis van de knopstatus
}
