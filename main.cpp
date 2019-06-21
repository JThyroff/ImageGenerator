#include <stdio.h>
#include <stdlib.h>

bool scale = true;

int main(){
    FILE *imageFile;
    int height=20,width=20;

    imageFile=fopen("image.ppm","wb");
    if(imageFile==nullptr){
        perror("ERROR: Cannot open output file");
        exit(EXIT_FAILURE);
    }

    fprintf(imageFile,"P6\n");               // P6 filetype
    fprintf(imageFile,"%d %d\n",width,height);   // dimensions
    fprintf(imageFile,"255\n");              // Max pixel

    unsigned char pix []= {};//{0,0,0,50,50,50,100,100,100,150,150,150,200,200,200,250,250,250};

    fwrite(pix,1,height*width*3,imageFile);
    fclose(imageFile);

    if(scale)
        system("convert image.ppm -scale 400x result.png");
    else
        system("convert image.ppm result.png");
}