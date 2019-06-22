//
// Created by lfnnx on 21.06.19.
//

#include <cstdlib>
#include <iostream>
#include "UnaryFunction.h"

unsigned char UnaryFunction::evaluate(unsigned x, unsigned y) {
    switch (lop){
        case NEGATE:
            return !var->evaluate(x,y);

        case COMPLEMENT:
            return ~var->evaluate(x,y);
        default:
            std::cout<<"Fehler in UnaryFuntion";
            exit(-1);
    }
}

std::string UnaryFunction::print() {
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
