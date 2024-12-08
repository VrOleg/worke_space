
#include <iostream>
#include <vector>

int heightChecker(std::vector<int> &heights);
void Sort(std::vector<int> &arr);

int Partition(std::vector<int> &arr, int low, int high);
void QuickSort(std::vector<int> &arr, int low, int high);
void Swape(int &a, int &b);

bool rotateString(std::string s, std::string goal);


std::string addBinary(std::string a, std::string b);

int main()
{
    // std::vector<int> test = {1, 1, 4, 2, 1, 3};

    std::string s = "1010";
    std::string goal = "1011";


    std::cout << addBinary(s, goal) << std::endl;

    return (0);
}

int heightChecker(std::vector<int> &heights)
{

    int size = heights.size();
    int result = 0;
    std::vector<int> temp = heights;

    QuickSort(temp, 0, temp.size() - 1);

    for (int i = 0; i < size; i++)
    {
        if (heights[i] != temp[i])
        {
            result++;
        }
    }
    return result;
}

int Partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            Swape(arr[i], arr[j]);
        }
    }
    Swape(arr[i + 1], arr[high]);
    return (i + 1);
}

void QuickSort(std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = Partition(arr, low, high);

        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void Swape(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

bool rotateString(std::string s, std::string goal)
{

    if (s.length() != goal.length())
    {
        return false;
    }

    int len = s.length();
    int i = 0;
    int t = 0;

    for (t = 0; t < len; t++)
    {
        if (s[i] == goal[t])
        {
            ++t;
            for (i = 1; i < len; i++)
            {
                if (s[i] != goal[t % len])
                {
                    t -= i;
                    i = 0;

                    if (len == t)
                    {
                        return false;
                    }
                    break;
                }
                t++;
            }
            if (i == len)
            {
                return (true);
            }
        }
    }
    return (false);
}

std::string addBinary(std::string a, std::string b)
{
    std::string result = "";
    bool res = false;
    int runner_a = a.length() - 1;
    int runner_b = b.length() - 1;

    while (0 <= runner_b && 0 <= runner_a)
    {
        if (res)
        {
            if (a[runner_a] != b[runner_b])
            {
                result.insert(result.begin(), '0');
            }
            else
            {
                result.insert(result.begin(), '1');

                if (a[runner_a] == '0')
                {
                    res = false;
                }
            }
        }
        else
        {
            if (a[runner_a] != b[runner_b])
            {
                result.insert(result.begin(), '1');
            }
            else
            {
                result.insert(result.begin(), '0');

                if (a[runner_a] == '1')
                {
                    res = true;
                }
            }
        }
        runner_a--;
        runner_b--;
    }

    while (0 <= runner_a)
    {
        if (res)
        {
            if ('1' == a[runner_a])
            {
                result.insert(result.begin(), '0');
            }
            else
            {
                res = false;
                result.insert(result.begin(), '1');
            }
        }
        else
        {
            result.insert(result.begin(), a[runner_a]);
        }
        
        runner_a--;
    }

    while (0 <= runner_b)
    {
        if (res)
        {
            if ('1' == b[runner_b])
            {
                result.insert(result.begin(), '0');
            }
            else
            {
                res = false;
                result.insert(result.begin(), '1');
            }
        }
        else
        {
            result.insert(result.begin(), b[runner_b]);
        }
        
        runner_b--;
    }

    if(res)
    {
        result.insert(result.begin(), '1');
    }

    return (result);
}