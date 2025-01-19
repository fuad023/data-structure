#include <iostream>
#include <vector>
using std::cout;

/* Starts from second element
 * Sets TEMP = ARR[CURR]
 * WHILE TEMP < ARR[PREV]
 *     Shifts PREVs to right
 * Sets TEMP at the empty index
 * Goes to next element and repeat
 */

void insertion_sort(std::vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        int ptr = i - 1;
        while (ptr >= 0 && key < arr[ptr])
        {
            arr[ptr + 1] = arr[ptr];
            ptr = ptr - 1;
        }
        arr[ptr + 1] = key;
    }
}

int main()
{
    std::vector<int> arr = {23, 1, 10, 5, 2};
    insertion_sort(arr);
    for (auto &&val : arr)
    {
        cout << val << ' ';
    }

    return 0;
}