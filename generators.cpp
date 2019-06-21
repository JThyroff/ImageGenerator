//
// Created by lfnnx on 21.06.19.
//

#include "generators.h"

void gen1(ucVec & image,unsigned width, unsigned height){

    for(unsigned y = 0; y < height; y++)
        for(unsigned x = 0; x < width; x++) {
            image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = x | y;
            image[4 * width * y + 4 * x + 3] = 255;
        }
}

void gen2(ucVec & image,unsigned width, unsigned height){

    for(unsigned y = 0; y < height; y++)
        for(unsigned x = 0; x < width; x++) {
            image[4 * width * y + 4 * x + 0] = 255 * !(x | y);
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = x & y;
            image[4 * width * y + 4 * x + 3] = 255;
        }
}

void gen3(ucVec & image,unsigned width, unsigned height){

    for(unsigned y = 0; y < height; y++)
        for(unsigned x = 0; x < width; x++) {
            image[4 * width * y + 4 * x + 0] = 255 * !(x ^ y);
            image[4 * width * y + 4 * x + 1] = !x ^ y;
            image[4 * width * y + 4 * x + 2] = x + y * 2 % 255;
            image[4 * width * y + 4 * x + 3] = 255;
        }
}

void gen4(ucVec & image,unsigned width, unsigned height){

    for(unsigned y = 0; y < height; y++)
        for(unsigned x = 0; x < width; x++) {

            image[4 * width * y + 4 * x + 0] = ((x | y) * (y / 255) + ((255 - y) / 255) * x & y) % 255;
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = x * y % 255;
            image[4 * width * y + 4 * x + 3] = 255;

        }
}

void gen5(ucVec & image,unsigned width, unsigned height){

    for(unsigned y = 0; y < height; y++)
        for(unsigned x = 0; x < width; x++) {

            image[4 * width * y + 4 * x + 0] = x * y % 255;
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = ((x | y) * (y / 255) + ((255 - y) / 255) * x & y) % 255;
            image[4 * width * y + 4 * x + 3] = 255;

        }
}