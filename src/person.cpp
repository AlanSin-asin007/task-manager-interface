#include "../header/person.hpp"
#include "../header/tasks.hpp"

#include <time.h>
#include <string>
#include <vector>

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

vector<Tasks*> Person::getTasks() const {
    return this->tasks;
}

vector<Person*> Person::getFriends() const {
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

void Person::setTasks(Tasks* newTasks) {
    this->tasks.push_back(newTasks);
}

void Person::setFriends(Person* newFriends) {
    this->friends.push_back(newFriends);
}