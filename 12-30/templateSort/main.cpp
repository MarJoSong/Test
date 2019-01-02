#include <iostream>

using namespace std;

template <class T>
void mySwap(T& a, T& b)
{
    T tmp = a;
    a = b;
    b= tmp;
}

template <class T>
void mySort(T arr[], int len)
{
    for (int i=0; i<len; ++i)
    {
        int max = i;
        for (int j=i+1; j<len+1; ++j)
        {
            if(arr[max] < arr[j])
            {
                max = j;
            }
        }
        if(max != i)
        {
            mySwap(arr[i], arr[max]);
        }
    }
}

template <class T>
void printArray(T arr[], int len)
{
    for (int i=0; i<len; ++i)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

void test()
{
    int intArr[] = {1,7,3,8,5};
    int len = sizeof (intArr)/sizeof (int);
    mySort(intArr, len);
    printArray(intArr, len);

    double doubleArr[] = {2.3,3.1,3.0,7.5,5.7};
    len = sizeof (doubleArr)/sizeof (double);
    mySort(doubleArr, len);
    printArray(doubleArr, len);

    char charArr[] = "HelloWorld!";
    len = sizeof (charArr)/sizeof (char);
    mySort(charArr, len);
    printArray(charArr, len);
}

int main()
{
    test();
    return 0;
}
