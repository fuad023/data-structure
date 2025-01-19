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

void delete_middle()
{
    /*
     * hint:
     * prev_node->next = curr_node->next;
     */
}

int main()
{
   insert_first(10);
   printing();
   insert_first(20);
   printing();
   insert_first(30);
   printing();
   insert_first(40);
   printing();
   delete_first();
   printing();
   insert_last(40);
   printing();
   delete_last();
   printing();
}