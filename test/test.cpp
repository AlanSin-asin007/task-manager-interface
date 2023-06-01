#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/DateSorter.h"
#include "../include/TaskSorter.h"
#include "../include/Person.h"
#include "../include/Task.h"

TEST(PersonTests, testGetTaskList) {  
    std::vector<Task> list = {Task(1, date::year{2023}/date::January/1), Task(1, date::year{2023}/date::January/2), Task(1, date::year{2023}/date::January/3)};
    Person* p = new Person(list);
    
    EXPECT_EQ(p->getTaskList(), list);
}

TEST(PersonTests, testSetTaskList) {
    std::vector<Task> list = {Task(1, date::year{2023}/date::January/1), Task(1, date::year{2023}/date::January/2), Task(1, date::year{2023}/date::January/3)};
    Person* p = new Person();
    
    p->setTaskList(list);

    EXPECT_EQ(p->getTaskList(), list);
}

TEST(DateSorterTests, testGetPerson) {
    Person* p = new Person();
    TaskSorter* sorter = new DateSorter(p);

    EXPECT_EQ(p, sorter->getPerson());
}

TEST(DateSorterTests, testSetPerson) {
    TaskSorter* sorter = new DateSorter(new Person());
    Person* p2 = new Person();
    sorter->setPerson(p2);

    EXPECT_EQ(p2, sorter->getPerson());
}

TEST(DateSorterTests, testSortIncreasing) {
    std::vector<Task> list;
    for (int i = 1; i < 6; ++i) {
        list.push_back(Task(5, date::year{2023}/date::January/i));
    }

    TaskSorter* sorter = new DateSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_LE(list.at(i).getDeadline(), list.at(i+1).getDeadline());
    }

}

TEST(DateSorterTests, testSortSame) {
    std::vector<Task> list;
    for (int i = 1; i < 21; ++i) {
        list.push_back(Task(5, date::year{2023}/date::January/1));
    }

    TaskSorter* sorter = new DateSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_LE(list.at(i).getDeadline(), list.at(i+1).getDeadline());
    }

}

TEST(DateSorterTests, testSortDecreasing) {
    std::vector<Task> list;
    for (int i = 20; i > 0 ; --i) {
        list.push_back(Task(5, date::year{2023}/date::January/i));
    }

    TaskSorter* sorter = new DateSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_LE(list.at(i).getDeadline(), list.at(i+1).getDeadline());
    }
}

TEST(personSignUpName, validName) {
    Person* personValidName = new Person();
    personValidName->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testName", personValidName->getName());
}

TEST(personSignUpName, invalidNameNonalphabetical) {
    Person* personInvalidNameNonalphabetical = new Person();
    personInvalidNameNonalphabetical->signUp("testName1", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidNameNonalphabetical->getName());
}

TEST(personSignUpName, invalidNameTooShort) {
    Person* personInvalidNameTooShort = new Person();
    personInvalidNameTooShort->signUp("a", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidNameTooShort->getName());
}

TEST(personSignUpName, invalidNameTooLong) {
    Person* personInvalidNameTooLong = new Person();
    personInvalidNameTooLong->signUp("testNameThatIsTooLong", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidNameTooLong->getName());
}

TEST(personSignUpEmail, validEmail) {
    Person* personValidEmail = new Person();
    personValidEmail->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testEmail@gmail.com", personValidEmail->getEmail());
}

TEST(personSignUpEmail, invalidEmailTooShort) {
    Person* personInvalidEmailTooShort = new Person();
    personInvalidEmailTooShort->signUp("testName", "a@a.a", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailTooShort->getEmail());
}

TEST(personSignUpEmail, invalidEmailTooLong) {
    Person* personInvalidEmailTooLong = new Person();
    personInvalidEmailTooLong->signUp("testName", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailTooLong->getEmail());
}

TEST(personSignUpEmail, invalidEmailUsername) {
    Person* personInvalidEmailUsername = new Person();
    personInvalidEmailUsername->signUp("testName", "testEmail1@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailUsername->getEmail());
}

TEST(personSignUpEmail, invalidEmailDomainname) {
    Person* personInvalidEmailDomainname = new Person();
    personInvalidEmailDomainname->signUp("testName", "testEmail@gmail1.com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailDomainname->getEmail());
}

TEST(personSignUpEmail, invalidEmailExtension) {
    Person* personInvalidEmailExtension = new Person();
    personInvalidEmailExtension->signUp("testName", "testEmail@gmail.com1", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailExtension->getEmail());
}

TEST(personSignUpEmail, invalidEmailFirstAt) {
    Person* personInvalidEmailFirstAt = new Person();
    personInvalidEmailFirstAt->signUp("testName", "@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailFirstAt->getEmail());
}

TEST(personSignUpEmail, invalidEmailDomainnameEmpty) {
    Person* personInvalidEmailDomainnameEmpty = new Person();
    personInvalidEmailDomainnameEmpty->signUp("testName", "testEmail@.com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailDomainnameEmpty->getEmail());
}

TEST(personSignUpEmail, invalidEmailLastDot) {
    Person* personInvalidEmailLastDot = new Person();
    personInvalidEmailLastDot->signUp("testName", "testEmail@gmail.", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailLastDot->getEmail());
}

TEST(personSignUpEmail, invalidEmailAtDotOrder) {
    Person* personInvalidEmailAtDotOrder = new Person();
    personInvalidEmailAtDotOrder->signUp("testName", "testEmail.gmail@com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailAtDotOrder->getEmail());
}

TEST(personSignUpPassword, validPassword) {
    Person* personValidPassword = new Person();
    personValidPassword->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testPassword1!", personValidPassword->getPassword());
}

TEST(personSignUpPassword, invalidPasswordTooShort) {
    Person* personInvalidPasswordTooShort = new Person();
    personInvalidPasswordTooShort->signUp("testName", "testEmail@gmail.com", "a");

    EXPECT_EQ("", personInvalidPasswordTooShort->getPassword());
}

TEST(personSignUpPassword, invalidPasswordTooLong) {
    Person* personInvalidPasswordTooLong = new Person();
    personInvalidPasswordTooLong->signUp("testName", "testEmail@gmail.com", "abcdefghijklmnopqrstuvwxyz");

    EXPECT_EQ("", personInvalidPasswordTooLong->getPassword());
}

TEST(personSignUpPassword, invalidPasswordOnlyLetter) {
    Person* personInvalidPasswordOnlyLetter = new Person();
    personInvalidPasswordOnlyLetter->signUp("testName", "testEmail@gmail.com", "testPassword");

    EXPECT_EQ("", personInvalidPasswordOnlyLetter->getPassword());
}

TEST(personSignUpPassword, invalidPasswordOnlyNum) {
    Person* personInvalidPasswordOnlyNum = new Person();
    personInvalidPasswordOnlyNum->signUp("testName", "testEmail@gmail.com", "120491845091");

    EXPECT_EQ("", personInvalidPasswordOnlyNum->getPassword());
}

TEST(personSignUpPassword, invalidPasswordOnlySpecialChar) {
    Person* personInvalidPasswordOnlySpecialChar = new Person();
    personInvalidPasswordOnlySpecialChar->signUp("testName", "testEmail@gmail.com", "!)@(#*$&%^$&#)");

    EXPECT_EQ("", personInvalidPasswordOnlySpecialChar->getPassword());
}

TEST(personSignUpPassword, invalidPasswordNoLetter) {
    Person* personInvalidPasswordNoLetter = new Person();
    personInvalidPasswordNoLetter->signUp("testName", "testEmail@gmail.com", "192304@!()&$!");

    EXPECT_EQ("", personInvalidPasswordNoLetter->getPassword());
}

TEST(personSignUpPassword, invalidPasswordNoNum) {
    Person* personInvalidPasswordNoNum = new Person();
    personInvalidPasswordNoNum->signUp("testName", "testEmail@gmail.com", "testPassword!");

    EXPECT_EQ("", personInvalidPasswordNoNum->getPassword());
}

TEST(personSignUpPassword, invalidPasswordNoSpecialChar) {
    Person* personInvalidPasswordNoSpecialChar = new Person();
    personInvalidPasswordNoSpecialChar->signUp("testName", "testEmail@gmail.com", "testPassword1");

    EXPECT_EQ("", personInvalidPasswordNoSpecialChar->getPassword());
}

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

    EXPECT_TRUE(personDefaultTasks->getTaskList().empty());
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

TEST(personSetters, setName) {
    Person* personSetName = new Person();
    personSetName->setName("testName");

    EXPECT_EQ("testName", personSetName->getName());
}

TEST(personSetters, setEmail) {
    Person* personSetEmail = new Person();
    personSetEmail->setEmail("testEmail@gmail.com");

    EXPECT_EQ("testEmail@gmail.com", personSetEmail->getEmail());
}

TEST(personSetters, setPassword) {
    Person* personSetPassword = new Person();
    personSetPassword->setPassword("testPassword1!");

    EXPECT_EQ("testPassword1!", personSetPassword->getPassword());
}

TEST(personSetters, setTasks) {
    Person* personSetTasks = new Person();
    Task tasksSetTasks(5, date::year{2023}/date::January/1);
    personSetTasks->setTasks(tasksSetTasks);

    EXPECT_FALSE(personSetTasks->getTaskList().empty());
}

TEST(personSetters, setFriends) {
    Person* personSetFriends = new Person();
    Person tasksSetFriends;
    personSetFriends->setFriends(tasksSetFriends);

    EXPECT_FALSE(personSetFriends->getFriends().empty());
}

TEST(personGenerateRandPassword, lengthOfPassword) {
    Person testPerson1;
    string res = testPerson1.generateRandPassword();
    EXPECT_EQ(20, res.length());
}

// Test case for the constructor
TEST(TaskTest, ConstructorTest) {

    EXPECT_NO_THROW(Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5));

}

// Test case for the getTaskName() function
TEST(TaskTest, GetTaskNameTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    ASSERT_EQ(task.getTaskName(), "Name");
}

// Test case for the setTaskName() function
TEST(TaskTest, SetTaskNameTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    task.setTaskName("NewTaskName");
    ASSERT_EQ(task.getTaskName(), "NewTaskName");
}

// Test case for the getDescription() function
TEST(TaskTest, GetDescriptionTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    ASSERT_EQ(task.getDescription(), "Description");
}

// Test case for the setDescription() function
TEST(TaskTest, SetDescriptionTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    task.setDescription("NewDescription");
    ASSERT_EQ(task.getDescription(), "NewDescription");
}

// Test case for the getLabel() function
TEST(TaskTest, GetLabelTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    ASSERT_EQ(task.getLabel(), "Label");
}

// Test case for the setLabel() function
TEST(TaskTest, SetLabelTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    task.setLabel("NewLabel");
    ASSERT_EQ(task.getLabel(), "NewLabel");
}

// Test case for the getTaskPriority() function
TEST(TaskTest, GetTaskImportanceTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    ASSERT_EQ(task.getRating(), 5);
}

// Test case for the setTaskPriority() function
TEST(TaskTest, SetTaskImportanceTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    task.setRating(7);
    ASSERT_EQ(task.getRating(), 7);
}

TEST(TaskTest, InvalidSetImportanceLess) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    EXPECT_ANY_THROW(task.setRating(-1));
}

TEST(TaskTest, InvalidSetImportanceMore) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    EXPECT_ANY_THROW(task.setRating(12));
}

// Test case for the getTaskDeadline() function
TEST(TaskTest, GetTaskDeadlineTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    ASSERT_EQ(task.getDeadline(), date::year{2023}/date::January/1);
}

// Test case for the setTaskDeadline() function
TEST(TaskTest, SetTaskDeadlineTest) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    task.setDeadline(date::year{2023}/date::February/1);
    ASSERT_EQ(task.getDeadline(), date::year{2023}/date::February/1);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}