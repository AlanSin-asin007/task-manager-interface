#include "../header/person.hpp"
#include "../header/tasks.hpp"

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

    EXPECT_TRUE(personDefaultTasks->getTasks().empty());
}

TEST(personDefaultConstructor, defaultFriends) {
    Person* personDefaultFriends = new Person();

    EXPECT_TRUE(personDefaultFriends->getFriends().empty());
}

TEST(personParameterizedConstructor, parameterizedName) {
    Person* personParameterizedName = new Person("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testName", personParameterizedName->getName());
}

TEST(personParameterizedConstructor, parameterizedEmail) {
    Person* personParameterizedEmail = new Person("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testEmail@gmail.com", personParameterizedEmail->getEmail());
}

TEST(personParameterizedConstructor, parameterizedPassword) {
    Person* personParameterizedPassword = new Person("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testPassword1!", personParameterizedPassword->getPassword());
}

TEST(personParameterizedConstructor, setName) {
    Person* personSetName = new Person();
    personSetName->setName("testName");

    EXPECT_EQ("testName", personSetName->getName());
}

TEST(personParameterizedConstructor, setEmail) {
    Person* personSetEmail = new Person();
    personSetEmail->setEmail("testEmail@gmail.com");

    EXPECT_EQ("testEmail@gmail.com", personSetEmail->getEmail());
}

TEST(personParameterizedConstructor, setPassword) {
    Person* personSetPassword = new Person();
    personSetPassword->setPassword("testPassword1!");

    EXPECT_EQ("testPassword1!", personSetPassword->getPassword());
}

TEST(personParameterizedConstructor, setTasks) {
    Person* personSetTasks = new Person();
    Tasks tasksSetTasks;
    personSetTasks->setTasks(tasksSetTasks);

    EXPECT_FALSE(personSetTasks->getTasks().empty());
}

TEST(personParameterizedConstructor, setFriends) {
    Person* personSetFriends = new Person();
    Person tasksSetFriends;
    personSetFriends->setFriends(tasksSetFriends);

    EXPECT_FALSE(personSetFriends->getFriends().empty());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}