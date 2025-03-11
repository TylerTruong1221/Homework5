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

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_add_positive_numbers);    //Run our test function
    return UNITY_END();
}