#include <iostream>
#include <vector>
#include <string>
#include "../header/Task.hpp"

Task::Task(string taskName, string taskDeadline, string description, string label, int taskPriority)
        : taskName(taskName), taskDeadline(taskDeadline), description(description), label(label), taskPriority(taskPriority) {}

string Task::getTaskName() const{
    return taskName;
}

string Task::getTaskDeadline() const{
    return taskDeadline;
}

string Task::getDescription() const{
    return description;
}

string Task::getLabel() const{
    return label;
}

int Task::getTaskPriority() const{
    return taskPriority;
}

void Task::setTaskName(const string& newTaskName) {
    taskName = newTaskName;
}

void Task::setTaskDeadline(const string& newTaskDeadline) {
    taskDeadline = newTaskDeadline;
}

void Task::setDescription(const string& newDescription) {
    description = newDescription;
}

void Task::setLabel(const string& newLabel) {
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

void Task::printTask() const{
    cout << "Task Name: " << taskName << "\nTask Deadline: " << taskDeadline << "\nDescription: " << description;
    cout << "\nLabel: " << label << "\nTask Priority: " << taskPriority << endl;
}

void Task::addTask(vector<Task>& taskList, const Task& task) {
    taskList.push_back(task);
}

void Task::deleteTask(vector<Task>& taskList, const string& taskName) {
    for (auto it = taskList.begin(); it != taskList.end(); ++it) {
        if (it->getTaskName() == taskName) {
            taskList.erase(it);
            break;
        }
    }
}

Task Task::copyTask(const Task& task) {
    Task copiedTask = Task(task.taskName, task.taskDeadline, task.description, task.label, task.taskPriority);
    return copiedTask;
}
