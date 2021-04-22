//
// Created by Johannes on 21.06.19.
//

#pragma once

#ifndef IMAGEGENERATOR_CONSTFUN_H
#define IMAGEGENERATOR_CONSTFUN_H


#include "FunctionParts.h"
#include "Function.h"

struct ConstFun : public Function {
    VARIABLES var;

    ConstFun(VARIABLES variables) {
        this->var = variables;
    }

    ~ConstFun(){

    }

    virtual unsigned char evaluate(unsigned x, unsigned y,unsigned w, unsigned h) override {

        switch (var) {
            case X:
                return x;
            case Y:
                return y;
            case Z:
                return 255;
            case W:
                return w;
            case H:
                return h;
        }
    }

    virtual std::string print() override {
        switch (var) {
            case X:
                return "X";
            case Y:
                return "Y";
            case Z:
                return "255";
            case W:return "WIDTH";
            case H:return "HEIGHT";
        }
    }
};


#endif //IMAGEGENERATOR_CONSTFUN_H
