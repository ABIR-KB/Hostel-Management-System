#include "data_entry.c"
#include "hostel.h"

void test_login_failure()
{    
    printf(" \n\nEnter wrong username/password for failure.");

    int actual = userLogin();

    int expected = 0;

    printf("\nexpected: %d actual: %d, success:%d\n",
        expected, actual, actual == expected);
}
int main() 
{
    test_login_failure();
    return 0;
}