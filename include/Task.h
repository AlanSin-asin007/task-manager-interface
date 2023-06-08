#ifndef _TASK_
#define _TASK_

#include <chrono>
#include <iostream>
#include <vector>
#include "Date.h"

using namespace std;

class Task {
    private:
        string taskName;
        string taskDescription;
        string taskLabel;
        date::year_month_day deadlineDate;
        int rating;
    
    public:
        Task() {};
        Task(string taskName, string description, string label, date::year_month_day deadline, int rating) : taskName(taskName), taskDescription(description), taskLabel(label), deadlineDate(deadline), rating(rating) {};
        Task(int rating, date::year_month_day deadline) : rating(rating), deadlineDate(deadline) {};

        string getTaskName() const;
        void setTaskName(const string& );

        string getDescription() const;
        void setDescription(const string& );

        string getLabel() const;
        void setLabel(const string& );

        int getRating() const;
        void setRating(int );

        date::year_month_day getDeadline() const;
        void setDeadline(date::year_month_day );

        void printTask();
        static void addTask(vector<Task>& taskList, const Task& task);
        static void deleteTask(vector<Task>& taskList, const string& taskName);
        
        bool operator==(const Task& rhs) const;
};

#endif