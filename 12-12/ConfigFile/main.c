#include <stdio.h>
#include <configfile.h>

int main()
{
    char** fileData = NULL;
    int lines = 0;
    loadFile_ConfigFile("config.ini",&fileData, &lines);
    struct ConfigInfo* info = NULL;
    printf("Detect %d lines Config Info\n", lines);
    parseFIle_ConfigFile(fileData, lines, &info);
    printf("ip:%s\n", getInfo_ConfigFile("ip", info, lines));
    printf("port:%s\n", getInfo_ConfigFile("port", info, lines));
    destory_ConfigFile(info);

    return 0;
}
