#include "../include/ImportanceSorter.h"

ImportanceSorter::ImportanceSorter(Person& person) : TaskSorter(person) {}

void ImportanceSorter::sort(std::vector<Task>& taskList) {
    for (int i = 0; i < taskList.size(); ++i) {
        int max = i;
        for (int j = i+1; j < taskList.size(); ++j) {
            if (taskList.at(j).getRating() > taskList.at(i).getRating()) {
                max = j;
            }
        }
        if (max != i) {
            std::swap(taskList[i], taskList[max]);
        }
    }
}