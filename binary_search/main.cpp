#include <iostream>
#include <vector>
using std::cout;

int binary_search(const std::vector<int>& arr, int key, size_t low, size_t high)
{
    while (low <= high)
    {
        size_t mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // key not found
}

int main()
{
    std::vector<int> arr = {1, 3, 5, 7, 9, 11, 13};

    int key = 7;
    int index = binary_search(arr, key, 0, arr.size() - 1);

    if (index != -1) {
        cout << "Key " << key << " found at index " << index << std::endl;
    } else {
        cout << "Key " << key << " not found in the array" << std::endl;
    }

    return 0;
}