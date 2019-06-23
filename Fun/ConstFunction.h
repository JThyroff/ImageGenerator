//
// Created by lfnnx on 21.06.19.
//

#pragma once

#ifndef IMAGEGENERATOR_CONSTFUNCTION_H
#define IMAGEGENERATOR_CONSTFUNCTION_H


#include "FunctionParts.h"
#include "Function.h"

struct ConstFunction : public Function {
    VARIABLES var;

    ConstFunction(VARIABLES variables) {
        this->var = variables;
    }

    ~ConstFunction(){

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


#endif //IMAGEGENERATOR_CONSTFUNCTION_H
