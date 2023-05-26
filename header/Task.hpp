#ifndef TASK_HPP
#define TASK_HPP

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Task {
private:
    string taskName;
    string taskDeadline;
    string description;
    string label;
    int taskPriority;

public:
    Task(string taskName, string taskDeadline, string description, string label, int taskPriority);

    // Getters
    string getTaskName() const;
    string getTaskDeadline() const;
    string getDescription() const;
    string getLabel() const;
    int getTaskPriority() const;

    // Setters
    void setTaskName(const string& newTaskName);
    void setTaskDeadline(const string& newTaskDeadline);
    void setDescription(const string& newDescription);
    void setLabel(const string& newLabel);
    void setTaskPriority(int newTaskPriority);
    void printTask() const;

    // Function declarations
    static void addTask(vector<Task>& taskList, const Task& task);
    static void deleteTask(vector<Task>& taskList, const string& taskName);
    static Task copyTask(const Task& task);
    static void modifyTask(vector<Task>& taskList, const string& taskName, const string& newTaskName, const string& newTaskDeadline, const string& newDescription, const string& newLabel, int newTaskPriority);
    static void modifyTaskDeadline(vector<Task>& taskList, const string& taskName, const string& newTaskDeadline);
};

#endif

