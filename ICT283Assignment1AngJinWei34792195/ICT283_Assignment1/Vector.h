#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <string>

using namespace std;

	/**
	 * @class Vector
	 * @brief Header file for Vector Class
	 *
	 * @author Ang Jin Wei
	 * @version 01
	 * @date 6/17/2023
	 */

template <class T>
class Vector
{
    public:

            /**
             * @brief Default Constructor for Vector
             */
        Vector(); //default constructor

            /**
             * @brief destructor for Vector
             */
        ~Vector(); //destructor

            /**
             * @brief Copy constructor for Vector
             *
             * @param Vector<T> & newvector - vector to be copied from
             */
        Vector(const Vector<T> & newvector);

            /**
             * @brief reallocate function
             *
             * @param int n - number of elements
             */
        void reallocate(int n); //reallocating elements

            /**
             * @brief PushBack function for Vector
             *
             * @param T& value - element to be added
             */
        void pushBack(const T& value); //adding elements to the back of vector

            /**
             * @brief popBack function for Vector
             */
        void popBack(); //remove element from back of vector

            /**
             * @brief Clear function for Vector
             */
        void Clear(); //clear memory from vector

            /**
             * @brief At function for Vector
             *
             * @param int i - index
             */
        T At(int i) const; //to find location of element

            /**
             * @brief operator[] function
             *
             * @param int index - index of element to be accessed
             */
        Vector<T>& operator[] (int index) const; //return element of particular index

            /**
             * @brief operator[] function (non constant)
             *
             * @param int index - index of element to be accessed
             */
        Vector<T>& operator[](int index);

            /**
             * @brief Size function to return size of vector
             *
             * @return int - vectorsize
             */
        int Size() const;

            /**
             * @brief operator= function
             *
             * @param Vector<T> newvector - vector you want to copy from
             */
        Vector<T>& operator= (const Vector<T> & newvector);

            /**
             * @brief print vector
             *
             * @return void
             */
        void printVector() const;

            /**
             * @brief Prints capacity of vector
             *
             * @return void
             */
        void getCapacity() const;


    private:
        T * vectorlist = nullptr;
        int vectorsize = 0;
        int vectorcapacity = 0;
};

template <class T>
Vector<T>::Vector(const Vector<T> & newvector)
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
}

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
    vectorlist = nullptr;
}

template <class T>
void Vector<T>::getCapacity() const
{
    cout << vectorcapacity << endl;
}

template <class T>
void Vector<T>::Clear()
{
    vectorsize = 0;
    delete[] vectorlist; //delete array
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
        vectorlist[vectorsize].~T(); //destructor
        vectorsize -= 1; //-1 from vectorsize
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
    for (int i=0; i<vectorsize; i++)
    {
        cout << vectorlist[i] << endl;
    }
}

#endif // VECTOR_H
