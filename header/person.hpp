#ifndef PERSON_HPP
#define PERSON_HPP

#include "tasks.hpp"
#include <string>
#include <vector>

using namespace std;

//REMEMBER TO UPDATE UML DIAGRAM

class Person {
    private:
        string name;
        string email;
        //12-20 char length
        string password;
        vector<Tasks> tasks;
        vector<Person> friends;
    public:
        //constructors
        Person();
        Person(const string& name, const string& email, const string& password);
        ~Person();

        //accessors
        string getName() const;
        string getEmail() const;
        string getPassword() const;
        vector<Tasks> getTasks() const;
        vector<Person> getFriends() const;

        //mutators
        void setName(const string& newName);
        void setEmail(const string& newEmail);
        void setPassword(const string& newPassword);
        void setTasks(Tasks& newTasks);
        void setFriends(Person& newFriends);

        // //list of issues
        // void delAcc();
        // //prompt user to enter new acc info
        // void signUp();
        // //initially prompts for original password confirmation
        // //automatically sets new password as randomly generated password
        // //max char length
        // string generateRandPassword();
        // //optional
        // void twoFA();
        // //prompts for original password confirmation
        // //may prompt for twoFA()?
        // //12-20 char length
        // void changePassword();
        // //similar to signUp()
        // //unnecessary?
        // void createNewAcc();
        // //prompts for user login info
        // //redirect to dashboard
        // void logIn();

        // //more possible implementations(?)
        // //essentially some additional accessors and mutators
        // string getFriends() const;
        // void changeName(string newName);
        // void changeEmail(string newEmail);
        // void changeTasks(string newTasks);
        // void changeFriends(string newFriends);
};

#endif // PERSON_HPP