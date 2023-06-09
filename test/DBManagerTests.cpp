#include "gtest/gtest.h"
#include "../include/json.h"
#include "../include/DBManager.h"
#include <iostream>
#include <fstream>

using json = nlohmann::json;
using namespace std;

TEST(loadDataTests, loadNormalData)
{
    DBManager DB;

    EXPECT_NO_THROW(DB.loadData("personData.json", "taskData.json"));
}

TEST(loadDataTests, loadEmptyData)
{
    DBManager DB;

    EXPECT_THROW(DB.loadData("personData.json","Test/test2.json"),nlohmann::json_abi_v3_11_2::detail::parse_error);
}

TEST(getPersonTests, loadNormalFile)
{
    DBManager DB;

    DB.loadData("personData.json", "taskData.json");

    Person John = DB.getPerson("John");

    EXPECT_EQ(John.getName(),"John");
    EXPECT_EQ(John.getEmail(),"john@gmail.com");
    EXPECT_EQ(John.getPassword(),"pass33!!!!!!!");
    EXPECT_EQ(John.getTaskList().size(),2);
    EXPECT_EQ(John.getFriends().size(),0);

}

TEST(getTasksTest, findTasksofFriendandFriends)
{
    DBManager DB;

    DB.loadData("personData.json", "taskData.json");

    Person Ram = DB.getPerson("Ram");

    EXPECT_EQ(Ram.getTaskList(), DB.getMyPersons().at(0).getTaskList());

    EXPECT_EQ(Ram.getFriends(), DB.getMyPersons().at(0).getFriends());
}

TEST(coutWorks, loadDataCall)
{
    DBManager DB;
    
    DB.loadData("personData.json", "taskData.json");

    EXPECT_EQ(true,true);
}

TEST(personTests, testStorePerson)
{
    DBManager DB;

    DB.loadData("personData.json", "taskData.json");

    Person Ram = DB.getPerson("Ram");

    Ram.setPassword("newPass1!!!!!");

    DB.storePerson(Ram, "personData.json", "taskData.json");

    EXPECT_EQ(true, true);

}

//cannot repeatedly test this function
//in order to repeatedly test, must be able to delete data from database
// TEST(personTests, addPerson)
// {
//     DBManager DB;

//     DB.loadData("personData.json", "taskData.json");

//     Person Larry;

//     Larry.signUp("Larry", "larry@gmail.com", "LarryPass12#3");


//     DB.storeNewPerson(Larry, "personData.json", "taskData.json");

//     EXPECT_EQ(true, true);
// }

// TEST(messageTest, sendMessagetoSomeone)
// {
//     DBManager DB;

//     DB.loadData("personData.json", "taskData.json");

//     Person Ram = DB.getPerson("Ram");

//     Ram.sendMessage("Shyam", "Message1234");

//     DB.storePerson(Ram, "personData.json", "taskData.json");

//     EXPECT_EQ(true, true);
// }

TEST(DBManagerDoesExist, nameDoesExist) {
    DBManager DB;
    DB.loadData("personData.json", "taskData.json");

    EXPECT_TRUE(DB.doesExist("Ram", "ram1@gmail.com"));
}

TEST(DBManagerDoesExist, emailDoesExist) {
    DBManager DB;
    DB.loadData("personData.json", "taskData.json");

    EXPECT_TRUE(DB.doesExist("Rama", "ram@gmail.com"));
}

TEST(DBManagerDoesExist, nameAndEmailDoNotExist) {
    DBManager DB;
    DB.loadData("personData.json", "taskData.json");

    EXPECT_FALSE(DB.doesExist("Rama", "ram1@gmail.com"));
}

TEST(DBManagerTests, validateGoodLogin) {
    DBManager DB;
    DB.loadData("personData.json", "taskData.json");
    string userName = "John", password = "pass33!!!!!!!";
    
    EXPECT_NO_THROW(DB.validateLogin(userName, password));
    EXPECT_TRUE(DB.validateLogin(userName, password));
}

TEST(DBManagerTests, validateBadLogin) {
    DBManager DB;
    DB.loadData("personData.json", "taskData.json");
    string userName = "BadName", password = "BadPassword";

    EXPECT_ANY_THROW(DB.validateLogin(userName, password));
}

// int main(int argc, char **argv) {
//     ::testing::InitGoogleTest(&argc, argv);
//     return RUN_ALL_TESTS();
// }