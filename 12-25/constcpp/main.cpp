#include <iostream>

using namespace std;

struct person{
    char name[64];
    int age;
};

int main()
{
    printf("%d",sizeof (person));
    printf("%d", sizeof (person&));
    return 0;
}
