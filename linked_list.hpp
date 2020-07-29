// define LinkedList here
/** LinkedList class
    @file abstract_list.hpp  */

#ifndef LINKED_LIST_HPP
#define LINKED_LIST_HPP

#include "abstract_list.hpp"

template <typename T>
class LinkedList : public AbstractList<T>
{
    struct Node
    {
        T data_;
        Node* next_;

        Node(const T& data = T(), Node* next = nullptr)
        {
            data_ = data;
            next_ = next;
        }
    };

    Node* front_;
    Node* back_;
    std::size_t length;

public:
     LinkedList();
     LinkedList(const LinkedList<T>& other);
    ~LinkedList();

     LinkedList<T>& operator=(const LinkedList& rhs);

    void push_front(const T& data);
    void push_back(const T& data);
    void pop_front();
    void pop_back();

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

};

#include "linked_list.tpp"
#endif  //LINKED_LIST_HPP
