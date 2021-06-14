# lab05
[![Build Status](https://travis-ci.org/supsun-sockol/lab05.svg?branch=main)](https://travis-ci.org/supsun-sockol/lab05)
[![Coverage Status](https://coveralls.io/repos/github/supsun-sockol/lab5/badge.svg?branch=main)](https://coveralls.io/github/supsun-sockol/lab5?branch=main)
```

    Создайте CMakeList.txt для библиотеки banking.
    Создайте модульные тесты на классы Transaction и Account.
        Используйте mock-объекты.
        Покрытие кода должно составлять 100%.
    Настройте сборочную процедуру на TravisCI.
    Настройте Coveralls.io.
```

## CmakeLists.txt
```
cmake_minimum_required(VERSION 3.2)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(bank)
SET(COVERAGE OFF CACHE BOOL "Coverage")
enable_testing()
add_subdirectory(third-party/gtest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


add_library(lib1 Account.h Account.cpp)
add_library(lib2 Transaction.h Transaction.cpp)
add_executable(runUnitTests test.cpp)
target_compile_options(runUnitTests PRIVATE --coverage)
target_link_libraries(runUnitTests PRIVATE --coverage gtest gtest_main)
add_test( runUnitTests runUnitTests )
```

## Tests

```
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

```
## Поцесс
1) Это был пипец
2) У меня не было инструкции по выполнению этой лабы, так что все делалось с помощью великого и могучего научного тыка.
3) У меня отказал cmake так что приходилось дополнительно извращаться, чтобы можно было собрать код
4) У меня было 85. !!!85!!! сборок на тейвисе.
5) В коде были ошибки, так гугл тесты не работали, а в банковском приложении пришлось поменять чуток кода.
6) А вообще тему усвоил, но хотелось бы побольше инструкций получать.
