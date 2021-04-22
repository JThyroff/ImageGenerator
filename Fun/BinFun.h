//
// Created by Johannes on 21.06.19.
//
#pragma once

#ifndef IMAGEGENERATOR_BINFUN_H
#define IMAGEGENERATOR_BINFUN_H


#include <cstdlib>
#include <iostream>
#include "Function.h"
#include "FunctionParts.h"

struct BinFun : public Function{
    Function * varl;
    Function * varr;
    ARITHOP aop;
    LOGOP lop;
    bool aritop = false;

    BinFun(Function * varl, Function * varr, ARITHOP op) {
        this->varl = varl;
        this->varr = varr;
        this->aop = op;
        aritop = true;
    }

    BinFun(Function * varl,Function* varr,LOGOP op){
        this->varl = varl;
        this->varr = varr;
        this->lop = op;
        aritop = false;
    }

    ~BinFun(){
        delete(varl);
        delete(varr);
    }

    virtual unsigned char evaluate(unsigned x, unsigned y, unsigned w, unsigned h) override ;

    virtual std::string print() override ;
};


#endif //IMAGEGENERATOR_BINFUN_H
