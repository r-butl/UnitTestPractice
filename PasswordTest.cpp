/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, two_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZ");
	ASSERT_EQ(2, actual);
}

TEST(PasswordTest, different_case_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zZ");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, skip_repeat_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("zxz");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, spaces_between)
{
	Password my_password;
	int actual = my_password.count_leading_characters("z z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, space_count)
{
	Password my_password;
	int actual = my_password.count_leading_characters("   x");
	ASSERT_EQ(3, actual);
}

TEST(PasswordTest, empty_string)
{
	Password my_password;
	int actual = my_password.count_leading_characters("");
	ASSERT_EQ(0, actual);
}

TEST(PasswordTest, slashes)
{
	Password my_password;
	int actual = my_password.count_leading_characters("\\\\\\\\\\");
	ASSERT_EQ(5, actual);
}

//////////////////////////////////////////////////////////////////////////


TEST(PasswordTest, alllower)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("aslfhdljdakj");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, allupper)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ASKJDAHFKJADUFHBK");
	ASSERT_EQ(false, actual);
}

TEST(PasswordTest, mix)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("AKJhshsjkSKJ");
	ASSERT_EQ(true, actual);
}

TEST(PasswordTest, mixwithspaces)
{
	Password my_password;
	bool actual = my_password.has_mixed_case("ASKJhkjS kjaskj KJH skj ");
	ASSERT_EQ(true, actual);
}