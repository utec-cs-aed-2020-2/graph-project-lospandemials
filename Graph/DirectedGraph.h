#ifndef NONDIRECTEDGRAPH_H
#define NONDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
public:
    DirectedGraph(){

    }
    ~DirectedGraph(){
        this->clear();
    }

    bool insertVertex(std::string id, TV vertex) override;
    bool createEdge(std::string id1, std::string id2, TE w) override;
    bool deleteVertex(std::string id) override;
    bool deleteEdge(std::string id1, std::string id2) override;
    
    void display();
};

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::insertVertex(std::string id, TV vertex){
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(std::string id1, std::string id2, TE w){
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteVertex(std::string id){
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(std::string id1, std::string id2){
    return true;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display(){
    std::cout << "-------------DirectedGraph-------------\n";
    this->display();
}

#endif