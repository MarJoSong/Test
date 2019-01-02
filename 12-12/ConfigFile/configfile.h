#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ConfigInfo{
    char key[64];
    char val[128];
};

#ifdef __cplusplus
    extern "C"{
#endif
    int getLine_ConfigFile(FILE* file);

    void loadFile_ConfigFile(const char* filePath, char*** fileData, int* line);

    void parseFIle_ConfigFile(char** fileData, int lines, struct ConfigInfo** info);

    char* getInfo_ConfigFile(char* key, struct ConfigInfo* info, int lines);

    int isValid_ConfigFile(char* buf);

    void destory_ConfigFile(struct ConfigInfo* info);
#ifdef __cplusplus
    }
#endif
