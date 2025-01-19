#include <iostream>
#include "lomuto_patition.h"
#include "hoares_partition.h"
using std::cout;

int main()
{
    std::vector<int> vec = {5, 3, 8, 4, 2, 7, 1, 10};
    quick_sort_hp(vec, 0, vec.size() - 1);

    for (int x : vec)
    {
        cout << x << ' ';
    }
    
    return 0;
}