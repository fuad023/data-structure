#include <bits/stdc++.h>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

    node(int value)
    : data(value), left(nullptr), right(nullptr) {}
};
node* root = nullptr;

void preorder(const node* temp)
{
    if (temp)
    {
        cout << temp->data << ' ';
        preorder(temp->left);
        preorder(temp->right);
    }
}

void bst_insert(const vector<int>& elements)
{
    for (int data : elements)
    {
        node* temp = new node(data);
        if (!root) root = temp;
        else
        {
            node *curr_node = root;
            node *prev_node = nullptr;
            while(curr_node)               // goto the correct pos
            {
                prev_node = curr_node;
                if(curr_node->data > data) // data smaller, goto left
                    curr_node = curr_node->left;
                else                       // data greater or equal, goto right
                    curr_node = curr_node->right;
            }
            if (prev_node->data > data)
                prev_node->left = temp;
            else
                prev_node->right = temp;
        }
    }
}

void bst_delete(int data)
{
    node* curr_node = root;
    node* prev_node = nullptr;

    // find the node to delete
    while (curr_node)
    {
        if (curr_node->data == data) break;
        prev_node = curr_node;
        if(curr_node->data > data) // data smaller, goto left
            curr_node = curr_node->left;
        else                       // data greater or equal, goto right
            curr_node = curr_node->right;
    }

    // node not found
    if (!curr_node) return;

    // case 1: no child
    else if (!curr_node->left && !curr_node->right)
    {
        if (!prev_node) // deleting root
            root = nullptr;
        if(prev_node->left == curr_node)
            prev_node->left = nullptr;
        else
            prev_node->right = nullptr;

        delete curr_node;
    }

    // case 2: only child
    else if(!curr_node->left || !curr_node->right)
    {
        // find child
        node* child = curr_node->left 
            ? curr_node->left 
            : curr_node->right;

        // set child
        if (!prev_node)  // deleting root
            root = child;
        else if(prev_node->left == curr_node)
            prev_node->left = child;
        else
            prev_node->right = child;

        delete curr_node;
    }

    // case 3: two children (inorder successor: find leftmost node in the right subtree)
    else
    {
        node* successor = curr_node->right;
        node* successor_parent = curr_node;

        while (successor->left) // find leftmost node in right subtree
        {
            successor_parent = successor;
            successor = successor->left;
        }

        // replace data
        curr_node->data = successor->data;

        // delete successor
        if (successor_parent->left == successor) // if (successor_parent == curr_node) then it must be checked
            successor_parent->left = successor->right;
        else
            successor_parent->right = successor->right;

        delete successor;
    }
}

int main()
{
    bst_insert({81,60,100,50,75,90,104});
    bst_delete(81);
    preorder(root); cout << endl;
}