#include "../include/UserInterface.h"
#include "../include/TaskSorter.h"
#include "../include/DateSorter.h"
#include "../include/ImportanceSorter.h"
#include "../include/Person.h"
#include "../include/Task.h"
#include "../include/Date.h"
#include <iomanip>

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

void UserInterface::displayListView() {
    TaskSorter* sorter = new ImportanceSorter(&loggedInUser);
    sorter->performSort();

    clear();
    cout << "--------------------" << '\n';
    cout << "   TASK LIST VIEW   " << '\n';
    cout << "--------------------" << '\n';

    cout << "Sort Type: RATING" << "\n\n";

    vector<Task> taskList = loggedInUser.getTaskList();

    for (int i = 0; i < taskList.size(); ++i) {
        cout << i+1 << ". ";
        taskList.at(i).printTask();
        cout << '\n';
    }
}

void UserInterface::displayCalendarView() {
    TaskSorter* sorter = new DateSorter(&loggedInUser);
    sorter->performSort();

    clear();
    cout << "---------------------" << '\n';
    cout << "    CALENDAR VIEW    " << '\n';
    cout << "---------------------" << '\n';

    cout << "Sort Type: DEADLINE" << "\n\n";

    auto today = floor<days>(chrono::system_clock::now());
    for (int i = 0; i < 7; ++i) {
        cout << setfill('+') << setw(10) << '\n';
        //cout << "|" << setfill(' ') << setw(8) << "|" << '\n';
        cout << "|"<< weekday{today} + days{i} << setfill(' ') << setw(5) << "|" << '\n';
        //cout << "|" << setfill(' ') << setw(8) << "|" << '\n';
        cout << setfill('+') << setw(10) << '\n' ;
        for (Task task : loggedInUser.getTaskList()) {
            if (getDaysApart(task.getDeadline(), year_month_day{today}) == i) {
                cout << '\n';
                task.printTask();
            }
        }
        cout << '\n';
    }
}

void UserInterface::startupMenu() {
    clear();
    int choice;
    cout << "-------------------------" << '\n';
    cout << " WELCOME TO TASK MANAGER " << '\n';
    cout << "-------------------------" << '\n';
    cout << "\n\n";

    while(true) {
        
        cout << "OPTIONS:" << '\n';
        cout << "1. Login" << '\n';
        cout << "2. Sign Up" << '\n';
        cout << "3. Quit Program" << '\n';
        cout << "Enter Selection: ";

        try {
            cin >> choice;
            databaseManager.loadData("personData.json", "taskData.json");
            switch(choice) {
                case 1:
                    login();
                    displayDashboard();
                    break;
                case 2:
                    cout << "SIGNING UP..." << endl;
                    break;
                case 3:
                    cout << "EXITING..." << endl;
                    exit(0);
                    break;
                default:
                    throw runtime_error("Enter a valid choice!\n");
                    break;

            }
        } catch (const runtime_error& e) {
            clear();
            cout << e.what() << endl;
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void UserInterface::login() {
    clear();
    cout << "---------------------" << '\n';
    cout << "        LOGIN        " << '\n';
    cout << "---------------------" << '\n';
    cout << "\n\n";

    string userName, password;
    cout << "Enter your Username: ";
    cin >> userName;
    cout << "Enter your Password: ";
    cin >> password;
    databaseManager.validateLogin(userName, password);
    loggedInUser = databaseManager.getPerson(userName);
}