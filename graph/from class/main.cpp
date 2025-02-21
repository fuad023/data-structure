#include <bits/stdc++.h>
using namespace std;

vector<int> Node_Vec[100];
vector<int> Node_Cost[100];

int main()
{
    int node_no, edge_no;

    cout << "Enter the number of nodes: ";
    cin >> node_no;

    cout << "Enter the number of edges: ";
    cin >> edge_no;

    for (size_t i = 1; i <= edge_no; i++)
    {
        int nodeA, nodeB, cost;
        cin >> nodeA >> nodeB >> cost;
        Node_Vec[nodeA].push_back(nodeB); // for directed graph
        Node_Cost[nodeA].push_back(nodeB); // for directed graph
    }

    for (size_t i = 1; i <= node_no; i++)
    {
        cout << i << " -> ";
        for (size_t j = 0; j < Node_Vec->size(); j++)
        {
            cout << Node_Vec[i][j];
        }
    }

    return 0;
}