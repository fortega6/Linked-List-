#ifndef TODO_HPP
#define TODO_HPP

#include "dynamic_array_list.hpp"
#include <string>

class ToDo
{
    typedef DynamicArrayList<std::string> TaskList;

    TaskList pendTasks_;
    TaskList doneTasks_;

    bool existFile(const std::string& fname);
    bool loadTasks(const std::string& fname);
    bool saveTasks(const std::string& fname);

    void addPendTask(const std::string& descr);
    void listTasks();
    void markAsDone(int taskNum);

    bool numstr(const char str[]);
    std::string trim(const std::string& str);

public:
     ToDo();
    ~ToDo();

     bool exec(int argc, char* argv[]);
};

#endif  //TODO_HPP
