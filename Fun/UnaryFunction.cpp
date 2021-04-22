//
// Created by Johannes on 21.06.19.
//

#include <cstdlib>
#include <iostream>
#include "UnaryFunction.h"

unsigned char UnFun::evaluate(unsigned x, unsigned y, unsigned w, unsigned h) {
    switch (lop){
        case NEGATE:
            return !var->evaluate(x,y, w, h);

        case COMPLEMENT:
            return ~var->evaluate(x,y, w, h);
        default:
            std::cout<<"Fehler in UnaryFuntion";
            exit(-1);
    }
}

std::string UnFun::print() {
    std::string toPrint = "";
    switch (lop){
        case NEGATE:
            toPrint+=" !"+var->print();
            break;
        case COMPLEMENT:
            toPrint+= " ~"+var->print();
            break;
        default:
            std::cout<<"Fehler in UnaryFuntion";
            exit(-1);

    }
    return toPrint;
}
