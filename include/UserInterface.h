#ifndef _USER_INTERFACE_
#define _USER_INTERFACE_

#include <iostream>
#include "Date.h"
#include "Person.h"

using namespace std;
using namespace date;

class UserInterface {
    private:
        //DBManager database;
        //Person loggedInUser;
        void clear() const;
        int getDaysApart(year_month_day, year_month_day) const;
        vector<Task> fetchNotifications(const Person&) const;
        void printNotifications(const vector<Task>&) const;
    public:
        UserInterface();
        ~UserInterface();
        void displayDashboard(Person&) const;
        void displayListView(Person&) const;
};


#endif