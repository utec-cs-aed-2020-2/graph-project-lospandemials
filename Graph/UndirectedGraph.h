#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
    UnDirectedGraph() : Graph<TV, TE>() {

    }
    ~UnDirectedGraph(){

    }

    bool insertVertex(std::string id, TV vertex) override;
    bool createEdge(std::string id1, std::string id2, TE w) override;
    bool deleteVertex(std::string id) override;
    bool deleteEdge(std::string id) override;
    
    void display();
};

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(std::string id, TV vertex){
    return;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(std::string id1, std::string id2, TE w){
    return;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(std::string id){
    return;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(std::string id){
    return;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display(){
    std::cout << "------------UnDirectedGraph------------\n";
    this->display();
}

#endif