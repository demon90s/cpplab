#pragma once

#include <string>

// ����Ķ���ȫ�ֱ����ķ������������� cpp �ļ� include�����ᵼ�� Link error��
// ����ʾ���ҵ�һ���������ض���ķ���
//std::string foo = "foo";

// ��������2������ͨ�����룬��������������
// ��������磺
// a_get_foo_info: 00007FF756BF3440
// b_get_foo_info: 00007FF756BF3470
//static std::string foo = "foo";

// ��ȷ�Ĵ�ͳ������ʹ�� extern ����������һ�� cpp �ļ���(���� foo.cpp)����������
// ��������磺
// a_get_foo_info: 00007FF7CFA63430
// b_get_foo_info: 00007FF7CFA63430
//extern std::string foo;

// ��ȷ�ļ�������ʹ�� inline ����ֻ��һ�ݸ���
// ����Ҫ���� c++17
// ��������磺
// a_get_foo_info: 00007FF762B53440
// b_get_foo_info: 00007FF762B53440
inline std::string foo = "foo";
