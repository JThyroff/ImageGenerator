//
// Created by lfnnx on 21.06.19.
//

#ifndef IMAGEGENERATOR_MAIN_H
#define IMAGEGENERATOR_MAIN_H

#endif //IMAGEGENERATOR_MAIN_H


#include "lodepng/lodepng.h"
#include "lodepng/lodepng.cpp"
#include <iostream>


typedef std::vector<unsigned char> ucVec;

void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height);