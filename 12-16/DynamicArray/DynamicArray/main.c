#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "DynamicArray.h"

struct Person{
    char name[64];
    int age;
};

void print_DynamicArray(void* data)
{
    struct Person* person = data;
    printf("Name: %s,\tAge: %d\n", person->name, person->age);
}

void test()
{
    struct DynamicArray* DArray = Init_DynamicArray(5);
    struct Person persons[6] = {
        {"aaa", 10},
        {"bbb", 20},
        {"ccc", 30},
        {"ddd", 40},
        {"eee", 50},
        {"fff", 60}
    };
    InsertByPos_DynamicArray(DArray, 0, &persons[0]);
    InsertByPos_DynamicArray(DArray, 0, &persons[1]);
    InsertByPos_DynamicArray(DArray, 0, &persons[2]);
    InsertByPos_DynamicArray(DArray, 1, &persons[3]);
    InsertByPos_DynamicArray(DArray, 1, &persons[4]);

    printf("Capacity: %d\n", DArray->capacity);
    InsertByPos_DynamicArray(DArray, 0, &persons[5]);
    printf("Capacity: %d\n", DArray->capacity);
    Foreach_DynamicArray(DArray, print_DynamicArray);

    printf("--------------------\n");
    DeleteByPos_DynamicArray(DArray, 2);
    Foreach_DynamicArray(DArray, print_DynamicArray);
}

int main()
{
    test();

    return 0;
}
