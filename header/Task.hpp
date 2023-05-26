#include <string>
#include <iostream>

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
    string getTaskName();
    string getTaskDeadline();
    string getDescription();
    string getLabel();
    int getTaskPriority();

    // Setters
    void setTaskName(string newTaskName);
    void setTaskDeadline(string newTaskDeadline);
    void setDescription(string newDescription);
    void setLabel(string newLabel);
    void setTaskPriority(int newTaskPriority);
    void printTask();
};
