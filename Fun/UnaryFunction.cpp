//
// Created by lfnnx on 21.06.19.
//

#include <cstdlib>
#include <iostream>
#include "UnaryFunction.h"

unsigned UnaryFunction::evaluate() {
    switch (lop){
        case ausruf:
            return !var;

        case tilde:break;
        default:
            std::cout<<"Fehler in UnaryFuntion";
            exit(-1);
    }
}
