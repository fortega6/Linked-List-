// implement DynamicArrayList here
/** @file linked_list.cpp */

#include "dynamic_array_list.hpp"
#include <stdexcept>

template <typename T>
void DynamicArrayList<T>::resize()
{
    //duplicate array memory size
    if (capacity == 0)
        capacity = 1;
    else
        capacity *= 2;
    T* tmpArr = new  T[capacity];

    //copy current array data to new one
    for (int i = 0; i < length; ++i)
        tmpArr[i] = array_list[i];

    //release current array mem.
    //and set the new array
    delete [] array_list;
    array_list = tmpArr;
}

template <typename T>
DynamicArrayList<T>::DynamicArrayList()
{
    array_list = nullptr;
    length = 0;
    capacity = 0;
}

template <typename T>
DynamicArrayList<T>::DynamicArrayList(const DynamicArrayList<T>& other)
{
    array_list = new T[other.capacity];
    for (int i = 0; i < other.length; ++i)
        array_list[i] = other.array_list[i];

    length = other.length;
    capacity = other.capacity;
}


template <typename T>
DynamicArrayList<T>::~DynamicArrayList()
{
    delete [] array_list;   //release allocated mem.
}

template <typename T>
DynamicArrayList<T>& DynamicArrayList<T>::operator=(const DynamicArrayList& other)
{
    if (capacity < other.length)    //there is no enough space in dest. list
    {
        //release current list mem.
        //and allocate enough space
        delete [] array_list;
        array_list = new T[other.capacity];
        capacity = other.capacity;
    }

    //copy right side list
    for (int i = 0; i < other.length; ++i)
        array_list[i] = other.array_list[i];
    length = other.length;

    return *this;
}

// determine if a list is empty
template <typename T>
bool DynamicArrayList<T>::isEmpty() const noexcept
{
    return (length == 0);
}

// return current length of the list
template <typename T>
std::size_t DynamicArrayList<T>::getLength() const noexcept
{
    return length;
}

// insert item at position in the list using 0-based indexing
// throws std::range_error if position is invalid
template <typename T>
void DynamicArrayList<T>::insert(std::size_t position, const T& item)
{
    if (position < 0 || position > length)
        throw std::range_error("Range error: position is invalid!");

    if (length == capacity)     //full array!
        resize();               //allocate more mem.

    //forward move array items in
    //the range [position, lenght - 1]
    for (int i = length; i > position; --i)
        array_list[i] = array_list[i - 1];

    //insert item and update array size
    array_list[position] = item;
    ++length;
}

// remove item at position in the list using 0-based indexing
// throws std::range_error if position is invalid
template <typename T>
void DynamicArrayList<T>::remove(std::size_t position)
{
    if (position < 0 || position >= length)
        throw std::range_error("Range error: position is invalid!");

    for (int i = position; i < (length - 1); ++i)
        array_list[i] = array_list[i + 1];
    --length;
}

// remove all items from the list
template <typename T>
void DynamicArrayList<T>::clear() noexcept
{
    length = 0;
}

// get a copy of the item at position using 0-based indexing
// throws std::range_error if position is invalid
template <typename T>
T DynamicArrayList<T>::getEntry(std::size_t position) const
{
    if (position < 0 || position >= length)
        throw std::range_error("Range error: position is invalid!");

    return array_list[position];
}

// set the value of the item at position using 0-based indexing
// throws std::range_error if position is invalid
template <typename T>
void DynamicArrayList<T>::setEntry(std::size_t position, const T& newValue)
{
    if (position < 0 || position >= length)
        throw std::range_error("Range error: position is invalid!");

    array_list[position] = newValue;
}


template <typename T>
void DynamicArrayList<T>::pushBack(const T& item)
{
    insert(length, item);
}


template <typename T>
void DynamicArrayList<T>::pushFront(const T& item)
{
    insert(0, item);
}


template <typename T>
void DynamicArrayList<T>::popBack()
{
    remove(length - 1);
}


template <typename T>
void DynamicArrayList<T>::popFront()
{
    remove(0);
}
