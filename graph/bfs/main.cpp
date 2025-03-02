#include <bits/stdc++.h>
using namespace std;

const int size = 11;
vector<int> Node_Vec[size];

void push_vertex(queue<int>& Queue, vector<int>& visit_order, vector<int>& level, int front_vertex, int adj_vertex)
{
    Queue.push(adj_vertex);
    visit_order.push_back(adj_vertex);
    level[adj_vertex] = level[front_vertex] + 1;
}

void explore_vertex(queue<int>& Queue, vector<int>& visit_order, vector<int>& level)
{
    int front_vertex = Queue.front();
    Queue.pop();

    for (int adj_vertex : Node_Vec[front_vertex])
    {
        if (level[adj_vertex] == -1)
        {
            push_vertex(Queue, visit_order, level, front_vertex, adj_vertex);
        }
    }
}

void breadth_first_search(int vertex)
{
    queue<int> Queue;
    vector<int> visit_order;
    vector<int> level(size, -1);
    push_vertex(Queue, visit_order, level, 0, vertex);

    while (!Queue.empty())
    {
        explore_vertex(Queue, visit_order, level);
    }
    
    for (int vertex : visit_order)
    {
        cout << vertex << ' ';
    } cout << '\n';

    for (int vertex : visit_order)
    {
        cout << vertex << " -> " << level[vertex] << '\n';
    }
}

int main()
{
    Node_Vec[1]  = {2,4};
    Node_Vec[2]  = {1,3,5,7,8};
    Node_Vec[3]  = {2,4,9,10};
    Node_Vec[4]  = {1,3};
    Node_Vec[5]  = {2,6,7,8};
    Node_Vec[6]  = {5};
    Node_Vec[7]  = {2,5,8};
    Node_Vec[8]  = {2,5,7};
    Node_Vec[9]  = {3};
    Node_Vec[10] = {3};
    breadth_first_search(1);

    return 0;
}