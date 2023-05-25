#include "../header/person.hpp"

#include <time.h>
#include <string>

using namespace std;

Person::Person() {
    this->name = "";
    this->email = "";
    this->password = "";
    this->tasks = "";
    this->friends = "";
}

Person::Person(const string name, const string email, const string password, const string tasks, const string friends) {
    this->name = name;
    this->email = email;
    this->password = password;
    this->tasks = tasks;
    this->friends = friends;
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

string Person::getTasks() const {
    return this->tasks;
}

string Person::getFriends() const {
    return this->friends;
}

void Person::setName(const string newName) {
    this->name = newName;
}

void Person::setEmail(const string newEmail) {
    this->email = newEmail;
}

void Person::setPassword(const string newPassword) {
    this->password = newPassword;
}

void Person::setTasks(const string newTasks) {
    this->tasks = newTasks;
}

void Person::setFriends(const string newFriends) {
    this->friends = newFriends;
}