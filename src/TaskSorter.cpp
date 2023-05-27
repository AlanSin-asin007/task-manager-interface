#include "../include/TaskSorter.h"

TaskSorter::TaskSorter(Person* p) {
    this->person = p;
}

TaskSorter::~TaskSorter() {
    delete person;
}

Person* TaskSorter::getPerson() const {
    return person;
}

void TaskSorter::setPerson(Person* p) {
    this->person = p;
}

std::vector<Task> TaskSorter::getTaskList() {
    return person->getTaskList();
}

void TaskSorter::updateTaskList(std::vector<Task>& v) {
    person->setTaskList(v);
}

void TaskSorter::performSort() {
    std::vector<Task> taskList = getTaskList();
    sort(taskList);
    updateTaskList(taskList);
}