#include "../include/TaskSorter.h"

TaskSorter::TaskSorter(Person& person) {
    this->person = person;
}

TaskSorter::~TaskSorter() {}

Person TaskSorter::getPerson() const {
    return person;
}

void TaskSorter::setPerson(Person& person) {
    this->person = person;
}

std::vector<Task> TaskSorter::getTaskList() {
    return person.getTaskList();
}

void TaskSorter::updateTaskList(std::vector<Task>& v) {
    person.setTaskList(v);
}

void TaskSorter::performSort() {
    std::vector<Task> taskList = getTaskList();
    sort(taskList);
    updateTaskList(taskList);
}