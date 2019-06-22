//
// Created by lfnnx on 21.06.19.
//

#include "BinaryFunction.h"

unsigned char BinaryFunction::evaluate(unsigned x, unsigned y) {
    if (aritop) {
        switch (aop) {
            case PLUS:
                return varr->evaluate(x, y) + varl->evaluate(x, y);
            case MINUS:
                return varl->evaluate(x, y) - varr->evaluate(x, y);
            case MUL:
                return varl->evaluate(x, y) * varr->evaluate(x, y);
            case DIV:
                return varl->evaluate(x, y) / (varr->evaluate(x, y) + 1);//no division by 0
        }
    } else {
        switch (lop) {
            case OR:
                return varr->evaluate(x, y) | varl->evaluate(x, y);

            case AND:
                return varl->evaluate(x, y) & varr->evaluate(x, y);
            case XOR:
                return varl->evaluate(x, y) ^ varr->evaluate(x, y);
            default:
                std::cout << "Fehler in BinaryFunction.h";
                exit(-1);
        }
    }
}

std::string BinaryFunction::print() {
    std::string toPrint = "(" + varl->print() + " ";
    if (aritop) {
        switch (aop) {
            case PLUS:
                toPrint += "+ ";
                break;
            case MINUS:
                toPrint += "- ";
                break;
            case MUL:
                toPrint += "* ";
                break;
            case DIV:
                toPrint += "/ ";
                break;
        }
    } else {
        switch (lop) {
            case OR:
                toPrint += "| ";
                break;
            case AND:
                toPrint += "& ";
                break;
            case XOR:
                toPrint += "^ ";
                break;
            default:
                std::cout << "Fehler in BinaryFunction.h";
                exit(-1);
        }
    }
    toPrint += varr->print() + ")";
    return toPrint;
}
