#include "../include/UserInterface.h"
#include "../include/Person.h"
#include "../include/TaskSorter.h"

void UserInterface::clear() const {
    cout << u8"\033[2J\033[1;1H";
}

void UserInterface::displayDashboard(Person& p) const {
    clear();
    string horizontalBar(39+p.getName().size(), '-');
    cout << horizontalBar << '\n';
    cout << "   HELLO " << p.getName() << ", WELCOME TO YOUR DASHBOARD"  << '\n';
    cout << horizontalBar << '\n';

}

void UserInterface::displayListView(Person& p) const {
    clear();
    cout << "--------------------" << endl;
    cout << "   TASK LIST VIEW   " << endl;
    cout << "--------------------" << endl;

    //cout << "Sort Type: " << endl << endl;

    vector<Task> taskList = p.getTaskList();

    for (int i = 0; i < taskList.size(); ++i) {
        cout << i+1 << ". ";
        taskList.at(i).printTask();
        cout << endl;
    }
}