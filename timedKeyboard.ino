/**
 * This sketch enables USB keyboard mode and sends a message every X seconds.
 * Change MESSAGE_TO_SEND define to set the message (keystrokes)
 * Change TIME_BETWEEN define in order to select seconds between repetitions.
 *
 * Dependencies:
 *  - Keyboard - https://www.arduino.cc/reference/en/language/functions/usb/keyboard/ - Available on Arduino core libraries
 *       - or -
 *  - DigiKeyboard - https://github.com/digistump/DigistumpArduino - Available on Arduino after installing Digistump Attiny core
 *
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
 *  - Digispark Attiny85 compatible boards (with DigiStump core)
 *
 * From keyboard library: This library is compatible with the avr, samd, sam, renesas_uno architectures.
 *
 * Creator: Naguissa - https://www.foroelectro.net - https://github.com/Naguissa
 *
 * Version: 2.0.0
 */

#define MESSAGE_TO_SEND " "
#define TIME_BETWEEN 10



#if defined(ARDUINO_ARCH_AVR) && (defined(ARDUINO_attiny) || defined(ARDUINO_AVR_DIGISPARK) || defined(ARDUINO_AVR_ATTINYX4) || defined(ARDUINO_AVR_ATTINYX5) || defined(ARDUINO_AVR_ATTINYX7) || defined(ARDUINO_AVR_ATTINYX8) || defined(ARDUINO_AVR_ATTINYX61) || defined(ARDUINO_AVR_ATTINY43) || defined(ARDUINO_AVR_ATTINY828) || defined(ARDUINO_AVR_ATTINY1634) || defined(ARDUINO_AVR_ATTINYX313))
    #define ATTINY 1
#endif

 
#ifdef ATTINY
    #include "DigiKeyboard.h"
#else
    #include "Keyboard.h"
#endif

void setup() {
    #ifndef ATTINY
        Serial.begin(9600); // open the serial port
    #endif
  }

void loop() {
    #ifdef ATTINY
        // DigiKeyboard.sendKeyStroke(0); // Add if problems in old systems
        DigiKeyboard.print(MESSAGE_TO_SEND);
        DigiKeyboard.delay(TIME_BETWEEN * 1000);
    #else
        Keyboard.print(MESSAGE_TO_SEND);
        delay(TIME_BETWEEN * 1000);
    #endif
}

