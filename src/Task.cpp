#include "../include/Task.h"
#include <stdexcept>

string Task::getTaskName() const {
    return taskName;
}

void Task::setTaskName(const string& newTaskName) {
    this->taskName = newTaskName;
}

string Task::getDescription() const {
    return taskDescription;
}

void Task::setDescription(const string& newDescription) {
    this->taskDescription = newDescription;
}

string Task::getLabel() const {
    return taskLabel;
}

void Task::setLabel(const string& newLabel) {
    this->taskLabel = newLabel;
}

date::year_month_day Task::getDeadline() const {
    return deadlineDate;
}

void Task::setDeadline(date::year_month_day newDeadline) {
    this->deadlineDate = newDeadline;
}

int Task::getRating() const {
    return rating;
}

void Task::setRating(int newRating) {
    if (newRating >= 1 && newRating <= 10) {
        this->rating = newRating;
    } else {
        throw std::out_of_range("Task importance must be between 1 and 10");
    }
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
    Task copiedTask = Task(task.getTaskName(), task.getDescription(), task.getLabel(), task.getDeadline(), task.getRating());
    return copiedTask;
}

void Task::modifyTask(vector<Task>& taskList, const string& taskName, const string& newTaskName, const date::year_month_day newTaskDeadline, const string& newDescription, const string& newLabel, int newTaskPriority) {
    for (Task& task : taskList) {
        if (task.getTaskName() == taskName) {
            task.setTaskName(newTaskName);
            task.setDeadline(newTaskDeadline);
            task.setDescription(newDescription);
            task.setLabel(newLabel);
            task.setRating(newTaskPriority);
            break;
        }
    }
}

void Task::modifyTaskDeadline(vector<Task>& taskList, const string& taskName, const date::year_month_day newTaskDeadline) {
    for (Task& task : taskList) {
        if (task.getTaskName() == taskName) {
            task.setDeadline(newTaskDeadline);
            break;
        }
    }
}


void Task::printTask() {
    cout << "Task Name: " << taskName << "\nTask Deadline: " << deadlineDate << "\nDescription: " << taskDescription;
    cout << "\nLabel: " << taskLabel << "\nTask Importance: " << rating << endl;
}

bool Task::operator==(const Task& rhs) const {
    return (this->getRating() == rhs.getRating() && this->getDeadline() == rhs.getDeadline());
}
