//
// Created by paul on 08/08/2021.
//

#include <stdio.h>
#include "headers/Shapes.h"

void borderPattern(unsigned long pixels[], const unsigned long foreground, const unsigned long background,
                   const size_t width, const size_t height, const size_t size) {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            if ((x <= size)
            ||  (y <= size)
            ||  (x >= width - size && x <= height - 1)
             || (y >= height - size && y <= height - 1) ) {
                pixels[y * width + x] = foreground;
            } else {
                pixels[y * width + x] = background;
            }
        }
    }
}
