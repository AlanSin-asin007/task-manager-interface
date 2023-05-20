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

Person::Person(string name, string email, string password, string tasks, string friends) {
    this->name = name;
    this->email = email;
    this->password = password;
    this->tasks = tasks;
    this->friends = friends;
}

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

string Person::generateRandPassword() {
    srand(time(NULL));

    unsigned i;
    string randPassword = "";

    for(i = 0; i < 20; ++i) {
        randPassword += char((rand() % 94) + 33);
    }
    return randPassword;
}