//
// Created by max on 2/18/2016.
//

#include "../include/Dimensions.h"
Dimensions::Dimensions(int x,int y){
    this->posX = x;
    this->posY = y;
    this->width = 0;
    this->height = 0;
}

Dimensions::Dimensions(int x,int y,int w,int h){
    this->posX = x;
    this->posY = y;
    this->width = w;
    this->height = h;
}

int Dimensions::getPosX() const {
    return posX;
}

void Dimensions::setPosX(int posX) {
    Dimensions::posX = posX;
}

int Dimensions::getPosY() const {
    return posY;
}

void Dimensions::setPosY(int posY) {
    Dimensions::posY = posY;
}

int Dimensions::getWidth() const {
    return width;
}

void Dimensions::setWidth(int width) {
    Dimensions::width = width;
}

int Dimensions::getHeight() const {
    return height;
}

void Dimensions::setHeight(int height) {
    Dimensions::height = height;
}