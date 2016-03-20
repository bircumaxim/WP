//
// Created by bircumaxim on 3/19/2016.
//

#include "../include/Config.h"

UINT Config::idGen(){
    UINT newId = this->idPool.size();
    this->idPool.push(newId);
    return newId;
}