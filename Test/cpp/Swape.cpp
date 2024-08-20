
#include <iostream>

void PrintArray(int *arr, size_t size);
void Swape(int *a, int *b);

int main()
{
    int arr[] = { 1,2,3,4,5,6,778,8};

    PrintArray(arr, 8);
    Swape(&arr[0], &arr[7]);
    PrintArray(arr, 8);

    return (0);
}

void Swape(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintArray(int *arr, size_t size)
{
    for(int i = 0; i < size - 1; ++i)
    {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[size -1] << std::endl;
}