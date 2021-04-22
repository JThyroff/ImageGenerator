//
// Created by Johannes on 21.06.19.
//

#pragma once

#ifndef IMAGEGENERATOR_FUNCTION_H
#define IMAGEGENERATOR_FUNCTION_H

class Function {
public:
     virtual unsigned char evaluate(unsigned x, unsigned y, unsigned w, unsigned h){};
     virtual std::string print(){ return "salat";};
};

#endif //IMAGEGENERATOR_FUNCTION_H
