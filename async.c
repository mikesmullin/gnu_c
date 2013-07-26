#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef void (*call_back) (S32, S32);

void test_call_back(S32 a, S32 b)
{
    printf("In call back function, a:%d \t b:%d \n", a, b);
}

void call_callback_func(call_back back)
{
    S32 a = 5;
    S32 b = 7;

    back(a, b);
}

void main(S32 argc, S8 *argv[])
{
    S32 ret = SUCCESS;

    call_back back;

    back = test_call_back;

    call_callback_func(back);

    return ret;
}
