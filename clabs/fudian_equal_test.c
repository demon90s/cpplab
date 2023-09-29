#include <assert.h>
#include <stdio.h>
#include <math.h>

void test1()
{
    double a = 1 / 3.0;
    double b = 1 - 2 / 3.0;

    // 输出的结果是一样的
    printf("a: %lf\n", a);
    printf("b: %lf\n", b);

    assert(a == b); // 但不能通过验证，[浮点数在运算过程中会产生误差，因为计算机无法精确表示无限循环小数]

    printf("test1 PASS\n");
}

// 返回1表示相等，返回0表示不等
int is_double_number_equal(double a, double b)
{
    // 绝对值之差的绝对值小于某个阙值可以认为相等
    if (fabs(a - b) < 0.0000001)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void test2()
{
    double a = 1 / 3.0;
    double b = 1 - 2 / 3.0;

    // 输出的结果是一样的
    printf("a: %lf\n", a);
    printf("b: %lf\n", b);

    assert(is_double_number_equal(a, b)); // 可以通过验证

    printf("test2 PASS\n");
}

int main()
{
    //test1();
    test2();
}
