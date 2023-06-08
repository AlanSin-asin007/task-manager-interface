#include "../include/DateSorter.h"

DateSorter::DateSorter(Person* p) : TaskSorter(p) {}

void DateSorter::sort(std::vector<Task>& taskList) {
    for (int i = 0; i < taskList.size(); ++i) {
        int max = i;
        for (int j = i+1; j < taskList.size(); ++j) {
            if (taskList.at(j).getDeadline() < taskList.at(i).getDeadline()) {
                max = j;
            }
        }
        if (max != i) {
            std::swap(taskList[i], taskList[max]);
        }
    }
}