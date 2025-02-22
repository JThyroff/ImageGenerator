//
// Created by Johannes on 21.06.19.
//

#ifndef IMAGEGENERATOR_GENERATORS_H
#define IMAGEGENERATOR_GENERATORS_H

#endif //IMAGEGENERATOR_GENERATORS_H

#include <iostream>
#include <vector>
#include "../Fun/Function.h"

typedef std::vector<unsigned char> ucVec;

void genBasedOnFunctions(ucVec & image, unsigned width, unsigned height, Function * red [],Function * green[],Function * blue[], unsigned arraySize);

void gen1(ucVec &image, unsigned width, unsigned height);

void gen2(ucVec &image, unsigned width, unsigned height);

void gen3(ucVec &image, unsigned width, unsigned height);

void gen4(ucVec &image, unsigned width, unsigned height);

void gen5(ucVec &image, unsigned width, unsigned height);

void gen6(ucVec &image, unsigned width, unsigned height);

void gen7(ucVec &image, unsigned width, unsigned height);

void gen8(ucVec & image,unsigned width, unsigned height);

void gen9(ucVec & image,unsigned width, unsigned height);