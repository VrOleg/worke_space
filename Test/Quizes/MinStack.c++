

#include <iostream>
#include <stack>

using namespace std;



namespace ilrd143
{

    class MinStack
    {
    public:
        void Push(int data);
        void Pop();
        int Top();
        int GetMin();
        bool IsEmpty();
        int Size();

    private:
        stack<int> m_data;
        stack<int> m_min;
    };

    void MinStack::Push(int data)
    {
        if (!m_data.empty() && m_min.top() < data)
        {
            m_min.push(m_min.top());
        }
        else
        {
            m_min.push(data);
        }
        m_data.push(data);
    }

    void MinStack::Pop()
    {
        m_data.pop();
        m_min.pop();
    }

    int MinStack::Top()
    {
        return (m_data.top());
    }

    int MinStack::GetMin()
    {
        return (m_min.top());
    }

    bool MinStack::IsEmpty()
    {
        return (m_data.empty());
    }

    int MinStack::Size()
    {
        return (m_data.size());
    }
}

void PrintTestResult(string message, bool status, string info = "");
void Init(ilrd143::MinStack &stack);
void TestPop(ilrd143::MinStack &stack);
void TestPush(ilrd143::MinStack &stack);
void TestSize(ilrd143::MinStack &stack);
void TestGetMin(ilrd143::MinStack &stack);
void TestTop(ilrd143::MinStack &stack);
void TestIsEmpty(ilrd143::MinStack &stack);

int main(int argc, char *argv[])
{
    ilrd143::MinStack minStack;

    TestIsEmpty(minStack);
    TestTop(minStack);
    TestGetMin(minStack);
    TestSize(minStack);
    TestPush(minStack);
    TestPop(minStack);

    return (0);
}

void TestIsEmpty(ilrd143::MinStack &stack)
{
    bool test = true;

    if (test == stack.IsEmpty())
    {
        Init(stack);
        if (test != stack.IsEmpty())
        {
            PrintTestResult("Test IsEmpty", 0);
        }
        else
        {
            PrintTestResult("Test IsEmpty", 1);
        }
    }
    else
    {
        PrintTestResult("Test IsEmpty", 2, "Stack is not empty at beggining");
    }
}

void TestTop(ilrd143::MinStack &stack)
{
    if (8 == stack.Top())
    {
        PrintTestResult("Test Top", 0);
    }
    else
    {
        PrintTestResult("Test Top", 1, "expect 8 but get " + to_string(stack.Top()));
    }
}

void TestGetMin(ilrd143::MinStack &stack)
{
    if (1 == stack.GetMin())
    {
        PrintTestResult("Test GetMin", 0);
    }
    else
    {
        PrintTestResult("Test GetMin", 1, "expect 1 but get " + to_string(stack.GetMin()));
    }
}

void TestSize(ilrd143::MinStack &stack)
{
    if (9 == stack.Size())
    {
        PrintTestResult("Test Size", 0);
    }
    else
    {
        PrintTestResult("Test Size", 1, "expect 9 but get " + to_string(stack.Size()));
    }
}

void TestPush(ilrd143::MinStack &stack)
{
    int size = stack.Size();

    stack.Push(999);

    if (size + 1 == stack.Size() && 999 == stack.Top())
    {
        PrintTestResult("Test Push", 0);
    }
    else
    {
        PrintTestResult("Test Push", 1);
    }
}

void TestPop(ilrd143::MinStack &stack)
{
    int top = stack.Top();
    int size = stack.Size();
    stack.Pop();

    if (size - 1 == stack.Size())
    {
        PrintTestResult("Test Pop", 0);
    }
    else
    {
        PrintTestResult("Test Pop", 1);
    }
}

void Init(ilrd143::MinStack &stack)
{
    stack.Push(4);
    stack.Push(7);
    stack.Push(8);
    stack.Push(59);
    stack.Push(1);
    stack.Push(63);
    stack.Push(2);
    stack.Push(4);
    stack.Push(8);
}

void PrintTestResult(string message, bool status, string info)
{
    string testStatus[] = {"SUCCESS", "FAILED"};

    if(status != 0)
    {
        cout << message << " : " << testStatus[1] << " status: " << status << " " << info << endl;
    }
    else
    {
        cout << message << " : " << testStatus[0] << " " << info << endl;
    }

}
