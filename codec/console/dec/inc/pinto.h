#ifndef PINTO_H__
#define PINTO_H__


#include <stdio.h>
#include <stdint.h>
#include <string.h>

class Pinto
{
private:
    /* data */
    uint8_t* pPintoBuf = NULL;
    uint8_t* pInputFileBuf = NULL;
    int32_t iFileSize;
    FILE* outputFile = NULL;
    uint8_t* pBufPos = NULL;

    uint8_t* pResidualStart = NULL;
    uint8_t* pResidualEnd = NULL;
    int32_t residualStartLeftBit = 0;
    int32_t residualEndLeftBit = 0;

public:
    Pinto();
    bool currNalisISlice = false;
    uint8_t copiedSize = 0;
    uint32_t totalCopiedSize = 0;
    bool isResidualcopied = false;
    uint8_t* pMbStart = NULL;

    void openFile(const char* filename);
    void initBuffer(int32_t iFileSize, uint8_t* inputFileBuf);
    void copyToBuffer(uint8_t* src, int32_t size);
    void copyResidualToBufferWithLeftbit(uint8_t* src, int32_t size, int32_t leftBit);
    void addStartCode();
    void updateBufferPosition(uint8_t* bufPos);

    bool isEqual();
    void writeOutputFile(uint32_t size);
    void closeFile();

    void workTest();
    void copyTest(uint8_t* currbuffer);
};

#endif