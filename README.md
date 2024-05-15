# A0 Cybernetics: ID-01
<img src="/Documents/READMEPics/led.gif" alt="LEDs" width=25%><img src="/Documents/READMEPics/depthSensing.gif" alt="Depth Sensing In Action" width=75%>

An interactive adult entertainment device and fitness tracker. It measures a user's position within the device and can transmit commands to connected devices via USB and/or Bluetooth communication. Use data is tracked as key presses for the keys on the device, converted into XP (experience points), and can be saved over the life of the device. Build experience, control other devices, and interact with media.

- Free and open source. I do this because I like it <3

- Onboard TFT screen with UI

- Play any game. Each key can be mapped to 99 different ASCII characters in the settings.

- 21 user-customizable LED lighting modes

- Hot-swappable Cherry MK style keyboard keys for user customization

- No programming or design knowledge is necessary to build

- Open-source and reprogrammable firmware running on ESP32-S3

- Compiled binary files are provided, so there is no need to compile the program.

- Fully 3D-printed parts (except for electrical components, heat set inserts, and screws)

- Multiple designs and customization pieces are provided to accommodate sleeves from Fleshlight and other more affordable options.

- Read the [Build Guide](Documents/buildGuide.txt) for a parts list and fully detailed step-by-step instructions.

## Upgraded Fleshlight End Caps

Multiple designs are provided for end caps for this device or a regular fleshlight.

- ARRI version has a central hole pattern compatible with 1/4"-20 ARRI locating pin camera rigging equipment.

- Ultimate version has the ARRI version pattern in the center and 7 additional 1/4"-20 screw points arranged in a geometric pattern that is compatible with camera cheese plate layouts or whatever you can imagine.

- One is a replacement for the original.

<img src="/Documents/READMEPics/fleshlightEndCaps.jpg" alt="Fleshlight End Caps" width=60%><img src="/Documents/READMEPics/housing1.jpg" alt="Flesh1ight Style Housing" width=21%><img src="/Documents/READMEPics/housing2.jpg" alt="Generic Style Housing" width=19%>

## Project OutFox / StepMania Compatibility

Play rhythm games with your adult toy. Insert to different depths to hit notes in sync with a rhythm game like DDR.

1. Download a version of StepMania like Project OutFox  projectoutfox.com. (no affiliation)
2. Download song packs and add them to the Project Outfox Songs folder. Search the internet for StepMania song packs.
3. Set up the game and controller as below, and most songs should be playable, but some difficult songs may be physically impossible to perform.

To use this as a controller to play Stepmania:
- On device:
	- In setting, ensure that key mode is set to StepMania. (is the default in firmware)
	- In the Main Menu, turn on BLE or USB Keyboard and connect to the computer.

- In Stepmania:
	- On the Map Controller Settings page in a device column, select the key names below then press the button on the device to map the device keys to the game keys:
		- Left -> Key 1 (most shallow key in the device)
		- Down -> Key 2
		- Up -> Key 3
		- Right -> Key 4 (deepest key in the device)
	- Calibrate Audio Sync - Select Calibrate audio sync option and complete the process to tune timing problems.
	- Set modifiers in Player Options to remove pressing more than one button at a time.
		- Press start again after selecting a song before the song starts to open the Player Options Menu
		- Navigate to the Modifiers submenu and select No Jumps on the Remove row
- Done, This will setup the game so that the notes are mapped from left/ most shallow key to right/ deepest key

## License

[MIT](https://choosealicense.com/licenses/mit/)
