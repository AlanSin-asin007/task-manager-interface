#ifndef _TASK_
#define _TASK_

#include <chrono>
#include "Date.h"

class Task {
    private:
        int rating;
        date::year_month_day deadlineDate;
    
    public:
        Task(int rating, date::year_month_day deadline) : rating(rating), deadlineDate(deadline) {};
        int getRating() const;
        void setRating(int );
        date::year_month_day getDeadline() const;
        void setDeadline(date::year_month_day );
        bool operator==(const Task& rhs) const;
};

#endif