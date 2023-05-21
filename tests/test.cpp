#include "../header/person.hpp"

#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST(personSignUpName, validName) {
    Person* personValidName = new Person();
    personValidName->signUp("testName", "testEmail", "testPassword");

    EXPECT_EQ("testName", personValidName->getName());
}

TEST(personSignUpName, nonalphabeticalName) {
    Person* personNonalphabeticalName = new Person();
    personNonalphabeticalName->signUp("testName1", "testEmail", "testPassword");

    EXPECT_EQ("", personNonalphabeticalName->getName());
}

TEST(personSignUpName, tooShortName) {
    Person* personTooShortName = new Person();
    personTooShortName->signUp("a", "testEmail", "testPassword");

    EXPECT_EQ("", personTooShortName->getName());
}

TEST(personSignUpName, tooLongName) {
    Person* personTooLongName = new Person();
    personTooLongName->signUp("testNameThatIsTooLong", "testEmail", "testPassword");

    EXPECT_EQ("", personTooLongName->getName());
}

TEST(personSignUpEmail, validEmail) {
    Person* personValidEmail = new Person();
    personValidEmail->signUp("testName", "testEmail@gmail.com", "testPassword");

    EXPECT_EQ("testEmail@gmail.com", personValidEmail->getEmail());
}

TEST(personSignUpEmail, tooShortEmail) {
    Person* personTooShortEmail = new Person();
    personTooShortEmail->signUp("testName", "a@a.a", "testPassword");

    EXPECT_EQ("", personTooShortEmail->getEmail());
}

TEST(personSignUpEmail, tooLongEmail) {
    Person* personTooLongEmail = new Person();
    personTooLongEmail->signUp("testName", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "testPassword");

    EXPECT_EQ("", personTooLongEmail->getEmail());
}

TEST(personSignUpEmail, invalidEmailUsername) {
    Person* personInvalidEmailUsername = new Person();
    personInvalidEmailUsername->signUp("testName", "testEmail1@gmail.com", "testPassword");

    EXPECT_EQ("", personInvalidEmailUsername->getEmail());
}

TEST(personSignUpEmail, invalidEmailDomainname) {
    Person* personInvalidEmailDomainname = new Person();
    personInvalidEmailDomainname->signUp("testName", "testEmail@gmail1.com", "testPassword");

    EXPECT_EQ("", personInvalidEmailDomainname->getEmail());
}

TEST(personSignUpEmail, invalidEmailExtension) {
    Person* personInvalidEmailExtension = new Person();
    personInvalidEmailExtension->signUp("testName", "testEmail@gmail.com1", "testPassword");

    EXPECT_EQ("", personInvalidEmailExtension->getEmail());
}

TEST(personSignUpEmail, invalidEmailFirstAt) {
    Person* personInvalidEmailFirstAt = new Person();
    personInvalidEmailFirstAt->signUp("testName", "@gmail.com", "testPassword");

    EXPECT_EQ("", personInvalidEmailFirstAt->getEmail());
}

TEST(personSignUpEmail, invalidEmailDomainnameEmpty) {
    Person* personInvalidEmailDomainnameEmpty = new Person();
    personInvalidEmailDomainnameEmpty->signUp("testName", "testEmail@.com", "testPassword");

    EXPECT_EQ("", personInvalidEmailDomainnameEmpty->getEmail());
}

TEST(personSignUpEmail, invalidEmailLastDot) {
    Person* personInvalidEmailLastDot = new Person();
    personInvalidEmailLastDot->signUp("testName", "testEmail@gmail.", "testPassword");

    EXPECT_EQ("", personInvalidEmailLastDot->getEmail());
}

TEST(personSignUpEmail, invalidEmailAtDotOrder) {
    Person* personInvalidEmailAtDotOrder = new Person();
    personInvalidEmailAtDotOrder->signUp("testName", "testEmail.gmail@com", "testPassword");

    EXPECT_EQ("", personInvalidEmailAtDotOrder->getEmail());
}

TEST(personSignUpPassword, validPassword) {
    Person* personValidPassword = new Person();
    personValidPassword->signUp("testName", "testEmail", "testPassword1!");

    EXPECT_EQ("testPassword1!", personValidPassword->getPassword());
}

TEST(personSignUpPassword, tooShortPassword) {
    Person* personTooShortPassword = new Person();
    personTooShortPassword->signUp("testName", "testEmail", "a");

    EXPECT_EQ("", personTooShortPassword->getPassword());
}

TEST(personSignUpPassword, tooLongPassword) {
    Person* personTooLongPassword = new Person();
    personTooLongPassword->signUp("testName", "testEmail", "abcdefghijklmnopqrstuvwxyz");

    EXPECT_EQ("", personTooLongPassword->getPassword());
}

TEST(personSignUpPassword, invalidPasswordOnlyLetters) {
    Person* personInvalidPasswordOnlyLetters = new Person();
    personInvalidPasswordOnlyLetters->signUp("testName", "testEmail", "testPassword");

    EXPECT_EQ("", personInvalidPasswordOnlyLetters->getPassword());
}

TEST(personSignUpPassword, invalidPasswordNoNum) {
    Person* personInvalidPasswordNoNum = new Person();
    personInvalidPasswordNoNum->signUp("testName", "testEmail", "testPassword!");

    EXPECT_EQ("", personInvalidPasswordNoNum->getPassword());
}

TEST(personSignUpPassword, invalidPasswordNoSpecialChar) {
    Person* personInvalidPasswordNoSpecialChar = new Person();
    personInvalidPasswordNoSpecialChar->signUp("testName", "testEmail", "testPassword1");

    EXPECT_EQ("", personInvalidPasswordNoSpecialChar->getPassword());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}