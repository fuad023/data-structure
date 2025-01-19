#include <vector>
// #include <cstdlib>

int hoares_partition(std::vector<int>& vec, int low, int high)
{
    // Select a random pivot and move it to the first position
    // int random_pivot_index = low + std::rand() % (high - low + 1);
    // std::swap(vec[low], vec[random_pivot_index]);

    int pivot = vec[low], i = low - 1, j = high + 1;
    while (true)
    {
        do { ++i; }
        while (vec[i] < pivot);

        do { --j; } 
        while (pivot < vec[j]);
        
        if (i >= j)
        {
            return j; // or, return i;
        }
        std::swap(vec[i], vec[j]);
    }
}

void quick_sort_hp(std::vector<int>& vec, int low, int high)
{
    if (low < high)
    {
        int pos = hoares_partition(vec, low, high);
        quick_sort_hp(vec, low, pos);      // or,   quick_sort_hp(vec, low, pos - 1);
        quick_sort_hp(vec, pos + 1, high); // then, quick_sort_hp(vec, pos, high);
    }
}