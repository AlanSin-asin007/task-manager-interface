#include "../include/Person.h"
#include "../include/Task.h"

#include "gtest/gtest.h"
#include <string>

using namespace std;

// TEST(personDefaultConstructor, defaultName) {
//     Person* personDefaultName = new Person();

//     EXPECT_EQ("", personDefaultName->getName());
// }

// TEST(personDefaultConstructor, defaultEmail) {
//     Person* personDefaultEmail = new Person();

//     EXPECT_EQ("", personDefaultEmail->getEmail());
// }

// TEST(personDefaultConstructor, defaultPassword) {
//     Person* personDefaultPassword = new Person();

//     EXPECT_EQ("", personDefaultPassword->getPassword());
// }

// TEST(personDefaultConstructor, defaultTasks) {
//     Person* personDefaultTasks = new Person();

//     EXPECT_TRUE(personDefaultTasks->getTasks().empty());
// }

// TEST(personDefaultConstructor, defaultFriends) {
//     Person* personDefaultFriends = new Person();

//     EXPECT_TRUE(personDefaultFriends->getFriends().empty());
// }

// TEST(personParameterizedConstructor, parameterizedName) {
//     Person* personParameterizedName = new Person("testName", "testEmail@gmail.com", "testPassword1!");

//     EXPECT_EQ("testName", personParameterizedName->getName());
// }

// TEST(personParameterizedConstructor, parameterizedEmail) {
//     Person* personParameterizedEmail = new Person("testName", "testEmail@gmail.com", "testPassword1!");

//     EXPECT_EQ("testEmail@gmail.com", personParameterizedEmail->getEmail());
// }

// TEST(personParameterizedConstructor, parameterizedPassword) {
//     Person* personParameterizedPassword = new Person("testName", "testEmail@gmail.com", "testPassword1!");

//     EXPECT_EQ("testPassword1!", personParameterizedPassword->getPassword());
// }

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}