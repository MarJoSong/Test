#include <iostream>
#include <string>

using namespace std;

template<class T>
class MyArray
{
public:
    explicit MyArray(int capacity)
    {
        this->Capacity = capacity;
        this->Size = 0;
        this->Address = new T[this->Capacity];
    }

    MyArray(const MyArray& array)
    {
        this->Capacity = array.Capacity;
        this->Size = array.Size;
        this ->Address = new T[this->Capacity];
        for (int i=0; i<this->Size; i++)
        {
            this->Address[i] = array.Address[i];
        }
    }

    MyArray& operator=(MyArray& array)
    {
        if(nullptr != this->Address)
        {
            delete [] this->Address;
            this->Address = nullptr;
        }
        this->Capacity = array.Capacity;
        this->Size = array.Size;
        this ->Address = new T[this->Capacity];
        for (int i=0; i<this->Size; i++)
        {
            this->Address[i] = array.Address[i];
        }
    }

    ~MyArray()
    {
        if(nullptr != this->Address)
        {
            delete [] this->Address;
            this->Address = nullptr;
        }
    }

    T& operator[](int index)
    {
        return this->Address[index];
    }

    void pushBack(T value)
    {
        if(this->Size>=this->Capacity)
        {
            cout << "Array Enlarge" << endl;
            this->Capacity *= 2;
            T* tmp = this->Address;
            this->Address = new T[this->Capacity];
            for (int i=0; i<this->Size; i++)
            {
                this->Address[i] = tmp[i];
            }
            delete [] tmp;
            tmp = nullptr;
        }
        this->Address[this->Size] = value;
        this->Size++;
    }

    int getSize()
    {
        return this->Size;
    }

    int getCapacity()
    {
        return this->Capacity;
    }

private:
    T* Address;
    int Size;
    int Capacity;

};
