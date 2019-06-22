//
// Created by lfnnx on 21.06.19.
//
#pragma once

#ifndef IMAGEGENERATOR_UNARYFUNCTION_H
#define IMAGEGENERATOR_UNARYFUNCTION_H


#include "Function.h"
#include "FunctionParts.h"

struct UnaryFunction : public Function{
    Function var;
    LOGOP lop;

    UnaryFunction(Function var,LOGOP op){
        this->var = var;
        this->lop = op;
    }
    virtual unsigned char evaluate(unsigned x, unsigned y) override;

    virtual std::string print() override ;
};


#endif //IMAGEGENERATOR_UNARYFUNCTION_H
