#include<iostream>
#include <fstream>
#include <stdexcept>
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
    //throw an exception here
    throw std::runtime_error("Person does not exist");
    // return Person();
}

void DBManager::loadData(string personJSON, string taskJSON)
{
    std::ifstream personJSONfilestream(personJSON);
    std::ifstream taskJSONfilestream(taskJSON);
    personData = json::parse(personJSONfilestream);
    taskData = json::parse(taskJSONfilestream);
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
        // taskPtrs.push_back(&Task(name, description, label, deadline, rating));

    }

    for(int i = 0; i<personData.at("Person").size(); ++i)
    {
        vector<string> taskNames = personData["Person"][i]["tasks"];
        vector<Task> individualTasks;
        // vector<Task*> individualTaskPtrs;
        vector<string> individualFriends = personData["Person"][i]["friends"];
        vector<string> messages = personData["Person"][i]["messages"];

        //AI
        for (string taskName : taskNames) {
            for (Task task : tasks) {
                if (taskName == task.getTaskName()) {
                    individualTasks.push_back(task);
                    //individualTaskPtrs.push_back(&task);
                }
            }
        }

        // for (string taskName : taskNames) {
        //     for (Task* t : taskPtrs) {
        //         if (taskName == t->getTaskName()) {
        //             individualTaskPtrs.push_back(t);
        //         }
        //     }
        // }


        Person p(personData["Person"][i]["name"],personData["Person"][i]["email"], personData["Person"][i]["password"]);
        p.setTaskList(individualTasks);
        // p.setTaskPtrList(individualTaskPtrs);
        p.setFriendsList(individualFriends);
        p.setMessages(messages);

        myPersons.push_back(p);
        //close the json files

        personJSONfilestream.close();
        taskJSONfilestream.close();

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

bool DBManager::doesExist(const string& newName, const string& newEmail) const
{
    for(int i=0; i<myPersons.size(); ++i)
    {
     
        if(newName==myPersons.at(i).getName() || newEmail==myPersons.at(i).getEmail())
        {
            return true;
        }
    }
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

// saveData: creates Person and Task json objects from myPersons and tasks vectors  
void DBManager::storeNewPerson(Person &p, string personFileName, string taskFileName)
{
    // json all;
    // json jPerson = json::array;
    
    json obj;

    obj["name"] = p.getName();
    obj["email"] = p.getEmail();
    obj["password"] = p.getPassword();
    obj["tasks"] = p.getTaskNames();
    obj["friends"] = p.getFriends();
    obj["messages"] = p.getMessages();

    personData["Person"].push_back(obj);

    std::ofstream personJsonOutput(personFileName);
    personJsonOutput << std::setw(4) << personData << std::endl;
    std::ofstream taskJsonOutput(taskFileName);
    taskJsonOutput << std::setw(4) << taskData << std::endl;

    personJsonOutput.close();
    taskJsonOutput.close();


}

//storePerson: modifies the existing person an task json objects and saves them in json file
void DBManager::storePerson(Person person, string personFileName, string taskFileName)
{
    //Iterates through personData json object, finds matching peron and only changes the matching person json
    for(int i = 0; i<personData.at("Person").size(); ++i)
    // for(int i=0; i<myPersons.size(); ++i)
    {
        if(person.getName()==personData["Person"][i]["name"])
        {
            // json obj2;

            personData["Person"][i]["email"] = person.getEmail();
            personData["Person"][i]["password"] = person.getPassword();
            personData["Person"][i]["friends"] = person.getFriends();
            personData["Person"][i]["messages"] = person.getMessages();
            
            vector<string> taskNames;
            for(Task task : person.getTaskList())
            {
                taskNames.push_back(task.getTaskName());
                //Loop through the taskData and find the matching tasks to replace
                for(int m=0; m<taskData.at("Tasks").size(); ++m)
                {
                    if(taskData.at("Tasks")[m]["id"]== task.getTaskName())
                    {
                        // string name = taskData.at("Tasks")[m]["id"];
                        taskData.at("Tasks")[m]["description"] = task.getDescription();
                        taskData.at("Tasks")[m]["label"] = task.getLabel();
                        taskData.at("Tasks")[m]["rating"] = task.getRating();
                        taskData.at("Tasks")[m]["deadline"]["yy"] = static_cast<int>(task.getDeadline().year());
                        taskData.at("Tasks")[m]["deadline"]["mm"] = static_cast<unsigned>(task.getDeadline().month());
                        taskData.at("Tasks")[m]["deadline"]["dd"] = static_cast<unsigned>(task.getDeadline().day());
                    }
                }
            }
            personData["Person"][i]["tasks"] = taskNames;
            // obj2.emplace("name", person.getName());
            // obj2.emplace("email", person.getEmail());
            // obj2.emplace("password", person.getPassword());
            // //obj2.emplace("tasks", person.getTasks());
            // obj2.emplace("friends", person.getFriends());
            // personData.at["Person"]
            
        }
    }
    //To save data to json file, do the following below:
    std::ofstream personJsonOutput(personFileName);
    personJsonOutput << std::setw(4) << personData << std::endl;
    std::ofstream taskJsonOutput(taskFileName);
    taskJsonOutput << std::setw(4) << taskData << std::endl;

    personJsonOutput.close();
    taskJsonOutput.close();
}

void DBManager::validateLogin(string& userName, string& password) const {
    for (Person person : myPersons) {
        if (person.getName() == userName && person.getPassword() == password) {
            return;
        }
    }
    throw runtime_error("Invalid Login!\n");
}

//STEPS TO FOLLOW

//1. LOAD PERSONS JSON FILE INTO JSON STRUCTURE WHICH IS FIRST 2 LINES OF CODE IN LOAD DATA FUNCTION
//2. LOAD TASK JSON FILE INTO JSON STRUCTURE AND THEN POPULATE myTasks vector
//3. FIND Person id of interest and create person object by looking for Person from step 1 noted down. Also make sure to
//add tasks pointers in the this Person object. 
//4. 