#include <iostream>
using std::cout;

class Node
{
public:
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class List
{
public:
    Node* head;
    Node* tail;

    List() : head(nullptr), tail(nullptr) {}
    List(const int arr[], size_t size)
    {
        if (size == 0)
        {
            head = nullptr;
            tail = nullptr;
        }

        head = new Node(arr[0]); // first Node

        Node* curr_node = head;  // for the following Nodes
        for (size_t i = 1; i < size; ++i)
        {
            curr_node->next = new Node(arr[i]);
            curr_node->next->prev = curr_node;
            curr_node = curr_node->next;
        }
        tail = curr_node;
    }

    void print_list()
    {
        if (!head) cout << "The list is empty.\n";

        // cout << "List: ";
        Node* curr_node = head;
        while (curr_node)
        {
            cout << curr_node->data << " -> ";
            curr_node = curr_node->next;
        }
        cout << "nullptr" << '\n';
    }

    void print_forward()
    {
        if (!head) cout << "The list is empty.\n";

        // cout << "Elements: ";
        Node* curr_node = head;
        while (curr_node)
        {
            cout << curr_node->data << ' ';
            curr_node = curr_node->next;
        }
        cout << '\n';
    }

    void print_backward()
    {
        if (!tail) cout << "The list is empty.\n";

        // cout << "Elements: ";
        Node* curr_node = tail;
        while (curr_node)
        {
            cout << curr_node->data << ' ';
            curr_node = curr_node->prev;
        }
        cout << '\n';
    }

    size_t search_node(int value)
    {
        Node* curr_node = head;
        size_t occurance = 0;
        while (curr_node)
        {
            if (curr_node->data == value)
            {
                ++occurance;
            }
            curr_node = curr_node->next;
        }
        return occurance;
    }

    void print_first()
    {
        if (!head)
        {
            cout << "The list is empty.\n";
            return;
        }
        cout /*<< "First element: "*/ << head->data << '\n';
    }

    void print_last()
    {
        if (!tail)
        {
            cout << "The list is empty.\n";
            return;
        }
        cout /*<< "Last element: "*/ << tail->data << '\n';
    }

    void print_second_last()
    {
        if (!tail || !tail->prev)
        {
            cout << "The list does not have sufficient nodes.\n";
            return;
        }
        cout /*<< "Second last element: "*/ << tail->prev->data << '\n';
    }

    void print_reverse()
    {
        if (!tail) cout << "The list is empty.\n";

        // cout << "Elements: ";
        Node* curr_node = tail;
        while (curr_node)
        {
            cout << curr_node->data << ' ';
            curr_node = curr_node->prev;
        }
        cout << '\n';
    }

    void size()
    {
        size_t size = 0;
        Node* curr_node = head;
        while (curr_node)
        {
            ++size;
            curr_node = curr_node->next;
        }
        cout << size << '\n';
    }

    void insert_first(int value) // works even if the list is empty
    {
        Node* new_node = new Node(value);

        if (!head) // no node exists
        {
            head = new_node;
            tail = new_node;
            cout << "Inserted node (value: " << head->data << ") at the beginning as the only node.\n";
            return;
        }
        // at least one Node exists, or more exist
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        cout << "Inserted node (value: " << head->data << ") at the beginning.\n";
    }

    void delete_first()
    {
        if (!head) // no node exists
        {
            cout << "The list is empty. Cannot delete first node.\n";
            return;
        }
        if (head == tail) // only one node exist
        {
            Node* del_node = head;
            head = nullptr;
            tail = nullptr;
            cout << "Deleted node (value: " << del_node->data << ") from the beginning as the only node.\n";
            delete del_node;
            return;
        }
        // multiple nodes exist
        Node* del_node = head;
        head = head->next;
        head->prev = nullptr;
        cout << "Deleted node (value: " << del_node->data << ") from the beginning.\n";
        delete del_node;
    }

    void insert_last(int value) // works even if the list is empty
    {
        Node* new_node = new Node(value);

        if (!tail) // no node exists
        {
            head = new_node;
            tail = new_node;
            cout << "Inserted node (value: " << tail->data << ") at the beginning as the only node.\n";
            return;
        }
        // at least one Node exists, or more exist
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        cout << "Inserted node (value: " << tail->data << ") at the end.\n";
    }

    void delete_last()
    {
        if (!tail) // no node exists
        {
            cout << "The list is empty. Cannot delete last node.\n";
            return;
        }

        if (!tail->prev) // only one node exists
        {
            Node* del_node = tail;
            head = nullptr;
            tail = nullptr;
            cout << "Deleted the only node (value: " << del_node->data << ") from the list.\n";
            delete del_node;
            return;
        }

        // multiple nodes exist
        Node* del_node = tail;
        tail = tail->prev;
        tail->next = nullptr;
        cout << "Deleted node (value: " << del_node->data << ") from the end.\n";
        delete del_node;
    }

    void insert_ref_value(int value, int ref_value)
    {
        if (!head) // no reference node exists
        {
            cout << "The list is empty.\n";
            return;
        }

        if (head->data == ref_value)
        {
            insert_first(value);
            return;
        }
        if (tail->data == ref_value)
        {
            insert_last(value);
            return;
        }

        Node* curr_node = head->next;
        while (curr_node && curr_node->data != ref_value)
        {
            curr_node = curr_node->next;
        }

        if (!curr_node) // not found
        {
            cout << "Node (value: " << ref_value << ") doesn't exist in the list." << '\n';
            return;
        }

        // found
        Node* new_node = new Node(value);

        curr_node->prev->next = new_node;
        new_node->prev = curr_node->prev;

        curr_node->prev = new_node;
        new_node->next = curr_node;

        cout << "New node (value: " << curr_node->prev->data << ") added at node (value: " << curr_node->data << ")\n";
    }

    void insert_at_pos(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position: " << pos << ".\n";
            return;
        }
        if (pos == 1)
        {
            insert_first(value);
            return;
        }

        Node* curr_node = head->next;
        size_t curr_pos = 2;
        while (curr_node && curr_pos != pos)
        {
            ++curr_pos;
            curr_node = curr_node->next;
        }
        
        if (!curr_node) // not found
        {
            cout << "Position " << pos << " is out of bounds!" << '\n';
            return;
        }

        // found
        if (tail == curr_node)
        {
            insert_last(value);
            return;
        }

        Node* new_node = new Node(value);

        curr_node->prev->next = new_node;
        new_node->prev = curr_node->prev;

        curr_node->prev = new_node;
        new_node->next = curr_node;

        cout << "New node (value: " << curr_node->prev->data << ") added at position " << pos << ".\n";

    }

    void delete_ref_value(int ref_value)
    {
        if (!head) // no reference node exists
        {
            cout << "The list is empty.\n";
            return;
        }

        if (head->data == ref_value) // first node
        {
            delete_first();
            return;
        }

        if (tail->data == ref_value) // last node
        {
            delete_last();
            return;
        }

        Node* curr_node = head->next;
        while (curr_node && curr_node->data != ref_value) // the following nodes
        {
            curr_node = curr_node->next;
        }

        if (!curr_node) // not found
        {
            cout << "Node (value: " << ref_value << ") doesn't exist in the list." << '\n';
            return;
        }

        // found
        Node* del_node = curr_node;

        curr_node->prev->next = curr_node->next;
        curr_node->next->prev = curr_node->prev;

        cout << "Node (value: " << del_node->data << ") deleted.\n";
        delete del_node;
    }

    void delete_at_pos(int pos)
    {
        if (!head)
        {
            cout << "The list is empty.\n";
            return;
        }

        if (pos < 1)
        {
            cout << "Invalid position: " << pos << ".\n";
            return;
        }

        if (pos == 1) // first node
        {
            delete_first();
            return;
        }

        Node* curr_node = head->next;
        size_t curr_pos = 2;
        while (curr_node && curr_pos != pos)
        {
            ++curr_pos;
            curr_node = curr_node->next;
        }

        if (!curr_node) // not found
        {
            cout << "Position " << pos << " is out of bounds!" << '\n';
            return;
        }

        // found
        if (tail == curr_node)
        {
            delete_last();
            return;
        }

        Node* del_node = curr_node;

        curr_node->prev->next = curr_node->next;
        curr_node->next->prev = curr_node->prev;

        cout << "Node (value: " << del_node->data << ") deleted.\n";
        delete del_node;
    }
};