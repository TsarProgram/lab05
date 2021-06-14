#include "Account.cpp"
#include "Transaction.cpp"

#include "gtest/gtest.h"

TEST(Account, test1)
{
	Account A(1, 5);
	EXPECT_EQ(A.GetBalance(), 5);
}
TEST(Account, test2)
{
	Account A(1, 5);
	A.Lock();
	A.ChangeBalance(3);
	EXPECT_EQ(A.GetBalance(), 8);
}
TEST(Account, test3)
{
	Account A(1, 5);
	EXPECT_ANY_THROW(A.ChangeBalance(3));
}
TEST(Account, test4)
{
	Account A(1, 5);
	A.Lock();
	EXPECT_ANY_THROW(A.Lock());
}

TEST(Account, test5)
{
	Account A(1, 5);
	EXPECT_ANY_THROW(A.ChangeBalance(3));
}
TEST(Transaction, test1)
{
	Transaction B;
	EXPECT_EQ(B.fee(), 1);
}
TEST(Transaction, test2)
{
	Transaction B;
	B.set_fee(5);
	EXPECT_EQ(B.fee(), 5);
}
TEST(Transaction, test3)
{
	Transaction B;
	Account A1(1, 2000);
	Account A2(2, 200);
	B.set_fee(100);
	B.Make(A1, A2, 400);
	EXPECT_EQ(A1.GetBalance(), 1500);
	EXPECT_EQ(A2.GetBalance(), 600);
}
TEST(Transaction, test4)
{
	Transaction B;
	Account A1(1, 1000);
	Account A2(2, 200);
	EXPECT_ANY_THROW(B.Make(A1, A2, -400));
	EXPECT_ANY_THROW(B.Make(A1, A2, 60));
}
TEST(Transaction, test5)
{
	Transaction B;
	Account A1(1, 1000);
	Account A2(2, 200);
	B.set_fee(300);
	EXPECT_FALSE(B.Make(A1, A2, 400));
}
TEST(Transaction, test6)
{
	Transaction B;
	Account A1(1, 1000);
	Account A2(2, 200);
	EXPECT_ANY_THROW(B.Make(A1, A2, -400));
}
TEST(Transaction, test7)
{
	Transaction B;
	Account A1(1, 1000);
	EXPECT_ANY_THROW(B.Make(A1, A1, 400));
}
TEST(Transaction, test8)
{
	Transaction B;
	Account A1(1, 1000);
	Account A2(2, 5000);
	EXPECT_FALSE(B.Make(A1, A2, 4000));
}
int main()
{
	return RUN_ALL_TESTS();
}
