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
   
}

template<typename TV, typename TE>
void FloydWarshall<TV, TE>::FloydWarshallAlgorithm(distanceMatrixType &distances, pathMatrixType &paths){
    
}

template<typename TV, typename TE>
returnFloydWarshallType FloydWarshall<TV, TE>::apply(){
   
}

#endif