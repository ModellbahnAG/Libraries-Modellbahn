/**
* @file ButtonManager.h
* @author Dennis Moschina
* @date 28 Dec 2020
* @copyright 2020 Dennis Moschina
*
* @brief Verwalte einfach mehrere Buttons in einem Programm.
*/

#ifndef BUTTON_MANAGER_H
#define BUTTON_MANAGER_H

#include <Arduino.h>
#include "Button.h"

/**
* @class ButtonListItem
* @brief Ein Element einer Linked List in der alle Buttons gespeichert werden.
* So können beliebig viele Buttons erzeugt werden.
*/
struct ButtonListItem {
  Button* button;
  ButtonListItem* next;
};

/**
* @class ButtonManager
* @brief Verwalte einfach mehrere Buttons in einem Programm.
*
* @details Es werden keine Instanzen dieser Klasse erstellt.
*
* @example ButtonManagerExample.cpp
*/
class ButtonManager {
  public:
    /**
    * @brief Füge einen neuen Button hinzu der verwaltet werden soll
    *
    * @param newButton Zeiger auf einen Button
    */
    static void addButton(Button* newButton);


    /**
    * @brief Überprüfe, ob ein Button gedrückt wurde oder ob einer wieder aktiviert
		* werden kann. Diese Methode muss in der loop() aufgerufen werden
    *
    * @details Wurde ein aktiver Button gedrückt, wird die durch Button::setCallback()
		* festgelegte Funktion ausgeführt.
    */
    static void handleButtons();

  private:
    static ButtonListItem* listHead;
};
#endif
