#include "../header/person.hpp"
#include "../header/tasks.hpp"

Tasks::Tasks() {
    taskName = "";
    taskDeadline = "";
    description = "";
    label = "";
    taskPriority = 0;
}

string Tasks::getTaskName() const {
    return taskName;
}

string Tasks::getTaskDeadline() const {
    return taskDeadline;
}

string Tasks::getDescription() const {
    return description;
}

string Tasks::getLabel() const {
    return label;
}

int Tasks::getPriority() const {
    return taskPriority;
}