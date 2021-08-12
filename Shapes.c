//
// Created by paul on 08/08/2021.
//

#include "headers/ppmHelper.h"
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

void checkerPattern(unsigned long pixels[], const unsigned long foreground, const unsigned long background,
                    const size_t width, const size_t height, size_t tileSize) {
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            pixels[y * width + x] = (x / tileSize + y / tileSize) % 2 == 0 ? background : foreground;
        }
    }
}

void stripesPattern(unsigned long pixels[], unsigned long foreground, unsigned long background,
                    size_t width, size_t height, size_t tileSize){
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            pixels[y * width + x] = ((x  + y )/ tileSize) % 2 == 0 ? background : foreground;
        }
    }
}

void solidCircle(unsigned long pixels[], unsigned long foreground, unsigned long background,
                 size_t width, size_t height, size_t radius){
    long cx = (long) width;
    long cy = (long) height;
    long r = (long) radius * 2;

    // Calculated twice the size in order to use sub pixel calculations
    for (size_t y = 0; y < height; ++y) {
        for (size_t x = 0; x < width; ++x) {
            long dx = cx - x * 2 - 1;
            long dy = cy - y * 2 - 1;

            pixels[y * width + x] = (dx * dx + dy * dy <= r * r) ? foreground : background;
        }
    }
}

void hollowCircle(unsigned long pixels[], unsigned long foreground, unsigned long background,
                  size_t width, size_t height, size_t radius) {
    fillPixels(pixels, background, width * height);

    drawCircle(pixels, foreground, width, height, radius);
}

void drawCircle(unsigned long pixels[], unsigned long foreground,
                size_t width, size_t height, size_t radius);

void drawCircle(unsigned long *pixels, unsigned long foreground, size_t width, size_t height, size_t radius) {

    size_t r = radius * 2;
    size_t cx = width;
    size_t cy = height;
    size_t x = 0;
    size_t y = r - 1;

    while (x <= y) {
        size_t px = (x + cx) / 2;
        size_t py = (y + cy) / 2;

        if (px <= width && py <= height) {

            pixels[py * width + px] = foreground;
            pixels[px * width + py] = foreground;

            pixels[(height - py) * width + px] = foreground;
            pixels[px * width + (height - py)] = foreground;

            pixels[py * width + (width - px)] = foreground;
            pixels[(width - px) * width + py] = foreground;

            pixels[(height - py) * width + (width - px)] = foreground;
            pixels[(width - px) * width + (height - py)] = foreground;
        }

        x += 1;
        if (x * x + y * y > r * r) {
            y -= 1;
        }
    }
}

void drawRecords(unsigned long pixels[], unsigned long foreground, unsigned long background,
                 size_t width, size_t height, size_t maxRadius) {
    fillPixels(pixels, background, width * height);

    for (size_t i = maxRadius / 10; i < maxRadius; i += 3) {
        drawCircle(pixels, foreground, width, height, i);
    }
}