#include <bits/stdc++.h>
using namespace std;

vector<int> Node_Vec[100];
vector<int> Node_Cost[100];

void directed_graph()
{
    size_t node_no, edge_no;

    cout << "Enter the number of nodes: ";
    cin >> node_no;

    cout << "Enter the number of edges: ";
    cin >> edge_no;

    for (size_t i = 1; i <= edge_no; ++i)
    {
        int node_a, node_b;
        cout << "Enter edge (from node to node): ";
        cin >> node_a >> node_b;
        Node_Vec[node_a].push_back(node_b);
    }

    for (size_t i = 1; i <= node_no; ++i)
    {
        cout << i << " -> ";
        for (size_t j = 0; j < Node_Vec[i].size(); ++j)
        {
            cout << Node_Vec[i][j] << " ";
        } cout << '\n';
    }
}

void undirected_graph()
{
    size_t node_no, edge_no;

    cout << "Enter the number of nodes: ";
    cin >> node_no;

    cout << "Enter the number of edges: ";
    cin >> edge_no;

    for (size_t i = 1; i <= edge_no; ++i)
    {
        int node_a, node_b;
        cout << "Enter edge (from node to node): ";
        cin >> node_a >> node_b;
        Node_Vec[node_a].push_back(node_b);            
        Node_Vec[node_b].push_back(node_a);
    }

    for (size_t i = 1; i <= node_no; ++i)
    {
        cout << i << " -> ";
        for (size_t j = 0; j < Node_Vec[i].size(); ++j)
        {
            cout << Node_Vec[i][j] << " ";
        } cout << '\n';
    }
}

void weighted_directed_graph()
{
    size_t node_no, edge_no;

    cout << "Enter the number of nodes: ";
    cin >> node_no;

    cout << "Enter the number of edges: ";
    cin >> edge_no;

    for (size_t i = 1; i <= edge_no; ++i)
    {
        int node_a, node_b, cost;
        cout << "Enter edge (from node to node) and cost: ";
        cin >> node_a >> node_b >> cost;
        Node_Vec[node_a].push_back(node_b);
        Node_Cost[node_a].push_back(cost);
    }

    for (size_t i = 1; i <= node_no; ++i)
    {
        cout << i << " -> ";
        for (size_t j = 0; j < Node_Cost[i].size(); ++j)
        {
            cout << Node_Cost[i][j] << " ";
        } cout << '\n';
    }
}

void weighted_undirected_graph()
{
    size_t node_no, edge_no;

    cout << "Enter the number of nodes: ";
    cin >> node_no;

    cout << "Enter the number of edges: ";
    cin >> edge_no;

    for (size_t i = 1; i <= edge_no; ++i)
    {
        int node_a, node_b, cost;
        cout << "Enter edge (from node to node) and cost: ";
        cin >> node_a >> node_b >> cost;
        Node_Vec[node_a].push_back(node_b);
        Node_Vec[node_b].push_back(node_a);
        Node_Cost[node_a].push_back(cost);
        Node_Cost[node_b].push_back(cost);
    }

    for (size_t i = 1; i <= node_no; ++i)
    {
        cout << i << " -> ";
        for (size_t j = 0; j < Node_Cost[i].size(); ++j)
        {
            cout << Node_Cost[i][j] << " ";
        } cout << '\n';
    }
}

int main()
{
    weighted_undirected_graph();

    return 0;
}