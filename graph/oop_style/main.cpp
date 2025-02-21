#include <memory>
#include "graph.h"

int main()
{
    shared_ptr<Graph> weighter_graph = make_shared<WeightedUndirectedGraph>();
    weighter_graph->input();
    weighter_graph->print_weight();

    return 0;
}