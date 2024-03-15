void tftSetup(){
    //turn on tft screen pin
  pinMode(PIN_POWER_ON, OUTPUT);
  digitalWrite(PIN_POWER_ON, HIGH);
  
    //screen setup
  tft.begin();
  
  tft.fillScreen(backgroundColor);
  tft.setRotation(2);   //invert screen - usb on top
  tft.setTextSize(1);
  tft.setTextFont(2);
  tft.setTextColor(foregroundColor, backgroundColor);
}


//drawTLAnimation(85, 159, 10); // dependent on screen size/ desied size of animation
void drawA0Animation(int32_t centerX, int32_t centerY, int size) {
  //tft.fillScreen(backgroundColor);
  unsigned long startTime = 0;
  unsigned long targetTime = 0; 
  unsigned long renderTime = random(333);
  for (int i = 1; i < size+1; i++){
    startTime = millis();
    targetTime = startTime + renderTime;
    int im1= i-1;
    int im18 = 8*im1;
    int i8 = 8*i;
    int im17 = 7*im1;
    int i7 = 7*i;
    int im14 = 4*im1;
    int i4 = 4*i;
    tft.drawLine (centerX, centerY-im18, centerX, centerY-i8, foregroundColor);
    tft.drawLine (centerX, centerY+im18, centerX, centerY+i8, foregroundColor);
    tft.drawLine (centerX-im14, centerY-im17, centerX-i4, centerY-i7, foregroundColor);
    tft.drawLine (centerX+im14, centerY+im17, centerX+i4, centerY+i7, foregroundColor);
    tft.drawLine (centerX-im17, centerY-im14, centerX-i7, centerY-i4, foregroundColor);
    tft.drawLine (centerX+im17, centerY+im14, centerX+i7, centerY+i4, foregroundColor);
    tft.drawLine (centerX-im18, centerY, centerX-i8, centerY, foregroundColor);
    tft.drawLine (centerX+im18, centerY, centerX+i8, centerY, foregroundColor);
    tft.drawLine (centerX-im17, centerY+im14, centerX-i7, centerY+i4, foregroundColor);
    tft.drawLine (centerX+im17, centerY-im14, centerX+i7, centerY-i4, foregroundColor);
    tft.drawLine (centerX-im14, centerY+im17, centerX-i4, centerY+i7, foregroundColor);
    tft.drawLine (centerX+im14, centerY-im17, centerX+i4, centerY-i7, foregroundColor);
    while (millis() <= targetTime) {}
  }
  tft.setTextDatum(1);
	tft.drawString("A0: ID-01", 85, 239);
	tft.setTextDatum(0);
  delay(2222);
}
