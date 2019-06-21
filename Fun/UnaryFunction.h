//
// Created by lfnnx on 21.06.19.
//

#ifndef IMAGEGENERATOR_UNARYFUNCTION_H
#define IMAGEGENERATOR_UNARYFUNCTION_H


#include "FunctionParts.h"

struct UnaryFunction {
    unsigned var;
    LOGOP lop;

    UnaryFunction(unsigned  var,LOGOP op){
        this->var = var;
        this->lop = op;
    }
    unsigned evaluate();
};


#endif //IMAGEGENERATOR_UNARYFUNCTION_H
