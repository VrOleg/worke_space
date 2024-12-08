
// You are given an array nums of non-negative integers and an integer k.

// An array is called special if the bitwise OR of all of its elements is at least k.

// Return the length of the shortest special non-empty
// subarray
//  of nums, or return -1 if no special subarray exists.

// sudo

// Initialize a sliding window: Use two pointers (left and right) to define a window that represents a subarray.
//                              Start with both pointers at the beginning of the array.
// Expand and check the OR: Incrementally add elements to the window (by moving right) and compute the bitwise OR
//                          for the current subarray.
// Shrink the window when condition is met: When the OR of the current subarray is at least k, try to shrink the
//                                          window from the left side (left++) while keeping the OR result greater
//                                          than or equal to k. Track the minimum length of such subarrays.
// Update the result: For each valid subarray found (where OR is at least k), update the result to be the minimum
//                    length of all such subarrays.
// Return the result: If no subarray meets the condition, return -1.

#include <iostream>
#include <vector>
#include <climits>

int MinimumSubarrayLength(std::vector<int> &nums, int k);

int CurrentWindowValue(std::vector<int> &nums, int left, int right);

int main()
{
    std::vector<int> test = {1, 2, 32, 21};
    int k = 55;

    std::cout << MinimumSubarrayLength(test, k) << " expected: 3" << std::endl;

    return (0);
}

int MinimumSubarrayLength(std::vector<int> &nums, int k)
{
    size_t size = nums.size();
    int minLength = INT_MAX;
    int currentOr = 0;
    size_t left = 0;
    size_t right = 0;

    for (right = 0; right < size; right++)
    {
        currentOr |= nums[right];

        while (currentOr >= k && left <= right)
        {
            minLength = minLength < (right - left + 1) ? minLength : (right - left + 1);

            ++left;
            currentOr = CurrentWindowValue(nums, left, right);
        }
    }

    return (minLength == INT_MAX) ? -1 : minLength;
}

int CurrentWindowValue(std::vector<int> &nums, int left, int right)
{
    int res = 0;

    for (size_t i = left; i <= right; i++)
    {
        res |= nums[i];
    }
    return res;
}