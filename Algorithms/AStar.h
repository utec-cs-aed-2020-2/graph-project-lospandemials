#ifndef ASTAR_H
#define ASTAR_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class AStar{
private:
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    void AStarAlgorithm(distanceUnorderedMapAStarType &distancesAStar,
                        parentUnorderedMapType &parents,
                        std::unordered_map<std::string, TE> hn,
                        std::string idFrom, std::string idTo);
public:
    AStar(Graph<TV, TE>* graph);
    returnAStarType apply(std::string idFrom, std::string idTo, std::unordered_map<std::string, TE> hn);
};

template<typename TV, typename TE>
AStar<TV, TE>::AStar(Graph<TV, TE>* graph){
    DirectedGraph<TV, TE>* dg = dynamic_cast<DirectedGraph<TV, TE>*>(graph);
    if(dg){
        this->vertexes = dg->vertexes;
        return;
    }
    UnDirectedGraph<TV, TE>* ug = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);
    if(ug){
        this->vertexes = ug->vertexes;
        return;
    }
    throw std::runtime_error("RUNTIME ERROR: No graph.");
}

#endif