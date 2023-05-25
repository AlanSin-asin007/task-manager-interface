#ifndef PERSON_HPP
#define PERSON_HPP

#include <string>
#include <stdexcept>
#include <time.h>

using namespace std;

//REMEMBER TO UPDATE UML DIAGRAM

class Person {
    private:
        //5-15 char limit
        //only alphabetical
        string name;
        //1-60 char limit before "@"
        //1-191 char limit after "@" and before "."
        //only alphabetical and numerical
        string email;
        //12-20 char length
        //check if there is at least one numerical and one special char
        string password;
        //list of Task objects
        string tasks;
        //list of Person objects
        string friends;
    public:
        //constructors
        Person();
        Person(const string name, const string email, const string password, const string tasks, const string friends);
        ~Person();

        //accessors
        string getName() const;
        string getEmail() const;
        string getPassword() const;
        string getTasks() const;
        string getFriends() const;

        //mutators
        void setName(const string newName);
        void setEmail(const string newEmail);
        void setPassword(const string newPassword);
        void setTasks(const string newTasks);
        void setFriends(const string newFriends);

        // //list of issues
        // void delAcc();
        //prompt user to enter new acc info
        void signUp(const string newName, const string newEmail, const string newPassword);
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

    private:
        //helper functions
        bool checkNameRequirements(const string newName) const;
        bool checkEmailRequirements(const string newEmail) const;
        bool checkPasswordRequirements(const string newPassword) const;
};

#endif // PERSON_HPP