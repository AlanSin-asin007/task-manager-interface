#ifndef PERSON_HPP
#define PERSON_HPP

using namespace std;
#include <vector>
#include <string>
class Person
{
private:
        string name;
        string email;
        //12-20 char length
        string password;
        vector<string> tasks;
        vector<string> friends;
    
public:

    Person();

    ~Person();

    Person(string n, string e, string p, vector<string> &t, vector<string> &f);

    void MessageFriend(string userName, string text);

    void ShareSchedule(string userName);

    //accessors
    string getName() const;
    string getEmail() const;
    string getPassword() const;
    vector<string> getTasks() const;
    vector<string> getFriends() const;

    // vector<People> LoadPeople();

        //mutators
    void setName(string newName);
    void setEmail(string newEmail);
    void setPassword(string newPassword);
    void setTasks(vector<string> newTasks);
    void setFriends(vector<string> newFriends);

        //new mutators
    void AddFriend(string userName);
    static bool doesExist(string userName);

};
#endif