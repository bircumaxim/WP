//
// Created by bircumaxim on 3/20/2016.
//

#ifndef LAB3_TETRAGON_H
#define LAB3_TETRAGON_H


#include "../../../Tools/Pen/include/Pen.h"

class Tetragon : public Pen {
    private:
        int length = 0;
        bool regular = false;
        virtual void MouseButtonDown(LPARAM,WPARAM) override;
        virtual void MouseButtonUp(LPARAM,WPARAM) override;
        virtual void MouseMove(LPARAM,WPARAM) override;
    public:
        Tetragon(HWND hwnd) : Pen(hwnd){}

        void setRegular(bool regular) {
            Tetragon::regular = regular;
        }


    bool isRegular() const {
        return regular;
    }
};


#endif //LAB3_TETRAGON_H
