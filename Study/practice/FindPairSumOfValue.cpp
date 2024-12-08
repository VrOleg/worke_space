
#include <iostream>
#include <list>

#include<unordered_map>

void PrintPairsThatSumEquelToValue(std::list<int>& numbers, int value);

int main()
{
    std::list<int> l1 = {4, 2, 1, 7, 3, 6, 4, 5};


    PrintPairsThatSumEquelToValue(l1, 8);
    
    return (0);
}

void PrintPairsThatSumEquelToValue(std::list<int>& numbers, int value)
{
    std::unordered_map<int,int> lut;

    // for(auto it = numbers.begin(); it != numbers.end(); ++it)
    // {
    //     if(lut.find(*it) != lut.end())
    //     {
    //         std::cout<< *it << " + " << lut[*it] << ", ";
    //     }
    //     else
    //     {
    //         lut[value - *it] = *it;
    //     }
    // }

     for(int number : numbers)
    {
        if(lut.end() != lut.find(number))
        {
            std::cout<< number << " + " << lut[number] << ", ";
        }
        else
        {
            lut[value - number] = number;
        }
    }


    std::cout << std::endl;
}