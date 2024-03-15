//////////////////////////////////////////
//////         Menu options        ///////
//////////////////////////////////////////
struct menuOption {
  bool selectable;    //set true to make an option selectible by inc options
	String (*text)();   //returns the text to write for option line in menu
  void (*function)(); //performs action of selecting option
};

void emptyFn() {return;}  //empty fn to fill fn spot for options that arent selectable and have no fn

//////////////////////////////////////////
///////// Main Menu Page Options  ////////
//////////////////////////////////////////
menuOption mainMenuOption {
  1,
  mainMenuOptionText,
  mainMenuOptionSelect,
};

String mainMenuOptionText() {
  return "Main Menu";
}

void mainMenuOptionSelect() {
  mainMenuSelect();
}

//////////////////////////////////////////
////////// Connection Options  ///////////
//////////////////////////////////////////
menuOption BLEOption {
  1,
  BLEOptionText,
  toggleBLEOption,
};

String BLEOptionText() {
  if (!BLEKeyboardState & !BLEKeyboardStarted) {
    return "BLE Keyboard : OFF        ";
  }
  else if (!BLEKeyboardState) {
    return "BLE Keyboard : PAUSED    ";
  }
  else {
    return "BLE Keyboard : ON         ";
  }
}

void toggleBLEOption() {
  BLEKeyboardToggle();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption USBOption {
  1,
  USBOptionText,
  toggleUSBOption,
};

String USBOptionText() {
  if (!USBKeyboardState & !USBKeyboardStarted) {
    return "USB Keyboard : OFF        ";
  }
  else if (!USBKeyboardState) {
    return "USB Keyboard : PAUSED    ";
  }
  else {
    return "USB Keyboard : ON         ";
  }
}

void toggleUSBOption() {
  USBKeyboardToggle();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption SerialDepthOption {
  1,
  SerialDepthOptionText,
  toggleSerialDepthOption,
};

String SerialDepthOptionText() {
  if (!SerialDepthState) {
    return "Serial Depth Log : OFF     ";
  }
  else {
    return "Serial Depth Log : ON      ";
  }
}

void toggleSerialDepthOption() {
  SerialDepthToggle();
  drawMenuOptionSelected(menuOptionSelected);
}
//////////////////////////////////////////
////////////// Save Option ///////////////
//////////////////////////////////////////
menuOption saveOption {
  1,
  saveOptionText,
  saveOptionSelect,
};

String saveOptionText() {
  return "Save";
}

void saveOptionSelect() {
  prepareSavePreferences();
  savePreferences();
  mainMenuDraw();
}

//////////////////////////////////////////
////////////// XP Counters ///////////////
//////////////////////////////////////////
menuOption sessionXPOption {
  0,
  sessionXPOptionText,
  emptyFn,
};

String sessionXPOptionText() {
  return ((String) "Session XP: " + sessionXP);
}

menuOption savedXPOption {
  0,
  savedXPOptionText,
  emptyFn,
};

String savedXPOptionText() {
  return ((String) "Saved XP: " + savedXP);
}

menuOption totalXPOption {
  0,
  totalXPOptionText,
  emptyFn,
};

String totalXPOptionText() {
  return ((String) "Total XP: " + totalXP);
}

//////////////////////////////////////////
/////////// Stats Page Options ///////////
//////////////////////////////////////////
menuOption statsOption {
  1,
  statsOptionText,
  statsOptionSelect,
};

String statsOptionText() {
  return "Stats";
}

void statsOptionSelect() {
  statsSelect();
}

menuOption key1CountTotalOption {
  0, 
  key1CountTotalOptionText,
  emptyFn,
};

String key1CountTotalOptionText() {
  return ((String) "D1 Total: " + keyCountTotal[0]);
}

menuOption key2CountTotalOption {
  0,
  key2CountTotalOptionText,
  emptyFn,
};

String key2CountTotalOptionText() {
  return ((String) "D2 Total: " + keyCountTotal[1]);
}

menuOption key3CountTotalOption {
  0,
  key3CountTotalOptionText,
  emptyFn,
};

String key3CountTotalOptionText() {
  return ((String) "D3 Total: " + keyCountTotal[2]);
}

menuOption key4CountTotalOption {
  0,
  key4CountTotalOptionText,
  emptyFn,
};

String key4CountTotalOptionText() {
  return ((String) "D4 Total: " + keyCountTotal[3]);
}

//////////////////////////////////////////
////////// Session page options  /////////
//////////////////////////////////////////
menuOption sessionOption {
  1,
  sessionOptionText,
  sessionOptionSelect,
};

String sessionOptionText() {
  return "Session Screen";
}

void sessionOptionSelect() {
  sessionSelect();
}


//////////////////////////////////////////
/////// Session Key Press Counters ///////
//////////////////////////////////////////
menuOption key1CountOption {
  0,
  key1CountOptionText,
  emptyFn,
};

String key1CountOptionText() {
  return ((String) "D1 Count: " + keyCountSession[0]);
}

menuOption key2CountOption {
  0,
  key2CountOptionText,
  emptyFn,
};

String key2CountOptionText() {
  return ((String) "D2 Count: " + keyCountSession[1]);
}

menuOption key3CountOption {
  0,
  key3CountOptionText,
  emptyFn,
};

String key3CountOptionText() {
  return ((String) "D3 Count: " + keyCountSession[2]);
}

menuOption key4CountOption {
  0,
  key4CountOptionText,
  emptyFn,
};

String key4CountOptionText() {
  return ((String) "D4 Count: " + keyCountSession[3]);
}


//////////////////////////////////////////
////////// Settings Page Options /////////
//////////////////////////////////////////
menuOption settingsOption {
  1,
  settingsOptionText,
  settingsOptionSelect,
};

String settingsOptionText() {
  return "Settings";
}

void settingsOptionSelect() {
  settingsSelect();
}

//////////////////////////////////////////
/////////// Char Array Options ///////////
//////////////////////////////////////////
menuOption depthCharArr0Option {
  1,
  depthCharArr0OptionText,
  depthCharArr0OptionSelect,
};

String depthCharArr0OptionText() {
	if (depthCharArr[0] <= 93) {
    return ((String) "D0: " + asciiCharArr[depthCharArr[0]]+ "                        ");
	}
	else if (depthCharArr[0] > 93) {
		switch (depthCharArr[0]) {
      case 94:	// Space
			//Serial.println("Space");
			return ((String) "D0: " + "Space" + "                   ");
		  case 95:	// Right Arrow
			//Serial.println("Right Arrow");
			return ((String) "D0: " + "Right Arrow" + "            ");
		  case 96:	// Left Arrow
			//Serial.println("Left Arrow");
			return ((String) "D0: " + "Left Arrow" + "             ");
		  case 97:	// Down Arrow
			//Serial.println("Down Arrow");
			return ((String) "D0: " + "Down Arrow" + "            ");
		  case 98:	// Up Arrow
			//Serial.println("Up Arrow");
			return ((String) "D0: " + "Up Arrow" + "               ");
	  }
  }
}

void depthCharArr0OptionSelect() {
  incDepthCharArr0();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption depthCharArr1Option {
  1,
  depthCharArr1OptionText,
  depthCharArr1OptionSelect,
};

String depthCharArr1OptionText() {
	if (depthCharArr[1] <= 93) {
    return ((String) "D1: " + asciiCharArr[depthCharArr[1]]+ "                        ");
	}
	else if (depthCharArr[1] > 93) {
		switch (depthCharArr[1]) {
      case 94:	// Space
			return ((String) "D1: " + "Space" + "                   ");
		  case 95:	// Right Arrow
			return ((String) "D1: " + "Right Arrow" + "            ");
		  case 96:	// Left Arrow
			return ((String) "D1: " + "Left Arrow" + "             ");
		  case 97:	// Down Arrow
			return ((String) "D1: " + "Down Arrow" + "            ");
		  case 98:	// Up Arrow
			return ((String) "D1: " + "Up Arrow" + "               ");
	  }
  }
}

void depthCharArr1OptionSelect() {
  incDepthCharArr1();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption depthCharArr2Option {
  1,
  depthCharArr2OptionText,
  depthCharArr2OptionSelect,
};

String depthCharArr2OptionText() {
	if (depthCharArr[2] <= 93) {
    return ((String) "D2: " + asciiCharArr[depthCharArr[2]]+ "                        ");
	}
	else if (depthCharArr[2] > 93) {
		switch (depthCharArr[2]) {
      case 94:	// Space
			return ((String) "D2: " + "Space" + "                   ");
		  case 95:	// Right Arrow
			return ((String) "D2: " + "Right Arrow" + "            ");
		  case 96:	// Left Arrow
			return ((String) "D2: " + "Left Arrow" + "             ");
		  case 97:	// Down Arrow
			return ((String) "D2: " + "Down Arrow" + "            ");
		  case 98:	// Up Arrow
			return ((String) "D2: " + "Up Arrow" + "               ");
	  }
  }
}

void depthCharArr2OptionSelect() {
  incDepthCharArr2();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption depthCharArr3Option {
  1,
  depthCharArr3OptionText,
  depthCharArr3OptionSelect,
};

String depthCharArr3OptionText() {
	if (depthCharArr[3] <= 93) {
    return ((String) "D3: " + asciiCharArr[depthCharArr[3]]+ "                        ");
	}
	else if (depthCharArr[3] > 93) {
		switch (depthCharArr[3]) {
      case 94:	// Space
			return ((String) "D3: " + "Space" + "                   ");
		  case 95:	// Right Arrow
			return ((String) "D3: " + "Right Arrow" + "            ");
		  case 96:	// Left Arrow
			return ((String) "D3: " + "Left Arrow" + "             ");
		  case 97:	// Down Arrow
			return ((String) "D3: " + "Down Arrow" + "            ");
		  case 98:	// Up Arrow
			return ((String) "D3: " + "Up Arrow" + "               ");
	  }
  }
}

void depthCharArr3OptionSelect() {
  incDepthCharArr3();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption depthCharArr4Option {
  1,
  depthCharArr4OptionText,
  depthCharArr4OptionSelect,
};

String depthCharArr4OptionText() {
	if (depthCharArr[4] <= 93) {
    return ((String) "D4: " + asciiCharArr[depthCharArr[4]]+ "                        ");
	}
	else if (depthCharArr[4] > 93) {
		switch (depthCharArr[4]) {
      case 94:	// Space
			return ((String) "D4: " + "Space" + "                   ");
		  case 95:	// Right Arrow
			return ((String) "D4: " + "Right Arrow" + "            ");
		  case 96:	// Left Arrow
			return ((String) "D4: " + "Left Arrow" + "             ");
		  case 97:	// Down Arrow
			return ((String) "D4: " + "Down Arrow" + "            ");
		  case 98:	// Up Arrow
			return ((String) "D4: " + "Up Arrow" + "               ");
	  }
  }
}

void depthCharArr4OptionSelect() {
  incDepthCharArr4();
  drawMenuOptionSelected(menuOptionSelected);
}

//////////////////////////////////////////
///////////// Color Options //////////////
//////////////////////////////////////////
menuOption foregroundColorOption {
  1,
  foregroundColorOptionText,
  foregroundColorOptionSelect,
};

String foregroundColorOptionText() {
  return ((String) "FGND: " + colorArr[foregroundColorIndex].name + "                    ");
}

void foregroundColorOptionSelect() {
  incForegroundColor();
  tft.setTextColor(foregroundColor, backgroundColor);
  settingsDraw();
  //drawMenuOptionSelected(menuOptionSelected);
}

menuOption backgroundColorOption {
  1,
  backgroundColorOptionText,
  backgroundColorOptionSelect,
};

String backgroundColorOptionText() {
  return ((String) "BGND: " + colorArr[backgroundColorIndex].name + "                  ");
}

void backgroundColorOptionSelect() {
  incBackgroundColor();
  tft.setTextColor(foregroundColor, backgroundColor);
  settingsDraw();
  //drawMenuOptionSelected(menuOptionSelected);
}

menuOption neokeyBrightnessOption {
  1,
  neokeyBrightnessOptionText,
  neokeyBrightnessOptionSelect,
};

String neokeyBrightnessOptionText() {
  return ((String) "LED Brightness : " + neokeyBrightness + "          ");
}

void neokeyBrightnessOptionSelect() {
  incNeokeyBrightness();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption neokeyColorModeOption {
  1,
  neokeyColorModeOptionText,
  neokeyColorModeOptionSelect,
};

String neokeyColorModeOptionText() {
  return ((String) "Color Mode : " + neokeyColorMode + "             ");
}

void neokeyColorModeOptionSelect() {
  incNeokeyColorMode();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption neokeyColorArr0Option {
  1,
  neokeyColorArr0OptionText,
  neokeyColorArr0OptionSelect,
};

String neokeyColorArr0OptionText() {
  return ((String) "C0: " + colorArr[neokeyColorArr[0]].name + "                    ");
}

void neokeyColorArr0OptionSelect() {
  incNeokeyColorArr0();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption neokeyColorArr1Option {
  1,
  neokeyColorArr1OptionText,
  neokeyColorArr1OptionSelect,
};

String neokeyColorArr1OptionText() {
  return ((String) "C1: " + colorArr[neokeyColorArr[1]].name + "                    ");
}

void neokeyColorArr1OptionSelect() {
  incNeokeyColorArr1();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption neokeyColorArr2Option {
  1,
  neokeyColorArr2OptionText,
  neokeyColorArr2OptionSelect,
};

String neokeyColorArr2OptionText() {
  return ((String) "C2: " + colorArr[neokeyColorArr[2]].name + "                    ");
}

void neokeyColorArr2OptionSelect() {
  incNeokeyColorArr2();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption neokeyColorArr3Option {
  1,
  neokeyColorArr3OptionText,
  neokeyColorArr3OptionSelect,
};

String neokeyColorArr3OptionText() {
  return ((String) "C3: " + colorArr[neokeyColorArr[3]].name + "                    ");
}

void neokeyColorArr3OptionSelect() {
  incNeokeyColorArr3();
  drawMenuOptionSelected(menuOptionSelected);
}

menuOption neokeyColorArr4Option {
  1,
  neokeyColorArr4OptionText,
  neokeyColorArr4OptionSelect,
};

String neokeyColorArr4OptionText() {
  return ((String) "C4: " + colorArr[neokeyColorArr[4]].name + "                    ");
}

void neokeyColorArr4OptionSelect() {
  incNeokeyColorArr4();
  drawMenuOptionSelected(menuOptionSelected);
}

/*
menuOption neokeyKeysModeOption {
  1,
  neokeyKeysModeOptionText,
  neokeyKeysModeOptionSelect,
};

String neokeyKeysModeOptionText() {
  return ((String) "Key Mode: " + neokeyKeysModes[neokeyKeysMode] + "               ");
}

void neokeyKeysModeOptionSelect() {
  incNeokeyKeysMode();
  drawMenuOptionSelected(menuOptionSelected);
}
*/

//////////////////////////////////////////
////// Draw and control menu pages ///////
//////////////////////////////////////////
const uint8_t maxOptionsArrSize = 18;
struct menuPage {
	String title;   //up to 9 Chars goes in menu bar
  void (*draw)();
  void (*select)();
  void (*specialFunction)();
	uint8_t optionsArrSize;
	menuOption optionsArr[maxOptionsArrSize];
};

const uint8_t menuPagesSize = 4;
menuPage menuPages[menuPagesSize] = {
  {
    "Main Menu",
    mainMenuDraw,
    mainMenuSelect,
    mainMenuSpecialFunction,
    9,
    {sessionOption, statsOption, settingsOption, BLEOption, USBOption, SerialDepthOption, saveOption, savedXPOption, totalXPOption,},
  },
  {
    "Stats",
    statsDraw,
    statsSelect,
    statsSpecialFunction,
    8,
    {mainMenuOption, sessionXPOption, savedXPOption, totalXPOption, key4CountTotalOption, key3CountTotalOption, key2CountTotalOption, key1CountTotalOption,},
  },
  {
    "Settings",
    settingsDraw,
    settingsSelect,
    settingsSpecialFunction,
    15,
    {mainMenuOption, depthCharArr0Option, depthCharArr1Option, depthCharArr2Option, depthCharArr3Option, depthCharArr4Option, foregroundColorOption, backgroundColorOption, neokeyBrightnessOption, neokeyColorModeOption, neokeyColorArr0Option, neokeyColorArr1Option, neokeyColorArr2Option, neokeyColorArr3Option, neokeyColorArr4Option,},
  },
  {
    "Session",
    sessionDraw,
    sessionSelect,
    sessionSpecialFunction,
    6,
    {mainMenuOption, sessionXPOption, key4CountOption, key3CountOption, key2CountOption, key1CountOption,},
  },
};

void mainMenuDraw() {
	drawMenu(menuPages[0]);
}

void mainMenuSelect() {
	menuPageSelected = 0;
	menuOptionSelected = 0;
  menuOptionSelectedLast = 0;
	mainMenuDraw();
}

void mainMenuSpecialFunction() {
	if (depthChangeFlag) {
    if (depth != 0) {
      drawMenuOption(8);
    }
	}
}

void sessionDraw() {
	drawMenu(menuPages[3]);
}

void sessionSelect() {
	menuPageSelected = 3;
	menuOptionSelected = 0;
  menuOptionSelectedLast = 0;
	sessionDraw();
}

void sessionSpecialFunction() {
	if (depthChangeFlag) {
    if (depth != 0) {
      drawMenuOption(5-(depth-1));
		  drawMenuOption(1);
    }
	}
}

void statsDraw() {
	drawMenu(menuPages[1]);
}

void statsSelect() {
	menuPageSelected = 1;
	menuOptionSelected = 0;
  menuOptionSelectedLast = 0;
	statsDraw();
}

void statsSpecialFunction() {
	if (depthChangeFlag) {
    if (depth != 0) {
      drawMenuOption(7-(depth-1));
      drawMenuOption(1);
      drawMenuOption(3);
    }
	}
}

void settingsDraw() {
	drawMenu(menuPages[2]);
}

void settingsSelect() {
	menuPageSelected = 2;
	menuOptionSelected = 0;
  menuOptionSelectedLast = 0;
	settingsDraw();
}

void settingsSpecialFunction() {
  return;
}


void drawMenuOption(uint8_t optionToDraw) {
  tft.drawString(menuPages[menuPageSelected].optionsArr[optionToDraw].text(), 0, (optionToDraw+1)*textHeight);
}

  //used in inc options and toggle ble
void drawMenuOptionSelected(uint8_t optionToUpdate) {
  tft.setTextColor(backgroundColor, foregroundColor);
  tft.drawString(menuPages[menuPageSelected].optionsArr[optionToUpdate].text(), 0, (optionToUpdate+1)*textHeight);
  tft.setTextColor(foregroundColor, backgroundColor);
}

void drawMenuBar(){
  tft.setTextDatum(1);    //set text reference to top middle of string
  tft.drawString (menuPages[menuPageSelected].title, 85, 0);
  tft.drawString("Next", 23, 0);
  tft.drawString("Select", 147, 0);
  tft.setTextDatum(0);    //set text reference to default top left of string
  tft.drawFastHLine(0, textHeight-1, 170, foregroundColor);
  tft.drawFastVLine(47, 0, textHeight-1, foregroundColor);
  tft.drawFastVLine(123, 0, textHeight-1, foregroundColor);
}

void drawMenu(struct menuPage page) {
	tft.fillScreen(backgroundColor);
	for (int i = 0; i < page.optionsArrSize; i++) {
		if (i == menuOptionSelected) {
			drawMenuOptionSelected(i);
		}
		else {
			drawMenuOption(i);
		}
	}
	drawMenuBar();
}

void drawMenuOptions() {      // update menuOptionSelected and menu option slecetd last on display
  if (menuOptionSelected == menuOptionSelectedLast) {
    return;
  }
	drawMenuOptionSelected(menuOptionSelected);
  drawMenuOption(menuOptionSelectedLast);
}

void incOptions() {
	do {
    menuOptionSelected ++;
    if (menuOptionSelected >= menuPages[menuPageSelected].optionsArrSize) {
      menuOptionSelected = 0;
    }
  } while (!menuPages[menuPageSelected].optionsArr[menuOptionSelected].selectable);
  drawMenuOptions();
  menuOptionSelectedLast = menuOptionSelected;
	//Serial.println((String) "Menu Option Selected : " + menuOptionSelected);
}

void onboardButtonsMenu() {
	onboardButtonsDT(incOptions, menuPages[menuPageSelected].optionsArr[menuOptionSelected].function);
}

void menuFn() {
  onboardButtonsMenu();
  menuPages[menuPageSelected].specialFunction();
}
