//
// Created by Johannes Thyroff on 21.06.19.
//

#pragma once

#ifndef IMAGEGENERATOR_MAIN_H
#define IMAGEGENERATOR_MAIN_H

#include "lodepng/lodepng.h"
#include "lodepng/lodepng.cpp"
#include <iostream>
#include <vector>
#include "Gen/generators.h"
#include "Gen/FunctionGenerator.cpp"
#include "ConfigParser.h"
#include "ConfigParser.cpp"
#include <chrono>

typedef std::vector<unsigned char> ucVec;
unsigned getArraySize(unsigned e);
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height);

#endif //IMAGEGENERATOR_MAIN_H
