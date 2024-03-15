  // read onboard buttons
void onboardButtonPoll() {
  but1State = digitalRead(PIN_BUTTON_1);
  but2State = digitalRead(PIN_BUTTON_2);
}

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
  currentTime = millis();
  onboardButtonPoll();  //checks onboard button states and updates
  // button 1 actions
	if (but1State != but1StateLast) {
    but1StateLast = but1State;
		but1LastDebounceTime = currentTime;
	}
	else if (but1State == 0) {
	  if (but1HoldFlag == 0) {
			if ((currentTime - but1LastDebounceTime) > but1DebounceDelay) {
				  // button 1 keydown past debounce
				but1Action();
				but1HoldFlag = 1;
        but1LastHoldTime = currentTime;
			}
		}
		else if (but1HoldFlag == 1) {
			if ((currentTime - but1LastHoldTime) > but1HoldDelay) {
				  // button 1 held down past hold
        but1Action();
				but1LastHoldTime = currentTime;
			}
		}
	}
	else if (but1HoldFlag == 1) {
		if (but1State == 1) {
			if ((currentTime - but1LastDebounceTime) > but1DebounceDelay) {
				  // button 1 keyup past debounce
				but1HoldFlag = 0;
			}
		}
	}

  //button 2 actions
	if (but2State != but2StateLast) {
    but2StateLast = but2State;
		but2LastDebounceTime = currentTime;
	}
	else if (but2State == 0) {
	  if (but2HoldFlag == 0) {
			if ((currentTime - but2LastDebounceTime) > but2DebounceDelay) {
				  // button 2 keydown past debounce
        but2Action();
				but2HoldFlag = 1;
				but2LastHoldTime = currentTime;
			}
		}
		else if (but2HoldFlag == 1) {
			if ((currentTime - but2LastHoldTime) > but2HoldDelay) {
				  // button 2 held down past hold
        but2Action();
				but2LastHoldTime = currentTime;
			}
		}
	}
	else if (but2HoldFlag == 1) {
		if (but2State == 1) {
			if ((currentTime - but2LastDebounceTime) > but2DebounceDelay) {
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
