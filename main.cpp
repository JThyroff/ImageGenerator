#include "main.h"

int main(int argc, char *argv[] ) {
    //NOTE: this sample will overwrite the file or test.png without warning!
    const char* filename = argc > 1 ? argv[1] : "result.png";

    //generate some image
    unsigned width = 512, height = 512;
    std::vector<unsigned char> image;
    image.resize(width * height * 4);
    for(unsigned y = 0; y < height; y++)
        for(unsigned x = 0; x < width; x++) {
            image[4 * width * y + 4 * x + 0] = 255 * !(x & y);
            image[4 * width * y + 4 * x + 1] = x ^ y;
            image[4 * width * y + 4 * x + 2] = x | y;
            image[4 * width * y + 4 * x + 3] = 255;
        }

    encodeOneStep(filename, image, width, height);
}

//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char* filename, std::vector<unsigned char>& image, unsigned width, unsigned height) {
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if(error) std::cout << "encoder error " << error << ": "<< lodepng_error_text(error) << std::endl;
}
