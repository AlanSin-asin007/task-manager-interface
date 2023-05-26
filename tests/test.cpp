#include <gtest/gtest.h>
#include "../header/Task.hpp"

// Test case for the deleteTask() function
TEST(TaskTest, ModifyTaskTest) {
    vector<Task> taskList;

    // Create tasks and add them to the taskList
    Task task1("Task1", "2023-06-01", "Description1", "Label1", 3);
    Task::addTask(taskList, task1);

    Task task2("Task2", "2023-06-05", "Description2", "Label2", 5);
    Task::addTask(taskList, task2);

    // Modify task with taskName "Task1"
    Task::modifyTask(taskList, "Task1", "ModifiedTask", "2023-06-10", "Modified Description", "Modified Label", 8);

    // Assertion: Task1 should be modified in the taskList
    bool taskModified = false;
    for (const Task& task : taskList) {
        if (task.getTaskName() == "ModifiedTask" && task.getTaskDeadline() == "2023-06-10" &&
            task.getDescription() == "Modified Description" && task.getLabel() == "Modified Label" &&
            task.getTaskPriority() == 8) {
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

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}






