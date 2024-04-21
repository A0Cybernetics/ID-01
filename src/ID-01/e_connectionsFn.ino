    //starts USB keyboard mode pauses sending keys when BLEKeyboardState = 0
void USBKeyboardToggle() {
  if (SerialDepthState) {return;} //usb and serial dont work at same time
  if (!USBKeyboardState) {
    if (!USBKeyboardStarted) {
      USBKeyboard.begin();
      USB.begin();
      USBKeyboardStarted = 1;
    }
    USBKeyboardState = 1;
    //Serial.println("USB Keyboard Started");
    return;
  }
  else if (USBKeyboardState) {
    USBKeyboardState = 0;
    //Serial.println("USB Keyboard Paused");
    return;
  }
}

  //starts and pairs bt once, pauses sending keys when BLEKeyboardState = 0
  //have to reset to fully turn off bt radio after toggling on
  //can stop with btStop() but to reconnect have to reset whole device
  //find better blekeyboard lib or write own fn
void BLEKeyboardToggle() {
  if (!BLEKeyboardState) {
    if (!BLEKeyboardStarted) {
      BLEKeyboard.begin();
      BLEKeyboardStarted = 1;
    }
    //Serial.println("BLE Keyboard Started");
    BLEKeyboardState = 1;
    return;
  }
  else if (BLEKeyboardState) {
    BLEKeyboardState = 0;
    //Serial.println("BLE Keyboard Paused");
    return;
  }
}

/*
void BLEKeyboardToggleTest() {
  if (!BLEKeyboardState) {
    //if (!BLEKeyboardStarted) {
      bleKeyboard.begin();
      //BLEKeyboardStarted = 1;
    //}
    BLEKeyboardState = 1;
    return;
  }
  else if (BLEKeyboardState) {
    btStop();                   //shuts down bt but cant restart
    BLEKeyboardState = 0;
    return;
  }
}
*/

    //starts serial depth log mode stops sending depth when SerialDepthState = 0
void SerialDepthToggle() {
  if (USBKeyboardStarted) {return;} //serial depth log wont work after starting usb keyboard
  if (!SerialDepthState) {
    SerialDepthState = 1;
    //Serial.println("Serial Depth Logging Started");
    return;
  }
  else if (SerialDepthState) {
    SerialDepthState = 0;
    //Serial.println("Serial Depth Logging Stopped");
    return;
  }
}
