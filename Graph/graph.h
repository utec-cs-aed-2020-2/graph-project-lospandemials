#ifndef GRAPH_H
#define GRAPH_H

#include "../lib.h"

template<typename TV, typename TE>
struct Edge;

template<typename TV, typename TE>
struct Vertex;

template<typename TV, typename TE>
class Graph;

template<typename TV, typename TE>
class Kruskal;

template<typename TV, typename TE>
class Prim;
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
protected:    
    std::unordered_map<std::string, Vertex<TV, TE>*>  vertexes;
    bool BFSisConnected(std::string id);

public:
    virtual bool insertVertex(std::string id, TV vertex) = 0;
    virtual bool createEdge(std::string id1, std::string id2, TE w) = 0;
    virtual bool deleteVertex(std::string id) = 0;
    virtual bool deleteEdge(std::string id1, std::string id2) = 0;
    TE &operator()(std::string start, std::string end);
    float density();
    bool isDense(float threshold = 0.5);
    bool isConnected();
    bool isStronglyConnected();
    bool empty();
    void clear();
    virtual void display() = 0;

    friend class Prim<TV, TE>;
    friend class Kruskal<TV, TE>;
};

template<typename TV, typename TE>
TE& Graph<TV, TE>::operator()(std::string start, std::string end){
    TE tmp;
    return tmp;
}

template<typename TV, typename TE>
float Graph<TV, TE>::density(){
    float res = 0.0;
    return res;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::isDense(float threshold){
    //default = 0.5
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
    for(auto v : this->vertexes)
        for(Edge<TV, TE>* e : v.second->edges)    
            e->killSelf();
    for(auto v : this->vertexes)
        v.second->killSelf();
}

template<typename TV, typename TE>
bool Graph<TV, TE>::BFSisConnected(std::string id){
    Vertex<TV, TE>* curVertex = nullptr;
    for(auto p : this->vertexes){
        if(p.first == id){
            curVertex = p.second;
            break;
        }
    }
    if(!curVertex)  throw std::runtime_error("RUNTIME ERROR: id doesn't exist.");
    if(this->vertexes.size() <= 1)   return true;
    std::queue<Vertex<TV, TE>*> q;
    std::unordered_map<Vertex<TV, TE>*, bool> visited;
    for(auto p : this->vertexes)  visited[p.second] = false;
    q.push(curVertex);
    visited[curVertex] = true;
    while(!q.empty()){
        curVertex = q.front();
        q.pop();
        for(auto edge : curVertex->edges){
            if(!visited[edge->vertexes[1]]){
                visited[edge->vertexes[1]] = true;
                q.push(edge->vertexes[1]);
            }
        }
    }
    for(auto p : visited) if(!p.second) return false;
    return true;
}

template<typename TV, typename TE>
void Graph<TV, TE>::display(){
    for(auto p : this->vertexes){
        std::cout << p.first << " (" << p.second->data << "):  ";
        for(auto it = begin(p.second->edges); it != end(p.second->edges); ){
            std::cout << (*it)->vertexes[1]->data << "(" << (*it)->weight << ")";
            if(++it == end(p.second->edges))  break;
            std::cout << ", ";
        }
        std::cout << "\n";
    }
}

#endif