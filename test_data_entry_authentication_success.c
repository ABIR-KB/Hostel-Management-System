#include "data_entry.c"
#include "hostel.h"

void test_login_success()
{
    printf("\n\n Enter Your Registered Username and Password:");

    int actual = userLogin();

    int expected = 1;

    printf("\nexpected: %d actual: %d, success:%d\n",
        expected, actual, actual == expected);
}

int main() {
    test_login_success();
    return 0;
}