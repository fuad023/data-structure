#include "node.h"

void insert_first(int val)
{
    Node* temp;
    temp = new Node;
    temp->data = val;
    temp->next = root;
    root = temp;
}

void delete_first()
{
    // node* temp = root;
    if (root != NULL)
    {
        root = root->next;
    }
    // delete(temp);
}

void insert_last(int val)
{
    // TODO: what to do when the first element IS empty
    
    Node* temp;
    temp = new Node;
    temp->data = val;
    temp->next = NULL;

    if (root == NULL)
    {
        root = temp;
        return;
    }

    Node* curr_node = root;
    while (curr_node->next != NULL)
    {
        curr_node = curr_node->next;
    }
    curr_node->next = temp;
}

void delete_last()
{
    Node* curr_node = root;
    Node* secound_last_node = NULL;
    while (curr_node->next != NULL)
    {
        secound_last_node = curr_node;
        curr_node = curr_node->next;
    }
    secound_last_node->next = NULL;
    // delete(curr_node);
}

void insert_middle()
{
    /*
     * by value: before and after
     * by position: before and after
     * 
     * hint:
     * temp->next = curr_node->next;
     * curr_node->next = temp;
     */
}

// does not add any node before HEAD, but adds node after last node and all others
void insert_after_ref_value(int value, int ref_value)
{
    if (!root)
    {
        cout << "List is empty!" << '\n';
        return;
    }
    
    Node* current = root;
    while (current && current->data != ref_value)
    {
        current = current->next;
    }

    if (!current)
    {
        cout << "Node (value: " << ref_value << ") doesn't exist." << '\n';
        return;
    }

    Node* new_node = new Node;
    new_node->data = value;

    new_node->next = current->next;
    current->next = new_node;
    cout << "New node (value: " << current->next->data << ") added after node (value: " << current->data << ")\n";
}

// does not add any node after last node, but adds node before HEAD and all others
void insert_before_ref_value(int value, int ref_value)
{
    if (!root)
    {
        cout << "List is empty!" << '\n';
        return;
    }

    if (root->data == ref_value) // added node before HEAD
    {
        Node* new_node = new Node;
        new_node->data = value;

        new_node->next = root;
        root = new_node;
        cout << "New node (value: " << root->data << ") added before node (value: " << root->next->data << ")\n";
        return;
    }

    Node* current = root->next;
    Node* prev = root;
    while (current && current->data != ref_value)
    {
        current = current->next;
        prev = prev->next;
    }

    if (!current)
    {
        cout << "Node (value: " << ref_value << ") doesn't exist." << '\n';
        return;
    }

    Node* new_node = new Node;
    new_node->data = value;

    prev->next = new_node;
    new_node->next = current;
    cout << "New node (value: " << prev->next->data << ") added before node (value: " << current->data << ")\n";
}

// does not add any node before HEAD, but adds node after last node and all others
void insert_after_pos(int value, int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position: " << pos << ".\n";
        return;
    }

    Node* new_node = new Node;
    new_node->data = value;

    // if (pos == 0) // at the HEAD
    // {
    //     new_node->next = root;
    //     root = new_node;
    //     return;
    // }
    
    Node* current = root;
    size_t curr_pos = 1;
    while (current && curr_pos != pos)
    {
        ++curr_pos;
        current = current->next;
    }
    
    if (!current)
    {
        cout << "Position " << pos << " is out of bounds!" << '\n';
        delete new_node;
        return;
    }

    new_node->next = current->next;
    current->next = new_node;
    cout << "New node (value: " << current->next->data << ") added after position " << current->data << ".\n";
}

// does not add any node after last node, but adds node before HEAD and all others
void insert_before_pos(int value, int pos)
{
    if (pos < 1)
    {
        cout << "Invalid position:" << pos << ".\n";
        return;
    }

    if (pos == 1) // at the HEAD
    {
        Node* new_node = new Node;
        new_node->data = value;

        new_node->next = root;
        root = new_node;
        cout << "New node (value: " << root->data << ") added before position " << root->next->data << ".\n";
        return;
    }
    
    Node* current = root;
    Node* prev = NULL;
    size_t curr_pos = 1;
    while (current && curr_pos != pos)
    {
        prev = current;
        current = current->next;
        ++curr_pos;
    }
    
    if (!current)
    {
        cout << "Position " << pos << " is out of bounds!" << '\n';
        return;
    }

    Node* new_node = new Node;
    new_node->data = value;

    new_node->next = current;
    prev->next = new_node;
    cout << "New node (value: " << prev->next->data << ") added before position " << current->data << ".\n";
}

void delete_middle()
{
    /*
     * hint:
     * prev_node->next = curr_node->next;
     */
}

// does not delete node before HEAD and after last node
void delete_after_ref_value(int ref_value)
{
    if (!root)
    {
        cout << "List is empty!" << '\n';
        return;
    }
    
    Node* current = root;
    while (current && current->data != ref_value)
    {
        current = current->next;
    }

    if (!current)
    {
        cout << "Node with value " << ref_value << " doesn't exist." << '\n';
        return;
    }

    if (!current->next)
    {
        cout << "No node exists after " << ref_value << '\n';
        return;
    }

    Node* del_node = current->next;
    current->next = del_node->next;
    cout << "Node (value: "<< del_node->data <<") deleted after node (value: " << current->data << ")\n";
    delete del_node;
}

// does not delete node before HEAD
void delete_before_ref_value(int ref_value)
{
    if (!root)
    {
        cout << "List is empty!" << '\n';
        return;
    }

    if (root->data == ref_value)
    {
        cout << "No node exists before HEAD!" << '\n';
        return;
    }

    if (root->next->data == ref_value)
    {
        Node* temp = root;
        root = root->next;
        cout << "Node (value: " << temp->data << ") deleted before node (value: " << root->data << ")" << '\n';
        delete temp;
        return;
    }

    Node* current = root->next->next;
    Node* second_last = root;
    while (current && current->data != ref_value)
    {
        current = current->next;
        second_last = second_last->next;
    }

    if (!current)
    {
        cout << "Node with value " << ref_value << " doesn't exist." << '\n';
        return;
    }

    Node* temp = second_last->next;
    second_last->next = current;
    cout << "Node (value: " << temp->data << ") deleted before node (value: " << current->data << ")" << '\n';
    delete temp;
}

int main()
{
    insert_first(40);
    insert_first(30);
    insert_first(20);
    insert_first(10);
    printing();

    // insert_after_ref_value(45, 40);
    // printing();
    // insert_before_ref_value(5, 10);
    // printing();

    // insert_after_pos(15, 1);
    // printing();
    // insert_after_pos(5, 0); // invalid call
    // printing();
    // insert_after_pos(50, 5);
    // printing();
    // insert_after_pos(55, 7); // invalid call
    // printing();

    insert_before_pos(15, 2);
    printing();
    insert_before_pos(5, 1);
    printing();
    insert_before_pos(35, 6);
    printing();
    insert_before_pos(50, 8); // invalid call
    printing();

    // delete_after_ref_value(10);
    // printing();

    // delete_before_ref_value(10);
    // delete_before_ref_value(20);
    // delete_before_ref_value(30);
    // delete_before_ref_value(40);
    // delete_before_ref_value(50);
    // printing();
}