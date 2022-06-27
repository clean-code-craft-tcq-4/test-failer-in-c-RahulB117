#include "misaligned.h"
#include <assert.h>


void referenceManual()
{
    int majorIndex = 0;
    int minorIndex = 0;
    int colorPairNumber = 0;
    int colorPairLength = 0;
    for(majorIndex = 0; majorIndex < numberOfMajorColors; majorIndex++) 
    {
        for(minorIndex = 1; minorIndex <= numberOfMinorColors; minorIndex++) 
        {
            colorPairLength = sprintf(&correctColorMap[colorPairNumber], "%d\t|%s\t|%s\n", majorIndex * numberOfMajorColors + minorIndex, majorColor[majorIndex], minorColor[minorIndex-1]);
            colorPairNumber = colorPairNumber + colorPairLength;
        }
    }
}

int printColorMap() 
{
    int majorIndex = 0;
    int minorIndex = 0;
    int colorPairNumber = 0;
    int colorPairLength = 0;
    for(majorIndex = 0; majorIndex < numberOfMajorColors; majorIndex++) 
    {
        for(minorIndex = 0; minorIndex < numberOfMinorColors; minorIndex++) 
        {
            colorPairLength = sprintf(&colorMap[colorPairNumber], "%d |%s |%s\n", (majorIndex * numberOfMajorColors + minorIndex)+1, majorColor[majorIndex], minorColor[minorIndex]);
            colorPairNumber = colorPairNumber + colorPairLength;
        }
    }
    return majorIndex * minorIndex;
}

void testAlignment()
{
    int result;
    referenceManual();
    result = strcmp(&correctColorMap[0], &colorMap[0]);
    assert( result == 0);     
}

int main() {
    int result = printColorMap();
    assert(result == 25);
    testAlignment();
    printf("All is well (maybe!)\n");
    return 0;
}
