#include <gtest/gtest.h>
#include "../header/Task.hpp"

// Test case for creating a label
TEST(TaskTest, CreateLabelTest) {
    // Create a task with a label
    Task task("Task1", "2023-06-01", "Description1", "Label1", 3);

    // Assertion: The task's label should be "Label1"
    EXPECT_EQ(task.getLabel(), "Label1");
}

int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}





