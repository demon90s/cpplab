#include <iostream>
#include <type_traits>

/*
    编译期检查一个类型是否是平凡类型
    此平凡类型的实例可安全使用 memcpy 来进行操作
*/

// 平凡
struct A
{
    int m;
};

// 平凡
class B
{
    void Reset() {}
    int *m;
};

// 非平凡
struct C
{
    C() {}
    int a;
};

// 平凡
struct D
{
    D() = default;

    int a;
};

int main()
{
    std::cout << std::boolalpha;

    std::cout << std::is_trivial<A>::value << std::endl;    // true
    static_assert(std::is_trivial<A>::value, "A must be a trivial class");  // 编译时即可检查

    std::cout << std::is_trivial<B>::value << std::endl;    // true

    std::cout << std::is_trivial<C>::value << std::endl;    // false

    std::cout << std::is_trivial<D>::value << std::endl;    // true
}