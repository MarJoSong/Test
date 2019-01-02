#include <stdio.h>
#include <arraysort.h>

void test()
{
    int arr[] = {2, 1, 9, 7, 8};
    arraySort(arr, sizeof (arr)/sizeof (int), sizeof (int), compareInc);
    for(int i=0; i<(int)(sizeof (arr)/sizeof (int)); ++i)
        printf("%d\t", arr[i]);
    printf("\n");
    arraySort(arr, sizeof (arr)/sizeof (int), sizeof (int), compareDec);
    for(int i=0; i<(int)(sizeof (arr)/sizeof (int)); ++i)
        printf("%d\t", arr[i]);
}

int main()
{
    test();
    return 0;
}
