#include <gtest/gtest.h>

// Підміняємо main з 8.1str.cpp, щоб він не конфліктував з main від GoogleTest
#define main program_main
#include "8.1str.cpp"
#undef main

TEST(MaxLength, EmptyString)
{
    EXPECT_EQ(MaxLength(""), 0u);
}

TEST(MaxLength, SingleWord)
{
    EXPECT_EQ(MaxLength("hello"), 5u);
}

TEST(MaxLength, SeveralWordsPicksLongest)
{
    EXPECT_EQ(MaxLength("hi there world"), 5u);
    EXPECT_EQ(MaxLength("a bb ccc dddd"), 4u);
}

TEST(MaxLength, LongestWordFirst)
{
    EXPECT_EQ(MaxLength("longest a bb"), 7u);
}

TEST(MaxLength, LongestWordLastWithoutTrailingDelimiter)
{
    EXPECT_EQ(MaxLength("a bb longest"), 7u);
}

TEST(MaxLength, PunctuationIsNotPartOfWord)
{
    EXPECT_EQ(MaxLength("Hello, world!"), 5u);
    EXPECT_EQ(MaxLength("(abc) [defgh] {ij}"), 5u);
}

TEST(MaxLength, HyphenSplitsWords)
{
    EXPECT_EQ(MaxLength("well-known"), 5u);
}

TEST(MaxLength, OnlyDelimiters)
{
    EXPECT_EQ(MaxLength("   ,,. ;!?"), 0u);
}

TEST(MaxLength, LeadingAndTrailingDelimiters)
{
    EXPECT_EQ(MaxLength("  ,, abc ,, "), 3u);
}

TEST(MaxLength, TabsAndNewlinesAreDelimiters)
{
    EXPECT_EQ(MaxLength("ab\tcde\nfghij\rk"), 5u);
}

TEST(MaxLength, DigitsCountAsWordCharacters)
{
    EXPECT_EQ(MaxLength("abc12345 x"), 8u);
}

TEST(MaxLength, CyrillicWordsAreCountedInBytes)
{
    // Кирилиця в UTF-8 займає 2 байти на символ, тому "привіт" = 12 байтів.
    // Тест фіксує поточну поведінку (string::size_t рахує байти, а не символи).
    EXPECT_EQ(MaxLength("привіт"), 12u);
}
