// define DynamicArrayList here
/** DynamicArrayList class
    @file dynamic_array_list.hpp  */

#ifndef DYNAMIC_ARRAY_LIST_HPP
#define DYNAMIC_ARRAY_LIST_HPP

#include "abstract_list.hpp"

template <typename T>
class DynamicArrayList : public AbstractList<T>
{
    T* array_list;
    std::size_t length;
    std::size_t capacity;

    void resize();

public:
     DynamicArrayList();
     DynamicArrayList(const DynamicArrayList<T>& other);
    ~DynamicArrayList();

    DynamicArrayList<T>& operator=(const DynamicArrayList& other);

    // determine if a list is empty
    bool isEmpty() const noexcept;

    // return current length of the list
    std::size_t getLength() const noexcept;

    // insert item at position in the list using 0-based indexing
    // throws std::range_error if position is invalid
    void insert(std::size_t position, const T& item);

    // remove item at position in the list using 0-based indexing
    // throws std::range_error if position is invalid
    void remove(std::size_t position);

    // remove all items from the list
    void clear() noexcept;

    // get a copy of the item at position using 0-based indexing
    // throws std::range_error if position is invalid
    T getEntry(std::size_t position) const;

    // set the value of the item at position using 0-based indexing
    // throws std::range_error if position is invalid
    void setEntry(std::size_t position, const T& newValue);

    void pushBack(const T& item);
    void pushFront(const T& item);
    void popBack();
    void popFront();
};

#include "dynamic_array_list.tpp"
#endif  //DYNAMIC_ARRAY_LIST_HPP
