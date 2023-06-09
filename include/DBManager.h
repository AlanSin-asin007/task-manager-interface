#ifndef DBMANAGER_H
#define DBMANAGER_H

#include "json.h"
#include "../include/Person.h"

using json = nlohmann::json;
using namespace std;

class DBManager
{ 
private:

    vector<Person> myPersons;
    vector<Task> tasks;
    // vector<Task*> taskPtrs;

    json personData;
    json taskData;
    
public:

    void validateLogin(string& userName, string& password) const;
    bool taskAlreadyExists(string& taskName) const;

    Person getPerson(string userName);

    vector<Person> getMyPersons() const {
        return this->myPersons;
    }

    //Load the Person database from json file
    void loadData(string personJSON, string taskJSON);

    //Add person into database
    void storePerson(Person& person, string personFileName, string taskFileName);


    bool doesExist(const string& newName, const string& newEmail) const;

    void storeNewPerson(Person &p, string personFileName, string taskFileName);

    //
    //void from_json(const nlohmann::json &j, Person &s);
    void to_json(nlohmann::json &j, const Person &s);

    //void from_json(const nlohmann::json &j, Task &t);
    //void to_json(nlohmann::json &j, const Task &t);

    void loadTasks(string fileName);

};

#endif