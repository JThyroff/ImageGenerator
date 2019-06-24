
#include "main.h"

bool goodFun(Function * fun, unsigned width, unsigned height){
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(0,1024);


    unsigned e1 = fun->evaluate(dist(rng),dist(rng),width,height);
    unsigned e2 = fun->evaluate(dist(rng),dist(rng),width,height);
    unsigned e3 = fun->evaluate(dist(rng),dist(rng),width,height);

    return (e1 != e2) || (e1 != e3) || (e2 != e3);
}

int main() {

    ConfigParser p;
    p.load("ImageGenerator.cfg");

    FunctionGenerator funGen = FunctionGenerator();
    unsigned arraySize = getArraySize(p.recursions);
    Function *red[arraySize];
    Function *green[arraySize];
    Function *blue[arraySize];

    std::cout << "Generating Image(s)..." << std::endl<<std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    auto x = std::chrono::time_point_cast<std::chrono::nanoseconds>(start);
    std::string res = std::to_string(x.time_since_epoch().count());

    for(int i = 0;i<p.count;i++){
        std::cout << "Generating Random Image..." << std::endl;

        ucVec imageRnd;
        std::string tmp = "rndImage#" + res+ "#i="+std::to_string(i)+".png";
        const char *filename0 =tmp.c_str();
        imageRnd.resize(p.width * p.height * 4);

        unsigned int * redp = p.getRedStartParams();
        unsigned int * greenp = p.getGreenStartParams();
        unsigned int * bluep = p.getBlueStartParams();

        for( int s = 0;s<arraySize;s++){
            red[s] = funGen.generateFunction(redp[0],redp[1],redp[2],redp[3]);
            green[s] = funGen.generateFunction(greenp[0],greenp[1],greenp[2],greenp[3]);
            blue[s] = funGen.generateFunction(bluep[0],bluep[1],bluep[2],bluep[3]);

            while(!goodFun(red[s],p.width,p.height)){
                red[s] = funGen.generateFunction(redp[0],redp[1],redp[2],redp[3]);
            }
            while(!goodFun(green[s],p.width,p.height)){
                green[s] = funGen.generateFunction(greenp[0],greenp[1],greenp[2],greenp[3]);
            }
            while(!goodFun(blue[s],p.width,p.height)){
                blue[s] = funGen.generateFunction(bluep[0],bluep[1],bluep[2],bluep[3]);
            }
        }


        /*
        std::string redFunc = red->print();
        std::string greenFunc = green->print();
        std::string blueFunc = blue->print();


        std::cout << "Red Fun:" << redFunc << std::endl;
        std::cout << "Green Fun:" << greenFunc << std::endl;
        std::cout << "Blue Fun:" << blueFunc << std::endl;
        */

        genBasedOnFunctions(imageRnd, p.width, p.height, red, green, blue,arraySize);
        encodeOneStep(filename0, imageRnd, p.width, p.height);

        std::cout << "Generating Random Image - Finished!" << std::endl<<std::endl;
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() << "ns\n";

    //generate some default images Comment this in, if you want some default examples



    unsigned width = p.width;
    unsigned height = p.height;
/*
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
*//*
    //img3
    ucVec image3;
    const char *filename3 = "image3.png";
    image3.resize(width * height * 4);
    gen3(image3, width, height);
    encodeOneStep(filename3, image3, width, height);
*//*

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
*/
    std::cout << "Generating Image(s) - Finished!" << std::endl;
}

//Encode from raw pixels to disk with a single function call
//The image argument has width * height RGBA pixels or width * height * 4 bytes
void encodeOneStep(const char *filename, ucVec &image, unsigned width, unsigned height) {
    //Encode the image
    unsigned error = lodepng::encode(filename, image, width, height);

    //if there's an error, display it
    if (error) std::cout << "encoder error " << error << ": " << lodepng_error_text(error) << std::endl;
}

unsigned getArraySize(unsigned e){
    if(e == 0){
        return 1;
    }else {
        return 2*getArraySize(e -1) + 1;
    }
}
