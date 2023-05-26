#include <gtest/gtest.h>
#include "../header/Task.hpp"

// Test case for the copyTask() function
TEST(TaskTest, CopyTaskTest) {
    // Create a task
    Task originalTask("Task1", "2023-06-01", "Description1", "Label1", 3);

    // Copy the task
    Task copiedTask = Task::copyTask(originalTask);

    // Assertion: The copied task should have the same attributes as the original task
    EXPECT_EQ(copiedTask.getTaskName(), originalTask.getTaskName());
    EXPECT_EQ(copiedTask.getTaskDeadline(), originalTask.getTaskDeadline());
    EXPECT_EQ(copiedTask.getDescription(), originalTask.getDescription());
    EXPECT_EQ(copiedTask.getLabel(), originalTask.getLabel());
    EXPECT_EQ(copiedTask.getTaskPriority(), originalTask.getTaskPriority());
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}




