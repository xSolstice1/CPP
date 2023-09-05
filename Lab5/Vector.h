#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <class T>
class Vector
{
    public:
        Vector(); //default constructor
        /**
        * @brief Default Constructor for Vector
        */

        ~Vector(); //destructor
        /**
        / @brief destructor for Vector
        */

        void reallocate(int n); //reallocating elements
        /**
        * @brief reallocate function
        */

        void pushBack(const T& value); //adding elements to the vector
        /**
        * @brief PushBack function for Vector
        */

        void popBack(); //remove element from the vector
        /**
        * @brief popBack function for Vector
        */

        void Clear(); //clear memory from vector
        /**
        * @brief Clear function for Vector
        */

        T At(int i) const; //to find location of element
        /**
        * @brief At function for Vector
        */

        Vector<T>& operator[] (int index) const; //return size of array
        /**
        * @brief operator[] function
        */

        Vector<T>& operator[](int index);
        /**
        * @brief operator[] function (non constant)
        */

        int Size() const;
        /**
        * @brief Size function to return size of vector
        */

        Vector<T>& operator= (const Vector<T> & copyVec);
        /**
        * @brief Copy constructor
        */

        void printVector() const;
        /**
        * @brief print vector
        */

        void getCapacity() const;
        /**
        * @brief Check capacity of vector
        */

    private:
        T *vectorlist = nullptr;
        int vectorsize = 0;
        int vectorcapacity = 0;
};

template<class T>
void Vector<T>:: reallocate(int n)
{
    T* newArray = new T[n];

    if (n < vectorsize)
    {
        vectorsize = n;
    }

    for(int i=0; i<vectorsize; i++)
    {
        newArray[i] = (vectorlist[i]);
    }

    delete[] vectorlist; //deallocate memory
    vectorlist = newArray;
    vectorcapacity = n;
}

template <class T>
Vector<T>::Vector()
{
    reallocate(5);
}

template <class T>
Vector<T>::~Vector()
{
    Clear();
    delete[] vectorlist;
}

template <class T>
void Vector<T>::getCapacity() const
{
    cout << vectorcapacity << endl;
}

template <class T>
void Vector<T>::Clear()
{
    for (int i=0; i<vectorsize; i++)
    {
        vectorlist[i].~T();
    }
    vectorsize = 0;
}

template <class T>
void Vector<T>::pushBack(const T& value)
{
    if (vectorsize >= vectorcapacity)
    {
        reallocate(vectorcapacity + vectorcapacity/2);
    }
    vectorlist[vectorsize] = value;
    vectorsize++;
}

template <class T>
void Vector<T>::popBack()
{
    if (vectorsize > 0)
    {
        vectorsize -= 1;
        vectorlist[vectorsize].~T();
    }
}

template <class T>
T Vector<T>::At (int i) const
{
    if ((i>=0) && (i<vectorsize))
    {
        return vectorlist[i];
    }
}

template <class T>
int Vector<T>::Size() const
{
    return vectorsize;
}

template <class T>
Vector<T>& Vector<T>::operator[](int index) const
{
    return vectorlist[index];
}

template <class T>
Vector<T>& Vector<T>::operator[](int index)
{
    return vectorlist[index];
}

template <class T>
Vector<T>& Vector<T>::operator= (const Vector<T>& newvector)
{
    if (this != &newvector)
    {
        vectorsize = newvector.vectorsize;
        vectorcapacity = newvector.vectorcapacity;
        vectorlist = new T[vectorcapacity];
        for (int i=0; i<vectorsize; i++)
        {
            vectorlist[i] = newvector.vectorlist[i];
        }
    }
    return *this;
}

template <class T>
void Vector<T>::printVector() const
{
    for (int i=0; i<vectorcapacity; i++)
    {
        cout << vectorlist[i] << endl;
    }
}

#endif // VECTOR_H
