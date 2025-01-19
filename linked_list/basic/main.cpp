#include <iostream>
using std::cin;
using std::cout;

struct Node
{
    int data;
    Node* next;
};
Node* root = NULL;

void printing()
{
    Node* curr_node = root;
    cout << "All Elements: ";
    while (curr_node != NULL)
    {
        cout << curr_node->data << ' ';
        curr_node = curr_node->next;
    } cout << '\n';
}

void searching(int val)
{
    Node* curr_node = root;
    int f = 0;
    while (curr_node != NULL)
    {
        if (curr_node->data == val)
        {
            f = 1;
            cout << "Value " << val << " found." << '\n';
            break;
        }
        curr_node = curr_node->next;
    }
}

void print_first()
{
    cout << "First Element: " << root->data << '\n';
}

void print_last()
{
    Node* curr_node = root;
    while (curr_node->next != NULL)
    {
        curr_node = curr_node->next;
    }
    cout << "Last Element: " << curr_node->data << '\n';
}

void print_secound_last()
{
    Node* curr_node = root;
    Node* secound_last_node = NULL;
    while (curr_node->next != NULL) // while (curr_node->next->next != NULL)
    {
        secound_last_node = curr_node;
        curr_node = curr_node->next;
    }
    cout << "Second Last Element: " << secound_last_node->data << '\n'; // curr_node->data
}

void reverse_print(Node* curr_node)
{
    if (curr_node != NULL)
    {
        reverse_print(curr_node->next);
        cout << curr_node->data << ' ';
    }
}

int main()
{
    // pointer declaration
    Node *p, *q, *r;

    // memory allocation
    p = new Node;
    q = new Node;
    r = new Node;

    // data assignment
    p->data = 10;
    q->data = 20;
    r->data = 30;

    // node linking
    p->next = q;
    q->next = r;
    r->next = NULL;
    root = p;

    // operation
    printing();
    searching(20);
    print_first();
    print_last();
    print_secound_last();
    cout << "Reverse Elements: "; reverse_print(root); cout << '\n';
}