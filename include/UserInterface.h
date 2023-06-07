#ifndef _USER_INTERFACE_
#define _USER_INTERFACE_

#include <iostream>
#include "Date.h"
#include "Person.h"

using namespace std;

class UserInterface {
    private:
        void clear();
    public:
        void displayDashboard();
        void displayListView(Person& p);

};


#endif