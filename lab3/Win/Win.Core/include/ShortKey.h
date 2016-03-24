//
// Created by bircumaxim on 3/21/2016.
//

#ifndef LAB3_SHORTKEY_H
#define LAB3_SHORTKEY_H

#include <windows.h>
#include "Config.h"

class ShortKey {
    private:
        HWND hwnd;
        int id;
        UINT key;
    public:
        ShortKey(HWND hwnd,UINT key){
            this->hwnd = hwnd;
            this->key = key;
            this->id = Config::instance().idGen();
            RegisterHotKey(this->hwnd,this->id,MOD_CONTROL,this->key);
        }

    int getId() const {
        return id;
    }
};


#endif //LAB3_SHORTKEY_H
