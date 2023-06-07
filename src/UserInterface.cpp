#include "../include/UserInterface.h"
#include "../include/Person.h"
#include "../include/TaskSorter.h"



void UserInterface::clear() {
    cout << u8"\033[2J\033[1;1H";
}