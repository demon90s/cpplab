#include <iostream>
#include <string>
#include <cassert>
#include <cstdio>

void test_char()
{
    // 定义一个宽字符变量
    wchar_t c = L'H';
    std::cout << c << std::endl; // 输出72 因为调用的是 int 参数版本的输出
    printf("%wc\n", c); // 输出 H Linux 下用 lc
    std::cout << sizeof(c) << std::endl; // 2 windodws
}

void test_str()
{
    // 宽字符字符串
    const wchar_t *str = L"Hello";
    std::cout << str << std::endl; // 输出 00007FF7ECC2E3A0
    printf("%ws\n", str); // 输出 Hello Linux 下用 ls
    std::cout << wcslen(str) << std::endl; // 5 windows

    // 传递给 wstring
    std::wstring wstr = str;
    printf("%ws\n", wstr.c_str()); // Hello Linux 下用 ls
    printf("%d\n", (int)wstr.length()); // 5 windows

    // 对比方法
    assert(wstr.compare(L"Hello") == 0);
    assert(wstr.compare(0, 2, L"He") == 0); // 前两个字符是 He

    printf("=====PASS=====\n");
}

int main()
{
    test_char();
    test_str();
}