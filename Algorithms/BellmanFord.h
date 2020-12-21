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
BellmanFord<TV, TE>::BellmanFord(Graph<TV, TE>* graph){
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

template<typename TV, typename TE>
void BellmanFord<TV, TE>::BellmanFordAlgorithm(distanceUnorderedMapType &distances, parentUnorderedMapType &parents, std::vector<std::string> order){
    TE maxVal = INF;
    for(int i=1; i<this->vertexes.size(); ++i){
        if(!BellmanFordRelax(distances, parents, order)) break;
    }
        
    if(BellmanFordRelax(distances, parents, order))
        std::cout << "\n.......¡Negative cycle found!.......\n";
}

template<typename TV, typename TE>
returnBellmanFordType BellmanFord<TV, TE>::apply(std::string id){
    distanceUnorderedMapType distances;
    parentUnorderedMapType parents;

    if(!this->vertexes.count(id)){
        std::cout << "ERROR: ID not found.\n";
        return std::make_pair(parents, distances);
    }

    std::cout << "\nBellman Ford from vertex: " << this->vertexes[id]->data << "\n";
    
    TE maxVal = INF;
    std::vector<std::string> order;
    order.push_back(id);
    for(auto p : this->vertexes){
        if(p.first == id)   distances[p.second] = 0;
        else    distances[p.second] = maxVal;
        parents[p.second] = nullptr;
        if(p.first != id)   order.push_back(p.first);
    }
    
    BellmanFordAlgorithm(distances, parents, order);
    return std::make_pair(parents, distances);
}

#endif