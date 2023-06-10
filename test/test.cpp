#include "gtest/gtest.h"
#include "../include/ImportanceSorter.h"
#include "../include/DateSorter.h"
#include "../include/TaskSorter.h"
#include "../include/Person.h"
#include "../include/Task.h"
#include "../include/DBManager.h"

using namespace std;
using namespace date;

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

TEST(DateSorterTests, testDateGetPerson) {
    Person p;
    TaskSorter* sorter = new DateSorter(p);

    EXPECT_EQ(p, sorter->getPerson());
    delete sorter;
}

TEST(DateSorterTests, testDateSetPerson) {
    Person p1;
    TaskSorter* sorter = new DateSorter(p1);
    Person p2;
    sorter->setPerson(p2);

    EXPECT_EQ(p2, sorter->getPerson());
    delete sorter;
}

TEST(DateSorterTests, testDateSortIncreasing) {
    std::vector<Task> list;
    for (int i = 1; i < 6; ++i) {
        list.push_back(Task(5, date::year{2023}/date::January/i));
    }
    Person p(list);
    TaskSorter* sorter = new DateSorter(p);
    sorter->performSort();
    list = sorter->getPerson().getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_LE(list.at(i).getDeadline(), list.at(i+1).getDeadline());
    }
    delete sorter;
}

TEST(DateSorterTests, testDateSortSame) {
    std::vector<Task> list;
    for (int i = 1; i < 21; ++i) {
        list.push_back(Task(5, date::year{2023}/date::January/1));
    }
    Person p(list);
    TaskSorter* sorter = new DateSorter(p);
    sorter->performSort();
    list = sorter->getPerson().getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_LE(list.at(i).getDeadline(), list.at(i+1).getDeadline());
    }
    delete sorter;
}

TEST(DateSorterTests, testDateSortDecreasing) {
    std::vector<Task> list;
    for (int i = 20; i > 0 ; --i) {
        list.push_back(Task(5, date::year{2023}/date::January/i));
    }
    Person p(list);
    TaskSorter* sorter = new DateSorter(p);
    sorter->performSort();
    list = sorter->getPerson().getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_LE(list.at(i).getDeadline(), list.at(i+1).getDeadline());
    }
    delete sorter;
}

TEST(ImportanceSorterTests, testImportanceGetPerson) {
    Person p;
    TaskSorter* sorter = new ImportanceSorter(p);

    EXPECT_EQ(p, sorter->getPerson());
    delete sorter;
}

TEST(ImportanceSorterTests, testImportanceSetPerson) {
    Person p1;
    TaskSorter* sorter = new ImportanceSorter(p1);
    Person p2;
    sorter->setPerson(p2);

    EXPECT_EQ(p2, sorter->getPerson());
    delete sorter;
}

TEST(ImportanceSorterTests, testImportanceSortIncreasing) {
    std::vector<Task> list;
    date::year_month_day d = date::year{2023}/date::January/1;
    for (int i = 1; i < 6; ++i) {
        list.push_back(Task(i, d));
    }
    Person p(list);
    TaskSorter* sorter = new ImportanceSorter(p);
    sorter->performSort();
    list = sorter->getPerson().getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }
    delete sorter;
}

TEST(ImportanceSorterTests, testImportanceSortSame) {
    std::vector<Task> list;
    for (int i = 1; i < 21; ++i) {
        list.push_back(Task(5, date::year{2023}/date::January/1));
    }
    Person p(list);
    TaskSorter* sorter = new ImportanceSorter(p);
    sorter->performSort();
    list = sorter->getPerson().getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }
    delete sorter;
}

TEST(ImportanceSorterTests, testImportanceSortDecreasing) {
    std::vector<Task> list;
    date::year_month_day d = date::year{2023}/date::January/1;
    for (int i = 20; i > 0 ; --i) {
        list.push_back(Task(i, d));
    }
    Person p(list);
    TaskSorter* sorter = new ImportanceSorter(p);
    sorter->performSort();
    list = sorter->getPerson().getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }
    delete sorter;
}

TEST(personValidation, validName) {
    Person* personValidName = new Person();
    //personValidName->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_NO_THROW(personValidName->checkNameRequirements("testName"));
    EXPECT_TRUE(personValidName->checkNameRequirements("testName"));
}

TEST(personValidation, invalidNameNonalphabetical) {
    Person* personInvalidNameNonalphabetical = new Person();
    
    EXPECT_ANY_THROW(personInvalidNameNonalphabetical->checkNameRequirements("testName1"));
}

TEST(personValidation, invalidNameTooShort) {
    Person* personInvalidNameTooShort = new Person();
    
    EXPECT_ANY_THROW(personInvalidNameTooShort->checkNameRequirements("a"));
}

TEST(personValidation, invalidNameTooLong) {
    Person* personInvalidNameTooLong = new Person();
    
    EXPECT_ANY_THROW(personInvalidNameTooLong->checkNameRequirements("testNameThatIsTooLongtestNameThatIsTooLongtestNameThatIsTooLongtestNameThatIsTooLong"));
}

TEST(personValidation, validEmail) {
    Person* personValidEmail = new Person();
    
    EXPECT_NO_THROW(personValidEmail->checkEmailRequirements("testEmail@gmail.com"));

}

TEST(personValidation, invalidEmailTooShort) {
    Person* personInvalidEmailTooShort = new Person();

    EXPECT_ANY_THROW(personInvalidEmailTooShort->checkEmailRequirements("a@a.a"));
}

TEST(personValidation, invalidEmailTooLong) {
    Person* personInvalidEmailTooLong = new Person();

    EXPECT_ANY_THROW(personInvalidEmailTooLong->checkEmailRequirements("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"));
}

TEST(personValidation, invalidEmailUsername) {
    Person* personInvalidEmailUsername = new Person();
    
    EXPECT_ANY_THROW(personInvalidEmailUsername->checkEmailRequirements("testEmail!@gmail.com"));
}

TEST(personValidation, invalidEmailDomainname) {
    Person* personInvalidEmailDomainname = new Person();

    EXPECT_ANY_THROW(personInvalidEmailDomainname->checkEmailRequirements("testEmail@gmail!.com"));
}

TEST(personValidation, invalidEmailExtension) {
    Person* personInvalidEmailExtension = new Person();

    EXPECT_ANY_THROW(personInvalidEmailExtension->checkEmailRequirements("testEmail@gmail.com!"));
}

TEST(personValidation, invalidEmailFirstAt) {
    Person* personInvalidEmailFirstAt = new Person();

    EXPECT_ANY_THROW(personInvalidEmailFirstAt->checkEmailRequirements("@gmail.com"));
}

TEST(personValidation, invalidEmailDomainnameEmpty) {
    Person* personInvalidEmailDomainnameEmpty = new Person();

    EXPECT_ANY_THROW(personInvalidEmailDomainnameEmpty->checkEmailRequirements("testEmail@.com"));
}

TEST(personValidation, invalidEmailLastDot) {
    Person* personInvalidEmailLastDot = new Person();

    EXPECT_ANY_THROW(personInvalidEmailLastDot->checkEmailRequirements("testEmail@gmail."));
}

TEST(personValidation, invalidEmailAtDotOrder) {
    Person* personInvalidEmailAtDotOrder = new Person();

    EXPECT_ANY_THROW(personInvalidEmailAtDotOrder->checkEmailRequirements("testEmail.gmail@com"));
}

TEST(personValidation, validPassword) {
    Person* personValidPassword = new Person();
    
    EXPECT_NO_THROW(personValidPassword->checkPasswordRequirements("testPassword1!"));
    EXPECT_TRUE(personValidPassword->checkPasswordRequirements("testPassword1!"));
}

TEST(personValidation, invalidPasswordTooShort) {
    Person* personInvalidPasswordTooShort = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordTooShort->checkPasswordRequirements("a"));
}

TEST(personValidation, invalidPasswordTooLong) {
    Person* personInvalidPasswordTooLong = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordTooLong->checkPasswordRequirements("abcdefghijklmnopqrstuvwxyz"));
}

TEST(personValidation, invalidPasswordOnlyLetter) {
    Person* personInvalidPasswordOnlyLetter = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordOnlyLetter->checkPasswordRequirements("testPassword"));
}

TEST(personValidation, invalidPasswordOnlyNum) {
    Person* personInvalidPasswordOnlyNum = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordOnlyNum->checkPasswordRequirements("120491845091"));
}

TEST(personValidation, invalidPasswordOnlySpecialChar) {
    Person* personInvalidPasswordOnlySpecialChar = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordOnlySpecialChar->checkPasswordRequirements("!)@(#*$&%^$&#)"));
}

TEST(personValidation, invalidPasswordNoLetter) {
    Person* personInvalidPasswordNoLetter = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordNoLetter->checkPasswordRequirements("192304@!()&$!"));
}

TEST(personValidation, invalidPasswordNoNum) {
    Person* personInvalidPasswordNoNum = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordNoNum->checkPasswordRequirements("testPassword!"));
}

TEST(personValidation, invalidPasswordNoSpecialChar) {
    Person* personInvalidPasswordNoSpecialChar = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordNoSpecialChar->checkPasswordRequirements("testPassword1"));
}

/*
TEST(personSignUpDatabase, nameAlreadyExists)
{
    DBManager DB;
    DB.loadData("personData.json", "taskData.json");

    Person* personNameAlreadyExists = new Person();

    EXPECT_ANY_THROW(personNameAlreadyExists->signUp("Ram", "ram1@gmail.com", "newPass1!!!!!"));
}

TEST(personSignUpDatabase, emailAlreadyExists)
{
    DBManager DB;
    DB.loadData("personData.json", "taskData.json");

    Person* personNameAlreadyExists = new Person();

    EXPECT_ANY_THROW(personNameAlreadyExists->signUp("Rama", "ram@gmail.com", "newPass1!!!!!"));
}
*/

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

TEST(personSetters, invalidNameForSetter) {
    Person* personSetName = new Person();

    EXPECT_ANY_THROW(personSetName->setName("testName1"));
}

TEST(personSetters, setEmail) {
    Person* personSetEmail = new Person();
    personSetEmail->setEmail("testEmail@gmail.com");

    EXPECT_EQ("testEmail@gmail.com", personSetEmail->getEmail());
}

TEST(personSetters, invalidEmailForSetter) {
    Person* personSetEmail = new Person();

    EXPECT_ANY_THROW(personSetEmail->setEmail("testEmail!@gmail.com"));
}

TEST(personSetters, setPassword) {
    Person* personSetPassword = new Person();
    personSetPassword->setPassword("testPassword1!");

    EXPECT_EQ("testPassword1!", personSetPassword->getPassword());
}

TEST(personSetters, invalidPasswordForSetter) {
    Person* personSetPassword = new Person();

    EXPECT_ANY_THROW(personSetPassword->setPassword("testPassword1"));
}

TEST(personSetters, setTasks) {
    Person* personSetTasks = new Person();
    Task tasksSetTasks(5, date::year{2023}/date::January/1);
    personSetTasks->addTask(tasksSetTasks);

    EXPECT_FALSE(personSetTasks->getTaskList().empty());
}

TEST(personSetters, setFriendsList) {
    Person* personSetFriends = new Person();
    vector<string> friendList = {"Friend1", "Friend2"};
    personSetFriends->setFriendsList(friendList);

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

TEST(TaskTest, CreateLabelTest) {
    // Create a task with a label
    Task task("Task1", "Description1", "Label1", year_month_day{floor<days>(chrono::system_clock::now())}, 5);

    // Assertion: The task's label should be "Label1"
    EXPECT_EQ(task.getLabel(), "Label1");
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

// Test case for the deleteTask() function
TEST(TaskTest, DeleteTaskTest) {
    vector<Task> taskList;

    // Create tasks and add them to the taskList
    Task task1("Task1", "Description", "Label", date::year{2023}/date::January/1, 5);
    Task::addTask(taskList, task1);

    Task task2("Task2", "Description", "Label", date::year{2023}/date::January/1, 5);
    Task::addTask(taskList, task2);

    // Delete task with taskName "Task1"
    Task::deleteTask(taskList, "Task1");

    // Assertion: Task1 should not be found in the taskList
    bool task1Found = false;
    for (const Task& task : taskList) {
        if (task.getTaskName() == "Task1") {
            task1Found = true;
            break;
        }
    }
    EXPECT_FALSE(task1Found);

    // Assertion: Task2 should still be present in the taskList
    bool task2Found = false;
    for (const Task& task : taskList) {
        if (task.getTaskName() == "Task2") {
            task2Found = true;
            break;
        }
    }
    EXPECT_TRUE(task2Found);
}

// Test case for the copyTask() function
TEST(TaskTest, CopyTaskTest) {
    // Create a task
    Task originalTask("Task1", "Description1", "Label1", year_month_day{floor<days>(chrono::system_clock::now())}, 5);

    // Copy the task
    Task copiedTask = Task::copyTask(originalTask);

    // Assertion: The copied task should have the same attributes as the original task
    EXPECT_EQ(copiedTask.getTaskName(), "Task1");
    EXPECT_EQ(copiedTask.getDescription(), "Description1");
    EXPECT_EQ(copiedTask.getLabel(), "Label1");
    EXPECT_EQ(copiedTask.getDeadline(), year_month_day{floor<days>(chrono::system_clock::now())});
    EXPECT_EQ(copiedTask.getRating(), 5);
}


TEST(TaskTest, ModifyTaskTest) {
    vector<Task> taskList;

    // Create tasks and add them to the taskList
    Task task1("Task1", "Description1", "Label1", year_month_day{floor<days>(chrono::system_clock::now())}, 3);
    Task::addTask(taskList, task1);

    Task task2("Task2", "Description2", "Label2", year_month_day{floor<days>(chrono::system_clock::now())}, 5);
    Task::addTask(taskList, task2);

    // Modify task with taskName "Task1"
    Task::modifyTask(taskList, "Task1", "ModifiedTask", year_month_day{floor<days>(chrono::system_clock::now()) + days{1}}, "Modified Description", "Modified Label", 8);

    // Assertion: Task1 should be modified in the taskList
    bool taskModified = false;
    for (const Task& task : taskList) {
        if (task.getTaskName() == "ModifiedTask" && task.getDeadline() == (year_month_day{floor<days>(chrono::system_clock::now()) + days{1}}) &&
            task.getDescription() == "Modified Description" && task.getLabel() == "Modified Label" &&
            task.getRating() == 8) {
            taskModified = true;
            break;
        }
    }
    EXPECT_TRUE(taskModified);

    // Assertion: Task2 should still be present in the taskList
    bool task2Found = false;
    for (const Task& task : taskList) {
        if (task.getTaskName() == "Task2") {
            task2Found = true;
            break;
        }
    }
    EXPECT_TRUE(task2Found);
}

TEST(TaskTest, ModifyTaskDeadlineTest) {
    vector<Task> taskList;

    // Create tasks and add them to the taskList
    Task task1("Task1", "Description1", "Label1", year_month_day{floor<days>(chrono::system_clock::now())}, 3);
    Task::addTask(taskList, task1);
    // Modify the task deadline for task with taskName "Task1"
    year_month_day newDeadline = year_month_day{floor<days>(chrono::system_clock::now()) + days{5}}; 
    Task::modifyTaskDeadline(taskList, "Task1", newDeadline);

    // Assertion: Task1's deadline should be updated to "2023-06-10"
    for (const Task& task : taskList) {
        if (task.getTaskName() == "Task1") {
            EXPECT_EQ(task.getDeadline(), newDeadline);
            break;
        }
    }
}

TEST(personChangePassword, validOriginalAndNewPassword) {
    Person* personChangePassword = new Person("testName", "testEmail@gmail.com", "originalPassword1!");
    personChangePassword->changePassword("originalPassword1!", "newPassword1!", "newPassword1!");

    EXPECT_EQ(personChangePassword->getPassword(), "newPassword1!");
}

TEST(personChangePassword, invalidOriginalPassword) {
    Person* personChangePassword = new Person("testName", "testEmail@gmail.com", "originalPassword1!");

    EXPECT_ANY_THROW(personChangePassword->changePassword("notOriginalPW1!", "newPassword1!", "newPassword1!"));
}

TEST(personChangePassword, newPasswordDoesNotEqualConfirmation) {
    Person* personChangePassword = new Person("testName", "testEmail@gmail.com", "originalPassword1!");

    EXPECT_ANY_THROW(personChangePassword->changePassword("originalPassword1!", "newPassword1!", "notNewPassword1!"));
}

TEST(personChangePassword, newPasswordViolatesConditions) {
    Person* personChangePassword = new Person("testName", "testEmail@gmail.com", "originalPassword1!");

    EXPECT_ANY_THROW(personChangePassword->changePassword("originalPassword1!", "newPassword", "newPassword1"));
}

TEST(PersonTests, getTaskNames) {
    Task task("Name", "Description", "Label", date::year{2023}/date::January/1, 5);
    Person* p = new Person();
    p->addTask(task);
    vector<string> vec = {"Name"};

    EXPECT_EQ(vec, p->getTaskNames());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}