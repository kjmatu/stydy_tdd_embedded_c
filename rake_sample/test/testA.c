#include "unity.h"
#include "A.h"
#include <stdio.h>


void putcharSpy(int c) { (void)putchar(c);}


void setUp(void)
{
}

void tearDown(void)
{
}

void testA(void)
{

	TEST_ASSERT_EQUAL(3, funcA(1,2));
}
