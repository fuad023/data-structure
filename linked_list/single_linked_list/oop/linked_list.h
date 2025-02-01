#include <iostream>
using std::cout;

class Node
{
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class List
{
public:
    Node* head;

    List() : head(nullptr) {}
    List(const int arr[], size_t size)
    {
        if (size == 0) head = nullptr;

        head = new Node(arr[0]); // first Node

        Node* curr_node = head; // for the following Nodes
        for (size_t i = 1; i < size; ++i)
        {
            curr_node->next = new Node(arr[i]);
            curr_node = curr_node->next;
        }
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

    void print_elements()
    {
        if (!head) cout << "The list is empty.\n";

        cout << "Elements: ";
        Node* curr_node = head;
        while (curr_node)
        {
            cout << curr_node->data << ' ';
            curr_node = curr_node->next;
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
        if (!head)
        {
            cout << "The list is empty.\n";
            return;
        }

        Node* curr_node = head;
        while (curr_node->next)
        {
            curr_node = curr_node->next;
        }
        cout /*<< "Last element: "*/ << curr_node->data << '\n';
    }

    void print_second_last()
    {
        if (!head || !head->next)
        {
            cout << "The list does not have sufficient nodes.\n";
            return;
        }
        
        Node* curr_node = head->next;
        Node* sec_last_node = head;
        while (curr_node->next)
        {
            curr_node = curr_node->next;
            sec_last_node = sec_last_node->next;
        }
        cout /*<< "Second last element: "*/ << sec_last_node->data << '\n';
    }

    void print_reverse(Node* curr_node)
    {
        if (!curr_node) return;
        print_reverse(curr_node->next);
        cout << curr_node->data << ' ';
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
        new_node->next = head;
        head = new_node;
        cout << "Inserted node (value: " << head->data << ") at the beginning.\n";
    }

    void delete_first()
    {
        if (!head)
        {
            cout << "The list is empty. Cannot delete first node.\n";
            return;
        }
        
        Node* del_node = head;
        head = head->next;
        cout << "Deleted node (value: " << del_node->data << ") from the beginning.\n";
        delete del_node;
    }

    void insert_last(int value) // works even if the list is empty
    {
        Node* curr_node = head;
        if (!curr_node) // if HEAD is empty
        {
            curr_node = new Node(value);
            head = curr_node;
            cout << "Inserted node (value: " << curr_node->data << ") as the first element in the list.\n";
            return;
        }
        
        while (curr_node->next) // otherwise go to last
        {
            curr_node = curr_node->next;
        }
        curr_node->next = new Node(value);
        cout << "Inserted node (value: " << curr_node->next->data << ") at the end.\n";
    }

    void delete_last()
    {
        if (!head) // empty list
        {
            cout << "The list is empty. Cannot delete last node.\n";
            return;
        }

        if (!head->next) // only one node exists
        {
            cout << "Deleted node (value: " << head->data << ") as the first element in the list.\n";
            delete head;
            head = nullptr;
            return;
        }

        Node* curr_node = head->next;
        Node* sec_last_node = head;
        while (curr_node->next)
        {
            curr_node = curr_node->next;
            sec_last_node = sec_last_node->next;
        }

        cout << "Deleted node (value: " << curr_node->data << ") from the end.\n";
        delete curr_node;
        sec_last_node->next = nullptr;
    }

    // does not add node after last node, but adds node before HEAD and all others
    void insert_before_ref_value(int value, int ref_value)
    {
        if (!head) // no reference node exists
        {
            cout << "The list is empty.\n";
            return;
        }

        Node* curr_node = head;
        Node* prev = nullptr;
        while (curr_node && curr_node->data != ref_value)
        {
            prev = curr_node;
            curr_node = curr_node->next;
        }

        if (!curr_node) // not found
        {
            cout << "Node (value: " << ref_value << ") doesn't exist in the list." << '\n';
            return;
        }

        // found
        Node* new_node = new Node(value);
        if (!prev) // adds node before HEAD
        {
            new_node->next = curr_node;
            head = new_node;
            cout << "New node (value: " << head->data << ") added before node (value: " << head->next->data << ") [HEAD].\n";
        }
        else // for nodes following the HEAD
        {
            prev->next = new_node;
            new_node->next = curr_node;
            cout << "New node (value: " << prev->next->data << ") added before node (value: " << curr_node->data << ")\n";
        }
    }

    // does not add node before HEAD, but adds node after last node and all others
    void insert_after_ref_value(int value, int ref_value)
    {
        if (!head) // no reference node exists
        {
            cout << "The list is empty.\n";
            return;
        }

        Node* curr_node = head;
        while (curr_node && curr_node->data != ref_value)
        {
            curr_node = curr_node->next;
        }

        if (!curr_node) // not found
        {
            cout << "Node (value: " << ref_value << ") doesn't exist." << '\n';
            return;
        }

        // found
        Node* new_node = new Node(value);
        new_node->next = curr_node->next;
        curr_node->next = new_node;
        cout << "New node (value: " << curr_node->next->data << ") added after node (value: " << curr_node->data << ")\n";
    }

    // does not add node after last node, but adds node before HEAD and all others
    void insert_before_pos(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position: " << pos << ".\n";
            return;
        }

        Node* curr_node = head;
        Node* prev = nullptr;
        size_t curr_pos = 1;
        while (curr_node && curr_pos != pos)
        {
            ++curr_pos;
            prev = curr_node;
            curr_node = curr_node->next;
        }
        
        if (!curr_node) // not found
        {
            cout << "Position " << pos << " is out of bounds!" << '\n';
            return;
        }

        // found
        Node* new_node = new Node(value);
        if (!prev) // at the HEAD
        {
            new_node->next = curr_node;
            head = new_node;
            cout << "New node (value: " << head->data << ") added before position " << pos << " [HEAD].\n";
            return;
        }
        else // for positions following the HEAD
        {
            new_node->next = curr_node;
            prev->next = new_node;
            cout << "New node (value: " << prev->next->data << ") added before position " << pos << ".\n";
        }
    }

    // does not add node before HEAD, but adds node after last node and all others
    void insert_after_pos(int value, int pos)
    {
        if (pos < 1)
        {
            cout << "Invalid position: " << pos << ".\n";
            return;
        }

        Node* curr_node = head;
        size_t curr_pos = 1;
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
        Node* new_node = new Node(value);
        new_node->next = curr_node->next;
        curr_node->next = new_node;
        cout << "New node (value: " << curr_node->next->data << ") added after position " << pos << ".\n";
    }

    // does not delete last node, but deletes HEAD and all others
    void delete_before_ref_value(int ref_value)
    {
        if (!head) // no reference node exists
        {
            cout << "The list is empty.\n";
            return;
        }

        if (head->data == ref_value) // first node: no delete before HEAD
        {
            cout << "No node exists before node (value: " << ref_value << ") [HEAD].\n";
            return;
        }

        if (head->next->data == ref_value) // second node: deletes HEAD node
        {
            Node* del_node = head;
            head = head->next;
            cout << "Node (value: " << del_node->data << ") deleted before node (value: " << head->data << ") [at HEAD].\n";
            delete del_node;
            return;
        }

        Node* curr_node = head->next->next;
        Node* second_last = head;
        while (curr_node && curr_node->data != ref_value) // the following nodes
        {
            curr_node = curr_node->next;
            second_last = second_last->next;
        }

        if (!curr_node) // not found
        {
            cout << "Node (value: " << ref_value << ") doesn't exist in the list." << '\n';
            return;
        }

        // found
        Node* del_node = second_last->next;
        second_last->next = curr_node;
        cout << "Node (value: " << del_node->data << ") deleted before node (value: " << curr_node->data << ").\n";
        delete del_node;
    }

    // does not delete HEAD, but deletes node after HEAD and all others
    void delete_after_ref_value(int ref_value)
    {
        if (!head) // no reference node exists
        {
            cout << "The list is empty.\n";
            return;
        }
        
        Node* curr_node = head;
        while (curr_node && curr_node->data != ref_value)
        {
            curr_node = curr_node->next;
        }

        if (!curr_node) // not found
        {
            cout << "Node (value: " << ref_value << ") doesn't exist in the list." << '\n';
            return;
        }

        if (!curr_node->next) // last node: no delete after last node
        {
            cout << "No node exists after node (value: " << curr_node->data << ") [LAST_NODE].\n";
            return;
        }

        // found
        Node* del_node = curr_node->next;
        curr_node->next = del_node->next;
        cout << "Node (value: "<< del_node->data << ") deleted after node (value: " << curr_node->data << ").\n";
        delete del_node;
    }

    // does not delete last node, but deletes HEAD and all others
    void delete_before_pos(int pos)
    {
        if (!head || !head->next) // at least two nodes must exist
        {
            cout << "The list does not have sufficient nodes.\n";
            return;
        }

        if (pos < 1)
        {
            cout << "Invalid position: " << pos << ".\n";
            return;
        }

        if (pos == 1) // first node: no delete before HEAD
        {
            cout << "No node exists before position " << pos << " [HEAD].\n";
            return;
        }


        if (pos == 2) // second node
        {
            Node* del_node = head;
            head = head->next;
            cout << "Node (value: " << del_node->data << ") deleted before node (value: " << head->data << ") [HEAD].\n";
            delete del_node;
            return;
        }

        // in-between node will get deleted, then PREV will get linked to CURR_NODE
        Node* curr_node = head->next->next; // third node
        Node* prev = head; // first node
        size_t curr_pos = 3;
        while (curr_node && curr_pos != pos)
        {
            ++curr_pos;
            curr_node = curr_node->next;
            prev = prev->next;
        }

        if (!curr_node) // not found
        {
            cout << "Position " << pos << " is out of bounds!" << '\n';
            return;
        }

        // found
        Node* del_node = prev->next;
        prev->next = curr_node;
        cout << "Node (value: " << del_node->data << ") deleted before node (value: " << curr_node->data << ").\n";
        delete del_node;
    }

    // does not delete HEAD, but deletes node after HEAD and all others
    void delete_after_pos(int pos)
    {
        if (!head) // no reference node exists
        {
            cout << "The list is empty.\n";
            return;
        }

        Node* curr_node = head;
        size_t curr_pos = 1;
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

        if (!curr_node->next) // last node: no delete after last node
        {
            cout << "No node exists after node (value: " << curr_node->data << ") [LAST_NODE].\n";
            return;
        }

        // found
        Node* del_node = curr_node->next;
        curr_node->next = del_node->next;
        cout << "Node (value: "<< del_node->data << ") deleted after node (value: " << curr_node->data << ").\n";
        delete del_node;
    }

    void bubble_sort()
    {
        Node* curr_node;
        Node* last_node = nullptr;
        while (head->next != last_node)
        {
            curr_node = head;
            while (curr_node->next != last_node)
            {
                if (curr_node->data > curr_node->next->data)
                {
                    std::swap(curr_node->data, curr_node->next->data);
                }
                curr_node = curr_node->next;
            }
            last_node = curr_node;
        }
    }

};