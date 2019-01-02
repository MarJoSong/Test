#include "arraysort.h"

void arraySort(void *arr, int len, int size, int compare(void *, void *))
{
    char* temp = static_cast<char*>(malloc(sizeof (size)));
    memset(temp, 0 ,sizeof (size));
    for(int i=0; i<len-1; ++i)
    {
        char* pMaxorMin = static_cast<char*>(arr) + i*size;
        for(int j=i+1; j<len;++j)
        {
            char* pJ = static_cast<char*>(arr) + j*size;
            if(compare(pMaxorMin, pJ));
            else {
                pMaxorMin = pJ;
            }
        }
        memcpy(temp, pMaxorMin, sizeof (size));
        memcpy(pMaxorMin, static_cast<char*>(arr) + i*size, sizeof (size));
        memcpy(static_cast<char*>(arr) + i*size, temp,sizeof (size));
    }
}

int compareInc(void *p1, void *p2)
{
    return *static_cast<int*>(p1) < *static_cast<int*>(p2);
}

int compareDec(void *p1, void *p2)
{
    return *static_cast<int*>(p1) > *static_cast<int*>(p2);
}
