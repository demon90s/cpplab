/*
    #include <type_traits>

    所谓 type_trait ，即提供一种用来处理 type 属性的办法。

    type_traits 提供了许多类型判断工具（ type predicate ），可以产出一个 std::true_type 或 std::false_type 。它们都是一个 intergral_constant 。

    is_pointer<T> 用来检测T是否是一个 pointer type ，若是，返回一个类型为 true_type 的值，否则返回一个类型为 false_type 的值。
    true_type 和 false_value 的 value 成员分别是 true 和 false 。

    is_array<T> 检测是否是一个数组类型。
*/

#include <iostream>
#include <vector>
#include <type_traits>

template<typename T>
void foo(const T& val)
{
    if (std::is_pointer<T>::value) {
        std::cout << "foo() called for a pointer" << std::endl;
    }
    else {
        std::cout << "foo() called for a value" << std::endl;
    }
}

void test_foo()
{
    int n = 42;
    foo(n);
    foo(&n);
}

void test_is_same()
{
    std::cout << std::boolalpha;
    std::cout << std::is_same<int, long>() << std::endl;
}

void test_is_integral()
{
    std::cout << std::boolalpha;

    std::cout << std::is_integral<char>::value << '\n'; // true
    std::cout << std::is_integral<int>::value << '\n'; // true
    std::cout << std::is_integral<float>::value << '\n'; // false
}

void test_is_float_point()
{
    std::cout << std::boolalpha;

    std::cout << std::is_floating_point<float>::value << '\n';  // true
    std::cout << std::is_floating_point<double>::value << '\n';  // true
    std::cout << std::is_floating_point<int>::value << '\n';  // false
    std::cout << std::is_floating_point<std::string>::value << '\n';    // false
}
 
void test_is_array() 
{
    class A {};

    std::cout << std::boolalpha;
    std::cout << std::is_array<A>::value << '\n';       // false
    std::cout << std::is_array<A[]>::value << '\n';     // true
    std::cout << std::is_array<A[5]>::value << '\n';    // true
}

// 下面的类型都是非标准布局
class Foo { virtual ~Foo() {} };
class A {
public:
    int m;
private:
    int n;
};

void test_is_standard_layout()
{
    std::cout << std::boolalpha;
    std::cout << std::is_standard_layout<int>::value << '\n'; // true
    std::cout << std::is_standard_layout<double>::value << '\n'; // true

    typedef double* PointerToDouble;
    std::cout << std::is_standard_layout<PointerToDouble>::value << '\n'; // true

    std::cout << std::is_standard_layout<std::vector<int>>::value << '\n'; // true

    std::cout << std::is_standard_layout<Foo>::value << '\n'; // false, because of the virtual function
    std::cout << std::is_standard_layout<A>::value << '\n'; // false
}

int main()
{
    //test_foo();
    //test_is_same();
    //test_is_integral();
    //test_is_float_point();
    //test_is_array();
    test_is_standard_layout();

    return 0;
}