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

void test_sub_positive_numbers(void) {
    TEST_ASSERT_EQUAL(3, sub(5, 2));    //Expect 5 - 2 = 3
}

void test_sub_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(4, sub(2, -2));
}

void test_sub_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-4, sub(-5, -1));
}

void test_sub_zero(void) {
    TEST_ASSERT_EQUAL(10, sub(10, 0));
    TEST_ASSERT_EQUAL(0, sub(0, 0));
}

void test_sub_overflow(void) {
    int result = sub(INT_MAX, -1);
    TEST_ASSERT_TRUE(result < 0);
}

void test_sub_underflow(void) {
    int result = sub(INT_MIN, 1);
    TEST_ASSERT_TRUE(result > 0);
}

void test_mult_positive_numbers(void) {
    TEST_ASSERT_EQUAL(8, mult(2, 4));
}

void test_mult_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-6, mult(3, -2));
}

void test_mult_negative_numbers(void) {
    TEST_ASSERT_EQUAL(10, mult(-2, -5));
}

void test_mult_zero(void) {
    TEST_ASSERT_EQUAL(0, mult(10, 0));
    TEST_ASSERT_EQUAL(0, mult(0, 0));
}

void test_mult_overflow(void) {
    int result = mult(INT_MAX, 2);
    TEST_ASSERT_TRUE(result < 0);
}

void test_mult_underflow(void) {
    int result = mult(INT_MIN + 1, 2);
    TEST_ASSERT_TRUE(result > 0);
}

void test_div_positive_numbers(void) {
    TEST_ASSERT_EQUAL(3, div(6, 2));
}

void test_div_positive_and_negative_numbers(void) {
    TEST_ASSERT_EQUAL(-2, div(4, -2));
}

void test_div_negative_numbers(void) {
    TEST_ASSERT_EQUAL(5, div(-5, -1));
}

void test_div_zero(void) {
    TEST_ASSERT_EQUAL(0, div(0, 10));
}

void test_div_fractions(void) {
    TEST_ASSERT_EQUAL(2, div(7, 3));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);    //Run our test function
    RUN_TEST(test_add_positive_and_negative_numbers);;
    RUN_TEST(test_add_negative_numbers);
    RUN_TEST(test_add_zero);
    RUN_TEST(test_add_overflow);
    RUN_TEST(test_add_underflow);
    RUN_TEST(test_sub_positive_numbers);  
    RUN_TEST(test_sub_positive_and_negative_numbers);;
    RUN_TEST(test_sub_negative_numbers);
    RUN_TEST(test_sub_zero);
    RUN_TEST(test_sub_overflow);
    RUN_TEST(test_sub_underflow);
    RUN_TEST(test_mult_positive_numbers);  
    RUN_TEST(test_mult_positive_and_negative_numbers);;
    RUN_TEST(test_mult_negative_numbers);
    RUN_TEST(test_mult_zero);
    RUN_TEST(test_mult_overflow);
    RUN_TEST(test_mult_underflow);
    RUN_TEST(test_div_positive_numbers);
    RUN_TEST(test_div_positive_and_negative_numbers);
    RUN_TEST(test_div_negative_numbers);
    RUN_TEST(test_div_zero);
    RUN_TEST(test_div_fractions);
    return UNITY_END();
}