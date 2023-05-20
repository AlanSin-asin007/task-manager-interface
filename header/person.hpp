#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>

using namespace std;

class Person {
    private:
        string name;
        string email;
        //12-20 char length
        string password;
        string tasks;
        string friends;
    public:
        //constructors
        Person();
        Person(string name, string email, string password, string tasks, string friends);

        //accessors
        string getName() const;
        string getEmail() const;
        string getPassword() const;
        string getTasks() const;

        // //list of issues
        // void delAcc();
        // //prompt user to enter new acc info
        // void signUp();
        // //initially prompts for original password confirmation
        // //automatically sets new password as randomly generated password
        // //max char length
        string generateRandPassword();
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