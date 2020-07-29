#include "todo.hpp"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

int main(int argc, char *argv[])
{
    try
    {
        ToDo todo;
        todo.exec(argc, argv);

        return EXIT_SUCCESS;
    }
    catch (std::runtime_error e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
}
