#ifndef _IMPORTANCE_SORTER_
#define _IMPORTANCE_SORTER_

#include "TaskSorter.h"

class ImportanceSorter : public TaskSorter {
    public:
        ImportanceSorter(Person& );
        void sort(std::vector<Task>& );
};

#endif