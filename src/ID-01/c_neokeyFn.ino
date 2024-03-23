//////////////////////////////////////////
////////// Main Neokey Functions /////////
//////////////////////////////////////////

  //sets up neokey call in main setup loop to start neokey
void neokeySetup() {
  while (! Neokey.begin(0x30)) {
    //Serial.println("Could not start NeoKey, check wiring?");
    tft.drawString("Could not start NeoKey...", 0, 0);
    tft.drawString("Check wiring?", 0, textHeight);
    delay(500);
    tft.fillScreen(backgroundColor);
  }
  //get # of neopixels/ keys
  numKeys = Neokey.pixels.numPixels();
  //setsup color array based on initial conditions
  updateKeyRGB32Bright(neokeyBrightness);
  //flash neokey lights on startup also provides delay for print
  flashNeokeyLeds();
  //Serial.println("NeoKey started!");
  //Serial.println((String)"Pixels: " + numKeys);
}

  //Main neokey function reads and sets vars, performs keys action, updates neokey leds
  //only need to call this to run neokey after neokeySetup
void neokeyFn() {
  neokeySetKeysDepth();     //gets new raw key reading formats it and sets new depth
  neokeyKeysWrite();        //write key on keypress
  //neokeyKeysFn();          //perform key actions based on neokeyKeyMode and neokeyCharArr
  neokeyColorFn();          //set neopixel color based on neokeyColorMode and neokeyColorArr
}


//////////////////////////////////////////
////////// neokeyKeysFunctions ///////////
//////////////////////////////////////////

  //gets new raw key reading formats it and sets new depth 0 = no buttons,4 = 4 is highest pressed
void neokeySetKeysDepth() {
  if (depthChangeFlag) {
    depthChangeFlag = 0;
    depthLast = depth;    // store depth as depthLast for next loop comparison
  }
  keysRaw = Neokey.read();
  if (keysRaw == keysRawLast) {
    return;
  }
  keysLast = keys;      // store keys as keysLast for comparison
  if (keysRaw & (1<<3)) {
    depth = 4;
    keys = 0b1111;
  }
  else if (keysRaw & (1<<2)) {
    depth = 3;
    keys = 0b0111;
  }
  else if (keysRaw & (1<<1)) {
    depth = 2;
    keys = 0b0011;
  }
  else if (keysRaw & (1<<0)) {
    depth = 1;
    keys = 0b0001;
  }
  else {
    depth = 0;
    keys = 0b0000;
  }
  keysRawLast = keysRaw;
  depthChangeFlag = (depth != depthLast);
}

  // increment key counts
void incKeyCount() {
  keyCountSession[depth-1]++; //increment key count
  keyCountTotal[depth-1]++; //increment total key count
}

  //key write actions on depth changed
void neokeyKeysWrite() {
  if (depthChangeFlag) {
    if (USBKeyboardState) {
      USBKeyboard.write(asciiCharArr[depthCharArr[depth]]);
    }
    if (BLEKeyboardState) {
      BLEKeyboard.write(asciiCharArr[depthCharArr[depth]]);
    }
    if (SerialDepthState) {
	    Serial.println((String) depth);
    }
    if (depth != 0) {
      incKeyCount();
      incXP();
    }
  }
}

/*
  //calls neokeyKeys function based on NeokeyKeysMode
void neokeyKeysFn() {
  switch (neokeyKeysMode){
    case 0:
      neokeyKeysWrite();
      break;
    case 1:
      neokeyKeysAll();
      break;
  }
}

  //key press and release actions on keys change
void neokeyKeysAll() {
	if (keys != keysLast) {
		for (uint16_t i=0; i < numKeys; i++) {
			if (keys & (1<<i)) {
				if (keysLast & (1<<i)) {
					// key i+1 held down
				}
				else {
						// key i+1 keydown
				}
			}
			else if (keysLast & (1<<i)) {
				// key i+1 keyup
			}
		}
	}
}

  //Velocity
unsigned long keyDistance = 1875;   //18.75mm => will /100
unsigned long vTime = ;   //time in ms between this keypress and last key press
long velocity = ;   //velocity of user as mm/ms + going deeper, - retracting
void velocity() {
  if (depthChangeFlag) {
    if (depthLast>0) {
      velocity = ((depth-depthLast)*keyDistance)/(time*100);
    }
    else {
      //unsure of distance if depthLast is 0
    }
  }
}
*/

//////////////////////////////////////////
///////// manipulate neokey vars /////////
//////////////////////////////////////////

  //cycle through asciiChars for keyCharArr[0]
void incDepthCharArr0() {
  if (depthCharArr[0] < asciiCharArrSize - 1) {
    depthCharArr[0]++;
  }
  else {
    depthCharArr[0] = 0;
  }
}

/*Serial.println(depthCharArr[0]);
if (depthCharArr[0] <= 93) {
  Serial.println(asciiCharArr[depthCharArr[0]]);
}
else if (depthCharArr[0] > 93) {
  switch (depthCharArr[0]) {
    case 94:
      Serial.println("Space");
      break;
    case 95:
      Serial.println("Right Arrow");
      break;
    case 96:
      Serial.println("Left Arrow");
      break;
    case 97:
      Serial.println("Down Arrow");
      break;
    case 98:
      Serial.println("Up Arrow");
      break;
  }
}*/

  //cycle through asciiChars for keyCharArr[1]
void incDepthCharArr1() {
  if (depthCharArr[1] < asciiCharArrSize - 1) {
    depthCharArr[1]++;
  }
  else {
    depthCharArr[1] = 0;
  }
}

  //cycle through asciiChars for keyCharArr[2]
void incDepthCharArr2() {
  if (depthCharArr[2] < asciiCharArrSize - 1) {
    depthCharArr[2]++;
  }
  else {
    depthCharArr[2] = 0;
  }
}

  //cycle through asciiChars for keyCharArr[3]
void incDepthCharArr3() {
  if (depthCharArr[3] < asciiCharArrSize - 1) {
    depthCharArr[3]++;
  }
  else {
    depthCharArr[3] = 0;
  }
}

  //cycle through asciiChars for keyCharArr[4]
void incDepthCharArr4() {
  if (depthCharArr[4] < asciiCharArrSize - 1) {
    depthCharArr[4]++;
  }
  else {
    depthCharArr[4] = 0;
  }
}

/*
  //increment through neokey keys modes
void incNeokeyKeysMode() {
  if (neokeyKeysMode < keysModesArraySize-1) {
    neokeyKeysMode ++;
  }
  else {
    neokeyKeysMode = 0;
  }
  //Serial.println((String) "Neokey Keys Mode : " + neokeyKeysModes[neokeyKeysMode]);
}
*/

//////////////////////////////////////////
////////// neokeyColorFunctions //////////
//////////////////////////////////////////

void neokeyColorFn () {
  if (neokeyBrightness == 0) {
    return;
  }
  switch (neokeyColorMode) {
    case 0:
      return;
    case 1:
      neokeySwirl();
      return;
    case 2:
      neokeySpectrum();
      return;
    case 3:
      neokeySpectrumSingle();
      return;
    case 4:
      neokeySolid();
      return;
    case 5:
      neokeySolidSingle();
      return;
    case 6:
      neokeySolidChange();
      return;
    case 7:
      neokeySolidChangeAll();
      return;
    case 8:
      neokeySolidIndividual();
      return;
    case 9:
      neokeySolidIndividualSingle();
      return;
    case 10:
      neokeyBreathe();
      return;
    case 11:
      neokeyBreatheSingle();
      return;
    case 12:
      neokeyBreatheChange();
      return;
    case 13:
      neokeyBreatheChangeAll();
      return;
    case 14:
      neokeyBreatheIndividual();
      return;
    case 15:
      neokeyBreatheIndividualSingle();
      return;
    case 16:
      neokeyStandbySwirl();
      return;
    case 17:
      neokeyStandbySpectrum();
      return;
    case 18:
      neokeyStandbySolid();
      return;
    case 19:
      neokeyStandbySolidIndividual();
      return;
    case 20:
      neokeyStandbyBreathe();
      return;
    case 21:
      neokeyStandbyBreatheIndividual();
      return;
  }
}

void wheelColorTimer() {
  currentTime = millis();
  colorChangeFlag = (currentTime > nextColorTime);
  if (colorChangeFlag) {
    neokeyWheelColor++;       // increment swirl color to make colors cycle
    nextColorTime = currentTime + neokeyColorSlow;
  }
}

void breatheBrightness0Timer() {
  currentTime = millis();
  colorChangeFlag = (currentTime > nextColorTime);
  if (colorChangeFlag) {
    neokeyCycleBreatheBrightness();
	  updateKeyRGB32Bright0(neokeyBrightnessBreathe);
    nextColorTime = currentTime + neokeyColorSlow;
  }
}

void breatheBrightnessTimer() {
  currentTime = millis();
  colorChangeFlag = (currentTime > nextColorTime);
  if (colorChangeFlag) {
    neokeyCycleBreatheBrightness();
	  updateKeyRGB32Bright(neokeyBrightnessBreathe);
    nextColorTime = currentTime + neokeyColorSlow;
  }
}

  //set pixel colors for swirl
void neokeySwirl() {
  if (!(depth == 0 & depthLast == 0)) {
    wheelColorTimer();
    if (depthChangeFlag || colorChangeFlag) {
      for (uint16_t i=0; i < numKeys; i++) {
        if (i < depth) {
          Neokey.pixels.setPixelColor(i, Wheel(((((numKeys-i) * 256 / numKeys) + neokeyWheelColor) & 255), neokeyBrightness));
        }
        else if (i < depthLast) {
          Neokey.pixels.setPixelColor(i, 0);
        }
        else {
          break;
        }
      }
      Neokey.pixels.show();     // turn on neopixel leds
    }
  }
}

	//set pixels synchronized cycle through spectrum
void neokeySpectrum() {
  if (!(depth == 0 & depthLast == 0)) {
    wheelColorTimer();
    if (depthChangeFlag || colorChangeFlag) {
      for (uint16_t i=0; i < numKeys; i++) {
        if (i < depth) {
          Neokey.pixels.setPixelColor(i, Wheel(neokeyWheelColor, neokeyBrightness));
        }
        else if (i < depthLast) {
          Neokey.pixels.setPixelColor(i, 0);
        }
        else {
          break;
        }
      }
      Neokey.pixels.show();
    }
  }
}

  //set pixel colors for spectrum single
void neokeySpectrumSingle() {
  if (!(depth == 0 & depthLast == 0)) {
    wheelColorTimer();
    if (depthChangeFlag || colorChangeFlag) {
      if (depth > 0) {
        Neokey.pixels.setPixelColor(depth-1, Wheel(neokeyWheelColor, neokeyBrightness));
      }
      if ((depthChangeFlag) & (depthLast > 0)) {
        Neokey.pixels.setPixelColor(depthLast-1, 0);
      }
      Neokey.pixels.show();
    }
  }
}

  //set pixel colors for solid
void neokeySolid() {
  if (depthChangeFlag) {
    for (uint16_t i=0; i < numKeys; i++) {
      if (i < depth) {
        Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[0]);
      }
      else if (i < depthLast) {
        Neokey.pixels.setPixelColor(i, 0);
      }
      else {
        break;
      }
    }
  Neokey.pixels.show();
  }
}

  //set pixel colors for solid single depth
void neokeySolidSingle() {
	if (depthChangeFlag) {
		if (depth > 0) {
			Neokey.pixels.setPixelColor(depth-1 , keyRGB32BrightColorArr[0]);
		}
		if (depthLast > 0) {
			Neokey.pixels.setPixelColor(depthLast-1, 0);
		}
		Neokey.pixels.show();
    }
}

  //set pixel colors for solid depth change colors all on
void neokeySolidChangeAll() {
	if (depthChangeFlag) {
		for (uint16_t i=0; i < numKeys; i++) {
      switch (depth) {
			  case 0:
		      Neokey.pixels.setPixelColor(i, 0);
          break;
        case 1:
          Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[1]);
          break;
        case 2:
          Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[2]);
          break;
        case 3:
          Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[3]);
          break;
        case 4:
          Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[4]);
          break;
      }
		}
		Neokey.pixels.show();
	}
}

  //set pixel colors for solid depth change colors
void neokeySolidChange() {
	if (depthChangeFlag) {
		for (uint16_t i=0; i < numKeys; i++) {
			if (i < depth) {
          switch (depth) {
            case 1:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[1]);
              break;
            case 2:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[2]);
              break;
            case 3:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[3]);
              break;
            case 4:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[4]);
              break;
          }
			}
			else if (i < depthLast) {
				Neokey.pixels.setPixelColor(i, 0);
			}
      else {
        break;
      }
		}
	Neokey.pixels.show();
	}
}

  //set pixel colors for solid individual preset colors <depth, skip depth last
void neokeySolidIndividual() {
	if (depthChangeFlag) {
		for (uint16_t i=0; i < numKeys; i++) {
			if (i < depth) {
        if (i+1 > depthLast) {
          switch (i+1) {
            case 1:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[1]);
              break;
            case 2:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[2]);
              break;
            case 3:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[3]);
              break;
            case 4:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[4]);
              break;
          }
				}
			}
			else if (i < depthLast) {
				Neokey.pixels.setPixelColor(i, 0);
			}
      else {
        break;
      }
		}
	Neokey.pixels.show();
	}
}

  //set pixel colors, single pixel individual preset colors
void neokeySolidIndividualSingle() {
	if (depthChangeFlag) {
		if (depth > 0) {
			switch (depth) {
        case 1:
          Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[1]);
          break;
        case 2:
          Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[2]);
          break;
        case 3:
          Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[3]);
          break;
        case 4:
          Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[4]);
          break;
			}
		}
		if (depthLast > 0) {
			Neokey.pixels.setPixelColor(depthLast-1 , 0);
		}
    Neokey.pixels.show();
	}
}

	//set pixel colors for breathing
void neokeyBreathe() {
  if (!(depth == 0 & depthLast == 0)) {
    breatheBrightness0Timer();
    if (depthChangeFlag || colorChangeFlag) {
      for (uint16_t i=0; i<numKeys; i++) {
        if (i < depth) {
          Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[0]);
        }
        else if (i < depthLast) {
          Neokey.pixels.setPixelColor(i, 0);
        }
        else {
          break;
        }
      }
      Neokey.pixels.show();
    }
  }
}

	//set pixel colors for breathe single
void neokeyBreatheSingle() {
  if (!(depth == 0 & depthLast == 0)) {
    breatheBrightness0Timer();
    if (depthChangeFlag || colorChangeFlag) {
      if (depth > 0) {
        Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[0]);
      }
      if ((depthChangeFlag) & (depthLast > 0)) {
        Neokey.pixels.setPixelColor(depthLast-1, 0);
      }
      Neokey.pixels.show();
    }
  }
}

	//set pixel colors for breathing single individual preset colors
void neokeyBreatheIndividualSingle() {
  if (!(depth == 0 & depthLast == 0)) {
    breatheBrightnessTimer();
    if (depthChangeFlag || colorChangeFlag) {
      if (depth > 0) {
        switch (depth) {
          case 1:
            Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[1]);
            break;
          case 2:
            Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[2]);
            break;
          case 3:
            Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[3]);
            break;
          case 4:
            Neokey.pixels.setPixelColor(depth-1, keyRGB32BrightColorArr[4]);
            break;
        }
      }
      if ((depthChangeFlag) & (depthLast > 0)) {
        Neokey.pixels.setPixelColor(depthLast-1, 0);
      }
      Neokey.pixels.show();
    }
  }
}

	//set pixel colors for breathing individual preset colors
void neokeyBreatheIndividual() {
  if (!(depth == 0 & depthLast == 0)) {
    breatheBrightnessTimer();
    if (depthChangeFlag || colorChangeFlag) {
      for (uint16_t i=0; i<numKeys; i++) {
        if (i < depth) {
          switch (i+1) {
            case 1:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[1]);
              break;
            case 2:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[2]);
              break;
            case 3:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[3]);
              break;
            case 4:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[4]);
              break;
          }
        }
        else if (i < depthLast) {
          Neokey.pixels.setPixelColor(i, 0);
        }
        else {
          break;
        }
      }
      Neokey.pixels.show();
    }
  }
}

	//set pixel colors for breathing depth change preset colors
void neokeyBreatheChange() {
  if (!(depth == 0 & depthLast == 0)) {
    breatheBrightnessTimer();
    if (depthChangeFlag || colorChangeFlag) {
      for (uint16_t i=0; i<numKeys; i++) {
        if (i < depth) {
          switch (depth) {
            case 1:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[1]);
              break;
            case 2:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[2]);
              break;
            case 3:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[3]);
              break;
            case 4:
              Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[4]);
              break;
          }
        }
        else if (i < depthLast) {
          Neokey.pixels.setPixelColor(i, 0);
        }
        else {
          break;
        }
      }
      Neokey.pixels.show();
    }
  }
}

	//set pixel colors for all breathing depth change preset colors
void neokeyBreatheChangeAll() {
  if (!(depth == 0 & depthLast == 0)) {
    breatheBrightnessTimer();
    if (depthChangeFlag || colorChangeFlag) {
      for (uint16_t i=0; i<numKeys; i++) {
        switch (depth) {
          case 0:
            Neokey.pixels.setPixelColor(i, 0);
            break;
          case 1:
            Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[1]);
            break;
          case 2:
            Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[2]);
            break;
          case 3:
            Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[3]);
            break;
          case 4:
            Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[4]);
            break;
        }
      }
      Neokey.pixels.show();
    }
  }
}

//////////////////Standby Color Fns
  //set pixel colors for standby swirl
void neokeyStandbySwirl() {
  wheelColorTimer();
  if (colorChangeFlag) {
    for (uint16_t i=0; i < numKeys; i++) {
      Neokey.pixels.setPixelColor(i, Wheel(((((numKeys-i) * 256 / numKeys) + neokeyWheelColor) & 255), neokeyBrightness));
    }
    Neokey.pixels.show();
  }
}

	//set pixel colors standby synchronized cycle through spectrum
void neokeyStandbySpectrum() {
  wheelColorTimer();
  if (colorChangeFlag) {
    for (uint16_t i=0; i < numKeys; i++) {
        Neokey.pixels.setPixelColor(i, Wheel(neokeyWheelColor, neokeyBrightness));
    }
    Neokey.pixels.show();
  }
}

  //set pixel colors for standby solid
void neokeyStandbySolid() {
if (standbyColorFlag == 0) {
    Neokey.pixels.setPixelColor(0, keyRGB32BrightColorArr[0]);
		Neokey.pixels.setPixelColor(1, keyRGB32BrightColorArr[0]);
		Neokey.pixels.setPixelColor(2, keyRGB32BrightColorArr[0]);
		Neokey.pixels.setPixelColor(3, keyRGB32BrightColorArr[0]);
	  Neokey.pixels.show();
	  standbyColorFlag = 1;
  }
}

  //set pixel colors for standby solid individual
void neokeyStandbySolidIndividual() {
	if (standbyColorFlag == 0) {
		Neokey.pixels.setPixelColor(0, keyRGB32BrightColorArr[1]);
		Neokey.pixels.setPixelColor(1, keyRGB32BrightColorArr[2]);
		Neokey.pixels.setPixelColor(2, keyRGB32BrightColorArr[3]);
		Neokey.pixels.setPixelColor(3, keyRGB32BrightColorArr[4]);
		Neokey.pixels.show();
		standbyColorFlag = 1;
	}
}

	//set pixel colors for standby breathe
void neokeyStandbyBreathe() {
  breatheBrightness0Timer();
  if (colorChangeFlag) {
    Neokey.pixels.setPixelColor(0, keyRGB32BrightColorArr[0]);
    Neokey.pixels.setPixelColor(1, keyRGB32BrightColorArr[0]);
    Neokey.pixels.setPixelColor(2, keyRGB32BrightColorArr[0]);
    Neokey.pixels.setPixelColor(3, keyRGB32BrightColorArr[0]);
    Neokey.pixels.show();
  }
}

	//set pixel colors for standby breathe individual preset colors
void neokeyStandbyBreatheIndividual() {
  breatheBrightnessTimer();
  if (colorChangeFlag) {
    Neokey.pixels.setPixelColor(0, keyRGB32BrightColorArr[1]);
    Neokey.pixels.setPixelColor(1, keyRGB32BrightColorArr[2]);
    Neokey.pixels.setPixelColor(2, keyRGB32BrightColorArr[3]);
    Neokey.pixels.setPixelColor(3, keyRGB32BrightColorArr[4]);
    Neokey.pixels.show();
  }
}




  //flash neokeyleds for startup
void flashNeokeyLeds () {
  for (uint16_t i=0; i<numKeys; i++) {
    Neokey.pixels.setPixelColor(i, keyRGB32BrightColorArr[i+1]);
    //Neokey.pixels.setPixelColor(i, Wheel(map(i, 0, numKeys, 0, 255), neokeyBrightnessMax));
    Neokey.pixels.show();
    delay(100);
  }
  for (uint16_t i=0; i<numKeys; i++) {
    Neokey.pixels.setPixelColor(i, 0x000000);
    Neokey.pixels.show();
    delay(100);
  }
}

  //reset/ initialize color vars neopixels
void resetNeokeyColors() {
  neokeyBrightnessBreathe = neokeyBrightness;
  updateKeyRGB32Bright(neokeyBrightness);
  neokeyWheelColor = 0;
  breatheFlag = 0;
  standbyColorFlag = 0;
  for (uint16_t i=0; i<numKeys; i++) {
    Neokey.pixels.setPixelColor(i, 0);
  }
  Neokey.pixels.show();
}

  //cycle through color modes
void incNeokeyColorMode () {
  if (neokeyColorMode < neokeyColorModeMax-1) {
		neokeyColorMode++;
    }
	else {
		neokeyColorMode = 0;
	}
  resetNeokeyColors();
    //Serial.println((String) "Color Mode : " + neokeyColorMode);
}

  //change neokey brightness
void incNeokeyBrightness() {
	uint8_t increment = 5;
	if (neokeyBrightness < (neokeyBrightnessMax-increment+1)) {
		neokeyBrightness += increment;
	}
	else {
		neokeyBrightness = 0;
	}
	resetNeokeyColors();
	//Serial.println((String) "Neokey Brightness : " + neokeyBrightness);
}

  //inc/dec brightness for breathe fns
void neokeyCycleBreatheBrightness() {
    if (breatheFlag == 0) {
    	// decrement brightness to fade
      neokeyBrightnessBreathe --;
      if (neokeyBrightnessBreathe == neokeyBrightnessMin) {
        breatheFlag = 1;
		  }
    }
	  else {
        //increment brightness to brighten
      neokeyBrightnessBreathe ++;
      if (neokeyBrightnessBreathe == neokeyBrightness) {
        breatheFlag = 0;
      }
	  }
}

  // Input a value 0 to 255 to get a color value.
  // The colors are a transition r - g - b - back to r.
  //* modified to add brightness control
uint32_t Wheel(uint8_t WheelPos, uint8_t brightness) {
  if (brightness == 0) {
    return 0;
  }
  else if(WheelPos < 85) {
    return seesaw_NeoPixel::Color((brightness * WheelPos * 3)/neokeyBrightnessMax, (brightness * (255 - WheelPos * 3)/neokeyBrightnessMax), 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return seesaw_NeoPixel::Color((brightness * (255 - WheelPos * 3)/neokeyBrightnessMax), 0, (brightness * WheelPos * 3)/neokeyBrightnessMax);
  } else {
   WheelPos -= 170;
   return seesaw_NeoPixel::Color(0, (brightness * WheelPos * 3)/neokeyBrightnessMax, (brightness * (255 - WheelPos * 3)/neokeyBrightnessMax));
  }
  return 0;
}
