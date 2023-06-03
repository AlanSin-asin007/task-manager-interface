#include "../Header/Person.hpp"
#include <iostream>
#include <fstream>
#include "../Header/json.hpp"
using json = nlohmann::json;
using namespace std;

// ...

// std::vector<Person> myPersons;




//Next goal is to create another branch which splits this one into 2 different branhces.

//


Person::Person() 
:name(""), email(""), password("")
{ }


//TODO: Fix the tasks and friends to be vectors of Strings. 
Person::Person(string n, string e, string p, vector<string> &t, vector<string> &f) 
:name(n), email(e), password(p), tasks(t), friends(f)
{
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

vector<string> Person::getTasks() const {
    return this->tasks;
}

vector<string> Person::getFriends() const {
    return this->friends;
}

void Person::setName(string newName) {
    this->name = newName;
}

void Person::setEmail(string newEmail) {
    this->email = newEmail;
}

void Person::setPassword(string newPassword) {
    this->password = newPassword;
}

void Person::setTasks(vector<string> newTasks) {
    this->tasks = newTasks;
}

void Person::setFriends(vector<string> newFriends) {
    this->friends = newFriends;
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