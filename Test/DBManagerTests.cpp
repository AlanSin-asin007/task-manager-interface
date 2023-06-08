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

    EXPECT_NO_THROW(DB.loadData("myData.json", "task1.json"));
}


TEST(loadDataTests, loadEmptyData)
{
    DBManager DB;

    EXPECT_THROW(DB.loadData("myData.json","Test/test2.json"),nlohmann::json_abi_v3_11_2::detail::parse_error);
}


TEST(getPersonTests, loadNormalFile)
{
    DBManager DB;

    DB.loadData("myData.json", "task1.json");

    Person John = DB.getPerson("John");

    EXPECT_EQ(John.getName(),"John");
    EXPECT_EQ(John.getEmail(),"john@gmail.com");
    EXPECT_EQ(John.getPassword(),"pass33");
    EXPECT_EQ(John.getTaskList().size(),2);
    EXPECT_EQ(John.getFriends().size(),0);

}

TEST(getTasksTest, findTasksofFriendandFriends)
{
    DBManager DB;

    DB.loadData("myData.json", "task1.json");

    Person Ram = DB.getPerson("Ram");

    EXPECT_EQ(Ram.getTaskList(), DB.getMyPersons().at(0).getTaskList());

    EXPECT_EQ(Ram.getFriends(), DB.getMyPersons().at(0).getFriends());
}

TEST(coutWorks, loadDataCall)
{
    DBManager DB;
    
    DB.loadData("myData.json", "task1.json");

    EXPECT_EQ(true,true);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}