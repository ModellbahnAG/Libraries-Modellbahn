/**
* @file LightEffects.h
* @author Dennis Moschina
* @date 28 Dec 2020
* @copyright 2020 Dennis Moschina
* @brief Eine Sammlung von Lichteffekten, die immer mal wieder gebraucht werden
* können.
*/

#ifndef LIGHTEFFECTS_H
#define LIGHTEFFECTS_H

#include <Arduino.h>
#include "NeoPixel.h"

/**
* @class LightEffects
* @brief Eine Sammlung von Lichteffekten, die immer mal wieder gebraucht werden
* können.
* @details Für jede dieser Funktionen muss vorher eine Instanz von NeoPixel
* erzeugt werden.
*/
class LightEffects {
  public:
    /**
    * @brief Simuliere einen Blitz für eine bestimmte Zeit.
    *
    * @param led ein Zeiger auf die vorher erstellte Instanz von NeoPixel
    * @param duration die Zeit, die der Blitz dauern soll in Sekunden. Der
    * Standardwert ist eine Sekunde.
    *
    * @details Der Blitz kann sowohl für Gewitter, als auch für Explosionen
    * eingesetzt werden.
    * Wird kein Wert für @p duration angegeben, wird der Standardwert
    * 1 verwendet.
    */
    static void flash(NeoPixel* led, int duration = 1);

    /**
    * @brief Simuliere eine Fackel. Für eine bestimmte Zeit.
    *
    * @param led ein Zeiger auf die vorher erstellte Instanz von NeoPixel
    * @param duration die Zeit, die die Fackeln leuchten sollen in Sekunden. Der
    * Standardwert ist 10 Sekunden.
    *
    * @details Wird kein Wert für @p duration angegeben, wird der Standardwert
    * 10 verwendet.
    */
    static void torch(NeoPixel* led, int duration = 10);

    /**
    * @brief Simuliere ein Feuer für eine bestimmte Zeit.
    *
    * @param led ein Zeiger auf die vorher erstellte Instanz von NeoPixel
    * @param duration die Zeit, die das Feuer brennen soll in Sekunden. Der
    * Standardwert ist 10 Sekunden.
    *
    * @details Wird kein Wert für @p duration angegeben, wird der Standardwert
    * 10 verwendet.
    */
    static void fire(NeoPixel* led, int duration = 10);
};

#endif
