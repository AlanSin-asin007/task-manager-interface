#ifndef DBMANAGER_HPP
#define DBMANAGER_HPP

#include "json.hpp"
#include "Person.hpp"

using namespace std;

class DBManager
{ 
private:

    vector<Person> myPersons;
    
public: 

    void loadData(string fileName);

    void storePerson(Person person, string fileName);

    Person getPerson(string userName);






};

#endif