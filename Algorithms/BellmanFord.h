#ifndef BELLMANFORD_H
#define BELLMANFORD_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class BellmanFord{
private:
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    void BellmanFordAlgorithm(distanceUnorderedMapType &distances, parentUnorderedMapType &parents, std::vector<std::string> order);
    bool BellmanFordRelax(distanceUnorderedMapType &distances, parentUnorderedMapType &parents, std::vector<std::string> order);
#define INF std::numeric_limits<TE>::max();
public:
    BellmanFord(Graph<TV, TE>* graph);
    returnBellmanFordType apply(std::string id);
};


#endif