//
// Created by lfnnx on 22.06.19.
//

#pragma once

#ifndef IMAGEGENERATOR_CONFIGPARSER_H
#define IMAGEGENERATOR_CONFIGPARSER_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

void load(std::string filename);

unsigned getWidth();
unsigned getHeigth();
unsigned getCount();
unsigned int * getRedStartParams();
unsigned int * getGreenStartParams();
unsigned int * getBlueStartParams();

#endif //IMAGEGENERATOR_CONFIGPARSER_H
