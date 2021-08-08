//
// Created by paul on 08/08/2021.
//

#ifndef CIRCLES_SHAPES_H
#define CIRCLES_SHAPES_H

#endif //CIRCLES_SHAPES_H

void borderPattern(unsigned long pixels[],  unsigned long foreground, unsigned long background,
                    size_t width,  size_t height,  size_t size);

void checkerPattern(unsigned long pixels[], unsigned long foreground, unsigned long background,
                    size_t width, size_t height, size_t tileSize);

void stripesPattern(unsigned long pixels[], unsigned long foreground, unsigned long background,
                    size_t width, size_t height, size_t tileSize);

void solidCircle(unsigned long pixels[], unsigned long foreground, unsigned long background,
                    size_t width, size_t height, size_t radius);

void hollowCircle(unsigned long pixels[], unsigned long foreground, unsigned long background,
                 size_t width, size_t height, size_t radius);