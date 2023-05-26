#include <iostream>
#include "../header/Task.hpp"

Task::Task(string taskName, string taskDeadline, string description, string label, int taskPriority)
        : taskName(taskName), taskDeadline(taskDeadline), description(description), label(label), taskPriority(taskPriority) {}

string Task::getTaskName() {
    return taskName;
}

string Task::getTaskDeadline() {
    return taskDeadline;
}

string Task::getDescription() {
    return description;
}

string Task::getLabel() {
    return label;
}

int Task::getTaskPriority() {
    return taskPriority;
}

void Task::setTaskName(string newTaskName) {
    taskName = newTaskName;
}

void Task::setTaskDeadline(string newTaskDeadline) {
    taskDeadline = newTaskDeadline;
}

void Task::setDescription(string newDescription) {
    description = newDescription;
}

void Task::setLabel(string newLabel) {
    label = newLabel;
}

void Task::setTaskPriority(int newTaskPriority) {
    if(newTaskPriority >= 1 && newTaskPriority <= 10) {
        taskPriority = newTaskPriority;
    }
    else {
        cout << "Task priority should be between 1 and 10" << endl;
    }
}

void Task::printTask() {
    cout << "Task Name: " << taskName << "\nTask Deadline: " << taskDeadline << "\nDescription: " << description;
    cout << "\nLabel: " << label << "\nTask Priority: " << taskPriority << endl;
}
