#include "../header/person.hpp"

#include <stdio.h>
#include <stdlib.h>
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

Person::Person(string name, string email, string password, string tasks, string friends) {
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

void Person::setName(string newName) {
    this->name = newName;
}

void Person::setEmail(string newEmail) {
    this->email = newEmail;
}

void Person::setPassword(string newPassword) {
    this->password = newPassword;
}

void Person::setTasks(string newTasks) {
    this->tasks = newTasks;
}

void Person::setFriends(string newFriends) {
    this->friends = newFriends;
}

string Person::generateRandPassword() {
    srand(time(NULL));

    string randPassword = "";

    for(unsigned i = 0; i < 20; ++i) {
        randPassword += char((rand() % 94) + 33);
    }
    return randPassword;
}