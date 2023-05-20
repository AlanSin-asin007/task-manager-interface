#include "../header/person.hpp"

#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(personDefaultConstructor, defaultName) {
    Person* personDefaultName = new Person();

    EXPECT_EQ("", personDefaultName->getName());
}

TEST(personDefaultConstructor, defaultEmail) {
    Person* personDefaultEmail = new Person();

    EXPECT_EQ("", personDefaultEmail->getEmail());
}

TEST(personDefaultConstructor, defaultPassword) {
    Person* personDefaultPassword = new Person();

    EXPECT_EQ("", personDefaultPassword->getPassword());
}

TEST(personDefaultConstructor, defaultTasks) {
    Person* personDefaultTasks = new Person();

    EXPECT_EQ("", personDefaultTasks->getTasks());
}

TEST(personDefaultConstructor, defaultFriends) {
    Person* personDefaultFriends = new Person();

    EXPECT_EQ("", personDefaultFriends->getFriends());
}

TEST(personParameterizedConstructor, parameterizedName) {
    Person* personParameterizedName = new Person("testName", "testEmail", "testPassword", "testTasks", "testFriends");

    EXPECT_EQ("testName", personParameterizedName->getName());
}

TEST(personParameterizedConstructor, parameterizedEmail) {
    Person* personParameterizedEmail = new Person("testName", "testEmail", "testPassword", "testTasks", "testFriends");

    EXPECT_EQ("testEmail", personParameterizedEmail->getEmail());
}

TEST(personParameterizedConstructor, parameterizedPassword) {
    Person* personParameterizedPassword = new Person("testName", "testEmail", "testPassword", "testTasks", "testFriends");

    EXPECT_EQ("testPassword", personParameterizedPassword->getPassword());
}

TEST(personParameterizedConstructor, parameterizedTasks) {
    Person* personParameterizedTasks = new Person("testName", "testEmail", "testPassword", "testTasks", "testFriends");

    EXPECT_EQ("testTasks", personParameterizedTasks->getTasks());
}

TEST(personParameterizedConstructor, parameterizedFriends) {
    Person* personParameterizedFriends = new Person("testName", "testEmail", "testPassword", "testTasks", "testFriends");

    EXPECT_EQ("testFriends", personParameterizedFriends->getFriends());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}