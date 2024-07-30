/**
 * This sketch enables USB keyboard mode and sends a message every X seconds.
 * Change MESSAGE_TO_SEND define to set the message (keystrokes)
 * Change TIME_BETWEEN define in order to select seconds between repetitions.
 *
 * Dependencies:
 *  - uTimerLib - https://github.com/Naguissa/uTimerLib - Available on Library Manager
 *  - Keyboard - https://www.arduino.cc/reference/en/language/functions/usb/keyboard/ - Available on Arduino core libraries
 *
 * Directly compatible boards (others may need extra hardware):
 *  - Arduino Micro
 *  - Arduino Leonardo
 *  - Arduino Mega
 *  - Arduino Due
 *  - Arduino MKR FOX 1200
 *  - Arduino MKR GSM 1400
 *  - Arduino MKR NB 1500
 *  - Arduino MKR VIDOR 4000
 *  - Arduino MKR WAN 1300 (LoRa connectivity)
 *  - Arduino MKR WAN 1310
 *  - Arduino MKR WiFi 1010
 *  - Arduino MKR ZERO (I2S bus & SD for sound, music & digital audio data)
 *  - Arduino MKR1000 WIFI
 *  - Arduino Nano
 *  - Arduino Nano 33 IoT
 *  - Arduino Uno
 *  - Arduino Yún
 *  - Arduino Zero
 *  - Arduino UNO R4 Minima
 *  - Arduino UNO R4 WiFi
 *
 * From keyboard library: This library is compatible with the avr, samd, sam, renesas_uno architectures.
 *
 * Creator: Naguissa - https://www.foroelectro.net - https://github.com/Naguissa
 *
 * Version: 1.0.0
 */
#include "Keyboard.h"
#include "uTimerLib.h"

#define MESSAGE_TO_SEND " "
#define TIME_BETWEEN 10

void setup() {
  // open the serial port:
  Serial.begin(9600);

  enableStrokes();
  }

void sendKeystrokeCb() {
    Keyboard.print(MESSAGE_TO_SEND);
}

void enableStrokes() {
  Keyboard.begin();
	TimerLib.setInterval_s(sendKeystrokeCb, TIME_BETWEEN);
}

void loop() {
}
