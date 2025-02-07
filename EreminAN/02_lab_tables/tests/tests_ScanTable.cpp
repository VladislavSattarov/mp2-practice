#include <gtest.h>

#include "Table.h"
#include "TArrayTable.h"
#include "ScanTable.h"

using namespace std;
#define SI <string, int>


///////////////////////////////////////////////////////////////////////////////////////////// 
TEST(TabRecord, can_create_TabRecord)
{
	ASSERT_NO_THROW(TabRecord SI TR("1", 5));
}

TEST(TabRecord, can_copy)
{
	TabRecord SI TR("2", 6);
	ASSERT_NO_THROW(TabRecord SI TR2(TR));
}
////////
TEST(TabRecord, SetKey_NoThrow)
{
	TabRecord SI TR("2", 6);
	ASSERT_NO_THROW(TR.SetKey("4"));
}

TEST(TabRecord, GetKey_NoThrow)
{
	TabRecord SI TR("2", 6);
	ASSERT_NO_THROW(TR.GetKey());
}

TEST(TabRecord, GetKey_true)
{
	TabRecord SI TR("2", 6);
	ASSERT_EQ(TR.GetKey(), "2");
}

TEST(TabRecord, SetKey_true)
{
	TabRecord SI TR("2", 6);
	TR.SetKey("5");
	ASSERT_EQ(TR.GetKey(), "5");
}
////////
TEST(TabRecord, SetData_NoThrow)
{
	TabRecord SI TR("2", 6);
	ASSERT_NO_THROW(TR.SetData(12));
}

TEST(TabRecord, GetData_NoThrow)
{
	TabRecord SI TR("2", 6);
	ASSERT_NO_THROW(TR.GetData());
}

TEST(TabRecord, GetData_true)
{
	TabRecord SI TR("2", 6);
	ASSERT_EQ(*TR.GetData(), 6);
}

TEST(TabRecord, SetData_true)
{
	TabRecord SI TR("2", 6);
	TR.SetData(12);
	ASSERT_EQ(*TR.GetData(), 12);
}
////////
TEST(TabRecord, assignment_operator_NoThrow)
{
	TabRecord SI TR("2", 6);
	TabRecord SI TR2("3", 15);
	ASSERT_NO_THROW(TR2 = TR);
}

///////////////////////////////////////////////////////////////////////////////////////////// 

TEST(ScanTable, can_create_ScanTable)
{
	ASSERT_NO_THROW(ScanTable SI TR(5));
}

TEST(ScanTable, can_ScanTable_copy)
{
	ScanTable SI TR(5);
	ASSERT_NO_THROW(ScanTable SI TR2(TR));
}

TEST(ScanTable, can_ScanTable_copy_1)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	ASSERT_NO_THROW(ScanTable SI TR2(TR));
}
////////
TEST(ScanTable, GetKey_NoThrow)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 18);
	ASSERT_NO_THROW(TR.GetKey());
}

TEST(ScanTable, GetKey_true)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	ASSERT_EQ(TR.GetKey(), "4");
}

TEST(ScanTable, GetData_NoThrow)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 5);
	ASSERT_NO_THROW(TR.GetData());
}

TEST(ScanTable, GetData_true)
{
	ScanTable SI TR(2);
	TR.InsRecord("1", 2);
	TR.InsRecord("4", 12);
	ASSERT_EQ(*TR.GetData(), 12);
}
////////
TEST(ScanTable, GoNext_Throw_1)
{
	ScanTable SI TR(2);
	TR.InsRecord("1", 2);
	TR.InsRecord("4", 12);
	ASSERT_NO_THROW(TR.GoNext());
}
TEST(ScanTable, GoNext_Throw_2)
{
	ScanTable SI TR(2);
	TR.InsRecord("1", 2);
	TR.InsRecord("4", 12);
	TR.GoNext();
	ASSERT_ANY_THROW(TR.GoNext());
}

TEST(ScanTable, GoNext_true)
{
	ScanTable SI TR(2);
	TR.InsRecord("1", 2);
	TR.GoNext();
	ASSERT_EQ(TR.GetCurrentPos(), 1);
}
////////
TEST(ScanTable, SetCurrentPos_NoThrow)
{
	ScanTable SI TR(2);
	TR.InsRecord("1", 2);
	TR.InsRecord("4", 12);
	ASSERT_NO_THROW(TR.SetCurrentPos(1));
}

TEST(ScanTable, SetCurrentPos_true_1)
{
	ScanTable SI TR(2);
	TR.InsRecord("1", 2);
	TR.InsRecord("4", 12);
	TR.SetCurrentPos(1);
	ASSERT_EQ(1, TR.GetCurrentPos());
}

TEST(ScanTable, SetCurrentPos_true_2)
{
	ScanTable SI TR(2);
	TR.InsRecord("1", 2);
	TR.InsRecord("4", 12);
	TR.SetCurrentPos(5);
	ASSERT_EQ(0, TR.GetCurrentPos());
}
////////
TEST(ScanTable, InsRecord_NoThrow_1)
{
	ScanTable SI TR(2);
	ASSERT_NO_THROW(TR.InsRecord("4", 12));
}

TEST(ScanTable, InsRecord_NoThrow_2)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	ASSERT_NO_THROW(TR.InsRecord("9", 12));
}

TEST(ScanTable, InsRecord_Throw_1)
{
	ScanTable SI TR(2);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	ASSERT_ANY_THROW(TR.InsRecord("9", 12));
}

TEST(ScanTable, InsRecord_Throw_2)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	ASSERT_ANY_THROW(TR.InsRecord("4", 12));
}

TEST(ScanTable, InsRecord_true_1)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	ASSERT_EQ(TR.GetDataCount(), 1);
	TR.InsRecord("1", 9);
	TR.InsRecord("2", 7);
	ASSERT_EQ(TR.GetDataCount(), 3);
	TR.SetCurrentPos(0);
	ASSERT_EQ(*TR.GetData(), 12);
	ASSERT_EQ(TR.GetKey(), "4");
	TR.SetCurrentPos(1);
	ASSERT_EQ(*TR.GetData(), 9);
	ASSERT_EQ(TR.GetKey(), "1");
	TR.SetCurrentPos(2);
	ASSERT_EQ(*TR.GetData(), 7);
	ASSERT_EQ(TR.GetKey(), "2");
}
////////
TEST(ScanTable, DelRecord_NoThrow_1)
{
	ScanTable SI TR(2);
	TR.InsRecord("4", 12);
	ASSERT_NO_THROW(TR.DelRecord("4"));
}

TEST(ScanTable, DelRecord_NoThrow_2)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	TR.InsRecord("7", 9);
	ASSERT_NO_THROW(TR.DelRecord("1"));
}

TEST(ScanTable, DelRecord_Throw_1)
{
	ScanTable SI TR(2);
	ASSERT_ANY_THROW(TR.DelRecord("9"));
}

TEST(ScanTable, DelRecord_Throw_2)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	ASSERT_ANY_THROW(TR.DelRecord("14"));
}

TEST(ScanTable, DelRecord_true_)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	TR.InsRecord("2", 7);
	TR.InsRecord("10", 17);
	ASSERT_EQ(TR.GetDataCount(), 4);
	TR.DelRecord("4");
	ASSERT_EQ(TR.FindRecord("4"), nullptr);
	ASSERT_NE(TR.FindRecord("10"), nullptr);
	TR.DelRecord("10");
	ASSERT_EQ(TR.FindRecord("10"), nullptr);
	ASSERT_EQ(TR.GetDataCount(), 2);
}
////////
TEST(ScanTable, FindRecord_NoThrow_1)
{
	ScanTable SI TR(2);
	TR.InsRecord("4", 12);
	ASSERT_NO_THROW(TR.FindRecord("4"));
}

TEST(ScanTable, FindRecord_NoThrow_2)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	TR.InsRecord("7", 9);
	ASSERT_NO_THROW(TR.FindRecord("1"));
}

TEST(ScanTable, FindRecord_Throw_1)
{
	ScanTable SI TR(2);
	ASSERT_ANY_THROW(TR.FindRecord("9"));
}

TEST(ScanTable, FindRecord_true_1)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	ASSERT_EQ(TR.FindRecord("10"), nullptr);
}

TEST(ScanTable, FindRecord_true_2)
{
	ScanTable SI TR(5);
	TR.InsRecord("4", 12);
	TR.InsRecord("1", 9);
	TR.InsRecord("2", 7);
	TR.InsRecord("10", 17);
	ASSERT_EQ(*TR.FindRecord("4"), 12);
	ASSERT_EQ(*TR.FindRecord("2"), 7);
	TR.SetCurrentPos(1);
	ASSERT_EQ(TR.FindRecord("1"), TR.GetData());
}