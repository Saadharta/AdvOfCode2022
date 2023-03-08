#include "../inc/day4.hpp"

#include <gtest/gtest.h>

TEST(EPPartialOverlap, NoPartialOverlap){
    std::vector<int> e1 {1,2,3,4};
    std::vector<int> e2 {5,6,7,8};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), false);
}

TEST(EPPartialOverlap, PartialOverlap){
    std::vector<int> e1 {1,2,3,4};
    std::vector<int> e2 {3,4,5,6};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), true);
}

TEST(EPPartialOverlap, PartialOverlapInclusive){
    std::vector<int> e1 {1,2,3,4,5,6,7,8};
    std::vector<int> e2 {3,4,5,6};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), true);
}

TEST(EPPartialOverlap, High1_2PartialOverlap){
    std::vector<int> e1 {1,2,3,4};
    std::vector<int> e2 {4,5,6,7};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), true);
}

TEST(EPPartialOverlap, Low1_2LimitPartialOverlap){
    std::vector<int> e1 {4,5,6,7};
    std::vector<int> e2 {1,2,3,4};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), true);
}

TEST(EPFullOverlap, NoOverlap){
    std::vector<int> e1 {1,2,3,4};
    std::vector<int> e2 {5,6,7,8};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), false);
}

TEST(EPFullOverlap, FullOverlap){
    std::vector<int> e1 {1,2,3,4,5,6,7,8};
    std::vector<int> e2 {3,4,5,6};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), true);
}

TEST(EPFullOverlap, MatchOverlap){
    std::vector<int> e1 {3,4,5,6};
    std::vector<int> e2 {3,4,5,6};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), true);
}

TEST(EPFullOverlap, High1_2Overlap){
    std::vector<int> e1 {1,2,3,4};
    std::vector<int> e2 {4};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), true);
}

TEST(EPFullOverlap, Low1_2Overlap){
    std::vector<int> e1 {1,2,3,4};
    std::vector<int> e2 {1};
    ElfPair ep(e1,e2);
    GTEST_ASSERT_EQ(ep.isPartialOverlappingSections(), true);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

