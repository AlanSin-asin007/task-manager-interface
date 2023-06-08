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

    // string name1 = data.value(“name”, “not found”);
    // string grade = data.value(“grade”, “not found”);

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
        
        //Task t1 = taskData.at("Tasks")[m].get<Task>();
        tasks.push_back(Task(name, description, label, deadline, rating));

    }


    for(int i = 0; i<data.at("Person").size(); ++i)
    {
        vector<string> taskNames = data["Person"][i]["tasks"];
        vector<Task> individualTasks;
        vector<string> individualFriends = data["Person"][i]["friends"];

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


        // for(int j = 0; j < taskName.size(); ++j)
        // { 
        //     for(int k = 0; k < tasks.size(); ++k)
        //     {
        //         if ()
        //         individualTasks.push_back(data[""]);
        //     }
        // }

        // vector<Person> dummyFriends;
        
        // Person p(data["Person"][i]["name"], data["Person"][i]["email"], data["Person"][i]["password"], individualTasks, dummyFriends);

        // myPersons.push_back(p);

        // for(int j = 0; j<individualTasks.size(); )

        // for(int j = 0; j<tasks.size(); ++i)
        // {
        //     for(int k = 0; k<individualTasks.size(); ++k)
        //     {
        //         if(taskData["tasks"][k]["id"]== data["Person"])
        //         individualTasks.push_back(Task)
        //     }
        // }

        //vector<Person> dummyFriends;

        //Person p(jperson Name, jperson Email, jperson Password, individualTasks, dummyFriends);

        //myPersons.push_back(p);
    }



    // for (auto task : tasks) {
    //     task.printTask();
    // }

    

    //From json data object, populate the vector called myPersons
    // for(int i = 0; i<count; ++i)
    // {
    //     int c_tasks = data["Person"][i].at("tasks").size();
    //     int c_friends = data["Person"][i].at("friends").size();
    //     std::vector<string> taskStrings;
    //     std::vector<string> friendStrings;
    //     // std::vector<task> tasks;
    //     json taskData = json::parse("task1.json");


    //     // for(int p = 0; p<data["Person"][i]["Tasks"].size(); ++p)
    //     // {
    //     //     for(int m=0; i<taskData.at("Tasks").size(); ++m)
    //     // {
    //     //     //find the corrresponding task within task data and put it in the tasks vector
    //     //     //1) Look through taskData, find names that match
    //     //     //2) Build Task objects from taskData
    //     //     //3) Load the Task object into tasks vector using push_back()
    //     //     //4) Create Person object using tasks vector
    //     //     //5) push_back onto myPersons.
    //     //     cout << 

    //     //     if(data["Person"][i]["Tasks"][p]==taskData.at("Tasks")[m])
    //     //     {
                
                
    //     //     }

    //     //     tasks.push_back();

    //     // }
    //     // }

    //     // for(int m=0; i<taskData.at("Tasks").size(); ++m)
    //     // {
    //     //     //find the corrresponding task within task data and put it in the tasks vector
    //     //     //1) Look through taskData, find names that match
    //     //     //2) Build Task objects from taskData
    //     //     //3) Load the Task object into tasks vector using push_back()
    //     //     //4) Create Person object using tasks vector
    //     //     //5) push_back onto myPersons.
    //     //     cout << 

    //     //     if(taskStrings.at(i)==taskData.at[m]("Tasks"))
    //     //     {
    //     //         //build task object
                
    //     //     }

    //     //     tasks.push_back();

    //     // }

    //     for(int j = 0; j<c_tasks; ++j)
    //     {
    //         t.push_back(data["Person"][i]["tasks"][j]);
    //     }

    //     for(int k = 0; k<c_friends; ++k)
    //     {
    //         f.push_back(data["Person"][i]["friends"][k]);
    //     }
        
    //     Person p(data["Person"][i]["name"], data["Person"][i]["email"], data["Person"][i]["password"], tasks, friendStrings);
    //     // Person p(data["Person"][i]["name"], data["Person"][i]["email"], data["Person"][i]["password"],  data["Person"][i].at("tasks"),  data["Person"][i].at("friends"));

    //     myPersons.push_back(p);

    //     //Instead of pushing all persons, load only that particular person. 
    // }
}

// void DBManager::loadTasks(string fileName)
// {
//     std::ifstream f1(fileName);
//     json data = json::parse(f1);

//     int count = data.at("Tasks").size();

//     //From json data object, populate the vector called taskList
//     for(int i = 0; i<count; ++i)
//     {
        
//         // (data["Tasks"]["id"]);

//         int yy = data["Person"][i]["deadline"]["yy"];
//         int mm = data["Person"][i]["deadline"]["mm"];
//         int dd = data["Person"][i]["deadline"]["dd"];


//         //construct a deadline object using yy mm dd

//         year_month_day deadlineDate = year(yy)/month(mm)/day(dd);

        
//         Task t(data["Person"][i]["id"],data["Person"][i]["description"], data["Person"][i]["label"], data["Person"][i]["deadline"]);//Add argument for deadline

//         myTasks.push_back(t);
//     }


// }

inline void to_json(nlohmann::json &j, const Person &s)
{
    j["email"] = s.getEmail();
    j["name"] = s.getName();
    j["person"] = s.getFriends();
    //j["task"] = s.getTaskList();
    j["password"] = s.getPassword();
}

// void DBManager::from_json(const nlohmann::json &j, Task &t)
// {
//     //In this funciton do I need to search for a person Name in the json structure? Or is the searching done somewhere else and this function just creates the Person object.
//     // s.setFriends((j.at("Person").get<Person>()));
//     //t.setDescription(j.at("name").get<std::string>());
//     //t.setLabel(j.at("email").get<std::string>());
//     //t.setTaskName(j.at("password").get<std::string>());
//     //t.setDeadline(j.at("password").get<std::string>());
//     //t.setRating(j.at(""));
//     j.at("id").get_to(t.getTaskName());
//     j.at("description").get_to(t.getDescription());
//     j.at("label").get_to(t.getLabel());
//     //j.at("deadline").get_to(t.getDeadline());
//     j.at("rating").get_to(t.getRating());
// }

// void DBManager::from_json(const nlohmann::json &j, Person &s)
// {
//     //In this funciton do I need to search for a person Name in the json structure? Or is the searching done somewhere else and this function just creates the Person object.
//     // s.setFriends((j.at("Person").get<Person>()));
//     s.setName(j.at("name").get<std::string>());
//     s.setEmail(j.at("email").get<std::string>());
//     s.setPassword(j.at("password").get<std::string>());
//     std::vector<string> t;

//     int c_tasks = j.at["Person"][i].at("tasks").size();


//     for(int i = 0; i<c_tasks; ++i)
//     {
//         t.push_back(data["Person"][j]["tasks"][i]);
//     }
//     s.setTaskList(j.at("tasks").get<std::string>());

// }

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