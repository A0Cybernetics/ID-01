// returns a 32bit rgb color from a color struct
uint32_t rgb32Color(struct color colorStruct) {
  return (((uint32_t)colorStruct.r << 16) | ((uint32_t)colorStruct.g << 8) | colorStruct.b);
}

// returns a 32bit rgb color from a color struct adjusted for 0-100 brightness mostly for neokey colors
uint32_t rgb32BrightColor(struct color colorStruct, uint8_t brightness) {
  return (((uint32_t) (brightness * colorStruct.r / neokeyBrightnessMax) << 16) | ((uint32_t) (brightness * colorStruct.g / neokeyBrightnessMax) << 8) | (brightness * colorStruct.b / neokeyBrightnessMax));
}

 //updateKeyRGB32Bright(brightness) converts key color array to 32bit color array adjusted for 0-100 brightness
void updateKeyRGB32Bright(uint8_t brightness) {
  for (uint8_t i=0; i<neokeyColorArrSize; i++) {
    keyRGB32BrightColorArr[i] = rgb32BrightColor(colorArr[neokeyColorArr[i]], brightness);
  }
}

 //updateKeyRGB32Bright0(brightness) converts key color array [0] to 32bit color adjusted for 0-100 brightness for color modes that only use keyRGB32BrightColorArr[0]
void updateKeyRGB32Bright0(uint8_t brightness) {
  keyRGB32BrightColorArr[0] = rgb32BrightColor(colorArr[neokeyColorArr[0]], brightness);
}

// returns a 16bit rgb color from a color struct for tftespi uses
uint16_t rgb16Color(color colorStruct) {
	return ((colorStruct.r & 0xF8)<<8 | (colorStruct.g & 0xFC)<<3 | colorStruct.b>>3);
}



  //cycle through colors for primaary Color/text color
void incForegroundColor() {
  if (foregroundColorIndex < colorArrSize - 1) {
    foregroundColorIndex++;
  }
  else {
    foregroundColorIndex = 0;
  }
  foregroundColor = rgb16Color(colorArr[foregroundColorIndex]);
  //Serial.println(colorArr[foregroundColorIndex].name);
}

  //cycle through colors for backgroundColor/ bkgd
void incBackgroundColor() {
  if (backgroundColorIndex < colorArrSize - 1) {
    backgroundColorIndex++;
  }
  else {
    backgroundColorIndex = 0;
  }
  backgroundColor = rgb16Color(colorArr[backgroundColorIndex]);
  //Serial.println(colorArr[backgroundColorIndex].name);
}

  //cycle through colors for neokeyColorArr[0]
void incNeokeyColorArr0() {
  if (neokeyColorArr[0] < colorArrSize - 1) {
    neokeyColorArr[0]++;
  }
  else {
    neokeyColorArr[0] = 0;
  }
  keyRGB32BrightColorArr[0] = rgb32BrightColor(colorArr[neokeyColorArr[0]], neokeyBrightness);
  //Serial.println(colorArr[neokeyColorArr[0]].name);
  standbyColorFlag = 0;
}

  //cycle through colors for neokeyColorArr[1]
void incNeokeyColorArr1() {
  if (neokeyColorArr[1] < colorArrSize - 1) {
    neokeyColorArr[1]++;
  }
  else {
    neokeyColorArr[1] = 0;
  }
  keyRGB32BrightColorArr[1] = rgb32BrightColor(colorArr[neokeyColorArr[1]], neokeyBrightness);
  standbyColorFlag = 0;
}

  //cycle through colors for neokeyColorArr[2]
void incNeokeyColorArr2() {
  if (neokeyColorArr[2] < colorArrSize - 1) {
    neokeyColorArr[2]++;
  }
  else {
    neokeyColorArr[2] = 0;
  }
  keyRGB32BrightColorArr[2] = rgb32BrightColor(colorArr[neokeyColorArr[2]], neokeyBrightness);
  standbyColorFlag = 0;
}

  //cycle through colors for neokeyColorArr[3]
void incNeokeyColorArr3() {
  if (neokeyColorArr[3] < colorArrSize - 1) {
    neokeyColorArr[3]++;
  }
  else {
    neokeyColorArr[3] = 0;
  }
  keyRGB32BrightColorArr[3] = rgb32BrightColor(colorArr[neokeyColorArr[3]], neokeyBrightness);
  standbyColorFlag = 0;
}

  //cycle through colors for neokeyColorArr[4]
void incNeokeyColorArr4() {
  if (neokeyColorArr[4] < colorArrSize - 1) {
    neokeyColorArr[4]++;
  }
  else {
    neokeyColorArr[4] = 0;
  }
  keyRGB32BrightColorArr[4] = rgb32BrightColor(colorArr[neokeyColorArr[4]], neokeyBrightness);
  standbyColorFlag = 0;
}

  //cycle neokeyColorSlow
void incNeokeyColorSlow() {
  if (neokeyColorSlow < neokeyColorSlowMax) {
    neokeyColorSlow++;
  }
  else {
    neokeyColorSlow = 0;
  }
}

/*
//Special Functions
//should print 15792383, 10145074, 9, 255
void colorTest () {
  uint32_t rgbColorTest= 0;
  uint8_t blueIndex = 0;
  rgbColorTest = rgb32Color(colorArray[0]);
  Serial.println(rgbColorTest);
  rgbColorTest = rgb32Color(colorArray[139]);
  Serial.println(rgbColorTest);
  blueIndex = getColorNameIndex("Blue");
  rgbColorTest = rgb32Color(colorArray[blueIndex]);
  Serial.println(blueIndex);
  Serial.println(rgbColorTest);
}

// search color array for string color name
//return index of match 0 - 139, or 255 for no match
uint8_t getColorNameIndex (String searchName) {
  for (uint8_t i=0; i<colorArrSize; i++) {
    if (colorArr[i].name == searchName) {
      return i;
    }
  }
  return 255; //not found <256
}

//Print color array to serial with rgb values as integers
void printColorArrAsInt(){
	for (uint8_t i=0; i<colorArrSize; i++) {
		Serial.println((String)"{\"" + colorArr[i].name + "\", " + colorArr[i].r +", " + colorArr[i].g +", " + colorArr[i].b +"},");
	}
  wait(1000000000000000);
}
*/
