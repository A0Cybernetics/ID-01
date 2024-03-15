  // increment xp counters
void incXP() {
  sessionXP++;
  totalXP++;
}

  // load prefrences or initialize prefs and vars
void loadPreferences() {
  preferences.begin("ID-01", false);
  savedXP = preferences.getUInt("XP", 0);
  keyCountSaved[0] = preferences.getUShort("K1", 0);
  keyCountSaved[1] = preferences.getUShort("K2", 0);
  keyCountSaved[2] = preferences.getUShort("K3", 0);
  keyCountSaved[3] = preferences.getUShort("K4", 0);
  depthCharArr[0] = preferences.getUChar("D0", 15);
  depthCharArr[1] = preferences.getUChar("D1", 16);
  depthCharArr[2] = preferences.getUChar("D2", 17);
  depthCharArr[3] = preferences.getUChar("D3", 18);
  depthCharArr[4] = preferences.getUChar("D4", 19);
  foregroundColorIndex = preferences.getUChar("FC", 56);
  backgroundColorIndex = preferences.getUChar("BC", 7);
  neokeyBrightness = preferences.getUChar("CB", 50);
  neokeyColorMode = preferences.getUChar("CM", 16);
  neokeyColorArr[0] = preferences.getUChar("C0", 31);
  neokeyColorArr[1] = preferences.getUChar("C1", 31);
  neokeyColorArr[2] = preferences.getUChar("C2", 112);
  neokeyColorArr[3] = preferences.getUChar("C3", 95);
  neokeyColorArr[4] = preferences.getUChar("C4", 66);
  preferences.end();

  foregroundColor = rgb16Color(colorArr[foregroundColorIndex]);
  backgroundColor = rgb16Color(colorArr[backgroundColorIndex]);
  totalXP = savedXP;
  for (uint8_t i=0; i<4; i++) {
    keyCountTotal[i] = keyCountSaved[i];
  }
}

  //prepare vars for save function
void prepareSavePreferences() {
  savedXP = totalXP;
  sessionXP = 0;
  for (uint8_t i=0; i<4; i++) {
    keyCountSaved[i] = keyCountTotal[i];
    keyCountSession[i] = 0;
  }
}

  //save vars to prefs
void savePreferences() {
  prepareSavePreferences();
  preferences.begin("ID-01", false);
  preferences.putUInt("XP", savedXP);
  preferences.putUShort("K1", keyCountSaved[0]);
  preferences.putUShort("K2", keyCountSaved[1]);
  preferences.putUShort("K3", keyCountSaved[2]);
  preferences.putUShort("K4", keyCountSaved[3]);
  preferences.putUChar("D0", depthCharArr[0]);
  preferences.putUChar("D1", depthCharArr[1]);
  preferences.putUChar("D2", depthCharArr[2]);
  preferences.putUChar("D3", depthCharArr[3]);
  preferences.putUChar("D4", depthCharArr[4]);
  preferences.putUChar("FC", foregroundColorIndex);
  preferences.putUChar("BC", backgroundColorIndex);
  preferences.putUChar("CB", neokeyBrightness);
  preferences.putUChar("CM", neokeyColorMode);
  preferences.putUChar("C0", neokeyColorArr[0]);
  preferences.putUChar("C1", neokeyColorArr[1]);
  preferences.putUChar("C2", neokeyColorArr[2]);
  preferences.putUChar("C3", neokeyColorArr[3]);
  preferences.putUChar("C4", neokeyColorArr[4]);
  preferences.end();
}
