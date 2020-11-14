#ifndef UNDIRECTEDGRAPH_H
#define UNDIRECTEDGRAPH_H

#include "graph.h"

template<typename TV, typename TE>
class UnDirectedGraph : public Graph<TV, TE>{
public:
    UnDirectedGraph() {

    }
    ~UnDirectedGraph(){
        this->clear();
    }

    bool insertVertex(std::string id, TV vertex) override;
    bool createEdge(std::string id1, std::string id2, TE w) override;
    bool deleteVertex(std::string id) override;
    bool deleteEdge(std::string id1, std::string id2) override;
    
    void display();
};

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::insertVertex(std::string id, TV vertex){
    if(this->vertexes.count(id))    return false;
    Vertex<TV, TE>* newVertex = new Vertex<TV, TE>(vertex);
    this->vertexes[id] = newVertex;
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::createEdge(std::string id1, std::string id2, TE w){
    if(!this->vertexes.count(id1) && !this->vertexes.count(id2))    return false;
    Vertex<TV, TE>* vertex1 = this->vertexes[id1];
    Vertex<TV, TE>* vertex2 = this->vertexes[id2];
    bool flag = false;
    for(auto e : vertex1->edges)
        if(e->vertexes[1] == vertex2)    return false;
    Edge<TV, TE>* newEdge1 = new Edge<TV, TE>(vertex1, vertex2, w);
    Edge<TV, TE>* newEdge2 = new Edge<TV, TE>(vertex2, vertex1, w);
    vertex1->edges.push_back(newEdge1);
    vertex2->edges.push_back(newEdge2);
    return true;
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteVertex(std::string id){
    if(!this->vertexes.count(id))    return false;
    for(Edge<TV, TE>* e : this->vertexes[id]->edges){
        Vertex<TV, TE>* vertex = e->vertexes[1];
        for(auto it = begin(vertex->edges); it != end(vertex->edges); ++it){
            if((*it)->vertexes[1] == this->vertexes[id]){
                (*it)->killSelf();
                vertex->edges.erase(it);
                break;
            }
        }
        e->killSelf();
    }
    this->vertexes[id]->killSelf();
    this->vertexes.erase(id);
    return true;    
}

template<typename TV, typename TE>
bool UnDirectedGraph<TV, TE>::deleteEdge(std::string id1, std::string id2){
    if(!this->vertexes.count(id1))    return false;
    if(!this->vertexes.count(id2))    return false;
    bool flag = false; //Para saber si existe un edge entre id1 y id2
    for(auto it = begin(this->vertexes[id1]->edges); it != end(this->vertexes[id1]->edges); ++it){
        if((*it)->vertexes[1] == this->vertexes[id2]){
            (*it)->killSelf();
            this->vertexes[id1]->edges.erase(it);
            flag = true;
            break;
        }
    }
    if(!flag)   return false;
    for(auto it = begin(this->vertexes[id2]->edges); it != end(this->vertexes[id2]->edges); ++it){
        if((*it)->vertexes[1] == this->vertexes[id1]){
            (*it)->killSelf();
            this->vertexes[id2]->edges.erase(it);
            break;
        }
    }
    return true;
}

template<typename TV, typename TE>
void UnDirectedGraph<TV, TE>::display(){
    std::cout << "------------UnDirectedGraph------------\n";
    Graph<TV, TE>::display();
}

#endif