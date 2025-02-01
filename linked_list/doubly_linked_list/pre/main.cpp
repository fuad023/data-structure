#include "doubly_linked_list.h"

int main()
{

    int arr[] = {10, 20, 30, 40, 50};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    List list(arr, n);

    // list.insert_first(5);
    // list.insert_last(55);
    // list.print_forward(); // 5 10 20 30 40 50 55

    // list.delete_first();
    // list.delete_last();
    // list.print_forward(); // 10, 20, 30, 40, 50


    // list.insert_at_ref_value(5, 5); // invalid
    // list.insert_at_ref_value(0, 10);
    // list.insert_at_ref_value(55, 55); // invalid
    // list.insert_at_ref_value(60, 50);
    // list.print_forward();

    // list.insert_at_ref_value(35, 40);
    // list.print_forward();
    // list.print_backward();


    // list.insert_at_pos(0, 0); // invalid
    // list.insert_at_pos(60, 6); // invalid
    // list.insert_at_pos(5, 1);
    // list.insert_at_pos(25, 4);
    // list.insert_at_pos(55, 7);
    // list.print_forward(); // 5 10 20 25 30 40 50 55
    // list.print_backward(); // 55 50 40 30 25 20 10 5


    // list.delete_ref_value(10);
    // list.delete_ref_value(50);
    // list.print_forward();
    // list.print_backward();

    // list.delete_ref_value(30);
    // list.print_forward();
    // list.print_backward();


    list.delete_at_pos(0);
    list.delete_at_pos(6);
    list.delete_at_pos(1);
    list.delete_at_pos(4);
    list.print_forward();
    list.print_backward();
    
    list.delete_at_pos(2);
    list.print_forward();
    list.print_backward();


    return 0;
}