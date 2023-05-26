#ifndef _PERSON_
#define _PERSON_

#include "Task.h"
#include <vector>

class Person {
    private:
        std::vector<Task> taskList;

    public:
        Person() {};
        Person(std::vector<Task>& vec) : taskList(vec) {};
        std::vector<Task> getTaskList() const {
            return taskList;
        }

        void setTaskList(std::vector<Task>& v) {
            this->taskList = v;
        }
};

#endif