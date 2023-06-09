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

void UserInterface::displayDashboard() {
    int choice;

    clear();
    while(true) {
        string horizontalBar(39+loggedInUser.getName().size(), '-');
        cout << horizontalBar << '\n';
        cout << "   HELLO " << loggedInUser.getName() << ", WELCOME TO YOUR DASHBOARD"  << '\n';
        cout << horizontalBar << '\n';

        printNotifications(fetchNotifications());
        cout << '\n';

        cout << "OPTIONS:" << '\n';
        cout << "1. View Task List" << '\n';
        cout << "2. View Calendar List" << '\n';
        cout << "3. Add Task" << '\n';
        //cout << "4. Change Tasks" << '\n';
        cout << "4. Message Friend" << '\n';
        cout << "5. Logout" << '\n';
        cout << "Enter Selection: ";

        try {
            cin >> choice;
            switch(choice) {
                case 1:
                    displayListView();
                    break;
                case 2:
                    displayCalendarView();
                    break;
                case 3:
                    createNewTask();
                    break;
                case 4:
                    break;
                case 5:
                    logout();
                    return;
                    break;
                default:
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

void UserInterface::createNewTask() {
    clear();
    cout << "---------------------" << '\n';
    cout << "   CREATE NEW TASK   " << '\n';
    cout << "---------------------" << '\n';


    string newTaskName;
    string newTaskDescription;
    string newTaskLabel;
    int deadlineYear;
    unsigned deadlineMonth;
    unsigned deadlineDay;
    unsigned newTaskRating;
    cin.ignore();
    cout << "Enter Task Name: ";
    getline(cin, newTaskName);
    cout << "Enter Task Description: ";
    getline(cin, newTaskDescription);
    cout << "Enter Task Label: ";
    getline(cin, newTaskLabel);
    cout << "Enter Deadline Year (yyyy): ";
    //cin.ignore();
    cin >> deadlineYear;
    cout << "Enter Deadline Month (1-12): ";
    cin >> deadlineMonth;
    cout << "Enter Deadline Day (1-31): ";
    cin >> deadlineDay;
    cout << "Enter the importance rating (1-10): ";
    cin >> newTaskRating;

    year_month_day taskDeadline = year(deadlineYear)/month(deadlineMonth)/day(deadlineDay);
    if (!taskDeadline.ok()) {
        throw runtime_error("Date is invalid!");
    } else if (getDaysApart(taskDeadline, year_month_day{floor<days>(chrono::system_clock::now())}) < 0) {
        throw runtime_error("Deadline cannot be in the past!");
    } else if (newTaskRating < 1 || newTaskRating > 10) {
        throw runtime_error("Importance Rating must be between 1 and 10");
    }
    char userConfirm;
    while (true) {
        cout << "Are you sure you want to make this task? (Y/N): ";
        cin >> userConfirm;
        switch(userConfirm) {
            case 'y': case 'Y': {
                cout << "Creating Task...\n";
                Task newTask(newTaskName, newTaskDescription, newTaskLabel, taskDeadline, newTaskRating);
                cout << "Adding Task...\n";
                loggedInUser.addTask(newTask);
                cout << "SUCCESS!\n";
                return;
            }   break;
            case 'n': case 'N':
                cout << "CANCELLING NEW TASK...\n";
                return;
                break;
            default:
                break;
        }
    }
}

void UserInterface::displayListView() {
    TaskSorter* sorter = new ImportanceSorter(loggedInUser);
    sorter->performSort();
    delete sorter;

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

    cout << "Press ENTER to return to dashboard...\n";
    string input;
    cin.ignore();
    getline(cin, input);
}

void UserInterface::displayCalendarView() {
    TaskSorter* sorter = new DateSorter(loggedInUser);
    sorter->performSort();
    delete sorter;

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

    cout << "Press ENTER to return to dashboard...\n";
    string input;
    cin.ignore();
    getline(cin, input);
}

void UserInterface::startupMenu() {

    clear();
    while(true) {
        int choice;
        cout << "-------------------------" << '\n';
        cout << " WELCOME TO TASK MANAGER " << '\n';
        cout << "-------------------------" << '\n';
        cout << "\n\n";
        
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
                    signUp();
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

void UserInterface::logout() {
    clear();
    cout << "LOGGING OUT...\n";
    databaseManager.storePerson(loggedInUser, "personData.json", "taskData.json");
}

void UserInterface::signUp() {
    string userName;
    string email;
    string password;
    while (true) {
        clear();
        cout << "---------------------" << '\n';
        cout << "       SIGN UP       " << '\n';
        cout << "---------------------" << '\n';

        cout << "\n\n";
        cout << "Enter your Username: ";
        cin >> userName;
        cout << "Enter your Email: ";
        cin >> email;
        cout << "Enter your Password: ";
        cin >> password;

        if(!databaseManager.doesExist(userName, email)) {
            if(checkNameRequirements(userName) && checkEmailRequirements(email) && checkPasswordRequirements(password)) {
                Person newPerson(userName, email, password);
                databaseManager.storeNewPerson(newPerson, "personData.json", "taskData.json");
                clear();
                cout << "Successfully signed up!\nYou can now log in\n";
                return;
            }
        }
        throw runtime_error("Sign up Failed!\nUser with that name or email already exists.");
    }
}

bool UserInterface::checkNameRequirements(const string& newName) const {
    //check char limit
    if(newName.length() < 2 || newName.length() > 64) {
        throw runtime_error("Invalid Name: 2-65 character limit");
    }

    //check if alphabetical
    for(unsigned i = 0; i < newName.length(); ++i) {
        if(newName.at(i) < 'A' || newName.at(i) > 'z' || (newName.at(i) > 'Z' && newName.at(i) < 'a')) {
            throw runtime_error("Invalid Name: Must contain only letters");
        }
    }
    return true;
}

bool UserInterface::checkEmailRequirements(const string& newEmail) const {
    //check char limit is greater than 5 and less than 257
    if(newEmail.length() < 6 || newEmail.length() > 256) {
        throw runtime_error("Invalid Email: 6-257 character limit");
    }

    //check if first char is a letter
    if(newEmail.at(0) < 'A' || newEmail.at(0) > 'z' || (newEmail.at(0) > 'Z' && newEmail.at(0) < 'a')) {
        throw runtime_error("Invalid Email: First character must be a letter");
    }

    //check for "@" and "."
    //check if char is alphabetical
    int atCounter = 0;
    int atIndex = -1;
    int dotCounter = 0;
    int dotIndex = -1;
    for(unsigned i = 0; i < newEmail.length(); ++i) {
        if(newEmail.at(i) == '@') {
            atCounter++;
            atIndex = i;
        }
        else if(newEmail.at(i) == '.') {
            dotCounter++;
            dotIndex = i;
        }
        else if(newEmail.at(i) < '0' || newEmail.at(i) > 'z' || (newEmail.at(i) > '9' && newEmail.at(i) < 'A') || (newEmail.at(i) > 'Z' && newEmail.at(i) < 'a')) {
            throw runtime_error("Invalid Email: Must contain only letters");
        }
        // else if(newEmail.at(i) < 'A' || newEmail.at(i) > 'z' || (newEmail.at(i) > 'Z' && newEmail.at(i) < 'a')) {
        //     throw runtime_error("Invalid Email: Must contain only letters");
        // }
    }
    //check if there is only one "@" and is before "."
    if(atCounter != 1 || atIndex >= dotIndex - 1) {
        throw runtime_error("Invalid Email: Must contain only one '@' and is before '.'");
    }
    //check if there is only one "." and is not the last char
    else if(dotCounter != 1 || dotIndex == newEmail.length() - 1) {
        throw runtime_error("Invalid Email: Must contain only one '.' and is not the last character");
    }
    return true;
}

bool UserInterface::checkPasswordRequirements(const string& newPassword) const {
    //check char limit is greater than 11 and less than 21
    if(newPassword.length() < 12 || newPassword.length() > 20) {
        throw runtime_error("Invalid Password: 12-20 character limit");
    }

    //check if there is at least one letter, special char, and one number
    int letterCounter = 0;
    int specialCharCounter = 0;
    int numCounter = 0;
    for(unsigned i = 0; i < newPassword.length(); ++i) {
        if((newPassword.at(i) >= 'A' && newPassword.at(i) <= 'Z') || (newPassword.at(i) >= 'a' && newPassword.at(i) <= 'z')) {
            letterCounter++;
        }
        else if((newPassword.at(i) >= '!' && newPassword.at(i) <= '/') || (newPassword.at(i) >= ':' && newPassword.at(i) <= '@') || (newPassword.at(i) >= '[' && newPassword.at(i) <= '`') || (newPassword.at(i) >= '{' && newPassword.at(i) <= '~')) {
            specialCharCounter++;
        }
        else if(newPassword.at(i) >= '0' && newPassword.at(i) <= '9') {
            numCounter++;
        }
    }
    if(letterCounter == 0 || specialCharCounter == 0 || numCounter == 0) {
        throw runtime_error("Invalid Password: Must contain at least one letter, number, and special character");
    }
    return true;
}