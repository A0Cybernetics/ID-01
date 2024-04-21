////////// COLOR //////////
struct color {
  String name;
  uint8_t r;
  uint8_t g;
  uint8_t b;
};

  // array 140 HTML colors color structs
const uint8_t colorArrSize = 140;
color colorArr[colorArrSize] = {	
	{"Alice Blue", 0xF0, 0xF8, 0xFF},
	{"Antique White", 0xFA, 0xEB, 0xD7},
	{"Aqua", 0x00, 0xFF, 0xFF},
	{"Aquamarine", 0x7F, 0xFF, 0xD4},
	{"Azure", 0xF0, 0xFF, 0xFF},
	{"Beige", 0xF5, 0xF5, 0xDC},
	{"Bisque", 0xFF, 0xE4, 0xC4},
	{"Black", 0x00, 0x00, 0x00},
	{"Blanched Almond", 0xFF, 0xEB, 0xCD},
	{"Blue", 0x00, 0x00, 0xFF},
	{"Blue Violet", 0x8A, 0x2B, 0xE2},
	{"Brown", 0xA5, 0x2A, 0x2A},
	{"Burly Wood", 0xDE, 0xB8, 0x87},
	{"Cadet Blue", 0x5F, 0x9E, 0xA0},
	{"Chartreuse", 0x7F, 0xFF, 0x00},
	{"Chocolate", 0xD2, 0x69, 0x1E},
	{"Coral", 0xFF, 0x7F, 0x50},
	{"Cornflower Blue", 0x64, 0x95, 0xED},
	{"Cornsilk", 0xFF, 0xF8, 0xDC},
	{"Crimson", 0xDC, 0x14, 0x3C},
	{"Cyan", 0x00, 0xFF, 0xFF},
	{"Dark Blue", 0x00, 0x00, 0x8B},
	{"Dark Cyan", 0x00, 0x8B, 0x8B},
	{"Dark Golden Rod", 0xB8, 0x86, 0x0B},
	{"Dark Gray", 0xA9, 0xA9, 0xA9},
	{"Dark Green", 0x00, 0x64, 0x00},
	{"Dark Khaki", 0xBD, 0xB7, 0x6B},
	{"Dark Magenta", 0x8B, 0x00, 0x8B},
	{"Dark Olive Green", 0x55, 0x6B, 0x2F},
	{"Dark Orange", 0xFF, 0x8C, 0x00},
	{"Dark Orchid", 0x99, 0x32, 0xCC},
	{"Dark Red", 0x8B, 0x00, 0x00},
	{"Dark Salmon", 0xE9, 0x96, 0x7A},
	{"Dark Sea Green", 0x8F, 0xBC, 0x8F},
	{"Dark Slate Blue", 0x48, 0x3D, 0x8B},
	{"Dark Sate Gray", 0x2F, 0x4F, 0x4F},
	{"Dark Turquoise", 0x00, 0xCE, 0xD1},
	{"Dark Violet", 0x94, 0x00, 0xD3},
	{"Deep Pink", 0xFF, 0x14, 0x93},
	{"Deep Sky Blue", 0x00, 0xBF, 0xFF},
	{"Dim Gray", 0x69, 0x69, 0x69},
	{"Dodger Blue", 0x1E, 0x90, 0xFF},
	{"Fire Brick", 0xB2, 0x22, 0x22},
	{"Floral White", 0xFF, 0xFA, 0xF0},
	{"Forest Green", 0x22, 0x8B, 0x22},
	{"Fuchsia", 0xFF, 0x00, 0xFF},
	{"Gainsboro", 0xDC, 0xDC, 0xDC},
	{"Ghost White", 0xF8, 0xF8, 0xFF},
	{"Gold", 0xFF, 0xD7, 0x00},
	{"Golden Rod", 0xDA, 0xA5, 0x20},
	{"Gray", 0x80, 0x80, 0x80},
	{"Green", 0x00, 0x80, 0x00},
	{"Green Yellow", 0xAD, 0xFF, 0x2F},
	{"Honey Dew", 0xF0, 0xFF, 0xF0},
	{"Hot Pink", 0xFF, 0x69, 0xB4},
	{"Indian Red", 0xCD, 0x5C, 0x5C},
	{"Indigo", 0x4B, 0x00, 0x82},
	{"Ivory", 0xFF, 0xFF, 0xF0},
	{"Khaki", 0xF0, 0xE6, 0x8C},
	{"Lavender", 0xE6, 0xE6, 0xFA},
	{"Lavender Blush", 0xFF, 0xF0, 0xF5},
	{"Lawn Green", 0x7C, 0xFC, 0x00},
	{"Lemon Chiffon", 0xFF, 0xFA, 0xCD},
	{"Light Blue", 0xAD, 0xD8, 0xE6},
	{"Light Coral", 0xF0, 0x80, 0x80},
	{"Light Cyan", 0xE0, 0xFF, 0xFF},
	{"Light Golden Rod Yellow", 0xFA, 0xFA, 0xD2},
	{"Light Gray", 0xD3, 0xD3, 0xD3},
	{"Light Green", 0x90, 0xEE, 0x90},
	{"Light Pink", 0xFF, 0xB6, 0xC1},
	{"Light Salmon", 0xFF, 0xA0, 0x7A},
	{"Light Sea Green", 0x20, 0xB2, 0xAA},
	{"Light Sky Blue", 0x87, 0xCE, 0xFA},
	{"Light Slate Gray", 0x77, 0x88, 0x99},
	{"Light Steel Blue", 0xB0, 0xC4, 0xDE},
	{"Light Yellow", 0xFF, 0xFF, 0xE0},
	{"Lime", 0x00, 0xFF, 0x00},
	{"Lime Green", 0x32, 0xCD, 0x32},
	{"Linen", 0xFA, 0xF0, 0xE6},
	{"Magenta", 0xFF, 0x00, 0xFF},
	{"Maroon", 0x80, 0x00, 0x00},
	{"Medium Aqua Marine", 0x66, 0xCD, 0xAA},
	{"Medium Blue", 0x00, 0x00, 0xCD},
	{"Medium Orchid", 0xBA, 0x55, 0xD3},
	{"Medium Purple", 0x93, 0x70, 0xDB},
	{"Medium Sea Green", 0x3C, 0xB3, 0x71},
	{"Medium Slate Blue", 0x7B, 0x68, 0xEE},
	{"Medium Spring Green", 0x00, 0xFA, 0x9A},
	{"Medium Turquoise", 0x48, 0xD1, 0xCC},
	{"Medium Violet Red", 0xC7, 0x15, 0x85},
	{"Midnight Blue", 0x19, 0x19, 0x70},
	{"Mint Cream", 0xF5, 0xFF, 0xFA},
	{"Misty Rose", 0xFF, 0xE4, 0xE1},
	{"Moccasin", 0xFF, 0xE4, 0xB5},
	{"Navajo White", 0xFF, 0xDE, 0xAD},
	{"Navy", 0x00, 0x00, 0x80},
	{"Old Lace", 0xFD, 0xF5, 0xE6},
	{"Olive", 0x80, 0x80, 0x00},
	{"Olive Drab", 0x6B, 0x8E, 0x23},
	{"Orange", 0xFF, 0xA5, 0x00},
	{"Orange Red", 0xFF, 0x45, 0x00},
	{"Orchid", 0xDA, 0x70, 0xD6},
	{"Pale Golden Rod", 0xEE, 0xE8, 0xAA},
	{"Pale Green", 0x98, 0xFB, 0x98},
	{"Pale Turquoise", 0xAF, 0xEE, 0xEE},
	{"Pale Violet Red", 0xDB, 0x70, 0x93},
	{"Papaya Whip", 0xFF, 0xEF, 0xD5},
	{"Peach Puff", 0xFF, 0xDA, 0xB9},
	{"Peru", 0xCD, 0x85, 0x3F},
	{"Pink", 0xFF, 0xC0, 0xCB},
	{"Plum", 0xDD, 0xA0, 0xDD},
	{"Powder Blue", 0xB0, 0xE0, 0xE6},
	{"Purple", 0x80, 0x00, 0x80},
	{"Red", 0xFF, 0x00, 0x00},
	{"Rosy Brown", 0xBC, 0x8F, 0x8F},
	{"Royal Blue", 0x41, 0x69, 0xE1},
	{"Saddle Brown", 0x8B, 0x45, 0x13},
	{"Salmon", 0xFA, 0x80, 0x72},
	{"Sandy Brown", 0xF4, 0xA4, 0x60},
	{"Sea Green", 0x2E, 0x8B, 0x57},
	{"Sea Shell", 0xFF, 0xF5, 0xEE},
	{"Sienna", 0xA0, 0x52, 0x2D},
	{"Silver", 0xC0, 0xC0, 0xC0},
	{"Sky Blue", 0x87, 0xCE, 0xEB},
	{"Slate Blue", 0x6A, 0x5A, 0xCD},
	{"Slate Gray", 0x70, 0x80, 0x90},
	{"Snow", 0xFF, 0xFA, 0xFA},
	{"Spring Green", 0x00, 0xFF, 0x7F},
	{"Steel Blue", 0x46, 0x82, 0xB4},
	{"Tan", 0xD2, 0xB4, 0x8C},
	{"Teal", 0x00, 0x80, 0x80},
	{"Thistle", 0xD8, 0xBF, 0xD8},
	{"Tomato", 0xFF, 0x63, 0x47},
	{"Turquoise", 0x40, 0xE0, 0xD0},
	{"Violet", 0xEE, 0x82, 0xEE},
	{"Wheat", 0xF5, 0xDE, 0xB3},
	{"White", 0xFF, 0xFF, 0xFF},
	{"White Smoke", 0xF5, 0xF5, 0xF5},
	{"Yellow", 0xFF, 0xFF, 0x00},
	{"Yellow Green", 0x9A, 0xCD, 0x32},
};

  //stores indexes of colorArray  raw color structs for key colors
  //0 for solid colors, 1-4 for individual key colors
const uint8_t neokeyColorArrSize = 5;
uint8_t neokeyColorArr[neokeyColorArrSize] = {113, 113, 76, 9, 112};  //76 lime 113 red 9 blue 112 purple
  //stores colors from keyColorArray converted to 32bit colors for neokey initialized in startupNeokey
  //updateKeyRGB32Bright(brightness) converts key color array to 32bit color array adjusted for 0-100 brightness
uint32_t keyRGB32BrightColorArr[neokeyColorArrSize] = {};

////////// NEOKEY //////////
uint16_t numKeys = 4;   //  stores number of neopixels / buttons should be 4 after numPixels = neokey.pixels.numPixels(); in startup

  //store ascii char that can be sent from keyboard 0-94 printed on display for select menu
  //i94= space, i95 = KEY_RIGHT_ARROW, i96 = KEY_LEFT_ARROW, i97= KEY_DOWN_ARROW, i98 = KEY_UP_ARROW
const uint8_t asciiCharArrSize = 99;
const char asciiCharArr[asciiCharArrSize]= {'!','\"','#','$','%','&','\'','(',')','*','+',',','-','.','/','0','1','2','3','4','5','6','7','8','9',':',';','<','=','>','?','@','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','[','\\',']','^','_','`','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','{','|','}','~',' ',0xD7/*215right*/,0xD8/*216left*/,0xD9/*217down*/,0xDA/*218up*/};
  //store selected chars for 0 - 4 depth/keys
uint8_t depthCharArr[5] = {93, 93, 93, 93, 93}; //{15, 16, 17, 18, 19}; //array storing char sent for 0 depth (0) and keys (1-4) /depth 1-4


uint8_t neokeyKeysMode = 0;           //switch in neokeyKeysFn changes neokeyKeys function based on this as index of names in neokeyKeysModes array
const uint8_t keysModesArraySize = 2; //sets size of  inc neokey keys modes max
const char *neokeyKeysModes[keysModesArraySize] = {"StepMania", "Write"}; //stores names of modes


uint8_t keys = 0;         //  stores new value of neokey keys
uint8_t keysLast = 0;     //  stores last value of neokey keys for edge detection
uint8_t keysRaw = 0;      //  stores new raw value of neokey keys
uint8_t keysRawLast = 0;  //  stores last value of neokey keys for edge detection
uint8_t depth = 0;        //  stores the depth level (0-4)
uint8_t depthLast = 0;    //  stores the last depth level (0-4)
bool depthChangeFlag = 0; //  signals if depth changes for loop
uint16_t keyCountSession[4] = {0,0,0,0}; //stores keycount for session
uint16_t keyCountSaved[4] = {0,0,0,0,};   //stores last saved lifetime keycount for calculations
uint16_t keyCountTotal[4] = {0,0,0,0,};   //stores keycount of session + saved keycounts to save
uint sessionXP = 0;       //  stores session xp / total of keycounts in unsaved session
uint savedXP = 0;       //  stores last saved total xp for calclations 4,294,967,295 max
uint totalXP = 0;    // stoes new total xp of session + saved xp

uint8_t neokeyColorMode = 16;  // sets the neopixel color function
const uint8_t neokeyColorModeMax = 22;  //sets max for inc neokey color mode based on switch in neokeyColorFn
uint8_t neokeyWheelColor = 0;          // tracks the colors of the LEDs color cycle for swirl
uint8_t neokeyBrightness = 50; // brightness setting 0-100
const uint8_t neokeyBrightnessMin = 0; //brightness minimum limit setting for breathe
const uint8_t neokeyBrightnessMax = 100; //brightness user setting and limit for breathe
uint8_t neokeyBrightnessBreathe = neokeyBrightness;  // varible changes with breathe animation
bool breatheFlag = 0;     //  bool that determines brightness increment or decrement
bool standbyColorFlag = 0;  // bool that indicates to skip setting colors for some standby modes
uint8_t neokeyColorSlow = 15; // slow down color changes
const uint8_t neokeyColorSlowMax = 100;
unsigned long nextColorTime = 0;
bool colorChangeFlag = 0;

////////// CONNECTIONS //////////
bool USBKeyboardState = 0;    //1 = use usb keyboard mode/ 0 = turn off
bool BLEKeyboardState = 0;    //1 = use bluetooth keyboard mode/ 0 = turn off
bool SerialDepthState = 0;    //1 = use serial depth logging/ 0 = turn off

bool USBKeyboardStarted = 0;  //0 =run start portion on first time only ges set to 1
bool BLEKeyboardStarted = 0;  // skips part of code after first time

////////// ONBOARD BUTTONS //////////
  //INPUT_PULLUP => 1 when not pressed, 0 when pressed
bool but1State = 1;
bool but1StateLast = 1;
bool but2State = 1;
bool but2StateLast = 1;

unsigned long currentTime = 0;  //used to store millis at beginning of function and reference without calling millis
const uint8_t butDebounceDelay = 59;
const uint16_t butHoldDelay = 500;
unsigned long but1NextDebounceTime = 0;
unsigned long but2NextDebounceTime = 0;
unsigned long but1NextHoldTime = 0;
unsigned long but2NextHoldTime = 0;
bool but1HoldFlag = 0;
bool but2HoldFlag = 0;

////////// Menu //////////
uint8_t foregroundColorIndex = 56;     // White 136, indigo 56
uint8_t backgroundColorIndex = 7;    //black  7
unsigned int foregroundColor = rgb16Color(colorArr[foregroundColorIndex]);
unsigned int backgroundColor = rgb16Color(colorArr[backgroundColorIndex]);
uint8_t menuPageSelected = 0;
uint8_t menuOptionSelected = 0;
uint8_t menuOptionSelectedLast = 0;

////////// TFT //////////
uint8_t textHeight = 16;
