//
// Created by lfnnx on 22.06.19.
//

#include "ConfigParser.h"

struct ConfigParser {
    unsigned width = 1024;
    unsigned height = 1024;
    unsigned count = 3;
    unsigned redStartParams[3] = {1, 1, 2};
    unsigned greenStartParams[3] = {1, 1, 2};
    unsigned blueStartParams[3] = {1, 1, 2};

    void load(std::string filename) {
        std::cout << "Loading: " + filename + "\n";

        std::ifstream inputStream;
        inputStream.open(filename);
        std::string line;
        std::string firstWord;

        if (inputStream.is_open()) {
            while (inputStream.peek() != EOF) {
                inputStream >> firstWord;

                if (firstWord == "#") {
                    //comment
                    continue;
                }

                if (firstWord == "width") {
                    inputStream >> width;
                } else if (firstWord == "height") {
                    inputStream >> height;
                } else if (firstWord == "redStartParams") {
                    inputStream >> redStartParams[0] >> redStartParams[1] >> redStartParams[2];
                } else if (firstWord == "greenStartParams") {
                    inputStream >> greenStartParams[0] >> greenStartParams[1] >> greenStartParams[2];
                } else if (firstWord == "blueStartParams") {
                    inputStream >> blueStartParams[0] >> blueStartParams[1] >> blueStartParams[2];
                } else if (firstWord == "count") {
                    inputStream >> count;
                } else {
                    std::cout << "Error. Parameter could not be read: " + firstWord + "\n";
                }
            }
        } else {
            std::cout << "Error. The config file could not be opened and thus could not be read. Path: " + filename +
                         "\n";
        }

        inputStream.close();
    }

    unsigned getWidth() { return width; }

    unsigned getHeigth() { return height; }

    unsigned getCount() { return count; }

    unsigned int *getRedStartParams() { return redStartParams; }

    unsigned int *getGreenStartParams() { return greenStartParams; }

    unsigned int *getBlueStartParams() { return blueStartParams; }
};
