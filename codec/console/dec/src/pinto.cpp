#include "pinto.h"
#include <iostream>

using namespace std;

Pinto::Pinto()
{
    
}

void Pinto::openFile(const char* filename)
{
    cout << "New file open for output file" << endl;
    outputFile = fopen(filename, "wb");
}

void Pinto::initBuffer(int32_t iInputFileSize, uint8_t* inputFileBuf)
{
    cout << "Init pinto buffer" << endl;
    pPintoBuf = new uint8_t[iInputFileSize];
    iFileSize = iInputFileSize;
    pInputFileBuf = inputFileBuf;
    pBufPos = pPintoBuf;
}

void Pinto::copyToBuffer(uint8_t* src, int32_t size)
{
    cout << "" << endl;
    cout << "Copy to buffer : "<<  size << endl;
    
    if(size > 0)
    {        
        for (size_t i = 0; i < size; i++)
        {
            cout << "[" << (int)src[i] << "]";
        }
        cout << "" << endl;

        memcpy(pBufPos, src, size);
        updateBufferPosition(pBufPos + size);
        totalCopiedSize += size;    
        cout << "curr total copied : " << totalCopiedSize << endl;
        cout << "" << endl;
    }else{
        cout << "size 0 not copied" << endl;
        cout << "" << endl;
    }
    
}

void Pinto::copyResidualToBufferWithLeftbit(uint8_t* src, int32_t size, int32_t leftBit)
{
    cout << "" << endl;
    cout << "Copy Residual with iLeftBit, copy size : "<<  size << endl;
    
    if(size > 0)
    {
        for (size_t i = 0; i < size; i++)
        {
            cout << "[" << (int)src[i] << "]";
        }
        cout << "" << endl;

        memcpy(pBufPos, src, size);
        updateBufferPosition(pBufPos + size);
        totalCopiedSize += size;
        
        if(residualStartLeftBit == 0 && pResidualEnd == 0){
            residualStartLeftBit = leftBit;
        }else{
            residualEndLeftBit = leftBit;
        }
        isResidualcopied = true;
        cout << "curr total copied : " << totalCopiedSize << endl;
        cout << "" << endl;
    }else{
        cout << "size 0 not copied" << endl;
        cout << "" << endl;
    }
    
}

void Pinto::updateBufferPosition(uint8_t* bufPos)
{
    pBufPos = bufPos;
}

void Pinto::addStartCode()
{
    cout << "Add Start Code 0 0 1" << endl;
    *pBufPos = 0;
    pBufPos++;
    *pBufPos = 0;
    pBufPos++;
    *pBufPos = 1;
    pBufPos++;
    totalCopiedSize += 3;
}

void Pinto::writeOutputFile(uint32_t size)
{
    cout << "Write output file" << endl;
    fwrite(pPintoBuf, 1, size, outputFile);
}

void Pinto::closeFile()
{
    cout << "Close output file" << endl;
    fclose(outputFile);
}

bool Pinto::isEqual()
{
    
    for(int i = 0; i < iFileSize; i++){
        if(pPintoBuf[i] != pInputFileBuf[i]){
            cout << "iFileSize : "<< iFileSize << endl;
            cout << "error index : "<< i << endl;

            if(i > 2 && i <= iFileSize - 4){
                cout << "[Pinto buffer]" << endl;
                cout << (int)pPintoBuf[i-2] << ", " << (int)pPintoBuf[i-1] << ", " << (int)pPintoBuf[i] << ", " << (int)pPintoBuf[i+1] << ", " << (int)pPintoBuf[i+2] << ", " << (int)pPintoBuf[i+3]<< endl;

                cout << "[InputFile buffer]" << endl;
                cout << (int)pInputFileBuf[i-2] << ", " << (int)pInputFileBuf[i-1] << ", " << (int)pInputFileBuf[i] << ", " << (int)pInputFileBuf[i+1] << ", " << (int)pInputFileBuf[i+2] << ", " << (int)pInputFileBuf[i+3] << endl;
            }

            return false;
        }
    }
    return true;
}

void Pinto::workTest()
{
    cout << "Pinto instance work" << endl;
    // cout << (currbuffer - pBufPos) << endl;
    // cout << (currbuffer - pInputFileBuf) << endl;

} 

void Pinto::copyTest(uint8_t* currbuffer)
{
    cout << "Pinto instance work" << endl;
    // cout << (currbuffer - pBufPos) << endl;
    // cout << (currbuffer - pInputFileBuf) << endl;
} 

