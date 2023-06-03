#include <gtest/gtest.h>
#include "../include/Task.h"

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

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



