#ifndef _USER_INTERFACE_
#define _USER_INTERFACE_

#include <iostream>
#include "Date.h"
#include "Person.h"

using namespace std;

class UserInterface {
    private:
        void clear() const;
        vector<Task> fetchNotifications(const Person& p) const;
    public:
        void displayDashboard(Person& p) const;
        void displayListView(Person& p) const;

};


#endif