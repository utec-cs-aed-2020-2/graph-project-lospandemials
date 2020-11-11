#ifndef GRAPH_H
#define GRAPH_H

#include "../lib.h"

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

//////////////////////////////////////////////////////

template<typename TV, typename TE>
struct Edge {
    Vertex<TV, TE>* vertexes[2];
    TE weight;
    Edge(Vertex<TV, TE>* v1, Vertex<TV, TE>* v2, TE weight){
        this->vertexes[0] = v1;
        this->vertexes[1] = v2;
        this->weight = weight;
    }
    void killSelf(){
        this->vertexes[0] = nullptr;
        this->vertexes[1] = nullptr;
        delete this;
    }
};

template<typename TV, typename TE>
struct Vertex {
    TV data;
    std::list<Edge<TV, TE>*> edges;
    Vertex(TV data){
        this->data = data;
    }
    void killSelf(){
        edges.clear();
        delete this;
    }
};

template<typename TV, typename TE>
class Graph{
private:    
    std::unordered_map<std::string, Vertex<TV, TE>*>  vertexes;
    
public:
    Graph(){}
    virtual bool insertVertex(std::string id, TV vertex) = 0;
    virtual bool createEdge(std::string id1, std::string id2, TE w) = 0;
    virtual bool deleteVertex(std::string id) = 0;
    virtual bool deleteEdge(std::string id) = 0;
    TE &operator()(std::string start, std::string end);
    float density();
    bool isDense(float threshold = 0.5);
    bool isConnected();
    bool isStronglyConnected();
    bool empty();
    void clear();
      
    void displayVertex(std::string id);
    bool findById(std::string id);
    void display();
};

template<typename TV, typename TE>
TE& Graph<TV, TE>::operator()(std::string start, std::string end){
    TE tmp;
    return tmp;
}

template<typename TV, typename TE>
float Graph<TV, TE>::density(){
    return 0.0;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::isDense(float threshold = 0.5){
    return true;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::isConnected(){
    return true;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::isStronglyConnected(){
    return true;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::empty(){
    return true;
}

template<typename TV, typename TE>
void Graph<TV, TE>::clear(){
    return;
}


template<typename TV, typename TE>
void Graph<TV, TE>::displayVertex(std::string id){
    return;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::findById(std::string id){
    return true;
}

template<typename TV, typename TE>
void Graph<TV, TE>::display(){
    return;
}

#endif