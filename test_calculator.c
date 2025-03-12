#include "unity.h"
#include "calculator.h"

//Optional but needs to be defined(runs before each test)
void setUp(void) {
    //Initialize resources for tests here
}

//Runs after each test
void tearDown(void) {
    //Clean up resources after each test
}

void test_add_positive_numbers(void) {
    TEST_ASSERT_EQUAL(5, add(2, 3)); //We expect 2 + 3 to be 5
}

void test_add_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(1, add(5, -4)); //We expect 5 + -4 = 1
}

void test_add_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-7, add(-3, -4)); //-3 + -4 = -7
}

//NOTE: we can do multiple validations in one test
void test_add_zero(void) {
    TEST_ASSERT_EQUAL(10, add(10, 0));
    TEST_ASSERT_EQUAL(0, add(0, 0));
}

void test_add_overflow(void) {
    int result = add(INT_MAX, 1);   //Should wrap around
    TEST_ASSERT_TRUE(result < 0);   //Checks if overflow
}

void test_add_underflow(void) {
    int result = add(INT_MIN, -1);
    TEST_ASSERT_TRUE(result > 0);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);    //Run our test function
    RUN_TEST(test_add_positive_and_negative_numbers);;
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);
    return UNITY_END();
}