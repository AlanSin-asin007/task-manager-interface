#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../include/ImportanceSorter.h"
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

TEST(SorterTests, testGetPerson) {
    Person* p = new Person();
    TaskSorter* sorter = new ImportanceSorter(p);

    EXPECT_EQ(p, sorter->getPerson());
}

TEST(SorterTests, testSetPerson) {
    TaskSorter* sorter = new ImportanceSorter(new Person());
    Person* p2 = new Person();
    sorter->setPerson(p2);

    EXPECT_EQ(p2, sorter->getPerson());
}

TEST(SorterTests, testSortIncreasing) {
    std::vector<Task> list;
    date::year_month_day d = date::year{2023}/date::January/1;
    for (int i = 1; i < 6; ++i) {
        list.push_back(Task(i, d));
    }

    TaskSorter* sorter = new ImportanceSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }

}

TEST(SorterTests, testSortSame) {
    std::vector<Task> list;
    for (int i = 1; i < 21; ++i) {
        list.push_back(Task(5, date::year{2023}/date::January/1));
    }

    TaskSorter* sorter = new ImportanceSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }

}

TEST(SorterTests, testSortDecreasing) {
    std::vector<Task> list;
    date::year_month_day d = date::year{2023}/date::January/1;
    for (int i = 20; i > 0 ; --i) {
        list.push_back(Task(i, d));
    }

    TaskSorter* sorter = new ImportanceSorter(new Person(list));
    sorter->performSort();
    list = sorter->getPerson()->getTaskList();

    for (int i = 0; i+1 < list.size(); ++i) {
        EXPECT_GE(list.at(i).getRating(), list.at(i+1).getRating());
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}