#include <iostream>
#include <filesystem>

void test_path()
{
    namespace fs = std::filesystem;

    fs::path showpath(fs::current_path() / "path.cpp");

    // path 可以直接转换成字符串
    std::cout << "path: " << showpath.c_str() << std::endl;

    std::cout << "is path exist: " << fs::exists(showpath) << std::endl;
    std::cout << "root_path(): " << showpath.root_path() << std::endl;
    std::cout << "filename(): " << showpath.filename() << std::endl;
    std::cout << "stem(): " << showpath.stem() << std::endl; // path
    std::cout << "extension(): " << showpath.extension() << std::endl; // .cpp

    // iterator over all elements of the path
    for (const fs::path &path : showpath)
    {
        std::cout << path << " ";
    }
    std::cout << std::endl;

    // append path
    {
        fs::path p("/root");
        p += "/tmp"; // like string

        p /= "somefile.txt"; // auto add /

        std::cout << p << std::endl;
    }
}

void test_path_swap()
{
    std::filesystem::path path1("/tmp/p1");
    std::filesystem::path path2("/tmp/p2");

    path1.swap(path2);

    std::cout << "path1: " << path1 << std::endl; // /tmp/p2
    std::cout << "path2: " << path2 << std::endl; // /tmp/p1
}

// const string_type& native() const noexcept;
// 返回path的字符串，具体的string_type因本地表示不同而不同
// 比如在Linux中，返回类型就是std::string
// 而在Windows Visual Studio中，返回类型就是std::wstring
void test_path_native()
{
    std::filesystem::path path("C:\\tmp\\ppp");

    auto native = path.native();
    std::cout << native << std::endl;
}

int main()
{
    //test_path();
    // test_path_swap();
    test_path_native();
}
