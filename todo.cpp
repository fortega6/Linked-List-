#include "todo.hpp"
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <cstdlib>


ToDo::ToDo()
{
}


ToDo::~ToDo()
{
}


bool ToDo::exec(int argc, char* argv[])
{
    //////////////////////////
    //invalid argument number!
    if (argc < 2)
        throw std::runtime_error("Error: too few arguments!");

    /////////////////////////////
    //argv[0]: program name (todo)
    std::string flag, fname, cmd;
    int parsed = 1;

    //////////////////////////////////
    //argv[1] y arg[2]:
    //optional file flag and file name
    flag = argv[parsed++];
    if (flag == "-f")
    {
        if (parsed == argc || !existFile(fname = argv[parsed++]))
            throw std::runtime_error(std::string("Error: the file \"") +
                                     fname +
                                     std::string("\" no exists!"));
    }
    else
    {
        --parsed;
        flag = "";
        fname = "todo.txt";
    }

    if (!loadTasks(fname))  //can't read the file!
        throw std::runtime_error("Error: error while reading the file!");

    /////////////////////
    //argv[1] or argv[3]:
    //todo-command
    cmd = argv[parsed++];

    if (cmd == "add")   //add new pending task!
    {
        //assemble task description
        //all that is left in argv[]
        std::string descr;
        for (int i = parsed; i < argc; ++i)
            descr += std::string(argv[i]) + " ";

        if (!descr.empty())
        {
            addPendTask(descr);
            saveTasks(fname);
        }
    }
    else if (cmd == "list") //list all tasks!
    {
        if (parsed == argc)
            listTasks();
        else
            throw std::runtime_error("Error: too many arguments for"
                                     " \"todo [-f file] list\" command");
    }
    else if (cmd == "do")   //mark a task as done!
    {
        if (parsed == argc || !numstr(argv[parsed]))
            throw std::runtime_error("Error: invalid \"todo [-f file] do task-no.\" argument");

        int num = atoi(argv[parsed]);
        int totTasks = pendTasks_.getLength() +
                       doneTasks_.getLength();

        if (num < 1 || num > totTasks)
            throw std::runtime_error("Error: \"todo [-f file] do task-no.\" invalid range task number");
        else
        {
            markAsDone(num);
            saveTasks(fname);
        }
    }
    else
        throw std::runtime_error("Error: invalid \"todo\" command");
    /////////////////////

    return true;
}


bool ToDo::existFile(const std::string& fname)
{
    std::ifstream file(fname);
    return file.good();
}


bool ToDo::loadTasks(const std::string& fname)
{
    bool success = false;
    std::ifstream file(fname);

    if (file.is_open())
    {
        bool err = false;

        while (!err && !file.eof())
        {
            //read line: P|D task-description
            std::string stat;
            std::string descr;

            file >> stat;                 //read status
            std::getline(file, descr);    //read description
            descr = trim(descr);

            if (!stat.empty())
                if (stat == "P")                    //pending task!
                    pendTasks_.pushBack(descr);
                else if (stat == "D")               //done task!
                    doneTasks_.pushBack(descr);
                else                                //error data!
                    err = true;
        }

        file.close();

        if (!err)   //file data loaded!
            success = true;
        else        //error! -> clear task lists
        {
            pendTasks_.clear();
            doneTasks_.clear();
        }
    }

    return success;
}


bool ToDo::saveTasks(const std::string &fname)
{
    bool success = false;
    std::ofstream file(fname);

    if (file.is_open())
    {
        for (int i = 0; i < pendTasks_.getLength(); ++i)
            file << "P " << pendTasks_.getEntry(i) << std::endl;

        for (int i = 0; i < doneTasks_.getLength(); ++i)
            file << "D " << doneTasks_.getEntry(i) << std::endl;

        file.close();
        success = true;
    }

    return success;
}


bool ToDo::numstr(const char str[])
{
    bool digittest = true;

    int i = 0;
    while (str[i] != '\0' && digittest)
        if (!isdigit(str[i]))
            digittest = false;
        else
            ++i;

    return digittest;
}


std::string ToDo::trim(const std::string& str)
{
    size_t first = str.find_first_not_of(" \n\r\t");

    if (first == std::string::npos)
        return str;

    size_t last = str.find_last_not_of(" \n\r\t");
    return str.substr(first, (last - first + 1));
}


void ToDo::addPendTask(const std::string& descr)
{
    pendTasks_.pushBack(descr);
}


void ToDo::listTasks()
{
    for (int i = 0; i < pendTasks_.getLength(); ++i)
        std::cout << i + 1 << ":[ ] " << pendTasks_.getEntry(i) << std::endl;

    for (int i = 0; i < doneTasks_.getLength(); ++i)
        std::cout << pendTasks_.getLength() + i  + 1<< ":[X] "
                  << doneTasks_.getEntry(i) << std::endl ;
}


void ToDo::markAsDone(int taskNum)
{
    if (taskNum >= 1 && taskNum <= pendTasks_.getLength())
    {
        int idx = taskNum - 1;
        std::string descr = pendTasks_.getEntry(idx);

        pendTasks_.remove(idx);
        doneTasks_.pushBack(descr);
    }
}
