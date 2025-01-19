#include <iostream>
#include <vector>
using std::cout;

/* Selects first element
 * Finds LOC of MIN value in the subsequent indices
 *     Swaps with selected element
 * Goes to next element and repeat
 */

size_t find_min(const std::vector<int>& arr, int key)
{
    int min = arr[key];
    size_t loc = key;
    for (size_t i = key + 1; i < arr.size(); i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            loc = i;
        }
    }
    return loc;
}

void selection_sort(std::vector<int>& arr)
{
    for (size_t i = 0; i < arr.size(); i++)
    {
        size_t loc = find_min(arr, i);
        std::swap(arr[i], arr[loc]);
    }
}

int main()
{
    std::vector<int> arr = {23, 25, 2, 6, 10};
    selection_sort(arr);
    for (auto &&val : arr)
    {
        cout << val << ' ';
    }

    return 0;
}