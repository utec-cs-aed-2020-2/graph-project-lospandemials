#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class Dijkstra{
private:
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    void DijkstraAlgorithm(parentUnorderedMapType &parents, distanceUnorderedMapType &distances, std::string id);
    #define INF std::numeric_limits<TE>::max();
public:
    Dijkstra(Graph<TV, TE>* graph);
    returnDijkstraType apply(std::string id);
};

template<typename TV, typename TE>
Dijkstra<TV, TE>::Dijkstra(Graph<TV, TE>* graph){
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

template<typename TV, typename TE>
void Dijkstra<TV, TE>::DijkstraAlgorithm(parentUnorderedMapType &parents, distanceUnorderedMapType &distances, std::string id){
    
}

template<typename TV, typename TE>
returnDijkstraType Dijkstra<TV, TE>::apply(std::string id){
   
}

#endif