#include <stdio.h>
#include <stdint.h>
#include <string.h>

class Pinto
{
private:
    /* data */
    uint8_t* pPintoBuf;
    int32_t iFileSize;
    FILE* outputFile = NULL;

public:
    Pinto();
    void openFile(const char* filename);
    void initBuffer(int32_t iFileSize);
    void copyToBuffer(uint8_t* src, int32_t size);
    void writeOutputFile(uint32_t size);
    void closeFile();
};