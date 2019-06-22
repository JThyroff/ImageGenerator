//
// Created by lfnnx on 21.06.19.
//

#pragma once

#ifndef IMAGEGENERATOR_CONSTFUNCTION_H
#define IMAGEGENERATOR_CONSTFUNCTION_H


#include "FunctionParts.h"
#include "Function.h"

struct ConstFunction : public Function {
    ConstFunction(VARIABLES variables) {
        (*this).var = var;
    }

    VARIABLES var;

    virtual unsigned char evaluate(unsigned x, unsigned y) override {
        switch (var) {
            case X:
                return x;
            case Y:
                return y;
            case Z:
                return 255;
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
        }
    }
};


#endif //IMAGEGENERATOR_CONSTFUNCTION_H
