#include <iostream>
#include <vector>
using std::cout;

size_t binary_search(const std::vector<int>& arr, int key, size_t low, size_t high)
{
    while (low <= high) {
        size_t mid = low + (high - low) / 2;
        if (arr[mid] <= key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return low;
}

void insertion_sort_using_binary_search(std::vector<int>& arr)
{
    for (size_t i = 1; i < arr.size(); i++)
    {
        int key = arr[i];
        size_t high = i - 1;
        // find correct position for key
        size_t pos = binary_search(arr, key, 0, high);

        // shift elements to make space for key
        for (size_t j = high; j >= pos; j--)
        {
            arr[j + 1] = arr[j];
        }

        // insert key at correct position
        arr[pos] = key;
    }
}

int main() {
    std::vector<int> arr = {12, 11, 13, 5, 6};

    insertion_sort_using_binary_search(arr);

    for (int num : arr) {
        cout << num << ' ';
    }

    return 0;
}
