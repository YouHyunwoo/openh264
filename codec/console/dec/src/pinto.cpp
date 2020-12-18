#include "pinto.h"


Pinto::Pinto()
{
    
}

void Pinto::openFile(const char* filename)
{
    outputFile = fopen(filename, "wb");
}

void Pinto::initBuffer(int32_t iFileSize)
{
    pPintoBuf = new uint8_t[iFileSize];
}

void Pinto::copyToBuffer(uint8_t* src, int32_t size)
{
    memcpy(pPintoBuf, src, size);
}

void Pinto::writeOutputFile(uint32_t size)
{
    fwrite(pPintoBuf, 1, size, outputFile);
}

void Pinto::closeFile()
{
    fclose(outputFile);
}