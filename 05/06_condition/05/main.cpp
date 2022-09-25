#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <condition_variable>
#include <iterator>

template <class T>
class MTQueue {
    std::condition_variable m_cv;
    std::mutex m_mtx;
    std::vector<T> m_arr;

public:
    T pop() {
        std::unique_lock<std::mutex> lck(m_mtx);
        m_cv.wait(lck, [this] { return !m_arr.empty(); });
        T ret = std::move(m_arr.back());
        m_arr.pop_back();
        return ret;
    }

    auto pop_hold() {
        std::unique_lock<std::mutex> lck(m_mtx);
        m_cv.wait(lck, [this] { return !m_arr.empty(); });
        T ret = std::move(m_arr.back());
        m_arr.pop_back();
        return std::pair<T, std::unique_lock<std::mutex>>(std::move(ret), std::move(lck));
    }

    void push(T val) {
        std::unique_lock<std::mutex> lck(m_mtx);
        m_arr.push_back(std::move(val));
        m_cv.notify_one();
    }

    void push_many(std::initializer_list<T> vals) {
        // for (auto& item: vals)
        // {
        //     m_arr.push_back(item);
        // }
        // std::copy(vals.begin(), vals.end(), back_inserter(m_arr));
        // std::unique_lock<std::mutex> lck(m_mtx);

        std::copy(
                 std::make_move_iterator(vals.begin()),
                 std::make_move_iterator(vals.end()),
                 std::back_insert_iterator<std::vector<T> >(m_arr));
        // 写法一样，但是下面的编译错误
        // std::copy(
        //          std::move_iterator<std::initializer_list<T>::iterator >(vals.begin()),
        //          std::move_iterator<std::initializer_list<T>::iterator >(vals.end()),
        //          std::back_insert_iterator<std::vector<T> >(m_arr));
        m_cv.notify_all();
    }
};

int main() {
    MTQueue<int> foods;

    std::thread t1([&] {
        for (int i = 0; i < 2; i++) {
            auto food = foods.pop();
            std::cout << "t1 got food:" << food << std::endl;
        }
    });

    std::thread t2([&] {
        for (int i = 0; i < 2; i++) {
            auto food = foods.pop();
            std::cout << "t2 got food:" << food << std::endl;
        }
    });

    foods.push(42);
    foods.push(233);
    foods.push_many({666, 4399});

    t1.join();
    t2.join();

    return 0;
}
