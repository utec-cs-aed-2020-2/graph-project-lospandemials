#ifndef FLOYDWARSHALL_H
#define FLOYDWARSHALL_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class FloydWarshall{
private:
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    void FloydWarshallAlgorithm(distanceMatrixType &distances, pathMatrixType &paths);
    #define INF std::numeric_limits<TE>::max();
public:
    FloydWarshall(Graph<TV, TE>* graph);
    returnFloydWarshallType apply();
};

template<typename TV, typename TE>
FloydWarshall<TV, TE>::FloydWarshall(Graph<TV, TE>* graph){
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
void FloydWarshall<TV, TE>::FloydWarshallAlgorithm(distanceMatrixType &distances, pathMatrixType &paths){
    TE maxVal = INF;
    for(auto k : distances){
        for(auto i : distances){
            for(auto j : distances){
                if(i.first != k.first && j.first != k.first){
                    if(distances[i.first][k.first] != maxVal && distances[k.first][j.first] != maxVal){
                        if(distances[i.first][k.first] + distances[k.first][j.first] < distances[i.first][j.first]){
                            distances[i.first][j.first] = distances[i.first][k.first] + distances[k.first][j.first];
                            paths[i.first][j.first] = k.first;
                        }
                    }
                }
            }
        }
    }
}

template<typename TV, typename TE>
returnFloydWarshallType FloydWarshall<TV, TE>::apply(){
    distanceMatrixType distances;
    pathMatrixType paths;
    for(auto i : this->vertexes){
        for(auto j : this->vertexes){
            if(i.second->id == j.second->id)  distances[i.second->id][j.second->id] = 0;
            else    distances[i.second->id][j.second->id] = INF;
            if(i.second->id == j.second->id)  paths[i.second->id][j.second->id] = "-";
            else    paths[i.second->id][j.second->id] = i.second->id;
        }
    }

    for(auto p : this->vertexes)    
        for(Edge<TV, TE>* edge : p.second->edges)   
            distances[edge->vertexes[0]->id][edge->vertexes[1]->id] = edge->weight;

    FloydWarshallAlgorithm(distances, paths);

    return std::make_pair(distances, paths);
}

#endif