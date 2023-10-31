#include <iostream>
#include <string>

int main()
{
    std::string s;
    std::cin >> s;

    // 当键入回车后，读取字符串存入s，但会保留回车在缓存
    std::cout << s;

    char character;
    std::cin.read(&character, 1); // 缓存内有数据，就直接读取了
    std::cout << (int)character; // 这句代码将输出10，因为它是换行符的ASC码

    return 0;
}
