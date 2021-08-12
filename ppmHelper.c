//
// Created by paul on 08/08/2021.
//

#include <stdio.h>
#include "headers/ppmHelper.h"


void fillPixels(unsigned long pixels[], unsigned long colour, size_t size){
    for (int i = 0; i < size; ++i) {
        pixels[i] = colour;
    }
}

int savePPM(char *fileName, const unsigned long pixels[], size_t width, size_t height) {

    printf("Saving\n");

    FILE *file;

    file = fopen(fileName, "wb");

    if (file) {
        char header[50];

        sprintf(header, "P6\n%lu %lu 255\n", width, height);

        fputs(header, file);

        for (size_t y = 0; y < height; ++y) {
            for (size_t x = 0; x < width; ++x) {
                unsigned long pixel = pixels[y * width + x];
                unsigned char colour[] = {(unsigned char) ((pixel >> 8 * 2) & 0xFF),
                                          (unsigned char) ((pixel >> 8 * 1) & 0xFF),
                                          (unsigned char) ((pixel >> 8 * 0) & 0xFF)};

                fwrite(colour, 1, 3, file);
            }
        }

        printf("File %s now saved\n", fileName);

        fclose(file);
        return 0;
    } else {
        return -1;
    }

}