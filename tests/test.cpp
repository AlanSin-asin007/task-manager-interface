#include "../header/Task.hpp"
#include "gtest/gtest.h"
using namespace std;

// Test case for the constructor
TEST(TaskTest, ConstructorTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    ASSERT_EQ(task.getTaskName(), "TaskName");
    ASSERT_EQ(task.getTaskDeadline(), "TaskDeadline");
    ASSERT_EQ(task.getDescription(), "Description");
    ASSERT_EQ(task.getLabel(), "Label");
    ASSERT_EQ(task.getTaskPriority(), 5);
}

// Test case for the getTaskName() function
TEST(TaskTest, GetTaskNameTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    ASSERT_EQ(task.getTaskName(), "TaskName");
}

// Test case for the getTaskDeadline() function
TEST(TaskTest, GetTaskDeadlineTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    ASSERT_EQ(task.getTaskDeadline(), "TaskDeadline");
}

// Test case for the getDescription() function
TEST(TaskTest, GetDescriptionTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    ASSERT_EQ(task.getDescription(), "Description");
}

// Test case for the getLabel() function
TEST(TaskTest, GetLabelTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    ASSERT_EQ(task.getLabel(), "Label");
}

// Test case for the getTaskPriority() function
TEST(TaskTest, GetTaskPriorityTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    ASSERT_EQ(task.getTaskPriority(), 5);
}

// Test case for the setTaskName() function
TEST(TaskTest, SetTaskNameTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    task.setTaskName("NewTaskName");
    ASSERT_EQ(task.getTaskName(), "NewTaskName");
}

// Test case for the setTaskDeadline() function
TEST(TaskTest, SetTaskDeadlineTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    task.setTaskDeadline("NewTaskDeadline");
    ASSERT_EQ(task.getTaskDeadline(), "NewTaskDeadline");
}

// Test case for the setDescription() function
TEST(TaskTest, SetDescriptionTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    task.setDescription("NewDescription");
    ASSERT_EQ(task.getDescription(), "NewDescription");
}

// Test case for the setLabel() function
TEST(TaskTest, SetLabelTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    task.setLabel("NewLabel");
    ASSERT_EQ(task.getLabel(), "NewLabel");
}

// Test case for the setTaskPriority() function
TEST(TaskTest, SetTaskPriorityTest) {
    Task task("TaskName", "TaskDeadline", "Description", "Label", 5);
    task.setTaskPriority(7);
    ASSERT_EQ(task.getTaskPriority(), 7);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}