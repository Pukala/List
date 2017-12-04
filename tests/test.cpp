#include "gtest/gtest.h"
#include "../code/include/list.hpp"
#include <string>
#include <sstream>

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

TEST_F(TestList, sizeList)
{
    l_sut.insert(7);
	l_sut.insert(3);
	l_sut.insert(2);
    EXPECT_EQ(l_sut.size(), 3);
}

TEST_F(TestList, deleteFirstItem)
{
    l_sut.insert(1);
    EXPECT_EQ(true, l_sut.deleteElement(1));
    EXPECT_EQ(nullptr, l_sut.getHead());
    EXPECT_EQ(0, l_sut.size());
}

TEST_F(TestList, deleteMoreThenFirstButNotLastCase)
{
    l_sut.insert(1);
    l_sut.insert(2);
    l_sut.insert(3);
    l_sut.insert(4);
     
    l_sut.deleteElement(3);
    EXPECT_EQ(4, l_sut.getHead()->nextNode->nextNode->valueNode);;
    EXPECT_EQ(l_sut.size(), 3);
}

TEST_F(TestList, deleteLastElementList)
{
    l_sut.insert(1);
    l_sut.insert(2);
    l_sut.insert(3);
    l_sut.insert(4);
     
    l_sut.deleteElement(4);
    EXPECT_EQ(3, l_sut.getHead()->nextNode->nextNode->valueNode);;
    EXPECT_EQ(l_sut.size(), 3);
}

TEST_F(TestList, findInEmptyList)
{
    EXPECT_EQ(l_sut.find(2), nullptr);
}

TEST_F(TestList, findInHeadList)
{
    l_sut.insert(1);
    auto x = l_sut.find(1);
    EXPECT_EQ(x->valueNode, 1); 
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
