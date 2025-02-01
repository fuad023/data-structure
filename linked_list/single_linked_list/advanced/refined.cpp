#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

void list(Node* head) {
    Node* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "null" << endl;
}

void insert_first(Node*& head, int value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    // cout << "Inserted " << value << " at the beginning." << endl;
}

void delete_first(Node*& head)
{
    if (!head)
    {
        cout << "The list is already empty. Nothing to delete." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;
    // cout << "Deleted " << temp->data << " from the beginning." << endl;
    delete temp;
}

void insert_last(Node*& head, int value)
{
    Node* newNode = new Node(value);

    if (!head)
    {
        head = newNode;
        // cout << "Inserted " << value << " as the first element in the list." << endl;
        return;
    }

    Node* current = head;
    while (current->next)
    {
        current = current->next;
    }
    current->next = newNode;
    // cout << "Inserted " << value << " at the end." << endl;
}

void delete_last(Node*& head)
{
    if (!head)
    {
        cout << "The list is already empty. Nothing to delete." << endl;
        return;
    }

    if (!head->next) // only one node in the list
    {
        // cout << "Deleted " << head->data << " from the list." << endl;
        delete head;
        head = nullptr;
        return;
    }

    Node* current = head;
    while (current->next->next) // traverse to second last node
    {
        current = current->next;
    }

    cout << "Deleted " << current->next->data << " from the end." << endl;
    delete current->next;
    current->next = nullptr;
}

int main() {
    Node* head = nullptr;

    // Test Insert First
    insert_first(head, 10);
    insert_first(head, 20);
    list(head);

    // Test Delete First
    delete_first(head);
    list(head);

    // Test Insert Last
    insert_last(head, 30);
    insert_last(head, 40);
    list(head);

    // Test Delete Last
    delete_last(head);
    list(head);

    delete_last(head);
    list(head);

    delete_last(head);
    // Edge case: Delete from an empty list
    delete_first(head);
    delete_last(head);

    return 0;
}