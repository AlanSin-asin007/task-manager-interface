#include <gtest/gtest.h>
#include "../header/Task.hpp"

TEST(TaskTest, ModifyTaskDeadlineTest) {
    vector<Task> taskList;

    // Create tasks and add them to the taskList
    Task task1("Task1", "2023-06-01", "Description1", "Label1", 3);
    Task::addTask(taskList, task1);

    Task task2("Task2", "2023-06-05", "Description2", "Label2", 5);
    Task::addTask(taskList, task2);

    // Modify the task deadline for task with taskName "Task1"
    string newDeadline = "2023-06-10";
    Task::modifyTaskDeadline(taskList, "Task1", newDeadline);

    // Assertion: Task1's deadline should be updated to "2023-06-10"
    for (const Task& task : taskList) {
        if (task.getTaskName() == "Task1") {
            EXPECT_EQ(task.getTaskDeadline(), newDeadline);
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}






