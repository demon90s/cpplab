#include <atomic>
#include <iostream>
#include <thread>
#include <cassert>

// std::atomic 类型的变量可以在多个线程之间进行读写操作，而不需要任何同步机制的保证。
// 但是需要注意，使用 std::atomic 时需要保证线程安全，并避免出现数据竞争等问题。

void simple_test_atomic()
{
    std::atomic<int> cnt(0);

    //auto f = [&cnt]() { cnt++; };
    auto f = [&cnt]() { cnt.fetch_add(1); }; // 最好使用这个方法，这是 chatGPT 建议的，说具有跨平台安全性

    std::thread t1(f), t2(f), t3(f);

    // ok, 不会有数据竞争问题

    t1.join();
    t2.join();
    t3.join();

    assert(cnt == 3);
}

int main()
{
    simple_test_atomic();
}