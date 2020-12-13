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
    std::priority_queue<
        std::pair<Vertex<TV, TE>*, TE>, 
        std::vector<std::pair<Vertex<TV, TE>*, TE> >, 
        ComparePairVertexTE<TV, TE>> pq;
    
    TE maxVal = INF;
    std::unordered_map<Vertex<TV, TE>*, bool> visited;
    for(auto p : this->vertexes){
        parents[p.second] = nullptr;
        distances[p.second] = maxVal;
        visited[p.second] = false;
    }
    parents[this->vertexes[id]] = this->vertexes[id];
    distances[this->vertexes[id]] = 0;
    
    pq.push(std::make_pair(this->vertexes[id], 0));

    while(!pq.empty()){
        std::pair<Vertex<TV, TE>*, TE> cur = pq.top();
        pq.pop();
        if(visited[cur.first])
            continue;
        
        visited[cur.first] = true;

        for(Edge<TV, TE>* edge : cur.first->edges){
            if(!visited[edge->vertexes[1]]){
                if(distances[cur.first] + edge->weight < distances[edge->vertexes[1]]){
                    distances[edge->vertexes[1]] = distances[cur.first] + edge->weight;
                    pq.push(std::make_pair(edge->vertexes[1], distances[edge->vertexes[1]]));
                    parents[edge->vertexes[1]] = cur.first;
                }
            }
        }
    }
}

template<typename TV, typename TE>
returnDijkstraType Dijkstra<TV, TE>::apply(std::string id){
    parentUnorderedMapType parents;
    distanceUnorderedMapType distances;
    
    if(!this->vertexes.count(id)){
        std::cout << "ERROR: ID not found.\n";
        return std::make_pair(parents, distances);
    }

    std::cout << "\nDijkstra from vertex: " << this->vertexes[id]->data << "\n";
    
    DijkstraAlgorithm(parents, distances, id);

    return std::make_pair(parents, distances);
}

#endif