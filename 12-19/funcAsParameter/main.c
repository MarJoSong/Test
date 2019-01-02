#include <stdio.h>

int con1(int a, int b)
{
    return a+b;
}

int con2(int a, int b)
{
    return a-b;
}

int con3(int a, int b)
{
    return a*b;
}

int con4(int a, int b)
{
    if(0 != b)
        return a/b;
    return 0;
}

int con5(int a, int b)
{
    return a%b;
}

void test01(int(*func)(int, int), int a, int b)
{
    int ret = func(a, b);
    printf("ret = %d", ret);
}

void test02()
{
    int(*fun_array[3])(int, int);//int(*fun_array[3])();
    fun_array[0] = con1;
    fun_array[1] = con2;
    fun_array[2] = con5;
    for (int i = 0; i < 3; ++i) {
        printf("%d\t", fun_array[i](10, 20));
    }
}

void test03(void *arr, int len,int size, void(*func)(void*))
{
    char* start = (char*)arr;
    for (int i=0; i<len; ++i) {
        func(start + i* size);
    }
}

void print(void* data)
{
    printf("%d\n", *(int*)data);
}

struct person{
    char name[20];
    int age;
};

void printstruct(void* data)
{
    struct person *p = (struct person*)data;
    printf("%s\t%d\n",p->name, p->age);

    //printf("%d\n", (*(struct person*)data).name, (*(struct person*)data).name);
}

int main()
{
    //test01(con1, 10, 20);
    //test02();

    int arr[5] = {1, 2, 3, 4, 5};
    test03(arr, 5, 4, print);

    struct person persons[] = {
        {"aaa", 10},
        {"bbb", 20},
        {"ccc", 30},
        {"ddd", 40},
        {"eee", 50}
    };
    test03(persons, 5, sizeof (struct person), printstruct);

    return 0;
}
