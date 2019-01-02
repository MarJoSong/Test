#include "configfile.h"

int getLine_ConfigFile(FILE* file)
{
    char buf[1024] = {0};
    int lines = 0;
    while (NULL != fgets(buf, 1024, file))
    {
        if(!isValid_ConfigFile(buf))
            continue;
        memset(buf, 0, 1024);
        ++lines;
    }
    fseek(file, 0, SEEK_SET);
    return lines;
}

void loadFile_ConfigFile(const char* filePath, char*** fileData, int* line)
{
    FILE* file = fopen(filePath, "r");
    if(NULL == file)
        return;

    int lines = getLine_ConfigFile(file);
    char** temp = (char**)malloc(sizeof (char*) * lines);
    char buf[1024] = {0};
    int index = 0;
    while (NULL != fgets(buf, 1024, file))
    {
        if(!isValid_ConfigFile(buf))
            continue;
        temp[index] = (char*)malloc(strlen(buf)+1);
        strcpy(temp[index++], buf);
        memset(buf, 0, 1024);
    }
    *fileData = temp;
    *line = lines;
}

void parseFIle_ConfigFile(char** fileData, int lines, struct ConfigInfo** info)
{
    struct ConfigInfo* myInfo = (struct ConfigInfo*)malloc(sizeof (struct ConfigInfo)*lines);
    memset(myInfo, 0, sizeof (struct ConfigInfo)*lines);

    for(int i=0; i<lines; ++i)
    {
        char* pos = strchr(fileData[i], ':');
        strncpy(myInfo[i].key, fileData[i], pos - fileData[i]);
        strncpy(myInfo[i].val, pos+1, strlen(pos+1)-1);
        //printf("key=%s\tval=%s\n",myInfo[i].key,myInfo[i].val);
    }
    *info = myInfo;
    for(int i=0; i<lines;++i)
    {
        if(fileData[i]!=NULL)
        {
            free(fileData[i]);
            fileData[i] = NULL;
        }
    }
}

char* getInfo_ConfigFile(char* key, struct ConfigInfo* info, int lines)
{
    for(int i=0;i<lines;++i)
    {
        if(strcmp(key, info[i].key)==0)
            return info[i].val;
    }
    return NULL;
}

int isValid_ConfigFile(char* buf)
{
    if('#'==buf[0] || '\n'==buf[0] || strchr(buf, ':')==NULL)
        return 0;
    return 1;
}

void destory_ConfigFile(struct ConfigInfo* info)
{
    if(info != NULL)
    {
        free(info);
        info = NULL;
    }
}
