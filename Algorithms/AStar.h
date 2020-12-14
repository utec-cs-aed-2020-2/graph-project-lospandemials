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

template<typename TV, typename TE>
void AStar<TV, TE>::AStarAlgorithm(distanceUnorderedMapAStarType &distancesAStar, parentUnorderedMapType &parents, std::unordered_map<std::string, TE> hn, std::string idFrom, std::string idTo){
    std::priority_queue<
            std::pair<Vertex<TV, TE>*, TE>,
            std::vector<std::pair<Vertex<TV, TE>*, TE> >,
    ComparePairVertexTE<TV, TE>> pq;
    std::unordered_map<Vertex<TV, TE>*, bool> visited;
    for(auto p : this->vertexes)    visited[p.second] = false;
    parents[this->vertexes[idFrom]] = this->vertexes[idFrom];

    pq.push(std::make_pair(this->vertexes[idFrom], 0 + hn[idFrom]));
    distancesAStar[this->vertexes[idFrom]] = std::make_pair(0, hn[idFrom]);

    while(!pq.empty()){
        Vertex<TV, TE>* curVertex = pq.top().first;
        TE fn = pq.top().second;
        pq.pop();
        if(visited[curVertex])
            continue;

        visited[curVertex] = true;
        if(curVertex->id == idTo) break;

        for(Edge<TV, TE>* edge : curVertex->edges){
            Vertex<TV, TE>* toVertex = edge->vertexes[1];
            if(!visited[toVertex]){
                if(distancesAStar.count(toVertex)){
                    if(edge->weight + distancesAStar[curVertex].first + hn[toVertex->id] < distancesAStar[toVertex].second){
                        distancesAStar[toVertex] = std::make_pair(edge->weight + distancesAStar[curVertex].first, edge->weight + distancesAStar[curVertex].first + hn[toVertex->id]);
                        parents[toVertex] = curVertex;
                        pq.push(std::make_pair(toVertex, distancesAStar[toVertex].second));
                    }
                }else{
                    parents[toVertex] = curVertex;
                    distancesAStar[toVertex] = std::make_pair(edge->weight + distancesAStar[curVertex].first, edge->weight + distancesAStar[curVertex].first + hn[toVertex->id]);
                    pq.push(std::make_pair(toVertex, distancesAStar[toVertex].second));
                }
            }
        }
    }
}

#endif