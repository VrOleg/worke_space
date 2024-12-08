

#include <iostream>
#include <mutex>

namespace ilrd143
{
    class Bank
    {
    public:
        Bank(const Bank &other_) = delete;
        static Bank *GetInstance();

    private:
        Bank() {};
        
        static Bank *m_bankPtr;
        static std::mutex m_mtx;

    };

    Bank* Bank::GetInstance()
    {
        if(nullptr == m_bankPtr)
        {
            std::lock_guard<std::mutex> lock(m_mtx);
            if(nullptr == m_bankPtr)
            {
                m_bankPtr = new Bank();
            }
        }
        return m_bankPtr;
    }
}