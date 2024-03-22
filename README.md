# Neon Sign with Cat Detection

# Introduction
* This is primarily used when my cat enters her litter box or sits on the litter box, a neon sign with "on air" lights up.
* Achieved using the distance difference between 0.25 seconds. If either sensor detects distance value change, the sign lights up.
* If distance values no longer change, the light will continue to be on for 5 seconds before it turns off.

# Parts Needed
* 1x Arduino Uno Board & USB Cable
* 2x HC-SR04 Distance Sensor
* 1x 5V Module 1 Channel Relay Switch
* 1x LED Neon Sign (Or whatever you want to turn on/off)
* 1x USB 2.0 Hub (Optional)

# Software Needed
* Arduino IDE

# How To
* Download [`/neon_uno_firmware.ino`](https://github.com/wu-hongjun/litterbox_neon/blob/main/neon_uno_firmware/neon_uno_firmware.ino) and save it to your computer.
* Wire up everything following the schematics below.
* Attach the two distance sensors to appropriate places that you want to sense the cat.
* Launch Arduino IDE, connect the Arduino board, and click the top left arrow button to upload the firmware to the board.
* Tip: You can see the distance readings of both sensors in Arduino IDE's `Tools/Serial Monitor`. 

# Schematics
* NOTE: In the schematics, the neon sign is expressed as a red LED light for simplicity.
![Schematics](https://github.com/wu-hongjun/litterbox_neon/blob/main/img/Schematics.png)
