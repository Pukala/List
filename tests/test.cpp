#include "gtest/gtest.h"
#include "../code/include/list.hpp"

class TestList : public ::testing::Test
{
public:
    List l_sut;
    TestList() = default;
    ~TestList() = default;
};

TEST_F(TestList, HeadIsNullInEmptyList)
{
    EXPECT_EQ(nullptr, l_sut.getHead());      
}

TEST_F(TestList, initNodeWithValue)
{
    Node nodeObj(5);
    EXPECT_EQ(5, nodeObj.valueNode);      
}

TEST_F(TestList, initNodeWithNullNext)
{
    Node nodeObj(5);
    EXPECT_EQ(nullptr, nodeObj.nextNode);      
}

TEST_F(TestList, HeadIsEmpty)
{
    EXPECT_EQ(true, l_sut.headIsEmpty());
}

TEST_F(TestList, insertElement)
{
    EXPECT_EQ(true, l_sut.insert(5));
}

TEST_F(TestList, insertElementWithCorrectValue)
{
    l_sut.insert(7);
    EXPECT_EQ(7, l_sut.getHead()->valueNode);
}

TEST_F(TestList, correctAddThreeElement)
{
    l_sut.insert(7);
	l_sut.insert(3);
	l_sut.insert(2);
	EXPECT_EQ(7, l_sut.getHead()->valueNode);
	EXPECT_EQ(3, l_sut.getHead()->nextNode->valueNode);
	EXPECT_EQ(2, l_sut.getHead()->nextNode->nextNode->valueNode);
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
