#include <memory>
#include <iostream>

// 当一个类的对象由 shared_ptr 管理，若要从成员函数中返回此对象的 shared_ptr 时
// 我们应当使用 enable_shared_from_this 类模板

class BadPractice
{
public:
    BadPractice()
    {
        std::cout << "BadPractice constructed" << std::endl;
    }
    ~BadPractice()
    {
        std::cout << "BadPractice destructed" << std::endl;
    }

    std::shared_ptr<BadPractice> GetSharedPtrOfThis()
    {
        return std::shared_ptr<BadPractice>(this);
    }
};
void badpratice_example()
{
    auto badpractice = std::make_shared<BadPractice>();
    auto badpractice2 = badpractice->GetSharedPtrOfThis(); //badpractice2 use count is 1, so double free

    // double free error
}

class BestPractice : public std::enable_shared_from_this<BestPractice>
{
public:
    static std::shared_ptr<BestPractice> Create()
    {
        return std::make_shared<BestPractice>();
    }

    std::shared_ptr<BestPractice> GetSharedPtrFromThis()
    {
        return shared_from_this();
    }
};
void bestpractice_example()
{
    auto bestpractice = BestPractice::Create();
    std::cout << "use count is: " << bestpractice.use_count() << std::endl;

    auto bestpractice2 = bestpractice->GetSharedPtrFromThis();
    // auto bestpractice2 = bestpractice; // also ok, normal use
    std::cout << "use count is: " << bestpractice2.use_count() << std::endl; // 2, ok
}

int main(int argc, char *argv[])
{
    //badpratice_example();
    bestpractice_example();

    return 0;
}
