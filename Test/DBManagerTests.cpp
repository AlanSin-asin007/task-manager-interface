#include "../include/DBManager.h"
#include "gtest/gtest.h"

using namespace std;


// TEST(loadDataTests, loadNormalData)
// {
//     DBManager DB;

//     EXPECT_NO_THROW(DB.loadData("Test/test1.json"));
// }


// TEST(loadDataTests, loadEmptyData)
// {
//     DBManager DB;

//     EXPECT_THROW(DB.loadData("Test/test2.json"),nlohmann::json_abi_v3_11_2::detail::parse_error);
// }

// TEST(getPersonTests, loadNormalFile)
// {
//     DBManager DB;

//     DB.loadData("Test/test1.json");

//     Person John = DB.getPerson("John");

//     EXPECT_EQ(John.getName(),"John");
//     EXPECT_EQ(John.getEmail(),"john@gmail.com");
//     EXPECT_EQ(John.getPassword(),"pass33");
//     EXPECT_EQ(John.getTasks().size(),3);
//     EXPECT_EQ(John.getFriends().size(),0);


// }

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
