
// waitebl
// threadSafty
// sirclar buffer
// include EnQueue() and DeQueue()


#include <iostream>
#include <mutex>

template<typename T>
class Buffer
{
public:
    Buffer(size_t capasity);
    ~Buffer();
    void EnQueue(const T data);
    T DeQueue();
private:
    T m_buff[];
    size_t m_size;
    std::mutex m_enqueue_mutex;
    std::mutex m_dequeue_mutex;
};

