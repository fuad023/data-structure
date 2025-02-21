#include <bits/stdc++.h>
using namespace std;

class Graph
{
protected:
    size_t node_no, edge_no;
    vector<int> Node_Vec[100];
    vector<int>Node_Cost[100];

public:
    virtual void input() {}
    virtual void print() {}
    virtual void print_weight() {}
};

class DirectedGraph : public Graph
{
public:
    void input() override
    {
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
    }

    void print() override
    {
        for (size_t i = 1; i <= node_no; ++i)
        {
            cout << i << " -> ";
            for (size_t j = 0; j < Node_Vec[i].size(); ++j)
            {
                cout << Node_Vec[i][j] << " ";
            } cout << '\n';
        }
    }
};

class UndirectedGraph : public Graph
{
public:
    void input() override
    {
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
    }

    void print() override
    {
        for (size_t i = 1; i <= node_no; ++i)
        {
            cout << i << " -> ";
            for (size_t j = 0; j < Node_Vec[i].size(); ++j)
            {
                cout << Node_Vec[i][j] << " ";
            } cout << '\n';
        }
    }
};

class WeightedDirectedGraph : public Graph
{
public:
    void input() override
    {
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
    }

    void print_weight() override
    {
        for (size_t i = 1; i <= node_no; ++i)
        {
            cout << i << " -> ";
            for (size_t j = 0; j < Node_Cost[i].size(); ++j)
            {
                cout << Node_Cost[i][j] << " ";
            } cout << '\n';
        }
    }
};

class WeightedUndirectedGraph : public Graph
{
public:
    void input() override
    {
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
    }

    void print_weight() override
    {
        for (size_t i = 1; i <= node_no; ++i)
        {
            cout << i << " -> ";
            for (size_t j = 0; j < Node_Cost[i].size(); ++j)
            {
                cout << Node_Cost[i][j] << " ";
            } cout << '\n';
        }
    }
};