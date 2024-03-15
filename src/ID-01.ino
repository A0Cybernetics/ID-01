//Screen  *have to modify User_Setup_Select.h to select board (T DIsplay S3): comment out line 27, uncomment line 133
// https://github.com/Bodmer/TFT_eSPI
#include "TFT_eSPI.h"
#include "User_Setup_Select.h"
TFT_eSPI tft = TFT_eSPI();

//Prefrences library for saving data to onboard flash
// https://github.com/espressif/arduino-esp32
// https://docs.espressif.com/projects/arduino-esp32/en/latest/api/preferences.html
#include <Preferences.h>
Preferences preferences;

// Neokey
// https://github.com/adafruit/Adafruit_Seesaw
// https://learn.adafruit.com/neokey-1x4-qt-i2c
#include "Adafruit_NeoKey_1x4.h"
#include "seesaw_neopixel.h"
Adafruit_NeoKey_1x4 Neokey;

//USB wired keyboard
// https://github.com/espressif/arduino-esp32/tree/master/libraries/USB/src
#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard USBKeyboard;

//BLE keyboard **dependent on NIMBLE for arduino. Have to edit BleKeyboard.h to enable NIMBLE: uncomment line 2
//BLEkeyboard: https://github.com/T-vK/ESP32-BLE-Keyboard
//NIMBLE: https://github.com/h2zero/NimBLE-Arduino
#include <BleKeyboard.h>  //comment out line 37-86 and rename keyReport to BLEKeyReport to prevent conflicts with USBHIDKeyboard
BleKeyboard BLEKeyboard("ID-01", "A0", 100); //BleKeyboard bleKeyboard("Bluetooth Device Name", "Bluetooth Device Manufacturer", 100)


//QWIIC pin defs
#define PIN_QWIIC_SDA 43
#define PIN_QWIIC_SCL 44

//onboard button pin defs
#define PIN_BUTTON_1 14
#define PIN_BUTTON_2 0

//tft power pin
#define PIN_POWER_ON 15

//battery voltage analog
#define PIN_BAT_VOLT 4


void setup() {
  Serial.begin(115200);

  //setup onboard buttons
  pinMode(PIN_BUTTON_1, INPUT_PULLUP);
  pinMode(PIN_BUTTON_2, INPUT_PULLUP);

  //start wire for QWIIC I2C
  Wire.begin(PIN_QWIIC_SDA, PIN_QWIIC_SCL);
  
  //load preferences to set vars
  loadPreferences();

  //tft screen setup before others so can use screen for errors before drawing first menu
  tftSetup();
  
  //neokey Startup sequence
  neokeySetup();

  //play startup tft animation
  drawA0Animation(85, 159, 10);

  //start menu on a page.
  mainMenuSelect();
  //statsSelect();
  //settingsSelect();
  //sessionSelect();
}


void loop() {
  neokeyFn();
  menuFn();
}
