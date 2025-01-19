#include <iostream>
using std::cin;
using std::cout;

struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

Node* create_linked_list(const int arr[], int n)
{
    if (n == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* current = head;

    for (size_t i = 1; i < n; i++)
    {
        current->next = new Node(arr[i]);
        current = current->next;
    }
    return head;
}

void print_list(Node* head)
{
    Node* current = head;
    while (current)
    {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << '\n';;
}

void print_elements(Node* head)
{
    Node* current = head;
    while (current)
    {
        cout << current->data << ' ';
        current = current->next;
    } cout << '\n';
}

bool search_node(Node* head, int value)
{
    Node* current = head;
    while (current)
    {
        if (current->data == value)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

void first_element(Node* head)
{
    if (head) {
        cout << "First element: " << head->data << '\n';
    } else {
        cout << "The list is empty." << '\n';
    }
}

void last_element(Node* head)
{
    if (!head)
    {
        cout << "The list is empty." << '\n';
        return;
    }

    Node* current = head;
    while (current->next)
    {
        current = current->next;
    }
    cout << "Last element: " << current->data << '\n';
}

void second_last_element(Node* head)
{
    if (!head || !head->next)
    {
        cout << "The list does not have enough elements." << '\n';
        return;
    }

    Node* current = head;
    while (current->next->next)
    {
        current = current->next;
    }
    cout << "Second last element: " << current->data << '\n';
}

void reverse(Node* head)
{
    if (!head) return;
    reverse(head->next);
    cout << head->data << ' ';
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node* head = create_linked_list(arr, n);

    cout << "Original List: ";
    print_list(head);

    cout << "\n1. Printing all elements: ";
    print_elements(head);

    cout << "\n2. Searching for 30: ";
    cout << (search_node(head, 30) ? "Found" : "Not Found") << '\n';

    cout << "\n3. Printing first element: ";
    first_element(head);

    cout << "\n4. Printing last element: ";
    last_element(head);

    cout << "\n5. Printing second last element: ";
    second_last_element(head);

    cout << "\n6. Printing in reverse order: ";
    reverse(head);
    cout << '\n';

    return 0;
}