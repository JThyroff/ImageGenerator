//
// Created by lfnnx on 21.06.19.
//

#ifndef IMAGEGENERATOR_FUNCTION_H
#define IMAGEGENERATOR_FUNCTION_H


#include <vector>
#include "FunctionParts.h"

typedef std::vector<LOGOP> logOpVec;
typedef std::vector<ARITHOP> arithOpVec;
typedef std::vector<VARIABLES> varVec;
typedef std::vector<R> order;

struct Function {
    logOpVec logOpVec1;
    arithOpVec arithOpVec1;
    varVec varVec1;
    order order1;

    Function(logOpVec logOpVec1, arithOpVec arithOpVec1, varVec varVec1, order order1) {
        this->logOpVec1 = logOpVec1;
        this->arithOpVec1 = arithOpVec1;
        this->varVec1 = varVec1;
        this->order1 = order1;
    }

    unsigned char evaluate(unsigned x, unsigned y);
};

#endif //IMAGEGENERATOR_FUNCTION_H
