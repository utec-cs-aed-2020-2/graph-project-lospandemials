#ifndef GRAPHALGORITHMS_H
#define GRAPHALGORITHMS_H

#include "../lib.h"
#include "../Graph/UndirectedGraph.h"
#include "../Graph/DirectedGraph.h"
#include "../DisjoinSet/dsarray.h"

template<typename TV, typename TE>
struct CompareEdge { 
    bool operator()(Edge<TV, TE>* const& e1, Edge<TV, TE>* const& e2) { 
        return e1->weight > e2->weight; 
    } 
};

template<typename TV, typename TE>
struct ComparePairVertexTE { 
    bool operator()(std::pair<Vertex<TV, TE>*, TE> const& p1, std::pair<Vertex<TV, TE>*, TE> const& p2) { 
        return p1.second > p2.second; 
    }
};
#endif