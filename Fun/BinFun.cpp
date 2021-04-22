//
// Created by Johannes on 21.06.19.
//

#include "BinFun.h"

unsigned char BinFun::evaluate(unsigned x, unsigned y, unsigned w, unsigned h) {
    if (aritop) {
        switch (aop) {
            case PLUS:
                return varr->evaluate(x, y, w, h) + varl->evaluate(x, y, w, h);
            case MINUS:
                return varl->evaluate(x, y, w, h) - varr->evaluate(x, y, w, h);
            case MUL:
                return varl->evaluate(x, y, w, h) * varr->evaluate(x, y, w, h);
            case DIV:
                return varl->evaluate(x, y, w, h) / (varr->evaluate(x, y, w, h) + 1);//no division by 0
        }
    } else {
        switch (lop) {
            case OR:
                return varr->evaluate(x, y, w, h) | varl->evaluate(x, y, w, h);

            case AND:
                return varl->evaluate(x, y, w, h) & varr->evaluate(x, y, w, h);
            case XOR:
                return varl->evaluate(x, y, w, h) ^ varr->evaluate(x, y, w, h);
            default:
                std::cout << "Fehler in BinFun.h";
                exit(-1);
        }
    }
}

std::string BinFun::print() {
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
                std::cout << "Fehler in BinFun.h";
                exit(-1);
        }
    }
    toPrint += varr->print() + ")";
    return toPrint;
}
