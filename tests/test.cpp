#include "../header/person.hpp"

#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(generateRandPassword, testLengthOfPassword) {
    Person testPerson1;
    string res = testPerson1.generateRandPassword();
    EXPECT_EQ(20, res.length());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}