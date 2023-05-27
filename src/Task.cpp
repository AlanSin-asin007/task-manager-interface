#include "../include/Task.h"

int Task::getRating() const {
    return rating;
}

void Task::setRating(int newRating) {
    rating = newRating;
}

date::year_month_day Task::getDeadline() const {
    return deadlineDate;
}

void Task::setDeadline(date::year_month_day newDeadline) {
    deadlineDate = newDeadline;
}

bool Task::operator==(const Task& rhs) const {
    return (this->getRating() == rhs.getRating() && this->getDeadline() == rhs.getDeadline());
}