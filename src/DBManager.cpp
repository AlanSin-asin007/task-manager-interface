#include<iostream>
#include <fstream>
#include "../Header/DBManager.hpp"
#include "../Header/json.hpp"
using json = nlohmann::json;


Person DBManager::getPerson(string userName)
{
    for(int i=0; i<myPersons.size(); ++i)
    {
     
        if(userName==myPersons.at(i).getName())
        {
            return myPersons.at(i);
        }
    }

    return Person();
}

void DBManager::loadData(string fileName)
{
    std::ifstream f1(fileName);
    json data = json::parse(f1);
    // string name1 = data.value(“name”, “not found”);
    // string grade = data.value(“grade”, “not found”);

    cout << data["Person"][0]["name"]<<endl;
    // Person p;
    int count = data.at("Person").size();

    //From json data object, populate the vector called myPersons
    for(int i = 0; i<count; ++i)
    {
        int c_tasks = data["Person"][i].at("tasks").size();
        int c_friends = data["Person"][i].at("friends").size();
        std::vector<string> t;
        std::vector<string> f;
        for(int j = 0; j<c_tasks; ++j)
        {
            t.push_back(data["Person"][i]["tasks"][j]);
        }

        for(int k = 0; k<c_friends; ++k)
        {
            f.push_back(data["Person"][i]["friends"][k]);
        }
        
        Person p(data["Person"][i]["name"], data["Person"][i]["email"], data["Person"][i]["password"], t, f);
        // Person p(data["Person"][i]["name"], data["Person"][i]["email"], data["Person"][i]["password"],  data["Person"][i].at("tasks"),  data["Person"][i].at("friends"));
        myPersons.push_back(p);
    }
}

void DBManager::storePerson(Person person, string fileName)
{
    json outData;
    for(int i=0; i< myPersons.size(); ++i)
    {
        if(person.getName()==myPersons.at(i).getName())
        {
            json obj2;
            obj2.emplace("name", person.getName());
            obj2.emplace("email", person.getEmail());
            obj2.emplace("password", person.getPassword());
            obj2.emplace("tasks", person.getTasks());
            obj2.emplace("friends", person.getFriends());
            outData.push_back(obj2);
            
        }
        else
        {
        json obj2;
        obj2.emplace("name", myPersons.at(i).getName());
        obj2.emplace("email", myPersons.at(i).getEmail());
        obj2.emplace("password", myPersons.at(i).getPassword());
        obj2.emplace("tasks", myPersons.at(i).getTasks());
        obj2.emplace("friends", myPersons.at(i).getFriends());
        outData.push_back(obj2);
        }
    }
    //To save data to json file, do the following below:
    std::ofstream output(fileName);
    output << std::setw(4) << outData << std::endl;
}