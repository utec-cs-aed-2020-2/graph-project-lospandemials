#ifndef DIRECTEDGRAPH_H
#define DIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class DirectedGraph : public Graph<TV, TE>{
public:
    DirectedGraph(){}
    ~DirectedGraph(){}
    bool createEdge(std::string id1, std::string id2, TE w) override;
    bool deleteEdge(std::string id1, std::string id2) override;
    bool isConnected() override;
    bool isStronglyConnected() override;
    bool isBipartite() override;
    void display() override;
};


template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::createEdge(std::string id1, std::string id2, TE w){
    if(!this->vertexes.count(id1) || !this->vertexes.count(id2)){
        std::cout << "\n--- ERROR: IDs not found.\n";
        return false;
    }    
    if(id1 == id2){
        std::cout << "\n--- ERROR: IDs are equal.\n";
        return false;
    }    
    Vertex<TV, TE>* vertex1 = this->vertexes[id1];
    Vertex<TV, TE>* vertex2 = this->vertexes[id2];
    for(auto e : vertex1->edges)
        if(e->vertexes[1] == vertex2)
            return false;
    Edge<TV, TE>* newEdge1 = new Edge<TV, TE>(vertex1, vertex2, w);
    vertex1->edges.push_back(newEdge1);
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::deleteEdge(std::string id1, std::string id2){
    if(id1 == id2 || !this->vertexes.count(id1) || !this->vertexes.count(id2))    return false;
    for(auto it = begin(this->vertexes[id1]->edges); it != end(this->vertexes[id1]->edges); ++it){
        if((*it)->vertexes[1] == this->vertexes[id2]){
            (*it)->killSelf();
            this->vertexes[id1]->edges.erase(it);
            return true;
        }
    }
    return false;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isConnected(){
    std::cout << "\n--- ERROR: This is directed graph\n";
    return false;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isStronglyConnected(){
    //Hacer un BFS por cada nodo O(V*(V+E))
    //kosaraju's BFS, dos BFS O(V+E)
    if(this->vertexes.size() <= 1)  return false;
    auto it = begin(this->vertexes);
    std::string id = (*it).first;
    if(!this->BFSisConnected(id)) return false;
    
    std::unordered_map<Vertex<TV, TE>*, std::string> ids;
    DirectedGraph<TV, TE> complementGraph;
    for(auto p : this->vertexes){
        complementGraph.insertVertex(p.first, p.second->data);
        ids[p.second] = p.first;
    }
    for(auto p : this->vertexes)
        for(auto e : p.second->edges)
            complementGraph.createEdge(ids[e->vertexes[1]], ids[e->vertexes[0]], e->weight);
    if(!complementGraph.BFSisConnected(id)) return false;
    return true;
}

template<typename TV, typename TE>
bool DirectedGraph<TV, TE>::isBipartite(){

    std::cout << "\n--- ERROR: This is directed graph\n";
    return false;
}

template<typename TV, typename TE>
void DirectedGraph<TV, TE>::display(){
    std::cout << "-------------DirectedGraph------------\n";
    Graph<TV, TE>::display();
}

#endif