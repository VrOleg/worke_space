
// create function that get sorted array shift N times, and num
// if num in array return index else return -1
// complexity log(n)

// 1 2 3 4 5 6 7 8 9
// 6 7 8 9 1 2 3 4 5

// sudu
//  binaray serch:
//       check the first element
//       check if midel element
//       use tow indexes (left = 0, right = size/2)
//       if num > arr[left] and num > arr[right] and arr[left] < arr[right] =>GoRight first = midel, midel = size/4 + midel
//       if num < arr[left] and num > arr[right] and arr[left] > arr[right] =>GoRight

//      if num > arr[left] and num > arr[right] and arr[left] > arr[right] =>GoLeft midel = midel - size/4
//      if num > arr[left] and num < arr[right] and arr[left] < arr[right] =>GoLeft

// GoRight:
//      diff = right - left
//      left = right
//      right = right + (diff / 2)

// GoLeft:
//      right =(right / 2)

#include <iostream>

size_t FindNumInShiftSortedArray(int *arr, size_t size, int num);
void PrintArray(int *arr, size_t size);

int main(int argv, char *args[])
{
    int arr[] = {6, 7, 8, 9, 1, 2, 3, 4, 5};
    // int arr[] = {6, 7, 8, 9, 1, 3, 4, 5};

    size_t size = 8;
    int num = 2;

    int result = FindNumInShiftSortedArray(arr, size, num);

    std::cout << "in array : ";
    PrintArray(arr, size);
    std::cout << " the number: " << num << " at index :" << result << std::endl;

    return (0);
}

size_t FindNumInShiftSortedArray(int *arr, size_t size, int num)
{
    size_t left = 0;
    size_t right = size - 2;
    size_t mid;

    while (left < right)
    {
        mid = left + (right - left) / 2;

        if (num == arr[mid])
        {
            return (mid);
        }
        if (arr[left] < arr[mid])
        {
            // check in Left half
            if (num > arr[left] && num < arr[mid])
            {
                // Search left half
                right = mid - 1;
            }
            else
            {
                // Search right half
                left = mid + 1;
            }
        }
        else
        {
            // check in Left half
            if (num < arr[left] && num > arr[right])
            {
                // Search right half
                left = mid + 1;
            }
            else
            {
                // Search left half
                right = mid - 1;
            }
        }
    }

    return (-1);
}

void PrintArray(int *arr, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::cout << arr[i] << ", ";
    }
}