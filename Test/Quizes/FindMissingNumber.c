

#include <stdio.h>

int FindMissingNumber(int *arr, size_t size);

int main(int argv, char *argvc[])
{
    int arr[] = {1,2,3,5,6,7,8,9};

    printf("missing number is %d\n", FindMissingNumber(arr, 9));
    return (0);
}

int FindMissingNumber(int *arr, size_t size)
{
    int i = 0;
    size_t sumValues = 0;
    size_t sumindex = 0;
    for(i = 0; i < size - 1; ++i)
    {
        sumValues += arr[i];
        sumindex += i + 1;
    }
    return ( (sumindex + i + 1) - sumValues);
}