#ifndef _USER_INTERFACE_
#define _USER_INTERFACE_

#include <iostream>
#include "Date.h"
#include "Person.h"
#include "DBManager.h"

using namespace std;
using namespace date;

class UserInterface {
    private:
        DBManager databaseManager;
        Person loggedInUser;
        void clear() const;
        int getDaysApart(year_month_day, year_month_day) const;
        vector<Task> fetchNotifications() const;
        bool checkNameRequirements(const string& newName) const;
        bool checkEmailRequirements(const string& newEmail) const;
        bool checkPasswordRequirements(const string& newPassword) const;
        void printNotifications(const vector<Task>& notificationList) const;
    public:
        UserInterface();
        UserInterface(Person& person) : loggedInUser(person) {};
        ~UserInterface();
        void startupMenu();
        void login();
        void signUp();
        void displayDashboard();
        void displayListView();
        void displayCalendarView();
};

#endif