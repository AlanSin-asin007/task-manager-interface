#include<iostream>
#include <fstream>
#include "../include/DBManager.h"
#include "../include/json.h"
#include "../include/Person.h"
#include "../include/Date.h"

using json = nlohmann::json;
using namespace date;


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

void DBManager::loadData(string personJSON, string taskJSON)
{
    std::ifstream personJSONfilestream(personJSON);
    std::ifstream taskJSONfilestream(taskJSON);
    json data = json::parse(personJSONfilestream);
    json taskData = json::parse(taskJSONfilestream);
    std::vector<Task> tasks;

// //IMPORTANT NOTE ANY LINE OF CODE BEYOND THIS IS NOT NEEDED FOR NOW
    // cout << data["Person"][0]["name"]<<endl;
    // Person p;
    // int count = data.at("Person").size();

    for(int m=0; m<taskData.at("Tasks").size(); ++m)
    {

        string name = taskData.at("Tasks")[m]["id"];
        string description = taskData.at("Tasks")[m]["description"];
        string label = taskData.at("Tasks")[m]["label"];
        int deadlineYear = taskData.at("Tasks")[m]["deadline"]["yy"];
        int deadlineMonth = taskData.at("Tasks")[m]["deadline"]["mm"];
        int deadlineDay = taskData.at("Tasks")[m]["deadline"]["dd"];
        year_month_day deadline = year(deadlineYear)/month(deadlineMonth)/day(deadlineDay);
        int rating = taskData.at("Tasks")[m]["rating"];
        
        tasks.push_back(Task(name, description, label, deadline, rating));

    }

    for(int i = 0; i<data.at("Person").size(); ++i)
    {
        vector<string> taskNames = data["Person"][i]["tasks"];
        vector<Task> individualTasks;
        vector<string> individualFriends = data["Person"][i]["friends"];

        //AI
        for (string taskName : taskNames) {
            for (Task task : tasks) {
                if (taskName == task.getTaskName()) {
                    individualTasks.push_back(task);
                }
            }
        }


        Person p(data["Person"][i]["name"],data["Person"][i]["email"], data["Person"][i]["password"]);
        p.setTaskList(individualTasks);
        p.setFriendsList(individualFriends);

    myPersons.push_back(p);
    }

//1) Look through taskData, find names that match
//2) Build Task objects from taskData
//3) Load the Task object into tasks vector using push_back()
//4) Create Person object using tasks vector
//5) push_back onto myPersons

}

inline void to_json(nlohmann::json &j, const Person &s)
{
    j["email"] = s.getEmail();
    j["name"] = s.getName();
    j["person"] = s.getFriends();
    //j["task"] = s.getTaskList();
    j["password"] = s.getPassword();
}

bool DBManager::doesExist(Person& person)
{
    return false;
}

// void DBManager::AddFriend(string userName)
// {
//     if(doesExist(userName))
//     {
//         for(int i=0; i<myPersons.size(); ++i)
//         { 
//             // myPersons.at(i).getFriends(userName);
//             //myPersons.at(i).setFriends(friends).push_back(userName);
//             this->friends.push_back(userName);
//         }
//     }

//     else
//     {
//         cout<<"Friend to add does not Exist, try another friend";
//     }
// }

void DBManager::storePerson(Person person, string fileName)
{
    json outData;
    for(int i=0; i<myPersons.size(); ++i)
    {
        if(person.getName()==myPersons.at(i).getName())
        {
            json obj2;
            obj2.emplace("name", person.getName());
            obj2.emplace("email", person.getEmail());
            obj2.emplace("password", person.getPassword());
            //obj2.emplace("tasks", person.getTasks());
            obj2.emplace("friends", person.getFriends());
            outData.push_back(obj2);
            
        }
        else
        {
        json obj2;
        obj2.emplace("name", myPersons.at(i).getName());
        obj2.emplace("email", myPersons.at(i).getEmail());
        obj2.emplace("password", myPersons.at(i).getPassword());
        //obj2.emplace("tasks", myPersons.at(i).getTasks());
        obj2.emplace("friends", myPersons.at(i).getFriends());
        outData.push_back(obj2);
        }
    }
    //To save data to json file, do the following below:
    std::ofstream output(fileName);
    output << std::setw(4) << outData << std::endl;
}



//STEPS TO FOLLOW

//1. LOAD PERSONS JSON FILE INTO JSON STRUCTURE WHICH IS FIRST 2 LINES OF CODE IN LOAD DATA FUNCTION
//2. LOAD TASK JSON FILE INTO JSON STRUCTURE AND THEN POPULATE myTasks vector
//3. FIND Person id of interest and create person object by looking for Person from step 1 noted down. Also make sure to
//add tasks pointers in the this Person object. 
//4. 