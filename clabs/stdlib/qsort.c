/*
    qsort
    void qsort(ptr, count, size, comp)

    对 ptr 所指向的数组进行升序排序，数组包含 count 个大小为 size 的元素，按照 comp 所指向的函数比较元素。

    comp 定义为：int (*comp)(const void* p1, const void* p2);

    RULES:
    p1排在p2前头 应该返回负数
    p1排在p2后头 应该返回正数
    如果两个数相等（返回0），它们排序后的结果是未指定的。

    NOTES:
    1. 从大到小逆序：return p2 - p1
    2. 从小到大逆序：return p1 - p2
*/

#include <stdio.h>
#include <stdlib.h>

struct Foo {
    char *name;
    int power;
};

int compare_foo(const void* p1, const void* p2)
{
    //printf("[COMPARE] p1[%d] p2[%d]\n", ((struct Foo*)p1)->power, ((struct Foo*)p2)->power);
    //return ((struct Foo*)p1)->power - ((struct Foo*)p2)->power;

    int power_diff = ((struct Foo*)p1)->power - ((struct Foo*)p2)->power;
    if (power_diff < 0)
    {
        return -1;
    }
    else if (power_diff > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    struct Foo foo_list[5] = {
        {"Foo", 100},
        {"Goo", 87},
        {"Drre", 76},
        {"Bar", 99},
        {"Wens", 29}
    };
    int i;

    printf("before sort:");
    for (i = 0; i < 5; i++) {
        printf(" {%s %d}", foo_list[i].name, foo_list[i].power);
    }
    printf("\n");

    qsort(foo_list, 5, sizeof(struct Foo), compare_foo);

    printf("after sort:");
    for (i = 0; i < 5; i++) {
        printf(" {%s %d}", foo_list[i].name, foo_list[i].power);
    }
    printf("\n");

    return 0;
}
