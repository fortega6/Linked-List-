// implement LinkedList here
/** @file linked_list.cpp */

#include "linked_list.hpp"
#include <stdexcept>

template <typename T>
LinkedList<T>::LinkedList()
{
    front_ = nullptr;
    back_ = nullptr;
    length = 0;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T>& other)
{
    //traverse and copy right side list
    front_ = nullptr;

    Node* othPtr = other.front_;
    Node* cpyPtr = nullptr;

    while (othPtr)
    {
        Node* node = new Node(othPtr->data_);
        if (!cpyPtr)
            front_ = cpyPtr = node;
        else
            cpyPtr = cpyPtr->next_ = node;

        othPtr = othPtr->next_;
    }

    back_ = cpyPtr;
    length = other.length;
}

template <typename T>
LinkedList<T>::~LinkedList()
{
    clear();
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& other)
{
    clear();    //release current allocated mem.

    //traverse and copy right side list
    Node* othPtr = other.front_;
    Node* cpyPtr = nullptr;

    while (othPtr)
    {
        Node* node = new Node(othPtr->data_);
        if (!cpyPtr)
            front_ = cpyPtr = node;
        else
            cpyPtr = cpyPtr->next_ = node;

        othPtr = othPtr->next_;
    }

    back_ = cpyPtr;
    length = other.length;
    return *this;
}

template <typename T>
void  LinkedList<T>::push_front(const T& data)
{
    insert(0, data);
}

template <typename T>
void  LinkedList<T>::push_back(const T& data)
{
    insert(length, data);
}

template <typename T>
void  LinkedList<T>::pop_front()
{
    remove(0);
}

template <typename T>
void  LinkedList<T>::pop_back()
{
    remove(length - 1);
}

// determine if a list is empty
template <typename T>
bool LinkedList<T>::isEmpty() const noexcept
{
    return (length == 0);
}

// return current length of the list
template <typename T>
std::size_t LinkedList<T>::getLength() const noexcept
{
    return length;
}

// insert item at position in the list using 0-based indexing
// throws std::range_error if position is invalid
template <typename T>
void LinkedList<T>::insert(std::size_t position, const T& item)
{
    if (position < 0 || position > length)
        throw std::range_error("Range error: position is invalid!");

    //traverse the list to position
    Node* curr = front_;
    Node* prev = nullptr;
    int count = 0;

    while (count < position)
    {
        prev = curr;
        curr = curr->next_;
        ++count;
    }

    //create and insert new node
    Node* node = new Node(item, curr);

    if (!prev)          //insert in the beginning!
        front_ = node;
    else                //insert after the beginning!
        prev->next_ = node;

    if (prev == back_)  //inserted at last!
        back_ = node;

    ++length;
}

// remove item at position in the list using 0-based indexing
// throws std::range_error if position is invalid
template <typename T>
void LinkedList<T>::remove(std::size_t position)
{
    if (position < 0 || position >= length)
        throw std::range_error("Range error: position is invalid!");

    //traverse the list to position
    Node* curr = front_;
    Node* prev = nullptr;
    int count = 0;

    while (count < position)
    {
        prev = curr;
        curr = curr->next_;
        ++count;
    }

    //remove the node
    if (prev)
        prev->next_ = curr->next_;
    else
        front_ = curr->next_;

    if (curr == back_)
        back_ = prev;

    --length;
    delete curr;
}

// remove all items from the list
template <typename T>
void LinkedList<T>::clear() noexcept
{
    //release nodes allocated mem.
    Node* ptr = front_;
    while (ptr)
    {
        Node* tmp = ptr;
        ptr = ptr->next_;
        delete tmp;
    }

    front_ = nullptr;
    back_ = nullptr;
    length = 0;
}

// get a copy of the item at position using 0-based indexing
// throws std::range_error if position is invalid
template <typename T>
T LinkedList<T>::getEntry(std::size_t position) const
{
    if (position < 0 || position >= length)
        throw std::range_error("Range error: position is invalid!");

    Node* curr = front_;
    for (int i = 0; i < position; ++i)
        curr = curr->next_;

    return curr->data_;
}

// set the value of the item at position using 0-based indexing
// throws std::range_error if position is invalid
template <typename T>
void LinkedList<T>::setEntry(std::size_t position, const T& newValue)
{
    if (position < 0 || position >= length)
        throw std::range_error("Range error: position is invalid!");

    Node* curr = front_;
    for (int i = 0; i < position; ++i)
        curr = curr->next_;

    curr->data_ = newValue;
}
