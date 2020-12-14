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

template<typename TV, typename TE>
bool BellmanFord<TV, TE>::BellmanFordRelax(distanceUnorderedMapType &distances, parentUnorderedMapType &parents, std::vector<std::string> order){
    TE maxVal = INF;
    bool flag = false;
    for(std::string id : order){
        for(Edge<TV, TE>* edge : this->vertexes[id]->edges){
            if(distances[edge->vertexes[0]] != maxVal && distances[edge->vertexes[0]] + edge->weight < distances[edge->vertexes[1]]){
                distances[edge->vertexes[1]] = distances[edge->vertexes[0]] + edge->weight;
                parents[edge->vertexes[1]] = edge->vertexes[0];
                flag = true;
            }
        }
    }
    return flag;
}

#endif