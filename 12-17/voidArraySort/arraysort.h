#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef __cplusplus
extern "C"{
#endif

void arraySort(void* arr, int len, int size, int compare(void*, void*));
int compareInc(void* p1, void* p2);
int compareDec(void* p1, void* p2);

#ifdef __cplusplus
}
#endif
