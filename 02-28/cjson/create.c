#include <stdio.h>
#include <string.h>
#include "cJSON.h"

int main()
{
    cJSON* obj =  cJSON_CreateObject();
    
    cJSON* brand = cJSON_CreateObject();

    cJSON_AddItemToObject(brand, "factory", cJSON_CreateString("一汽大众"));
    cJSON_AddItemToObject(brand, "last", cJSON_CreateNumber(31));
    cJSON_AddItemToObject(brand, "price", cJSON_CreateNumber(83));
    cJSON_AddItemToObject(brand, "sell", cJSON_CreateNumber(49));
    cJSON_AddItemToObject(brand, "sum", cJSON_CreateNumber(80));

    cJSON* array = cJSON_CreateArray();
    cJSON_AddItemToArray(array, cJSON_CreateNumber(124));
    cJSON_AddItemToArray(array, cJSON_CreateString("hello,world"));
    cJSON_AddItemToArray(array, cJSON_CreateBool(0));
    cJSON* subsub = cJSON_CreateObject();
    cJSON_AddItemToObject(subsub, "梅赛德斯奔驰", cJSON_CreateString("心所向, 恒持久"));
    cJSON_AddItemToArray(array, subsub);
    cJSON_AddItemToObject(brand, "other", array);

    cJSON_AddItemToObject(obj, "奔驰", brand);

    char* data = cJSON_Print(obj);
    FILE* fp = fopen("car.json", "w");
    fwrite(data, 1, strlen(data)+1, fp);
    fclose(fp);

    return 0;
}
