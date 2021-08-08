//
// Created by paul on 08/08/2021.
//
#include <stdio.h>
#ifndef CIRCLES_PPMHELPER_H
#define CIRCLES_PPMHELPER_H

#endif //CIRCLES_PPMHELPER_H

void fillPixels(unsigned long pixels[], unsigned long colour, size_t size);

int savePPM(char *fileName, unsigned long pixels[], size_t width, size_t height);
