//
// Created by lfnnx on 21.06.19.
//

#ifndef IMAGEGENERATOR_BINARYFUNCTION_H
#define IMAGEGENERATOR_BINARYFUNCTION_H


#include <bits/valarray_before.h>
#include <cstdlib>
#include <iostream>
#include "FunctionParts.h"

struct BinaryFunction {
    unsigned varl;
    unsigned varr;
    ARITHOP aop;
    LOGOP lop;
    bool aritop = false;

    BinaryFunction(unsigned varl, unsigned varr, ARITHOP op) {
        this->varl = varl;
        this->varr = varr;
        this->aop = op;
        aritop = true;
    }

    BinaryFunction(unsigned  varl,unsigned  varr,LOGOP op){
        this->varl = varl;
        this->varr = varr;
        this->lop = op;
        aritop = false;
    }
    unsigned evaluate();
};


#endif //IMAGEGENERATOR_BINARYFUNCTION_H
