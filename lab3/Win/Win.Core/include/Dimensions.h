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
    Dimensions(int x,int y);

    Dimensions(int x,int y,int w,int h);

    int getPosX() const;

    void setPosX(int posX);

    int getPosY() const;

    void setPosY(int posY);

    int getWidth() const;

    void setWidth(int width);

    int getHeight() const;

    void setHeight(int height);
};


#endif //LAB1_DIMENSIONS_H
