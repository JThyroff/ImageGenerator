#include "main.h"
#include "Gen/generators.h"
#include "Gen/FunctionGenerator.cpp"


int main() {
    FunctionGenerator funGen = FunctionGenerator();
    Function *red;
    Function *green;
    Function *blue;

    std::cout << "Generating Images..." << std::endl;

    unsigned width = 1024, height = 1024;

    std::cout << "Generating Random Image..." << std::endl;

    ucVec imageRnd;
    const char *filename0 = "rndImage";
    imageRnd.resize(width * height * 4);
    red = funGen.generateFunction(1, 0, 0);
    green = funGen.generateFunction(1, 0, 0);
    blue = funGen.generateFunction(1, 0, 0);

    std::string redFunc = red.print();
    std::string greenFunc = green.print();
    std::string blueFunc = blue.print();

    std::cout << "Red Fun:" << redFunc << std::endl;
    std::cout << "Green Fun:" << greenFunc << std::endl;
    std::cout << "Blue Fun:" << blueFunc << std::endl;


    genBasedOnFunctions(imageRnd, width, height, red, green, blue);
    encodeOneStep(filename0, imageRnd, width, height);

    std::cout << "Generating Random Image - Finished!" << std::endl;

    //generate some default images

    //img1
    ucVec image;
    const char *filename = "image1.png";
    image.resize(width * height * 4);
    gen1(image, width, height);
    encodeOneStep(filename, image, width, height);

    //img2
    ucVec image2;
    const char *filename2 = "image2.png";
    image2.resize(width * height * 4);
    gen2(image2, width, height);
    encodeOneStep(filename2, image2, width, height);

    //img3
    width = 256;
    height = 256;
    ucVec image3;
    const char *filename3 = "image3.png";
    image3.resize(width * height * 4);
    gen3(image3, width, height);
    encodeOneStep(filename3, image3, width, height);


    width = 1024;
    height = 1024;
    //img4
    ucVec image4;
    const char *filename4 = "image4.png";
    image4.resize(width * height * 4);
    gen4(image4, width, height);
    encodeOneStep(filename4, image4, width, height);

    width = 512;
    height = 512;
    //img5
    ucVec image5;
    const char *filename5 = "image5.png";
    image5.resize(width * height * 4);
    gen5(image5, width, height);
    encodeOneStep(filename5, image5, width, height);

    width = 512;
    height = 512;
    //img6
    ucVec image6;
    const char *filename6 = "image6.png";
    image6.resize(width * height * 4);
    gen6(image6, width, height);
    encodeOneStep(filename6, image6, width, height);

    width = 1024;
    height = 1024;
    //img7
    ucVec image7;
    const char *filename7 = "image7.png";
    image7.resize(width * height * 4);
    gen7(image7, width, height);
    encodeOneStep(filename7, image7, width, height);

    width = 512;
    height = 512;
    //img8
    ucVec image8;
    const char *filename8 = "image8.png";
    image8.resize(width * height * 4);
    gen8(image8, width, height);
    encodeOneStep(filename8, image8, width, height);

    width = 1024;
    height = 1024;
    //img9
    ucVec image9;
    const char *filename9 = "image9.png";
    image9.resize(width * height * 4);
    gen9(image9, width, height);
    encodeOneStep(filename9, image9, width, height);

    std::cout << "Generating Images - Finished!" << std::endl;
}

//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char *filename, ucVec &image, unsigned width, unsigned height) {
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}
