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
*
* @details Diese Klasse implementiert nur die grundlegensten Funktionen. Für
* alles aufwendigere wird empfohlen die [FastLED Bibliothek](http://fastled.io)
* direkt zu verwenden.
* Derzeit können nur die Pins 2 bis 13 verwendet werden!
*
* @example NeoPixelExample.cpp
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
    * @details Derzeit können nur die Pins 2 bis 13 verwendet werden!
    * @todo Weitere Pins verfügbar machen
    */
    NeoPixel(int numPixel, int pin);

    /**
    * @brief Ändere die Farbe aller LEDs in einem bestimmten Intervall.
    *
    * @param color Die Farbe die die LEDs bekommen sollen als Typ
    * [CRGB](http://fastled.io/docs/3.1/struct_c_r_g_b.html). Die Farbe kann
    * als Hexcode (@c 0xFF0000 für Rot), als @c CRGB(255,0,0) für Rot, oder
    * als @c CRGB::Red angegeben werden.
    * @param start Start des Intervalls in dem die LEDs die Farbe bekommen sollen.
    * Der Standardwert ist 0
    * @param end Ende des Intervalls in dem die LEDs die Farbe bekommen sollen.
    * Der Standardwert ist die letze LED. Wird dieser Wert angegeben, muss auch
    * @p start angegeben werden.
    *
    * @details Werden keine Werte für @p start und @p end angegeben, werden
    * hierfür die Standardwerte verwendet.
    * <p> Diese Methode macht das gleiche wie
    * {@link NeoPixel::fill(int r, int g, int b, int start = 0, int end = -1)}
    * und unterscheidet sich von ihr nur in ihren Parametern.
    */
    void fill(CRGB color, int start = 0, int end = -1);
    /**
    * @brief @copybrief fill(CRGB color, int start = 0, int end = -1)
    *
    * @param r Der Rotanteil der Farbe die die LEDs bekommen sollen
    * @param g Der Grünanteil der Farbe die die LEDs bekommen sollen
    * @param b Der Blauanteil der Farbe die die LEDs bekommen sollen
    * @param start Start des Intervalls in dem die LEDs die Farbe bekommen sollen.
    * Der Standardwert ist 0
    * @param end Ende des Intervalls in dem die LEDs die Farbe bekommen sollen.
    * Der Standardwert ist die letze LED. Wird dieser Wert angegeben, muss auch
    * @p start angegeben werden.
    *
    * @details Werden keine Werte für @p start und @p end angegeben, werden
    * hierfür die Standardwerte verwendet.
    * <p>
    * Diese Methode macht das gleiche wie
    * {@link NeoPixel::fill(CRGB color, int start = 0, int end = -1)} und
    * unterscheidet sich von ihr nur in ihren Parametern.
    */
    void fill(int r, int g, int b, int start = 0, int end = -1);

    /**
    * @brief Ändere die Farbe einer LED
    *
    * @param color Die Farbe, die die LED bekommen soll als Typ
    * [CRGB](http://fastled.io/docs/3.1/struct_c_r_g_b.html). Die Farbe kann
    * als Hexcode (@c 0xFF0000 für Rot), als @c CRGB(255,0,0) für Rot, oder
    * als @c CRGB::Red angegeben werden.
    * @param pixel Die Nummer der LED die die Farbe bekommen soll
    *
    * @details Diese Methode macht das gleiche wie
    * {@link NeoPixel::setColor(int r, int g, int b, int pixel)} und unterscheidet sich
    * von ihr nur in ihren Parametern.
    */
    void setColor(CRGB color, int pixel);
    /**
    * @copybrief setColor()
    *
    * @param r Der Rotanteil der Farbe, die die LED bekommen soll
    * @param g Der Grünanteil der Farbe, die die LED bekommen soll
    * @param b Der Blauanteil der Farbe, die die LED bekommen soll
    * @param pixel Die Nummer der LED die die Farbe bekommen soll
    *
    * @details Diese Methode macht das gleiche wie
    * {@link NeoPixel::setColor(CRGB color, int pixel)} und unterscheidet sich
    * von ihr nur in ihren Parametern.
    */
    void setColor(int r, int g, int b, int pixel);

    /**
    * @brief Ändere die Helligkeit einer LED oder aller LEDs gleichzeitig
    *
    * @param brightness Die zu setzende Helligkeit. Liegt im Intervall [0, 255].
    * Der Standardwert ist das Maximum von 255
    * @param pixel Die Nummer der LED, die ihre Helligkeit ändern soll. Der
    * Standardwert sind alle LEDs gleichzeitig
    *
    * @details Die Farbe der LED(s) bleibt dabei erhalten. Es kann sogar von
    * einer dunklen Farbe, wie @c CRGB(10, 10, 10) die Helligkeit erhöht
    * werden.
    */
    void setBrightness(int brightness = 255, int pixel = -1);

    /**
    * @brief Schalte alle LEDs aus
    * @details Alle LEDs werden auf die Farbe Schwarz gesetzt. Um eine einzele
    * LED auszuschalten muss @c NeoPixel::setColor(CRGB::Black, <Nummer der LED>)
    * verwendet werden.
    */
    void off();

    /**
    * @brief Erhalte die Anzahl der LEDs.
    *
    * @attention Diese Methode kann nicht genutzt werden um automatisch
    * herauszufinden wie viele LEDs angeschlossen, sie gibt lediglich zurück,
    * was als Anzahl der LEDs vorher angegeben wurde.
    *
    * @return Anzahl der LEDs im strip
    */
    int getNumberOfPixels();

    /**
    * @brief @copybrief LightEffects::flash()
    *
    * @param duration die Zeit, die der Blitz dauern soll in Sekunden. Der Standardwert ist eine Sekunde.
    *
    * @details Der Blitz kann sowohl für Gewitter, als auch für Explosionen
    * eingesetzt werden. Wird kein Wert für @p duration angegeben, wird der
    * Standardwert 1 verwendet.
    *
    * @note Diese Methode ist äquivalent zu LightEffects::flash()
    */
    void flash(int duration = 1);
    /**
    * @brief @copybrief LightEffects::torch()
    *
    * @param duration die Zeit, die die Fackeln leuchten sollen in Sekunden. Der
    * Standardwert ist eine Sekunde.
    *
    * @details Der Blitz kann sowohl für Gewitter, als auch für Explosionen
    * eingesetzt werden. Wird kein Wert für @p duration angegeben, wird der
    * Standardwert 1 verwendet.
    *
    * @note Diese Methode ist äquivalent zu LightEffects::torch()
    */
    void torch(int duration = 10);
    /**
    * @brief @copybrief LightEffects::fire()
    *
    * @param duration die Zeit, die das Feuer brennen soll in Sekunden. Der
    * Standardwert ist 10 Sekunden.
    *
    * @details Wird kein Wert für @p duration angegeben, wird der
    * Standardwert 10 verwendet.
    *
    * @note Diese Methode ist äquivalent zu LightEffects::fire()
    */
    void fire(int duration = 10);

  private:
    int pin;
    int numPixel;
    CRGBSet leds = CRGBSet(new CRGB[0], 0);
};




#endif
