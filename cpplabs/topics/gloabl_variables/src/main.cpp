#include <iostream>

void a_get_foo_info();
void b_get_foo_info();

int main()
{
	a_get_foo_info();
	b_get_foo_info();

	std::cin.get();
}