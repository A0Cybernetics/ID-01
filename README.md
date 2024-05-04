# A0 Cybernetics ID-01
![Flesh1ight Style Housing](/Documents/READMEPics/housing1.jpg "Flesh1ight Style Housing") ![Depth Sensing In Action](/Documents/READMEPics/depthSensing.gif "Depth Sensing In Action") ![Generic Style Housing](/Documents/READMEPics/housing2.jpg "Generic Style Housing")

An interactive adult entertainment device and fitness tracker.  Measures a users position within the device and can transmit commands to connected devices via usb and bluetooth communication.  Use data is tracked as key presses for the keys on the device, converted into XP (eXperience Points), and can be saved over the life of the device.  Build experience, control other devices, and interact with media.

- Free and open source.  I do this because I like it <3

- Uses hot swappable Cherry MK style keyboard keys for extensive user customization options

- Onboard TFT screen with extensive options user customization options

- No programming or design knowledge necessary to build

- Open source and reprogrammable firmware running on ESP32-S3

- Compiled binary files provided so there is no need to compile the program

- Fully 3D Printed parts (except for electrical components, heat set inserts and screws)

- Multiple designs and customized pieces are provided to accomodate sleeves from Flesh1ight and other more affordable options

- Read the build guide for parts list and fully detailed step by step instructions

## Project OutFox / StepMania Compatibility

Play rhythm games with your sex toy. Insert to different depths to hit notes in sync with a rhythm game like Dance Dance Revolution.

1. Download a version of StepMania like Project OutFox @ projectoutfox.com
2. Download song packs and add them to Project Outfox Songs Folder. Search the internet for StepMania song packs.
3. Setup the game and controller as below and most songs should be playable, but some difficult songs may be physically impossible to perform.

To use this as a controller to play Stepmania:
- On device:
	- In Setting ensure that key mode is set to StepMania (is default)
	- On Main Menu turn on BLE or USB Keyboard and connect to computer

- In Stepmania:
	- On Map Controller Settings page in a device column select the key names below then press the button on the device to map the device keys to the game keys:
		- Left -> Key 1 (most shallow key on device)
		- Down -> Key 2
		- Up   -> Key 3
		- Right-> Key 4 (deepest key on device)
	- Calibrate Audio Sync - Select Calibrate audio sync option and complete the process to tune timing problems.
	- Set modifiers in Player Options to remove pressing more than one button at a time.
		- Press start again after selecting a song before the song starts to open the Player Options Menu
		- Navigate to the Modifiers sub menu and select No Jumps on the Remove row
	- Done, This will setup the game so that the notes are mapped from left/ most shallow key to right/ deepest key

## License

[MIT](https://choosealicense.com/licenses/mit/)
