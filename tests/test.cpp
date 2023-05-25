#include "../header/person.hpp"

#include "gtest/gtest.h"

TEST(personSignUpName, validName) {
    Person* personValidName = new Person();
    personValidName->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testName", personValidName->getName());
}

TEST(personSignUpName, invalidNameNonalphabetical) {
    Person* personInvalidNameNonalphabetical = new Person();
    personInvalidNameNonalphabetical->signUp("testName1", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidNameNonalphabetical->getName());
}

TEST(personSignUpName, invalidNameTooShort) {
    Person* personInvalidNameTooShort = new Person();
    personInvalidNameTooShort->signUp("a", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidNameTooShort->getName());
}

TEST(personSignUpName, invalidNameTooLong) {
    Person* personInvalidNameTooLong = new Person();
    personInvalidNameTooLong->signUp("testNameThatIsTooLong", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidNameTooLong->getName());
}

TEST(personSignUpEmail, validEmail) {
    Person* personValidEmail = new Person();
    personValidEmail->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testEmail@gmail.com", personValidEmail->getEmail());
}

TEST(personSignUpEmail, invalidEmailTooShort) {
    Person* personInvalidEmailTooShort = new Person();
    personInvalidEmailTooShort->signUp("testName", "a@a.a", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailTooShort->getEmail());
}

TEST(personSignUpEmail, invalidEmailTooLong) {
    Person* personInvalidEmailTooLong = new Person();
    personInvalidEmailTooLong->signUp("testName", "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ@abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailTooLong->getEmail());
}

TEST(personSignUpEmail, invalidEmailUsername) {
    Person* personInvalidEmailUsername = new Person();
    personInvalidEmailUsername->signUp("testName", "testEmail1@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailUsername->getEmail());
}

TEST(personSignUpEmail, invalidEmailDomainname) {
    Person* personInvalidEmailDomainname = new Person();
    personInvalidEmailDomainname->signUp("testName", "testEmail@gmail1.com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailDomainname->getEmail());
}

TEST(personSignUpEmail, invalidEmailExtension) {
    Person* personInvalidEmailExtension = new Person();
    personInvalidEmailExtension->signUp("testName", "testEmail@gmail.com1", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailExtension->getEmail());
}

TEST(personSignUpEmail, invalidEmailFirstAt) {
    Person* personInvalidEmailFirstAt = new Person();
    personInvalidEmailFirstAt->signUp("testName", "@gmail.com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailFirstAt->getEmail());
}

TEST(personSignUpEmail, invalidEmailDomainnameEmpty) {
    Person* personInvalidEmailDomainnameEmpty = new Person();
    personInvalidEmailDomainnameEmpty->signUp("testName", "testEmail@.com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailDomainnameEmpty->getEmail());
}

TEST(personSignUpEmail, invalidEmailLastDot) {
    Person* personInvalidEmailLastDot = new Person();
    personInvalidEmailLastDot->signUp("testName", "testEmail@gmail.", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailLastDot->getEmail());
}

TEST(personSignUpEmail, invalidEmailAtDotOrder) {
    Person* personInvalidEmailAtDotOrder = new Person();
    personInvalidEmailAtDotOrder->signUp("testName", "testEmail.gmail@com", "testPassword1!");

    EXPECT_EQ("", personInvalidEmailAtDotOrder->getEmail());
}

TEST(personSignUpPassword, validPassword) {
    Person* personValidPassword = new Person();
    personValidPassword->signUp("testName", "testEmail@gmail.com", "testPassword1!");

    EXPECT_EQ("testPassword1!", personValidPassword->getPassword());
}

TEST(personSignUpPassword, invalidPasswordTooShort) {
    Person* personInvalidPasswordTooShort = new Person();
    personInvalidPasswordTooShort->signUp("testName", "testEmail@gmail.com", "a");

    EXPECT_EQ("", personInvalidPasswordTooShort->getPassword());
}

TEST(personSignUpPassword, invalidPasswordTooLong) {
    Person* personInvalidPasswordTooLong = new Person();
    personInvalidPasswordTooLong->signUp("testName", "testEmail@gmail.com", "abcdefghijklmnopqrstuvwxyz");

    EXPECT_EQ("", personInvalidPasswordTooLong->getPassword());
}

TEST(personSignUpPassword, invalidPasswordOnlyLetter) {
    Person* personInvalidPasswordOnlyLetter = new Person();
    personInvalidPasswordOnlyLetter->signUp("testName", "testEmail@gmail.com", "testPassword");

    EXPECT_EQ("", personInvalidPasswordOnlyLetter->getPassword());
}

TEST(personSignUpPassword, invalidPasswordOnlyNum) {
    Person* personInvalidPasswordOnlyNum = new Person();
    personInvalidPasswordOnlyNum->signUp("testName", "testEmail@gmail.com", "120491845091");

    EXPECT_EQ("", personInvalidPasswordOnlyNum->getPassword());
}

TEST(personSignUpPassword, invalidPasswordOnlySpecialChar) {
    Person* personInvalidPasswordOnlySpecialChar = new Person();
    personInvalidPasswordOnlySpecialChar->signUp("testName", "testEmail@gmail.com", "!)@(#*$&%^$&#)");

    EXPECT_EQ("", personInvalidPasswordOnlySpecialChar->getPassword());
}

TEST(personSignUpPassword, invalidPasswordNoLetter) {
    Person* personInvalidPasswordNoLetter = new Person();
    personInvalidPasswordNoLetter->signUp("testName", "testEmail@gmail.com", "192304@!()&$!");

    EXPECT_EQ("", personInvalidPasswordNoLetter->getPassword());
}

TEST(personSignUpPassword, invalidPasswordNoNum) {
    Person* personInvalidPasswordNoNum = new Person();
    personInvalidPasswordNoNum->signUp("testName", "testEmail@gmail.com", "testPassword!");

    EXPECT_EQ("", personInvalidPasswordNoNum->getPassword());
}

TEST(personSignUpPassword, invalidPasswordNoSpecialChar) {
    Person* personInvalidPasswordNoSpecialChar = new Person();
    personInvalidPasswordNoSpecialChar->signUp("testName", "testEmail@gmail.com", "testPassword1");

    EXPECT_EQ("", personInvalidPasswordNoSpecialChar->getPassword());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}