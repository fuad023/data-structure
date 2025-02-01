#include <iostream>
using std::cout;
using std::endl;

struct Node
{
    int data;
    Node* next;
    Node* prev;
};


Node* root = nullptr;
Node* tail = nullptr;


void printingF()
{
    Node* curr_node = root;
    while (curr_node != nullptr)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->next;
    }
    cout << endl;
}

void printingB()
{
    Node* curr_node = tail;
    while (curr_node != nullptr)
    {
        cout << curr_node->data << " ";
        curr_node = curr_node->prev;
    }
    cout << endl;
}

void searching() {}
void print_first() {}
void print_last() {}
void reverse_print() {}

void insert_first(int val)
{
    Node* temp;
    temp = new Node();
    temp->data = val;
    if (root != nullptr && tail != nullptr)
    {
        root->prev = temp;
        temp->next = root;
        temp->prev = nullptr;
        root = temp;
    }
    if (root == nullptr && tail == nullptr)
    {
        temp->next = nullptr;
        temp->prev = nullptr;
        root = temp;
        tail = temp;
    }
}

void insert_last(int val)
{
    Node* temp;
    temp = new Node();
    temp->data = val;
    if (root != nullptr && tail != nullptr)
    {
        tail->next = temp;
        temp->next = nullptr;
        temp->prev = tail;
        tail = temp;
    }
    if (root == nullptr && tail == nullptr)
    {
        temp->next = nullptr;
        temp->prev = nullptr;
        root = temp;
        tail = temp;
    }
}

void delete_first()
{
    Node* curr_node = root;
    if (curr_node != nullptr)
    {
        root = curr_node->next;
        root->prev = nullptr;
    }
}

void delete_last()
{
    Node* curr_node = tail;
    if (curr_node != nullptr)
    {
        tail = curr_node->prev;
        tail->next = nullptr;
    }
}
void insert_middle()
{
    Node* temp;
    Node* curr_node = nullptr;

    // there must exist two nodes

    // process 1
    // temp->prev = curr_node;
    // temp->next = curr_node->next;
    // curr_node->next->prev = temp;
    // curr_node->next = temp;

    // process 2
    // temp->next = curr_node->next;
    // curr_node->next = temp;
    // temp->prev = curr_node;
    // temp->next->prev = temp;
}

void delete_middle()
{
    Node* temp;
    Node* curr_node = nullptr;

    // process 1
    // temp->prev->next = temp->next;
    // temp->next->prev = temp->prev;

    // process 2
    // curr_node->next->prev = curr_node->prev;
    // curr_node->prev->next = curr_node->next;
    // curr_node->next = nullptr;
    // curr_node->prev = nullptr;

}

int main()
{
    Node *p, *q, *r;
    p = new Node();
    q = new Node();
    r = new Node();

    p->data = 10;
    q->data = 20;
    r->data = 30;
    
    
    p->next = q;
    q->next = r;
    r->next = nullptr;

    r->prev = q;
    q->prev = p;
    p->prev = nullptr;

    root = p;
    tail = r;

    // printingF();
    // printingB();

    insert_first(5);
    // printingF();

    insert_last(45);
    printingF();

    delete_first();
    printingF();

    delete_last();
    printingF();
}