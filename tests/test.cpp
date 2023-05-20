#include "../header/person.hpp"

#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(personDefaultConstructor, testName) {
    Person* testPersonName = new Person();

    EXPECT_EQ("", testPersonName->getName());
}

TEST(personDefaultConstructor, testEmail) {
    Person* testPersonEmail = new Person();

    EXPECT_EQ("", testPersonEmail->getEmail());
}

TEST(personDefaultConstructor, testPassword) {
    Person* testPersonPassword = new Person();

    EXPECT_EQ("", testPersonPassword->getPassword());
}

TEST(personDefaultConstructor, testTasks) {
    Person* testPersonTasks = new Person();

    EXPECT_EQ("", testPersonTasks->getTasks());
}

TEST(personDefaultConstructor, testFriends) {
    Person* testPersonFriends = new Person();

    EXPECT_EQ("", testPersonFriends->getFriends());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}