#include "../header/person.hpp"

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

void Person::signUp(const string newName, const string newEmail, const string newPassword) {
    //check database if name/email is currently in use
    if(!checkNameRequirements(newName)) {
        //throw exception for invalid name
    }
    else if(!checkEmailRequirements(newEmail)) {
        //throw exception for invalid email
    }
    else if(!checkPasswordRequirements(newPassword)) {
        //throw exception for invalid password
    }
    else {
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
        return false;
    }

    //check if alphabetical
    for(unsigned i = 0; i < newName.length(); ++i) {
        if(newName.at(i) < 'A' || newName.at(i) > 'z' || (newName.at(i) > 'Z' && newName.at(i) < 'a')) {
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
        return false;
    }

    //check if first char is a letter
    if(newEmail.at(0) < 'A' || newEmail.at(0) > 'z' || (newEmail.at(0) > 'Z' && newEmail.at(0) < 'a')) {
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
            return false;
        }
    }
    //check if there is only one "@" and is before "."
    if(atCounter != 1 || atIndex >= dotIndex - 1) {
        return false;
    }
    //check if there is only one "." and is not the last char
    else if(dotCounter != 1 || dotIndex == newEmail.length() - 1) {
        return false;
    }
    return true;
}

//12-20 char length
//check if there is at least one letter, special char, and one number
bool Person::checkPasswordRequirements(const string newPassword) const {
    //check char limit is greater than 11 and less than 21
    if(newPassword.length() < 12 || newPassword.length() > 20) {
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
        return false;
    }
    return true;
}