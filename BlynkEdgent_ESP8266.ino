#define BLYNK_FIRMWARE_VERSION "1.0.0"
#define BLYNK_TEMPLATE_ID "...."
#define BLYNK_TEMPLATE_NAME "...."

#define BLYNK_PRINT Serial

#include "BlynkEdgent.h"

// Pin Definitions
const int RelayPin1 = D1;
const int RelayPin2 = D2;
const int RelayPin3 = D3;  // New
const int RelayPin4 = D4;  // New

// Virtual Pins
#define VPIN_BUTTON_1 V1
#define VPIN_BUTTON_2 V2
#define VPIN_BUTTON_3 V3  // New
#define VPIN_BUTTON_4 V4  // New
#define VPIN_MEMORY_CONTROL V0

bool toggleState_1 = LOW;
bool toggleState_2 = LOW;
bool toggleState_3 = LOW;  // New
bool toggleState_4 = LOW;  // New

// Blynk Handlers
BLYNK_CONNECTED() {
  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
  Blynk.syncVirtual(VPIN_BUTTON_3);  // New
  Blynk.syncVirtual(VPIN_BUTTON_4);  // New
  Blynk.syncVirtual(VPIN_MEMORY_CONTROL);
}

BLYNK_WRITE(VPIN_BUTTON_1) {
  toggleState_1 = param.asInt();
  digitalWrite(RelayPin1, toggleState_1 ? LOW : HIGH);
  saveV1(toggleState_1);
}

BLYNK_WRITE(VPIN_BUTTON_2) {
  toggleState_2 = param.asInt();
  digitalWrite(RelayPin2, toggleState_2 ? LOW : HIGH);
  saveV2(toggleState_2);
}

BLYNK_WRITE(VPIN_BUTTON_3) {  // New
  toggleState_3 = param.asInt();
  digitalWrite(RelayPin3, toggleState_3 ? LOW : HIGH);
  saveV3(toggleState_3);
}

BLYNK_WRITE(VPIN_BUTTON_4) {  // New
  toggleState_4 = param.asInt();
  digitalWrite(RelayPin4, toggleState_4 ? LOW : HIGH);
  saveV4(toggleState_4);
}

BLYNK_WRITE(VPIN_MEMORY_CONTROL) {
  uint8_t value = param.asInt();
  saveV0(value);
}

void restoreRelaysOnBoot() {
  Serial.println("Restore begin");
  uint8_t v0, v1, v2, v3, v4;
  loadSavedStates(v0, v1, v2, v3, v4);

  if (v0 == 1) {
    digitalWrite(RelayPin1, v1 ? LOW : HIGH);
    digitalWrite(RelayPin2, v2 ? LOW : HIGH);
    digitalWrite(RelayPin3, v3 ? LOW : HIGH);  // New
    digitalWrite(RelayPin4, v4 ? LOW : HIGH);  // New
    Serial.println("V0 is HIGH, device controlled");
  } else {
    digitalWrite(RelayPin1, HIGH);
    digitalWrite(RelayPin2, HIGH);
    digitalWrite(RelayPin3, HIGH);  // New
    digitalWrite(RelayPin4, HIGH);  // New
  }
  Serial.println("Restore end");
}

// Setup
void setup() {
  Serial.begin(115200);
  EEPROM.begin(512);      // Init EEPROM early, once only

  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(RelayPin3, OUTPUT);  // New
  pinMode(RelayPin4, OUTPUT);  // New

  restoreRelaysOnBoot();  // Restore before Blynk connects

  BlynkEdgent.begin();    // This will use EEPROM but it’s already ready
}

// Loop
void loop() {
  BlynkEdgent.run();
}
