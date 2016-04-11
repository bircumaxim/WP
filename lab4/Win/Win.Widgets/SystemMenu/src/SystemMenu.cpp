//
// Created by bircumaxim on 3/19/2016.
//

#include "../include/SystemMenu.h"

SystemMenu::SystemMenu(){
    hmenu = CreateMenu();
}

void SystemMenu::AppendPopup(HMENU popupHemnu,LPCSTR label) {
    AppendMenu(this->hmenu, MF_STRING | MF_POPUP, (UINT_PTR )popupHemnu, label);
}