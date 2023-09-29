#include <string>
#include <iostream>

int main(int argc, char *argv[])
{
    std::hash<std::string> string_hasher;
    size_t result = string_hasher("hello");

    std::cout << result << std::endl;

    return 0;
}
