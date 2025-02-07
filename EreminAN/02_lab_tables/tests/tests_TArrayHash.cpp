#include <gtest.h>
#include "ScanTable.h"
#include "TArrayHash.h"


using namespace std;
#define SI <string, int>


///////////////////////////////////////////////////////////////////////////////////////////// 
TEST(TArrayHash, can_create_TArrayHash)
{
	ASSERT_NO_THROW(TArrayHash SI TH(5));
}

TEST(TArrayHash, can_copy)
{
	TArrayHash SI TH(6);
	ASSERT_NO_THROW(TArrayHash SI TH2(TH));
}

TEST(TArrayHash, can_copy_2)
{
	TArrayHash SI TH(6);
	ASSERT_NO_THROW(TArrayHash SI TH2(TH));
}
///////////
TEST(TArrayHash, GetKey_NoThrow)
{
	TArrayHash SI TH(5);
	TH.InsRecord("4", 18);
	ASSERT_NO_THROW(TH.GetKey());
}

TEST(TArrayHash, GetKey_true)
{
	TArrayHash SI TH(5);
	TH.InsRecord("4", 12);
	TH.InsRecord("1", 13);
	ASSERT_EQ(TH.GetKey(), "1");
}

TEST(TArrayHash, GetData_NoThrow)
{
	TArrayHash SI TH(5);
	TH.InsRecord("4", 5);
	ASSERT_NO_THROW(TH.GetData());
}

TEST(TArrayHash, GetData_true)
{
	TArrayHash SI TH(3);
	TH.InsRecord("1", 2);
	TH.InsRecord("2", 8);
	TH.InsRecord("4", 12);
	ASSERT_EQ(*TH.GetData(), 12);
}
///////////
TEST(TArrayHash, GoNext_Throw_1)
{
	TArrayHash SI TH(3);
	TH.InsRecord("1", 2);
	TH.InsRecord("4", 15);
	ASSERT_NO_THROW(TH.GoNext());
}

TEST(TArrayHash, GoNext_Throw_2)
{
	TArrayHash SI TH(2);
	TH.InsRecord("1", 2);
	TH.InsRecord("4", 12);
	TH.SetCurrentPos(1);
	TH.GoNext();
	ASSERT_ANY_THROW(TH.GoNext());
}

TEST(TArrayHash, GoNext_true)
{
	TArrayHash SI TH(3);
	TH.InsRecord("1", 2);
	TH.SetCurrentPos(0);
	TH.GoNext();
	ASSERT_EQ(TH.GetCurrentPos(), 1);
}
///////////
TEST(TArrayHash, Reset_Throw_1)
{
	TArrayHash SI TH(3);
	TH.InsRecord("1", 2);
	TH.InsRecord("4", 12);
	ASSERT_NO_THROW(TH.Reset());
}

TEST(TArrayHash, Reset_true_1)
{
	TArrayHash SI TH(2);
	TH.InsRecord("1", 2);
	TH.InsRecord("4", 12);
	TH.Reset();
	ASSERT_EQ(TH.GetCurrentPos(), 0);
}

TEST(TArrayHash, Reset_true_2)
{
	TArrayHash SI TH(10);
	TH.InsRecord("1", 2);
	TH.InsRecord("4", 12);
	TH.InsRecord("6", 1);
	TH.Reset();
	ASSERT_EQ(TH.GetCurrentPos(), 2);
}
///////////
TEST(TArrayHash, InsRecord_NoThrow_1)
{
	TArrayHash SI TH(2);
	ASSERT_NO_THROW(TH.InsRecord("4", 12));
}

TEST(TArrayHash, InsRecord_NoThrow_2)
{
	TArrayHash SI TH(5);
	TH.InsRecord("4", 12);
	TH.InsRecord("1", 9);
	ASSERT_NO_THROW(TH.InsRecord("9", 125));
}

TEST(TArrayHash, InsRecord_Throw_1)
{
	TArrayHash SI TH(2);
	TH.InsRecord("4", 12);
	TH.InsRecord("1", 9);
	ASSERT_ANY_THROW(TH.InsRecord("9", 12));
}

TEST(TArrayHash, InsRecord_Throw_2)
{
	TArrayHash SI TH(5);
	TH.InsRecord("4", 12);
	TH.InsRecord("1", 9);
	ASSERT_ANY_THROW(TH.InsRecord("4", 12));
}

TEST(TArrayHash, InsRecord_true_1)
{
	TArrayHash SI TH(5);
	TH.InsRecord("1", 6);
	ASSERT_EQ(*TH.GetData(), 6);
	ASSERT_EQ(TH.GetKey(), "1");
	ASSERT_EQ(TH.GetDataCount(), 1);
	TH.InsRecord("3", 93);
	ASSERT_EQ(*TH.GetData(), 93);
	ASSERT_EQ(TH.GetKey(), "3");
	TH.InsRecord("28", 71);
	ASSERT_EQ(*TH.GetData(), 71);
	ASSERT_EQ(TH.GetKey(), "28");
	ASSERT_EQ(TH.GetDataCount(), 3);
}
///////////
TEST(TArrayHash, DelRecord_NoThrow_1)
{
	TArrayHash SI TH(2);
	TH.InsRecord("2", 12);
	ASSERT_NO_THROW(TH.DelRecord("2"));
}

TEST(TArrayHash, DelRecord_NoThrow_2)
{
	TArrayHash SI TH(5);
	TH.InsRecord("1", 12);
	TH.InsRecord("5", 1);
	TH.InsRecord("9", 2);
	ASSERT_NO_THROW(TH.DelRecord("1"));
}

TEST(TArrayHash, DelRecord_Throw_1)
{
	TArrayHash SI TH(2);
	ASSERT_ANY_THROW(TH.DelRecord("1"));
}

TEST(TArrayHash, DelRecord_Throw_2)
{
	TArrayHash SI TH(5);
	TH.InsRecord("5", 12);
	TH.InsRecord("2", 5);
	ASSERT_ANY_THROW(TH.DelRecord("14"));
}

TEST(TArrayHash, DelRecord_true_)
{
	TArrayHash SI TH(5);
	TH.InsRecord("4", 6);
	TH.InsRecord("1", 5);
	TH.InsRecord("5", 71);
	TH.InsRecord("11", 7);
	TH.InsRecord("41", 71);
	ASSERT_EQ(TH.GetDataCount(), 5);
	TH.DelRecord("1");
	ASSERT_EQ(TH.FindRecord("1"), nullptr);
	ASSERT_NE(TH.FindRecord("5"), nullptr);
	TH.DelRecord("5");
	ASSERT_EQ(TH.FindRecord("5"), nullptr);
	ASSERT_EQ(TH.GetDataCount(), 3);
}
///////////
TEST(TArrayHash, FindRecord_NoThrow_1)
{
	TArrayHash SI TH(2);
	TH.InsRecord("14", 1);
	ASSERT_NO_THROW(TH.FindRecord("14"));
}

TEST(TArrayHash, FindRecord_NoThrow_2)
{
	TArrayHash SI TH(5);
	TH.InsRecord("5", 1);
	TH.InsRecord("2", 5);
	TH.InsRecord("3", 2);
	ASSERT_NO_THROW(TH.FindRecord("2"));
}

TEST(TArrayHash, FindRecord_Throw_1)
{
	TArrayHash SI TH(2);
	ASSERT_NO_THROW(TH.FindRecord("1"));
	ASSERT_EQ(TH.FindRecord("1"), nullptr);
}

TEST(TArrayHash, FindRecord_true_1)
{
	TArrayHash SI TH(5);
	TH.InsRecord("1", 1);
	TH.InsRecord("2", 5);
	ASSERT_EQ(TH.FindRecord("5"), nullptr);
}

TEST(TArrayHash, FindRecord_true_2)
{
	TArrayHash SI TH(5);
	TH.InsRecord("4", 12);
	TH.InsRecord("1", 9);
	TH.InsRecord("2", 7);
	TH.InsRecord("10", 17);
	ASSERT_EQ(*TH.FindRecord("4"), 12);
	ASSERT_EQ(*TH.FindRecord("2"), 7);
}
///////////


