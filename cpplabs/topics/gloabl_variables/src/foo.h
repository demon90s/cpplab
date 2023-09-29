#pragma once

#include <string>

// 错误的定义全局变量的方法，如果被多个 cpp 文件 include，将会导致 Link error。
// 如提示：找到一个或多个多重定义的符号
//std::string foo = "foo";

// 错误做法2：可以通过编译，但会产生多个副本
// 测试输出如：
// a_get_foo_info: 00007FF756BF3440
// b_get_foo_info: 00007FF756BF3470
//static std::string foo = "foo";

// 正确的传统做法，使用 extern 声明，并在一个 cpp 文件中(比如 foo.cpp)，做出定义
// 测试输出如：
// a_get_foo_info: 00007FF7CFA63430
// b_get_foo_info: 00007FF7CFA63430
//extern std::string foo;

// 正确的简单做法，使用 inline ，则只有一份副本
// 但需要开启 c++17
// 测试输出如：
// a_get_foo_info: 00007FF762B53440
// b_get_foo_info: 00007FF762B53440
inline std::string foo = "foo";
