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
    Person* p = new Person();
    TaskSorter* sorter = new DateSorter(p);

    EXPECT_EQ(p, sorter->getPerson());
}

TEST(DateSorterTests, testDateSetPerson) {
    TaskSorter* sorter = new DateSorter(new Person());
    Person* p2 = new Person();
    sorter->setPerson(p2);

    EXPECT_EQ(p2, sorter->getPerson());
}

TEST(DateSorterTests, testDateSortIncreasing) {
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

TEST(DateSorterTests, testDateSortSame) {
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

TEST(DateSorterTests, testDateSortDecreasing) {
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

TEST(ImportanceSorterTests, testImportanceGetPerson) {
    Person* p = new Person();
    TaskSorter* sorter = new ImportanceSorter(p);

    EXPECT_EQ(p, sorter->getPerson());
}

TEST(ImportanceSorterTests, testImportanceSetPerson) {
    TaskSorter* sorter = new ImportanceSorter(new Person());
    Person* p2 = new Person();
    sorter->setPerson(p2);

    EXPECT_EQ(p2, sorter->getPerson());
}

TEST(ImportanceSorterTests, testImportanceSortIncreasing) {
    std::vector<Task> list;
    date::year_month_day d = date::year{2023}/date::January/1;
    for (int i = 1; i < 6; ++i) {
        list.push_back(Task(i, d));
    }

    TaskSorter* sorter = new ImportanceSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }

}

TEST(ImportanceSorterTests, testImportanceSortSame) {
    std::vector<Task> list;
    for (int i = 1; i < 21; ++i) {
        list.push_back(Task(5, date::year{2023}/date::January/1));
    }

    TaskSorter* sorter = new ImportanceSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }

}

TEST(ImportanceSorterTests, testImportanceSortDecreasing) {
    std::vector<Task> list;
    date::year_month_day d = date::year{2023}/date::January/1;
    for (int i = 20; i > 0 ; --i) {
        list.push_back(Task(i, d));
    }

    TaskSorter* sorter = new ImportanceSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }
}

TEST(personSignUpName, validName) {
    Person* personValidName = new Person();
    personValidName->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testName", personValidName->getName());
}

TEST(personSignUpName, invalidNameNonalphabetical) {
    Person* personInvalidNameNonalphabetical = new Person();
    
    EXPECT_ANY_THROW(personInvalidNameNonalphabetical->signUp("testName1", "testEmail@gmail.com", "testPassword1!"));
}

TEST(personSignUpName, invalidNameTooShort) {
    Person* personInvalidNameTooShort = new Person();
    
    EXPECT_ANY_THROW(personInvalidNameTooShort->signUp("a", "testEmail@gmail.com", "testPassword1!"));
}

TEST(personSignUpName, invalidNameTooLong) {
    Person* personInvalidNameTooLong = new Person();
    
    EXPECT_ANY_THROW(personInvalidNameTooLong->signUp("testNameThatIsTooLongtestNameThatIsTooLongtestNameThatIsTooLongtestNameThatIsTooLong", "testEmail@gmail.com", "testPassword1!"));
}

TEST(personSignUpEmail, validEmail) {
    Person* personValidEmail = new Person();
    personValidEmail->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testEmail@gmail.com", personValidEmail->getEmail());
}

TEST(personSignUpEmail, invalidEmailTooShort) {
    Person* personInvalidEmailTooShort = new Person();

    EXPECT_ANY_THROW(personInvalidEmailTooShort->signUp("testName", "a@a.a", "testPassword1!"));
}

TEST(personSignUpEmail, invalidEmailTooLong) {
    Person* personInvalidEmailTooLong = new Person();

    EXPECT_ANY_THROW(personInvalidEmailTooLong->signUp("testName", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "testPassword1!"));
}

TEST(personSignUpEmail, invalidEmailUsername) {
    Person* personInvalidEmailUsername = new Person();
    
    EXPECT_ANY_THROW(personInvalidEmailUsername->signUp("testName", "testEmail!@gmail.com", "testPassword1!"));
}

TEST(personSignUpEmail, invalidEmailDomainname) {
    Person* personInvalidEmailDomainname = new Person();

    EXPECT_ANY_THROW(personInvalidEmailDomainname->signUp("testName", "testEmail@gmail!.com", "testPassword1!"));
}

TEST(personSignUpEmail, invalidEmailExtension) {
    Person* personInvalidEmailExtension = new Person();

    EXPECT_ANY_THROW(personInvalidEmailExtension->signUp("testName", "testEmail@gmail.com!", "testPassword1!"));
}

TEST(personSignUpEmail, invalidEmailFirstAt) {
    Person* personInvalidEmailFirstAt = new Person();

    EXPECT_ANY_THROW(personInvalidEmailFirstAt->signUp("testName", "@gmail.com", "testPassword1!"));
}

TEST(personSignUpEmail, invalidEmailDomainnameEmpty) {
    Person* personInvalidEmailDomainnameEmpty = new Person();

    EXPECT_ANY_THROW(personInvalidEmailDomainnameEmpty->signUp("testName", "testEmail@.com", "testPassword1!"));
}

TEST(personSignUpEmail, invalidEmailLastDot) {
    Person* personInvalidEmailLastDot = new Person();

    EXPECT_ANY_THROW(personInvalidEmailLastDot->signUp("testName", "testEmail@gmail.", "testPassword1!"));
}

TEST(personSignUpEmail, invalidEmailAtDotOrder) {
    Person* personInvalidEmailAtDotOrder = new Person();

    EXPECT_ANY_THROW(personInvalidEmailAtDotOrder->signUp("testName", "testEmail.gmail@com", "testPassword1!"));
}

TEST(personSignUpPassword, validPassword) {
    Person* personValidPassword = new Person();
    personValidPassword->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testPassword1!", personValidPassword->getPassword());
}

TEST(personSignUpPassword, invalidPasswordTooShort) {
    Person* personInvalidPasswordTooShort = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordTooShort->signUp("testName", "testEmail@gmail.com", "a"));
}

TEST(personSignUpPassword, invalidPasswordTooLong) {
    Person* personInvalidPasswordTooLong = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordTooLong->signUp("testName", "testEmail@gmail.com", "abcdefghijklmnopqrstuvwxyz"));
}

TEST(personSignUpPassword, invalidPasswordOnlyLetter) {
    Person* personInvalidPasswordOnlyLetter = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordOnlyLetter->signUp("testName", "testEmail@gmail.com", "testPassword"));
}

TEST(personSignUpPassword, invalidPasswordOnlyNum) {
    Person* personInvalidPasswordOnlyNum = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordOnlyNum->signUp("testName", "testEmail@gmail.com", "120491845091"));
}

TEST(personSignUpPassword, invalidPasswordOnlySpecialChar) {
    Person* personInvalidPasswordOnlySpecialChar = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordOnlySpecialChar->signUp("testName", "testEmail@gmail.com", "!)@(#*$&%^$&#)"));
}

TEST(personSignUpPassword, invalidPasswordNoLetter) {
    Person* personInvalidPasswordNoLetter = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordNoLetter->signUp("testName", "testEmail@gmail.com", "192304@!()&$!"));
}

TEST(personSignUpPassword, invalidPasswordNoNum) {
    Person* personInvalidPasswordNoNum = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordNoNum->signUp("testName", "testEmail@gmail.com", "testPassword!"));
}

TEST(personSignUpPassword, invalidPasswordNoSpecialChar) {
    Person* personInvalidPasswordNoSpecialChar = new Person();

    EXPECT_ANY_THROW(personInvalidPasswordNoSpecialChar->signUp("testName", "testEmail@gmail.com", "testPassword1"));
}

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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}