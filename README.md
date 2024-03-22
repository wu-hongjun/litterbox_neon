# Neon Sign with Cat Detection

# Introduction
* This is used when the cat enters her litter box or sits on the litter box, a neon sign with "on air" lights up.
* Achieved using the distance difference from the reading of the ultrasonic distance sensors between 0.25 seconds. If either sensor detects distance value change, the sign lights up.
* If distance values no longer change, the light will continue to be on for 5 seconds before it turns off.
![Cat](https://github.com/wu-hongjun/litterbox_neon/blob/main/img/cat.jpeg)

# Parts Needed
### Note: Links here is just an example, you don't have to use exact parts.
* 1x [Arduino Uno Board & USB Cable](https://www.amazon.com/Arduino-A000066-ARDUINO-UNO-R3/dp/B008GRTSV6/)
* 2x [HC-SR04 Distance Sensor](https://www.amazon.com/WWZMDiB-HC-SR04-Ultrasonic-Distance-Measuring/dp/B0B1MJJLJP/)
* 1x [5V Module 1 Channel Relay Switch](https://www.amazon.com/dp/B0B4JSH9HB?psc=1&ref=ppx_yo2ov_dt_b_product_details)
* 1x [LED Neon Sign](https://www.amazon.com/AIR-LED-Connected-Decorative-Decoration/dp/B098D9S5RQ/) (Or whatever you want to turn on/off)
* 1x [USB 2.0 Hub](https://www.amazon.com/Anker-Transfer-Extended-Charging-Supported/dp/B0CCDZWH5H/) 

# Software Needed
* [Arduino IDE](https://www.arduino.cc/en/software)

# How To
## Hardware
* Wire up everything following the schematics below.
* Using a knife, carefully peel open a small portion of the neon sign's cable to reveal the + (vcc) and - (GND) wires.
* Cut one of the two wires in half, and connect them to the relay, where I drew a red LED. This will turn on/off a device.
* Connect the Arduino board's USB cable and the Neon sign's USB cable to a USB hub so they can be powered via one cable.
* Zip-tie everything on a cardboard so things don't move too easily.
![Board](https://github.com/wu-hongjun/litterbox_neon/blob/main/img/board.JPG)
* Attach the two distance sensors to appropriate places that you want to sense the cat.
![Sensors](https://github.com/wu-hongjun/litterbox_neon/blob/main/img/sensors.JPG)
## Software
* Download [`/neon_uno_firmware.ino`](https://github.com/wu-hongjun/litterbox_neon/blob/main/neon_uno_firmware/neon_uno_firmware.ino) and save it to your computer.
* Launch Arduino IDE, connect the Arduino board, and click the top left arrow button to upload the firmware to the board.
* All Set! Connect the whole thing to a power outlet and chill!
* Tip: You can see the distance readings of both sensors in Arduino IDE's `Tools/Serial Monitor`. 

# Schematics
* NOTE: In the schematics, the neon sign is expressed as a red LED light for simplicity.
![Schematics](https://github.com/wu-hongjun/litterbox_neon/blob/main/img/Schematics.png)
