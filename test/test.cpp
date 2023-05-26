#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/DateSorter.h"
#include "../include/TaskSorter.h"
#include "../include/Person.h"

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

TEST(DateSorterTests, testGetPerson) {
    Person* p = new Person();
    TaskSorter* sorter = new DateSorter(p);

    EXPECT_EQ(p, sorter->getPerson());
}

TEST(DateSorterTests, testSetPerson) {
    TaskSorter* sorter = new DateSorter(new Person());
    Person* p2 = new Person();
    sorter->setPerson(p2);

    EXPECT_EQ(p2, sorter->getPerson());
}

TEST(DateSorterTests, testSortIncreasing) {
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

TEST(DateSorterTests, testSortSame) {
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

TEST(DateSorterTests, testSortDecreasing) {
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

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}