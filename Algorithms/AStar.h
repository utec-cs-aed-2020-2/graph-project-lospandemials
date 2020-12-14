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


#endif