#ifndef _DATE_SORTER_
#define _DATE_SORTER_

#include "TaskSorter.h"

class DateSorter : public TaskSorter {
    public:
        DateSorter(Person* );
        void sort(std::vector<Task>& );
};

#endif