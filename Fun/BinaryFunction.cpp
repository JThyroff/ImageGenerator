//
// Created by lfnnx on 21.06.19.
//

#include "BinaryFunction.h"
unsigned BinaryFunction::evaluate(){
    if(aritop){
        switch (aop){
            case plus:
                return varr + varl;
            case minus:
                return varl-varr;
            case mal:
                return varl*varr;
            case geteilt:
                return varl / varr;
        }
    }else{
        switch (lop){
            case oder:
                return varr | varl;

            case und:
                return varl & varr;
            case xoder:
                return varl ^varr;
            default:
                std::cout<<"Fehler in BinaryFunction.h";
                exit(-1);
        }
    }
}