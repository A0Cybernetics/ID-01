/*
  // read onboard buttons
void onboardButtonPoll() {
  but1State = digitalRead(PIN_BUTTON_1);
  but2State = digitalRead(PIN_BUTTON_2);
}
*/

  // debounced and throttled onboard button fn accepts void functions for button actions
  // to use, use name with no (), void functions only
  //example: onboardButtonsDT(incNeokeyBrightness, incNeopixelColorMode);
  /* for functions like
  //incNeokeyKeysMode();
  //incDepthCharArr0();
  //incDepthCharArr1();
  //incDepthCharArr2();
  //incDepthCharArr3();
  //incDepthCharArr4();
  //incNeokyColorMode();
  //incNeokeyBrightness();
  //incNeokeyColorSlow()
  //incNeokeyColorArr0();
  //incNeokeyColorArr1();
  //incNeokeyColorArr2();
  //incNeokeyColorArr3();
  //incNeokeyColorArr4();
  //BLEKeyboardToggle();
  //USBKeyboardToggle();
  //SerialDepthToggle();
  */
void onboardButtonsDT(void (*but1Action)(), void (*but2Action)()) {
    //onboardButtonPoll();  //checks onboard button states and updates
  but1State = digitalRead(PIN_BUTTON_1);
  but2State = digitalRead(PIN_BUTTON_2);
    // button 1 actions
	if (but1State != but1StateLast) {
    but1StateLast = but1State;
		but1NextDebounceTime = millis() + butDebounceDelay;
	}
	else if (but1State == 0) {
    currentTime = millis();
	  if (but1HoldFlag == 0) {
			if (currentTime > but1NextDebounceTime) {
				  // button 1 keydown past debounce
				but1Action();
				but1HoldFlag = 1;
        but1NextHoldTime = currentTime + butHoldDelay;
			}
		}
		else if (but1HoldFlag == 1) {
			if (currentTime > but1NextHoldTime) {
				  // button 1 held down past hold
        but1Action();
				but1NextHoldTime = currentTime + butHoldDelay;
			}
		}
	}
	else if (but1HoldFlag == 1) {
		if (but1State == 1) {
      currentTime = millis();
			if (currentTime > but1NextDebounceTime) {
				  // button 1 keyup past debounce
				but1HoldFlag = 0;
			}
		}
	}

  //button 2 actions
	if (but2State != but2StateLast) {
    but2StateLast = but2State;
		but2NextDebounceTime = millis() + butDebounceDelay;
	}
	else if (but2State == 0) {
    currentTime = millis();
	  if (but2HoldFlag == 0) {
			if (currentTime > but2NextDebounceTime) {
				  // button 2 keydown past debounce
        but2Action();
				but2HoldFlag = 1;
				but2NextHoldTime = currentTime + butHoldDelay;
			}
		}
		else if (but2HoldFlag == 1) {
			if (currentTime > but2NextHoldTime) {
				  // button 2 held down past hold
        but2Action();
				but2NextHoldTime = currentTime + butHoldDelay;
			}
		}
	}
	else if (but2HoldFlag == 1) {
		if (but2State == 1) {
      currentTime = millis();
			if (currentTime > but2NextDebounceTime) {
				  // button 2 keyup past debounce
				but2HoldFlag = 0;
			}
		}
	}
}

/*
void onboardButtonActionsTemplate()  {
  if (but1State != but1StateLast) {
    if (but1State == 0) {
      // button 1 keydown
    }
    else {
      // button 1 keyup
    }
    but1StateLast = but1State;
  }
  if (but2State != but2StateLast) {
    if (but2State == 0) {
      // button 2 keydown
    }
    else {
      // button 2 keyup
    }
    but2StateLast = but2State;
  }
}
*/
