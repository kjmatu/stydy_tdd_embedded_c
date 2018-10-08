#include "unity_fixture.h"
#include <stdio.h>
#include <memory.h>

TEST_GROUP(sprintf);

static char output[100];
static const char * expected;

TEST_SETUP(sprintf)
{
    memset(output, 0xaa, sizeof output);
    expected = "";
}

TEST_TEAR_DOWN(sprintf)
{
}

static void expect(const char * s)
{
    expected = s;
}

static void given(int charsWritten)
{
    TEST_ASSERT_EQUAL(strlen(expected), charsWritten);
    TEST_ASSERT_EQUAL_STRING(expected, output);
    TEST_ASSERT_BYTES_EQUAL(0xaa, output[strlen(expected) + 1]);
}

TEST(sprintf, NoFormatOperations)
{
    expect("hey");
    given(sprintf(output, "hey"));
}

TEST(sprintf, InsertString)
{
    expect("Hello World\n");
    given(sprintf(output, "Hello %s\n", "World"));
}

TEST(sprintf, InsertNumber)
{
    expect("10\n");
    given(sprintf(output, "%d\n", 10));
}

TEST(sprintf, OutputSmallCaseHex)
{
    expect("a\n");
    given(sprintf(output, "%x\n", 10));
}

TEST(sprintf, OutputBigCaseHex)
{
    expect("A\n");
    given(sprintf(output, "%X\n", 10));
}
