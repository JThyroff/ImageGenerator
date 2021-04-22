//
// Created by Johannes on 21.06.19.
//

#include "generators.h"
#include "../Fun/Function.h"

/*
f
f
	f
f
f
	f
		f
f
f
	f
f
f
	f
		f
			f
 * */
unsigned ev(Function *fun[], unsigned x, unsigned y, unsigned w, unsigned h, unsigned idx, unsigned recDepth) {

    recDepth = (recDepth - 1) / 2;
    unsigned eins;
    unsigned zwei;
    if (recDepth == 1) {
        eins = fun[idx - 1]->evaluate(x, y, w, h);
        zwei = fun[idx - 2]->evaluate(x, y, w, h);
    } else {
        eins = ev(fun, x, y, w, h, idx - 1, recDepth);
        zwei = ev(fun, x, y, w, h, (idx - 1) - recDepth, recDepth);
    }

    return fun[idx]->evaluate(eins, zwei, w, h);
}

void
genBasedOnFunctions(ucVec &image, unsigned width, unsigned height, Function *red[], Function *green[], Function *blue[],
                    unsigned arraySize) {
    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {
            unsigned blueRes;
            unsigned redRes;
            unsigned greenRes;
            if (arraySize == 1) {
                blueRes = blue[0]->evaluate(x, y, width, height);
                redRes = blue[0]->evaluate(x, y, width, height);
                greenRes = blue[0]->evaluate(x, y, width, height);
            } else {

                blueRes = ev(blue, x, y, width, height, arraySize - 1, arraySize);
                redRes = ev(red, x, y, width, height, arraySize - 1, arraySize );
                greenRes = ev(green, x, y, width, height, arraySize - 1, arraySize);
            }

            image[4 * width * y + 4 * x + 0] = redRes;
            image[4 * width * y + 4 * x + 1] = greenRes;
            image[4 * width * y + 4 * x + 2] = blueRes;
            image[4 * width * y + 4 * x + 3] = 255;
        }
}

void gen1(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {
            image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = x | y;
            image[4 * width * y + 4 * x + 3] = 255;
        }
}

void gen2(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {
            image[4 * width * y + 4 * x + 0] = 255 * !(x | y);
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = x & y;
            image[4 * width * y + 4 * x + 3] = 255;
        }
}

void gen3(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {
            image[4 * width * y + 4 * x + 0] = x * y / width;
            image[4 * width * y + 4 * x + 1] = (x - y) / (height * x);
            image[4 * width * y + 4 * x + 2] = (x - y) / (width - height);
            image[4 * width * y + 4 * x + 3] = 255;
        }
}

void gen4(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {

            image[4 * width * y + 4 * x + 0] = ((x | y) * (y / 255) + ((255 - y) / 255) * x & y) % 255;
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = x * y % 255;
            image[4 * width * y + 4 * x + 3] = 255;

        }
}

void gen5(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {

            image[4 * width * y + 4 * x + 0] = x * y;
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = ((x | y) * (y / 255) + ((255 - y) / 255) * x & y);
            image[4 * width * y + 4 * x + 3] = 255;

        }
}

void gen6(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {

            image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
            image[4 * width * y + 4 * x + 1] = x * ~x - y * y;
            image[4 * width * y + 4 * x + 2] = x * ~x - y * ~y * y;
            image[4 * width * y + 4 * x + 3] = 255;

        }
}

void gen7(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {

            image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
            image[4 * width * y + 4 * x + 1] = 255 * ~(x | y);
            image[4 * width * y + 4 * x + 2] = x * ~x - ~y * y;
            image[4 * width * y + 4 * x + 3] = 255;

        }
}

void gen8(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {

            image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
            image[4 * width * y + 4 * x + 1] = 255 * !(x & y) * 255 * ~(x | y);
            image[4 * width * y + 4 * x + 2] = 0;
            image[4 * width * y + 4 * x + 3] = 255;

        }
}

void gen9(ucVec &image, unsigned width, unsigned height) {

    for (unsigned y = 0; y < height; y++)
        for (unsigned x = 0; x < width; x++) {

            image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
            image[4 * width * y + 4 * x + 1] = 255 * !(x & y) * 255 * ~(x | y);
            image[4 * width * y + 4 * x + 2] = 255 * (x | y);
            image[4 * width * y + 4 * x + 3] = 255;

        }
}