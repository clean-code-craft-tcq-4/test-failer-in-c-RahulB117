#include <stdio.h>
#include <string.h>

#define COLORMANUAL_SIZE 500

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
int numberOfMajorColors = sizeof(majorColor) / sizeof(majorColor[0]);
int numberOfMinorColors = sizeof(minorColor) / sizeof(minorColor[0]);
char colorMap[COLORMANUAL_SIZE];
char correctColorMap[COLORMANUAL_SIZE];

void referenceManual();
int printColorMap();
void testAlignment();

