#include <gtest/gtest.h>

// Підміняємо main з 8.1int.cpp, щоб він не конфліктував з main від GoogleTest
#define main program_main
#include "8.1int.cpp"
#undef main

// ---------- FindThirdCommaIndex ----------

TEST(FindThirdCommaIndex, ThreeCommas)
{
    EXPECT_EQ(FindThirdCommaIndex("a,b,c,d"), 5);
}

TEST(FindThirdCommaIndex, ThirdCommaIsLastChar)
{
    EXPECT_EQ(FindThirdCommaIndex("a,b,c,"), 5);
}

TEST(FindThirdCommaIndex, MoreThanThreeCommasReturnsThird)
{
    EXPECT_EQ(FindThirdCommaIndex("a,b,c,d,e,f"), 5);
}

TEST(FindThirdCommaIndex, OnlyCommas)
{
    EXPECT_EQ(FindThirdCommaIndex(",,,"), 2);
}

TEST(FindThirdCommaIndex, StartsWithCommas)
{
    EXPECT_EQ(FindThirdCommaIndex(",,,abc"), 2);
}

TEST(FindThirdCommaIndex, TwoCommasReturnsMinusOne)
{
    EXPECT_EQ(FindThirdCommaIndex("a,b,c"), -1);
}

TEST(FindThirdCommaIndex, OneCommaReturnsMinusOne)
{
    EXPECT_EQ(FindThirdCommaIndex("abc,def"), -1);
}

TEST(FindThirdCommaIndex, NoCommas)
{
    EXPECT_EQ(FindThirdCommaIndex("hello world"), -1);
}

TEST(FindThirdCommaIndex, EmptyString)
{
    EXPECT_EQ(FindThirdCommaIndex(""), -1);
}

// ---------- ChangeCommasToStars ----------

TEST(ChangeCommasToStars, SingleComma)
{
    char buf[100] = "a,b";
    char *res = ChangeCommasToStars(buf);
    EXPECT_STREQ(res, "a**b");
    EXPECT_STREQ(buf, "a**b"); // результат також записується у параметр
    delete[] res;
}

TEST(ChangeCommasToStars, MultipleCommas)
{
    char buf[100] = "a,b,c,d";
    char *res = ChangeCommasToStars(buf);
    EXPECT_STREQ(res, "a**b**c**d");
    EXPECT_STREQ(buf, "a**b**c**d");
    delete[] res;
}

TEST(ChangeCommasToStars, NoCommas)
{
    char buf[100] = "hello world";
    char *res = ChangeCommasToStars(buf);
    EXPECT_STREQ(res, "hello world");
    EXPECT_STREQ(buf, "hello world");
    delete[] res;
}

TEST(ChangeCommasToStars, OnlyCommas)
{
    char buf[100] = ",,";
    char *res = ChangeCommasToStars(buf);
    EXPECT_STREQ(res, "****");
    delete[] res;
}

TEST(ChangeCommasToStars, CommaAtStartAndEnd)
{
    char buf[100] = ",abc,";
    char *res = ChangeCommasToStars(buf);
    EXPECT_STREQ(res, "**abc**");
    delete[] res;
}

TEST(ChangeCommasToStars, EmptyString)
{
    char buf[100] = "";
    char *res = ChangeCommasToStars(buf);
    EXPECT_STREQ(res, "");
    EXPECT_STREQ(buf, "");
    delete[] res;
}

TEST(ChangeCommasToStars, ResultLengthGrowsByCommaCount)
{
    char buf[100] = "1,2,3,4,5";
    size_t before = strlen(buf);
    char *res = ChangeCommasToStars(buf);
    EXPECT_EQ(strlen(res), before + 4); // 4 коми -> +4 символи
    delete[] res;
}
