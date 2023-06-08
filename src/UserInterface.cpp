#include "../include/UserInterface.h"
#include "../include/Person.h"
#include "../include/TaskSorter.h"
#include "../include/Date.h"

using namespace date;

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void UserInterface::clear() const {
    cout << u8"\033[2J\033[1;1H";
}

int UserInterface::getDaysApart(year_month_day date1, year_month_day date2) const{
    return (sys_days{date1}-sys_days{date2}).count();
}

vector<Task> UserInterface::fetchNotifications() const {
    auto today = year_month_day{floor<days>(chrono::system_clock::now())};
    vector<Task> approachingTasks;
    for (auto task : loggedInUser.getTaskList()) {
        if (getDaysApart(task.getDeadline(), today) <= 3)
            approachingTasks.push_back(task);
    }
    return approachingTasks;
}

void UserInterface::printNotifications(const vector<Task>& notificationList) const {
    
    cout << "You have " << notificationList.size() << " notifications!\n";
    int daysApart;
    for (auto task : notificationList) {
        daysApart = getDaysApart(task.getDeadline(), year_month_day{floor<days>(chrono::system_clock::now())});
        cout << task.getTaskName() << " is due";
        daysApart == 0 ? cout << " TODAY!\n" : cout << " in " << daysApart << " days!\n";
    }
}

void UserInterface::displayDashboard() const {
    clear();
    string horizontalBar(39+loggedInUser.getName().size(), '-');
    cout << horizontalBar << '\n';
    cout << "   HELLO " << loggedInUser.getName() << ", WELCOME TO YOUR DASHBOARD"  << '\n';
    cout << horizontalBar << '\n';

    vector<Task> approachingTasks = fetchNotifications();
    printNotifications(approachingTasks);
}

void UserInterface::displayListView() const {
    clear();
    cout << "--------------------" << endl;
    cout << "   TASK LIST VIEW   " << endl;
    cout << "--------------------" << endl;

    //cout << "Sort Type: " << endl << endl;

    vector<Task> taskList = loggedInUser.getTaskList();

    for (int i = 0; i < taskList.size(); ++i) {
        cout << i+1 << ". ";
        taskList.at(i).printTask();
        cout << endl;
    }
}