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
    * @brief Simuliere einen Blitz.
    *
    * @param led ein Zeiger auf die vorher erstellte Instanz von NeoPixel
    *
    * @details Der Blitz kann sowohl für Gewitter, als auch für Explosionen
    * eingesetzt werden.
    */
    static void flash(NeoPixel* led);

    /**
    * @brief Simuliere eine Fackel.
    *
    * @param led ein Zeiger auf die vorher erstellte Instanz von NeoPixel
    */
    static void torch(NeoPixel* led);

    /**
    * @brief Simuliere ein Feuer.
    *
    * @param led ein Zeiger auf die vorher erstellte Instanz von NeoPixel
    */
    static void fire(NeoPixel* led);
};

#endif
