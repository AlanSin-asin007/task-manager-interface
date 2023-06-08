
// #include "../Header/Person.hpp"
#include <iostream>
#include <fstream>
#include "../include/json.h"
#include "../include/Person.h"
#include "../include/Task.h"
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


//For doesExist need to put in DBManager class if want to use it

// bool Person::doesExist(string userName)
// {
// // auto findPerson = response.find(userName);

// // if (findPerson != response.end())
// // {
// //     return true;

// // }
// // else
// // {
// //     return false; 
// // }

//     for(int i=0; i<myPersons.size(); ++i)
//     {
//         string s = myPersons.at(i).getName();
//         if(userName == s)
//         {
//             return true;   
//         }
//     }
//     return false;
// }

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

vector<string> Person::getFriends() const {
    return this->friends;
}

void Person::setName(const string& newName) {
    this->name = newName;
}

void Person::setEmail(const string& newEmail) {
    this->email = newEmail;
}

void Person::setPassword(const string& newPassword) {
    this->password = newPassword;
}

void Person::setTaskList(const vector<Task>& taskList) {
    this->taskList = taskList;
}

void Person::setTasks(Task& newTask) {
    this->taskList.push_back(newTask);
}

void Person::setFriends(Person& newFriends) {
    //this->friends.push_back(newFriends);
}

void Person::setFriendsList(const vector<string>& friendsList) {
    this->friends = friendsList;
}

void Person::signUp(const string newName, const string newEmail, const string newPassword) {
    //check database if name/email is currently in use
    if(checkNameRequirements(newName) && checkEmailRequirements(newEmail) && checkPasswordRequirements(newPassword)) {
        this->name = newName;
        this->email = newEmail;
        this->password = newPassword;
    }
}

//5-15 char limit
//only alphabetical
bool Person::checkNameRequirements(const string newName) const {
    //check char limit
    if(newName.length() < 5 || newName.length() > 15) {
        cout << "Invalid Name: 5-15 character limit" << endl;
        return false;
    }

    //check if alphabetical
    for(unsigned i = 0; i < newName.length(); ++i) {
        if(newName.at(i) < 'A' || newName.at(i) > 'z' || (newName.at(i) > 'Z' && newName.at(i) < 'a')) {
            cout << "Invalid Name: Must contain only letters" << endl;
            return false;
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
bool Person::checkEmailRequirements(const string newEmail) const {
    //check char limit is greater than 5 and less than 257
    if(newEmail.length() < 6 || newEmail.length() > 256) {
        cout << "Invalid Email: 6-257 character limit" << endl;
        return false;
    }

    //check if first char is a letter
    if(newEmail.at(0) < 'A' || newEmail.at(0) > 'z' || (newEmail.at(0) > 'Z' && newEmail.at(0) < 'a')) {
        cout << "Invalid Email: First character must be a letter" << endl;
        return false;
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
        // else if(newEmail.at(i) < '0' || newEmail.at(i) > 'z' || (newEmail.at(i) > '9' && newEmail.at(i) < 'A') || (newEmail.at(i) > 'Z' && newEmail.at(i) < 'a')) {
        //     return false;
        // }
        else if(newEmail.at(i) < 'A' || newEmail.at(i) > 'z' || (newEmail.at(i) > 'Z' && newEmail.at(i) < 'a')) {
            cout << "Invalid Email: Must contain only letters" << endl;
            return false;
        }
    }
    //check if there is only one "@" and is before "."
    if(atCounter != 1 || atIndex >= dotIndex - 1) {
        cout << "Invalid Email: Must contain only one '@' and is before '.'" << endl;
        return false;
    }
    //check if there is only one "." and is not the last char
    else if(dotCounter != 1 || dotIndex == newEmail.length() - 1) {
        cout << "Invalid Email: Must contain only one '.' and is not the last character" << endl;
        return false;
    }
    return true;
}

//12-20 char length
//check if there is at least one letter, special char, and one number
bool Person::checkPasswordRequirements(const string newPassword) const {
    //check char limit is greater than 11 and less than 21
    if(newPassword.length() < 12 || newPassword.length() > 20) {
        cout << "Invalid Password: 12-20 character limit" << endl;
        return false;
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
        cout << "Invalid Password: Must contain at least one letter, number, and special character" << endl;
        return false;
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

