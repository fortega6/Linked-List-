#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "dynamic_array_list.hpp"
#include "linked_list.hpp"

// implement your tests here

using namespace std;

TEST_CASE( "Test LinkedList insert", "[LinkedList]" )
{
    INFO("Hint: testing LinkedList insert()");
    LinkedList<int> intList;
    std::size_t listLength;
    bool success;

    for (std::size_t i = 0; i < 5; ++i) {
        intList.insert(0, 1);
    }

    listLength = intList.getLength();
    success = (listLength == 5);
    REQUIRE(success);

    for (std::size_t i = 0; i < 5; ++i) {
        intList.insert( intList.getLength(),2);
    }

    listLength = intList.getLength();
    success = (listLength == 10);
    REQUIRE(success);

    for (std::size_t i = 0; i < 5; ++i) {
        intList.insert(6, 2);
    }

    listLength = intList.getLength();
    success = (listLength == 15);
    REQUIRE(success);

    //check if exceptions works
    try
    {
        intList.insert(20, 3);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }
}

TEST_CASE( "Test LinkedList copy assignment operator", "[LinkedList]" )
{
    INFO("Hint: testing LinkedList copy assignment operator()");
    LinkedList<int> intList, intListCopy;
    std::size_t listLength;
    bool success;

    intList.insert(0, 1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.insert(1, 3);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.insert(1, 2);
    listLength = intList.getLength();
    success = (listLength == 3);
    REQUIRE(success);

    //check if exceptions works
    try
    {
        intList.insert(5, 3);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }

    intListCopy = intList;

    for (std::size_t i = 0; i < intListCopy.getLength(); ++i) {
        success = (intList.getEntry(i) == intListCopy.getEntry(i));
        REQUIRE(success);
    }

    intListCopy.insert(1, 4);

    REQUIRE(intListCopy.getEntry(1) == 4);
    REQUIRE(intListCopy.getLength() == 4);

    intList =  intListCopy;

    for (std::size_t i = 0; i < intList.getLength(); ++i) {
        success = (intList.getEntry(i) == intListCopy.getEntry(i));
        REQUIRE(success);
    }
}

TEST_CASE( "Test LinkedList length", "[LinkedList]" )
{
    INFO("Hint: testing LinkedList length()");
    LinkedList<int> intList;
    std::size_t listLength;
    bool success;

    listLength = intList.getLength();
    success = (listLength == 0);
    REQUIRE(success);

    intList.insert(0, 1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.insert(1, 3);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.insert(1, 2);
    listLength = intList.getLength();
    success = (listLength == 3);
    REQUIRE(success);
}

TEST_CASE( "Test LinkedList isEmpty", "[LinkedList]" )
{
    INFO("Hint: testing LinkedList isEmpty()");
    LinkedList<int> intList;
    std::size_t listLength;
    bool success;

    success = intList.isEmpty();
    REQUIRE(success);

    listLength = intList.getLength();
    success = (listLength == 0);
    REQUIRE(success);

    intList.insert(0, 1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.insert(1, 3);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.insert(1, 2);
    listLength = intList.getLength();
    success = (listLength == 3);
    REQUIRE(success);

    intList.clear();

    success = intList.isEmpty();
    REQUIRE(success);
}

TEST_CASE( "Test LinkedList remove", "[LinkedList]" )
{
    INFO("Hint: testing LinkedList remove()");
    LinkedList<int> intList;
    std::size_t listLength;
    bool success;

    listLength = intList.getLength();
    success = (listLength == 0);
    REQUIRE(success);

    intList.insert(0, 1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.insert(1, 3);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.insert(1, 2);
    listLength = intList.getLength();
    success = (listLength == 3);
    REQUIRE(success);

    //check if exceptions works
    try
    {
        intList.remove(9);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }

    intList.remove(1);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.remove(1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.remove(0);
    listLength = intList.getLength();
    success = (listLength == 0);
    REQUIRE(success);

    //check if exceptions works
    try
    {
        intList.remove(0);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }
}

TEST_CASE( "Test LinkedList getEntry", "[LinkedList]" )
{
    INFO("Hint: testing LinkedList getEntry()");
    LinkedList<int> intList;
    std::size_t testSize = 3;
    std::size_t entry;
    bool success;

    for (std::size_t i = 0; i < testSize; ++i) {
        intList.insert(i, i+1);
    }

    for (std::size_t i = 0; i < testSize; ++i) {
        entry = intList.getEntry(i);
        success = (entry == i+1);
        REQUIRE(success);
    }

    //check if exceptions works
    try
    {
        entry = intList.getEntry(9);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }
}

TEST_CASE( "Test LinkedList setEntry", "[LinkedList]" )
{
    INFO("Hint: testing LinkedList setEntry()");
    LinkedList<int> intList;
    std::size_t testSize = 3;
    std::size_t entry;
    bool success;

    for (std::size_t i = 0; i < testSize; ++i) {
        intList.insert(i, 4);
    }

    for (std::size_t i = 0; i < testSize; ++i) {
        intList.setEntry(i, i+1);
    }

    for (std::size_t i = 0; i < testSize; ++i) {
        entry = intList.getEntry(i);
        success = (entry == i+1);
        REQUIRE(success);
    }

    //check if exceptions works
    try
    {
        intList.setEntry(9, 9);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }
}

TEST_CASE( "Test LinkedList clear", "[LinkedList]" )
{
    INFO("Hint: testing LinkedList clear()");
    LinkedList<int> intList;
    std::size_t testSize = 3;
    std::size_t entry;
    bool success;

    for (std::size_t i = 0; i < testSize; ++i) {
        intList.insert(i, i+1);
    }

    intList.clear();
    entry = intList.getLength();
    success = (entry == 0);
    REQUIRE(success);
}

TEST_CASE( "Test DynamicArrayList insert", "[DynamicArrayList]" )
{
    INFO("Hint: testing DynamicArrayList insert()");
    // Create a Bag to hold ints
    DynamicArrayList<int> intList;
    std::size_t listLength;
    bool success;

    for (std::size_t i = 0; i < 5; ++i) {
        intList.insert(0, 1);
    }

    listLength = intList.getLength();
    success = (listLength == 5);
    REQUIRE(success);

    for (std::size_t i = 0; i < 5; ++i) {
        intList.insert( intList.getLength(),3);
    }

    listLength = intList.getLength();
    success = (listLength == 10);
    REQUIRE(success);

    for (std::size_t i = 0; i < 5; ++i) {
        intList.insert(5, 2);
    }

    listLength = intList.getLength();
    success = (listLength == 15);
    REQUIRE(success);

    //check if exceptions works
    try
    {
        intList.insert(20, 3);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }

}

TEST_CASE( "Test DynamicArrayList copy assignment operator", "[DynamicArrayList]" )
{
    INFO("Hint: testing LinkedList copy assignment operator()");
    DynamicArrayList<int> intList, intListCopy;
    std::size_t listLength;
    bool success;

    intList.insert(0, 1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.insert(1, 3);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.insert(1, 2);
    listLength = intList.getLength();
    success = (listLength == 3);
    REQUIRE(success);

    //check if exceptions works
    try
    {
        intList.insert(5, 3);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }

    intListCopy = intList;

    for (std::size_t i = 0; i < intList.getLength(); ++i) {
        success = (intList.getEntry(i) == intListCopy.getEntry(i));
        REQUIRE(success);
    }

    intListCopy.insert(1, 4);

    REQUIRE(intListCopy.getEntry(1) == 4);
    REQUIRE(intListCopy.getLength() == 4);

    intList =  intListCopy;

    for (std::size_t i = 0; i < intList.getLength(); ++i) {
        success = (intList.getEntry(i) == intListCopy.getEntry(i));
        REQUIRE(success);
    }
}

TEST_CASE( "Test DynamicArrayList length", "[DynamicArrayList]" )
{
    INFO("Hint: testing DynamicArrayList length()");
    DynamicArrayList<int> intList;
    std::size_t listLength;
    bool success;

    listLength = intList.getLength();
    success = (listLength == 0);
    REQUIRE(success);

    intList.insert(0, 1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.insert(1, 3);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.insert(1, 2);
    listLength = intList.getLength();
    success = (listLength == 3);
    REQUIRE(success);

}

TEST_CASE( "Test DynamicArrayList isEmpty", "[DynamicArrayList]" )
{
    INFO("Hint: testing DynamicArrayList isEmpty()");
    LinkedList<int> intList;
    std::size_t listLength;
    bool success;

    success = intList.isEmpty();
    REQUIRE(success);

    listLength = intList.getLength();
    success = (listLength == 0);
    REQUIRE(success);

    intList.insert(0, 1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.insert(1, 3);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.insert(1, 2);
    listLength = intList.getLength();
    success = (listLength == 3);
    REQUIRE(success);

    intList.clear();

    success = intList.isEmpty();
    REQUIRE(success);
}

TEST_CASE( "Test DynamicArrayList remove", "[DynamicArrayList]" )
{
    INFO("Hint: testing DynamicArrayList remove()");
    DynamicArrayList<int> intList;
    std::size_t listLength;
    bool success;

    listLength = intList.getLength();
    success = (listLength == 0);
    REQUIRE(success);

    intList.insert(0, 1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.insert(1, 2);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.insert(1, 3);
    listLength = intList.getLength();
    success = (listLength == 3);
    REQUIRE(success);

    //check if exceptions works
    try
    {
        intList.remove(9);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }

    intList.remove(1);
    listLength = intList.getLength();
    success = (listLength == 2);
    REQUIRE(success);

    intList.remove(1);
    listLength = intList.getLength();
    success = (listLength == 1);
    REQUIRE(success);

    intList.remove(0);
    listLength = intList.getLength();
    success = (listLength == 0);
    REQUIRE(success);

    //check if exceptions works
    try
    {
        intList.remove(0);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }
}

TEST_CASE( "Test DynamicArrayList getEntry", "[DynamicArrayList]" )
{
    INFO("Hint: testing DynamicArrayList getEntry()");
    DynamicArrayList<int> intList;
    std::size_t testSize = 3;
    std::size_t entry;
    bool success;

    for (std::size_t i = 0; i < testSize; ++i) {
        intList.insert(i, i+1);
    }

    for (std::size_t i = 0; i < testSize; ++i) {
        entry = intList.getEntry(i);
        success = (entry == i+1);
        REQUIRE(success);
    }

    //check if exceptions works
    try
    {
        entry = intList.getEntry(9);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }
}

TEST_CASE( "Test DynamicArrayList setEntry", "[DynamicArrayList]" )
{
    INFO("Hint: testing DynamicArrayList setEntry()");
    DynamicArrayList<int> intList;
    std::size_t testSize = 3;
    std::size_t entry;
    bool success;

    for (std::size_t i = 0; i < testSize; ++i) {
        intList.insert(i, 4);
    }

    for (std::size_t i = 0; i < testSize; ++i) {
        intList.setEntry(i, i+1);
    }

    for (std::size_t i = 0; i < testSize; ++i) {
        entry = intList.getEntry(i);
        success = (entry == i+1);
        REQUIRE(success);
    }

    //check if exceptions works
    try
    {
        intList.setEntry(9, 9);
        REQUIRE(false);
    }
    catch (range_error e)
    {
        REQUIRE(true);
    }
}

TEST_CASE( "Test DynamicArrayList clear", "[DynamicArrayList]" )
{
    INFO("Hint: testing DynamicArrayList clear()");
    DynamicArrayList<int> intList;
    std::size_t testSize = 3;
    std::size_t entry;
    bool success;

    for (std::size_t i = 0; i < testSize; ++i) {
        intList.insert(i, i+1);
    }

    intList.clear();
    entry = intList.getLength();
    success = (entry == 0);
    REQUIRE(success);

}
