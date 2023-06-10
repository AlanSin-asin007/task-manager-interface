#ifndef _TASK_SORTER_
#define _TASK_SORTER_

#include "Person.h"

class TaskSorter {
    protected:
        Person person;
        std::vector<Task> getTaskList();
        void updateTaskList(std::vector<Task>& );
        virtual void sort(std::vector<Task>& ) = 0;

    public:
        TaskSorter(Person& );
        ~TaskSorter();
        void performSort();
        Person getPerson() const;
        void setPerson(Person& );

};

#endif