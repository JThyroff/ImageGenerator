//
// Created by lfnnx on 21.06.19.
//
#pragma once

#ifndef IMAGEGENERATOR_BINARYFUNCTION_H
#define IMAGEGENERATOR_BINARYFUNCTION_H


#include <cstdlib>
#include <iostream>
#include "Function.h"
#include "FunctionParts.h"

struct BinaryFunction : public Function{
    Function * varl;
    Function * varr;
    ARITHOP aop;
    LOGOP lop;
    bool aritop = false;

    BinaryFunction(Function * varl, Function * varr, ARITHOP op) {
        this->varl = varl;
        this->varr = varr;
        this->aop = op;
        aritop = true;
    }

    BinaryFunction(Function * varl,Function* varr,LOGOP op){
        this->varl = varl;
        this->varr = varr;
        this->lop = op;
        aritop = false;
    }

    ~BinaryFunction(){
        delete(varl);
        delete(varr);
    }

    virtual unsigned char evaluate(unsigned x, unsigned y, unsigned w, unsigned h) override ;

    virtual std::string print() override ;
};


#endif //IMAGEGENERATOR_BINARYFUNCTION_H
