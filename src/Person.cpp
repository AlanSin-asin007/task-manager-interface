
// #include "../Header/Person.hpp"
#include <iostream>
#include <fstream>
#include "../include/json.h"
#include "../include/Person.h"
#include "../include/Task.h"
#include "../include/DBManager.h"
using json = nlohmann::json;
using namespace std;

Person::Person() {
    this->name = "";
    this->email = "";
    this->password = "";
}

Person::Person(const string& name, const string& email, const string& password) {
    this->name = name;
    this->email = email;
    this->password = password;
}

Person::~Person() {}

string Person::getName() const {
    return this->name;
}

string Person::getEmail() const {
    return this->email;
}

string Person::getPassword() const {
    return this->password;
}

// void Person::AddFriend(string userName)
// {
//     if(doesExist(userName))
//     {
//         for(int i=0; i<myPersons.size(); ++i)
//         { 
//             // myPersons.at(i).getFriends(userName);
//             //myPersons.at(i).setFriends(friends).push_back(userName);
//             this->friends.push_back(userName);
//         }
//     }

//     else
//     {
//         cout<<"Friend to add does not Exist, try another friend";
//     }
// }
vector<Task> Person::getTaskList() const {
    return this->taskList;
}

vector<string> Person::getTaskNames() const {
    vector<string> v;
    for (Task t: taskList)
    {
        v.push_back(t.getTaskName());
    }
    return v;
}

vector<string> Person::getFriends() const {
    return this->friendsList;
}

vector<string> Person::getMessages() const {
    return this->messages;
}

void Person::setName(const string& newName) {
    if(checkNameRequirements(newName)) {
        this->name = newName;
    }
}

void Person::setEmail(const string& newEmail) {
    if(checkEmailRequirements(newEmail)) {
        this->email = newEmail;
    }
}

void Person::setPassword(const string& newPassword) {
    if(checkPasswordRequirements(newPassword)) {
        this->password = newPassword;
    }
}

void Person::setTaskList(const vector<Task>& taskList) {
    this->taskList = taskList;
}

// void Person::addTaskPtr(Task *newTask)
// {
//     taskPtrList.push_back(newTask);
// }

// void Person::setTaskPtrList(const vector<Task*> &taskPtrList)
// {
//     this->taskPtrList = taskPtrList;
// }

void Person::setTasks(Task& newTask) {
    this->taskList.push_back(newTask);
}

void Person::setFriendsList(const vector<string>& friendsList) {
    this->friendsList = friendsList;
}

void Person::setMessages(const vector<string>& m) 
{
    messages = m;
}

//sendMessage: send a message to userName.
void Person::sendMessage(const string &userName, const string &message)
{
    string m;
    m = userName + ": " + message;
    messages.push_back(m);
}

void Person::signUp(const string& newName, const string& newEmail, const string& newPassword) {
    //check database if name/email is currently in use
    DBManager signUpDBManager;

    signUpDBManager.loadData("personData.json", "taskData.json");

    if(signUpDBManager.doesExist(newName, newEmail)) {
        throw runtime_error("Error: Name and/or Email already exists.");
    }
    else if(checkNameRequirements(newName) && checkEmailRequirements(newEmail) && checkPasswordRequirements(newPassword)) {
        this->name = newName;
        this->email = newEmail;
        this->password = newPassword;
    }
}

//2-65 char limit
//only alphabetical
bool Person::checkNameRequirements(const string& newName) const {
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

//1-60 char limit before "@"
//1-191 char limit after "@" and before "."
//only alphabetical and numerical
//check for only one "@"

//case 1: first char is a letter
//case 2: "@" somewhere in the str before the "."
//case 3: text after "@" but before "."
//case 4: text after "."
bool Person::checkEmailRequirements(const string& newEmail) const {
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

//12-20 char length
//check if there is at least one letter, special char, and one number
bool Person::checkPasswordRequirements(const string& newPassword) const {
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

string Person::generateRandPassword() {
    srand(time(NULL));

    string randPassword = "";

    for(unsigned i = 0; i < 20; ++i) {
        randPassword += char((rand() % 94) + 33);
    }
    return randPassword;
}

void Person::changePassword(const string& originalPassword, const string& newPassword, const string& confirmNewPassword) {
    if(this->password == originalPassword) {
        if(newPassword == confirmNewPassword && checkPasswordRequirements(newPassword)) {
            this->password = newPassword;
        }
        else {
            throw runtime_error("Error in confirming new password.");
        }
    }
    else {
        throw runtime_error("Incorrect original password.");
    }
}

bool Person::logIn(const string& newEmail, const string& newPassword) const {
    //check database for same email and correct corresponding password

    //check if email is found in database
    //then check if email's corresponding password is the same as newPassword
    //return true if both are true
    //return false otherwise

    return false;
}