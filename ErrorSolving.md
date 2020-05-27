# Error solving

Circuit: 
- Can be that you need to turn the long and short leg of the led with eachother
- Do used the right resistor and is it in the right row
- Did assigned it to the right pin

Connecting the board:
- Be sure you installed the board manager for MKR WiFi 1010 Arduino
- Select the right port and board
- Still don't recognize, try to reset the Arduino by dubbel clicking on the reset button.

Run the code doesn't work:
- See if you installed all the libraries
- See if you not accidentally wrote something in the code
- New assigned variables are assigned at the top

Still not working:
- Did you assigned the right pin number for the leds and button?
- Is your WiFi code correct?
- Is your MQTT code correct?
- Both subscriber assigned in Basic_LEDS and in connect file
- Check the serial monitor in the right up corner if your getting signals through. You can test with this by writing Serial.print(); in between code.
