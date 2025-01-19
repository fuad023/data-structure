#include <vector>
// #include <cstdlib>

size_t lomuto_partition(std::vector<int>& vec, int low, int high)
{
    // Select a random pivot and move it to the last position
    // int random_pivot_index = low + std::rand() % (high - low + 1);
    // std::swap(vec[high], vec[random_pivot_index]);

    int& pivot = vec[high], i = low - 1;
    for (size_t j = low; j < high; j++)
    {
        if (vec[j] < pivot)
        {
            ++i;
            std::swap(vec[i], vec[j]);
        }
    }
    std::swap(vec[i + 1], pivot);
    return i + 1;
}

void quick_sort_lp(std::vector<int>& vec, int low, int high)
{
    if (low < high)
    {
        int pos = lomuto_partition(vec, low, high);
        quick_sort_lp(vec, low, pos - 1);
        quick_sort_lp(vec, pos + 1, high);
    }
}