#include "threadpool.h"

ThreadPool::ThreadPool(size_t num_threads)
{
    for (size_t i = 0; i < num_threads; ++i) {
        threads.emplace_back([this] {
            while (true) {
                std::function<void()> task;
                {
                    std::unique_lock<std::mutex> lock(mutex);
                    cv.wait(lock, [this] {return !tasks.empty() || stop; });
                    if (stop && tasks.empty()) {
                        return;
                    }
                    task = std::move(tasks.front());
                    tasks.pop();
                }
                task();
            }
        });
    }
}

ThreadPool::~ThreadPool()
{
    {
        std::unique_lock<std::mutex> lock(mutex);
        stop= true;
    }
    cv.notify_all();
    for (auto& thread : threads)
        thread.join();
}
template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(mutex);
        if(stop)
            throw std::runtime_error("поставить в очередь остановленный пул потоков");
        tasks.emplace([task](){ (*task)(); });
    }
    cv.notify_one();
    return res;
}
void ThreadPool::handleExceptions(std::__exception_ptr::exception_ptr ptr)
{
    if (ptr) {
        try {
            std::rethrow_exception(ptr);
        } catch(const std::exception& e) {
            std::cerr << "Exception in thread: " << e.what() << '\n';
        }
    }
}
