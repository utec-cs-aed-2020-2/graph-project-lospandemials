#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
    DirectedGraph() : Graph<TV, TE>() {

    }
    ~DirectedGraph(){

    }

    bool insertVertex(std::string id, TV vertex) override;
    bool createEdge(std::string id1, std::string id2, TE w) override;
    bool deleteVertex(std::string id) override;
    bool deleteEdge(std::string id) override;
    
    void display();
};

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::insertVertex(std::string id, TV vertex){
    return;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(std::string id1, std::string id2, TE w){
    return;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteVertex(std::string id){
    return;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(std::string id){
    return;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display(){
    std::cout << "-------------DirectedGraph-------------\n";
    this->display();
}

#endif