
#include <iostream>

int main(int argv, char *argvc[])
{

    return (0);
}

int FibonachiNthValue(int n)
{
    int first = 1;
    int second = 1;
    int sum;

    if(n < 2)
    {
        return (n);
    }

    for (size_t i = 2; i <= n; i++)
    {
        sum = first + second;
        first = second;
        second = sum;
    }
    return second;
}