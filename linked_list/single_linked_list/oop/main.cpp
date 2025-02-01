#include "linked_list.h"

int main()
{
/*
    // CHECK #1 - test all at once

    int arr[] = {10, 20, 30, 40, 50};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    List list(arr, n);

    cout << "\nList: ";
    list.print_list();

    cout << "\n1. Elements: ";
    list.print_elements();

    cout << "\n2. Searching for 30: ";
    cout << (list.search_node(30) ? "Found" : "Not Found") << '\n';

    cout << "\n3. First element: ";
    list.print_first();

    cout << "\n4. Last element: ";
    list.print_last();

    cout << "\n5. Second last element: ";
    list.print_second_last();

    cout << "\n6. Reverse order: ";
    list.print_reverse(list.head);
    cout << '\n';

    cout << "\n7. Element count: ";
    list.size();
*/

/*
    List list;

    // CHECK #2 - test segments individually

    // segment 1
    // list.insert_first(20);
    // list.insert_first(10);
    // cout << "Elements: "; list.print_elements(); cout << '\n';
    // list.delete_first();
    // list.delete_first();
    // list.delete_first();
    // cout << "Elements: "; list.print_elements(); cout << '\n';
    // segment close

    // segment 2
    // list.insert_last(30);
    // list.insert_last(40);
    // cout << "Elements: "; list.print_elements(); cout << '\n';
    // list.delete_last();
    // list.delete_last();
    // list.delete_last();
    // cout << "Elements: "; list.print_elements(); cout << '\n';
    // segment close
*/

/*
    // CHECK #3 - test each segment at a time

    int arr[] = {10, 20, 30, 40};
    size_t n = sizeof(arr) / sizeof(arr[0]);

    List list(arr, n);
    list.print_elements(); cout << '\n';

    // segment 1 - insert before by value
    // list.insert_before_ref_value(-5, 0); // invalid call
    // list.print_elements();
    // list.insert_before_ref_value(5, 10);
    // list.print_elements();
    // list.insert_before_ref_value(35, 40);
    // list.print_elements();
    // list.insert_before_ref_value(45, 50); // invalid call
    // list.print_elements();
    // segment close

    // segment 2 - insert after by value
    // list.insert_after_ref_value(5, 0); // invalid call
    // list.print_elements();
    // list.insert_after_ref_value(15, 10);
    // list.print_elements();
    // list.insert_after_ref_value(45, 40);
    // list.print_elements();
    // list.insert_after_ref_value(55, 50); // invalid call
    // list.print_elements();
    // segment close

    // segment 3 - insert before by position
    // list.insert_before_pos(15, 2);
    // list.print_elements();
    // list.insert_before_pos(5, 1); // at HEAD
    // list.print_elements();
    // list.insert_before_pos(35, 6);
    // list.print_elements();
    // list.insert_before_pos(50, 8); // invalid call
    // list.print_elements();
    // segment close

    // segment 4 - insert after by position
    // list.insert_after_pos(5, 0); // invalid call
    // list.print_elements();
    // list.insert_after_pos(15, 1);
    // list.print_elements();
    // list.insert_after_pos(45, 5);
    // list.print_elements();
    // list.insert_after_pos(55, 7); // invalid call
    // list.print_elements();
    // segment close

    // segment 5 - delete before by value
    // list.delete_before_ref_value(0); // invalid call
    // list.print_elements();
    // list.delete_before_ref_value(10);
    // list.print_elements();
    // list.delete_before_ref_value(40);
    // list.print_elements();
    // list.delete_before_ref_value(50); // invalid call
    // list.print_elements();
    // segment close

    // segment 6 - delete after by value
    // list.delete_after_ref_value(0); // invalid call
    // list.print_elements();
    // list.delete_after_ref_value(10);
    // list.print_elements();
    // list.delete_after_ref_value(40); // invalid call
    // list.print_elements();
    // list.delete_after_ref_value(30);
    // list.print_elements();
    // segment close

    // segment 5 - delete before by pos
    // list.delete_before_pos(0); // invalid call
    // list.print_elements();
    // list.delete_before_pos(1); // invalid call
    // list.print_elements();
    // list.delete_before_pos(2);
    // list.print_elements();
    // list.delete_before_pos(4); // invalid call
    // list.print_elements();
    // segment close

    // segment 6 - delete after by pos
    // list.delete_after_pos(0); // invalid call
    // list.print_elements();
    // list.delete_after_pos(1);
    // list.print_elements();
    // list.delete_after_pos(3); // invalid call
    // list.print_elements();
    // list.delete_after_pos(4); // invalid call
    // list.print_elements();
    // segment close
*/

/*
    int arr[] = {50, 20, 40, 10, 30};
    size_t n = sizeof(arr) / sizeof(arr[0]);
    List list(arr, n);

    list.bubble_sort();
    list.print_list();
*/
    return 0;
}