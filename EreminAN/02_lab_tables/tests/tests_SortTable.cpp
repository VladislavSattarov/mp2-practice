#include <gtest.h>
#include "SortTable.h"

using namespace std;
#define SI <string, int>


TEST(SortTable, can_create_ScanTable)
{
	ASSERT_NO_THROW(SortTable SI ST(5));
}

TEST(SortTable, can_ScanTable_copy)
{
	SortTable SI ST(5);
	ASSERT_NO_THROW(SortTable SI ST2(ST));
}

TEST(SortTable, can_ScanTable_copy_1)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 12);
	ST.InsRecord("1", 22);
	ASSERT_NO_THROW(SortTable SI ST2(ST));
}

TEST(SortTable, can_ScanTable_copy_2)
{
	ScanTable SI ST(5);
	ST.InsRecord("4", 12);
	ST.InsRecord("1", 22);
	ASSERT_NO_THROW(SortTable SI ST2(ST));
}
////////
TEST(SortTable, InsRecord_NoThrow_1)
{
	SortTable SI ST(2);
	ASSERT_NO_THROW(ST.InsRecord("1", 4));
}

TEST(SortTable, InsRecord_NoThrow_2)
{
	SortTable SI ST(5);
	ST.InsRecord("3", 19);
	ST.InsRecord("2", 5);
	ASSERT_NO_THROW(ST.InsRecord("9", 12));
}

TEST(SortTable, InsRecord_Throw_1)
{
	SortTable SI ST(2);
	ST.InsRecord("5", 4);
	ST.InsRecord("1", 2);
	ASSERT_ANY_THROW(ST.InsRecord("9", 12));
}

TEST(SortTable, InsRecord_Throw_2)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 12);
	ST.InsRecord("1", 9);
	ASSERT_ANY_THROW(ST.InsRecord("4", 2));
}

TEST(SortTable, InsRecord_true_1)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 12);
	ASSERT_EQ(ST.GetDataCount(), 1);
	ST.InsRecord("1", 9);
	ST.InsRecord("2", 7);
	ASSERT_EQ(ST.GetDataCount(), 3);
	ST.SetCurrentPos(0);
	ASSERT_EQ(*ST.GetData(), 9);
	ASSERT_EQ(ST.GetKey(), "1");
	ST.SetCurrentPos(1);
	ASSERT_EQ(*ST.GetData(), 7);
	ASSERT_EQ(ST.GetKey(), "2");
	ST.SetCurrentPos(2);
	ASSERT_EQ(*ST.GetData(), 12);
	ASSERT_EQ(ST.GetKey(), "4");
	ST.InsRecord("3", 8);
	ASSERT_EQ(*ST.GetData(), 8);
	ASSERT_EQ(ST.GetKey(), "3");
}
////////
TEST(SortTable, DelRecord_NoThrow_1)
{
	SortTable SI ST(2);
	ST.InsRecord("4", 12);
	ASSERT_NO_THROW(ST.DelRecord("4"));
}

TEST(SortTable, DelRecord_NoThrow_2)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 12);
	ST.InsRecord("1", 9);
	ST.InsRecord("7", 9);
	ASSERT_NO_THROW(ST.DelRecord("1"));
}

TEST(SortTable, DelRecord_Throw_1)
{
	SortTable SI ST(2);
	ASSERT_ANY_THROW(ST.DelRecord("9"));
}

TEST(SortTable, DelRecord_Throw_2)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 12);
	ST.InsRecord("1", 9);
	ASSERT_ANY_THROW(ST.DelRecord("14"));
}

TEST(SortTable, DelRecord_true_)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 12);
	ST.InsRecord("1", 9);
	ST.InsRecord("2", 7);
	ST.InsRecord("10", 17);
	ASSERT_EQ(ST.GetDataCount(), 4);
	ST.DelRecord("4");
	ASSERT_EQ(ST.FindRecord("4"), nullptr);
	ASSERT_NE(ST.FindRecord("10"), nullptr);
	ST.DelRecord("10");
	ASSERT_EQ(ST.FindRecord("10"), nullptr);
	ASSERT_EQ(ST.GetDataCount(), 2);
}
////////
TEST(SortTable, FindRecord_NoThrow_1)
{
	SortTable SI ST(2);
	ST.InsRecord("4", 12);
	ASSERT_NO_THROW(ST.FindRecord("4"));
}

TEST(SortTable, FindRecord_NoThrow_2)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 12);
	ST.InsRecord("1", 9);
	ST.InsRecord("7", 9);
	ASSERT_NO_THROW(ST.FindRecord("1"));
}

TEST(SortTable, FindRecord_NoThrow_3)
{
	SortTable SI ST(2);
	ASSERT_ANY_THROW(ST.FindRecord("9"), nullptr);
}

TEST(SortTable, FindRecord_true_1)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 12);
	ST.InsRecord("1", 9);
	ASSERT_EQ(ST.FindRecord("10"), nullptr);
}

TEST(SortTable, FindRecord_true_2)
{
	SortTable SI ST(5);
	ST.InsRecord("4", 18);
	ST.InsRecord("1", 9);
	ST.InsRecord("2", 5);
	ST.InsRecord("10", 17);
	ASSERT_EQ(*ST.FindRecord("4"), 18);
	ASSERT_EQ(*ST.FindRecord("2"), 5);
	ST.SetCurrentPos(0);
	ASSERT_EQ(ST.FindRecord("1"), ST.GetData());
}