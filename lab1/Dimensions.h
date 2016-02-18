//
// Created by max on 2/18/2016.
//

#ifndef LAB1_DIMENSIONS_H
#define LAB1_DIMENSIONS_H


class Dimensions {
private:
    int posX;
    int posY;
    int width;
    int height;
public:
    Dimensions(int x,int y,int w,int h){
        this->posX = x;
        this->posY = y;
        this->width = w;
        this->height = h;
    }

    int getPosX() const {
        return posX;
    }

    void setPosX(int posX) {
        Dimensions::posX = posX;
    }

    int getPosY() const {
        return posY;
    }

    void setPosY(int posY) {
        Dimensions::posY = posY;
    }

    int getWidth() const {
        return width;
    }

    void setWidth(int width) {
        Dimensions::width = width;
    }

    int getHeight() const {
        return height;
    }

    void setHeight(int height) {
        Dimensions::height = height;
    }
};


#endif //LAB1_DIMENSIONS_H
