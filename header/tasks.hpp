#ifndef TASKS_HPP
#define TASKS_HPP

#include "person.hpp"
#include <string>

using namespace std;

//stub
class Tasks {
    private:
        string taskName;
        string taskDeadline;
        string description;
        string label;
        int taskPriority;
    public:
        //constructors
        Tasks();

        string getTaskName() const;
        string getTaskDeadline() const;
        string getDescription() const;
        string getLabel() const;
        int getPriority() const;
};

#endif // TASKS_HPP