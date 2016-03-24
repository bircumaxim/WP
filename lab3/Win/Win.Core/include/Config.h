//
// Created by bircumaxim on 3/19/2016.
//

#ifndef LAB3_CONFIG_H
#define LAB3_CONFIG_H

#include <windows.h>
#include <iostream>
#include <c++/stack>

using namespace std;

class Config {

    private:
        stack<UINT> idPool;
    public:
        UINT idGen();
        static Config& instance() {
            static Config instance;
            return instance;
        }
};


#endif //LAB3_CONFIG_H
