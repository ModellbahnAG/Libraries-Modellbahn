/**
* @file NeoPixel.h
* @author Dennis Moschina
* @date 28 Dec 2020
* @copyright 2020 Dennis Moschina
* @brief Ein einfacher Wrapper für die FastLED Bibliothek.
*/

#ifndef NEOPIXEL_H
#define NEOPIXEL_H

#include <Arduino.h>
#include <FastLED.h>

/**
* @class NeoPixel
* @brief Füge einfach neue LED strips zum Projekt hinzu und steuere diese mit
* den grundlegensten Funktionen an.
* @details Diese Klasse implementiert nur die grundlegensten Funktionen. Für
* alles aufwendigeres wird empfohlen die FastLED Bibliothek direkt zu verwenden.
* Derzeit können nur die Pins 2 bis 13 verwendet werden!
*
* @todo Weitere Pins verfügbar machen
*/
class NeoPixel {
  public:
    /**
    * @brief Erstelle einen LED strip mit einer festen Anzahl an LEDs und
    * steuere diesen leicht an.
    *
    * @param numPixel Die Anzahl der LEDs im LED strip
    * @param pin Der Pin, an den der LED strip angeschlossen ist
    *
    * @return Referenz zur Instanz von NeoPixel
    *
    * @details Derzeit können nur die Pins 2 bis 13 verwendet werden!
    */
    NeoPixel(int numPixel, int pin);

    /**
    * @brief Ändere die Farbe aller LEDs in einem bestimmten Intervall.
    *
    * @param color Die Farbe die die LEDs bekommen sollen
    * @param start Start des Intervalls in dem die LEDs die Farbe bekommen sollen.
    * Der Standardwert ist 0
    * @param end Ende des Intervalls in dem die LEDs die Farbe bekommen sollen.
    * Der Standardwert ist die Anzahl der LEDs im strip
    */
    void fill(CRGB color, int start = 0, int end = -1);
    /**
    * @brief Ändere die Farbe aller LEDs in einem bestimmten Intervall.
    *
    * @param r Der Rotanteil der Farbe die die LEDs bekommen sollen
    * @param g Der Grünanteil der Farbe die die LEDs bekommen sollen
    * @param b Der Blauanteil der Farbe die die LEDs bekommen sollen
    * @param start Start des Intervalls in dem die LEDs die Farbe bekommen sollen.
    * Der Standardwert ist 0
    * @param end Ende des Intervalls in dem die LEDs die Farbe bekommen sollen.
    * Der Standardwert ist die Anzahl der LEDs im strip
    */
    void fill(int r, int g, int b, int start = 0, int end = -1);

    /**
    * @brief Ändere die Farbe einer LED
    *
    * @param color Die Farbe die die LED bekommen soll
    * @param pixel Die Nummer der LED die die Farbe bekommen soll
    */
    void setColor(CRGB color, int pixel);
    /**
    * @brief Ändere die Farbe einer LED
    *
    * @param r Der Rotanteil der Farbe die die LED bekommen soll
    * @param g Der Grünanteil der Farbe die die LED bekommen soll
    * @param b Der Blauanteil der Farbe die die LED bekommen soll
    * @param pixel Die Nummer der LED die die Farbe bekommen soll
    */
    void setColor(int r, int g, int b, int pixel);

    /**
    * @brief Ändere die Helligkeit einer LED oder aller LEDs gleichzeitig.
    * @param brightness Die zu setzende Helligkeit. Liegt im Intervall [0, 255].
    * Der Standardwert ist das Maximum von 255
    * @param pixel Die Nummer der LED, die ihre Helligkeit ändern soll. Der
    * Standardwert sind alle LEDs gleichzeitig
    */
    void setBrightness(int brightness = 255, int pixel = -1);

    /**
    * @brief Schalte alle LEDs aus
    * @details Alle LEDs werden auf die Farbe Schwarz gesetzt
    */
    void off();

    /**
    * @brief Erhalte die Anzahl der LEDs im strip
    * @return Anzahl der LEDs im strip
    */
    int getNumberOfPixels();

  private:
    int pin;
    int numPixel;
    CRGBSet leds = CRGBSet(new CRGB[0], 0);
};

#endif
