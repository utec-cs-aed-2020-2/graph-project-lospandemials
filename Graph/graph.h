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

//////////////////////////////////////////////////////

template<typename TV, typename TE>
class Graph{
protected:    
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    bool BFSisConnected(std::string id);
public:
    Graph(){}
    ~Graph(){
        this->clear();
    }
    bool insertVertex(std::string id, TV vertex);
    virtual bool createEdge(std::string id1, std::string id2, TE w) = 0;
    //virtual bool createEdge(std::string id1, std::string id2) = 0;
    bool deleteVertex(std::string id);
    virtual bool deleteEdge(std::string id1, std::string id2) = 0;
    bool operator()(std::string start, std::string end);
    float density() const;
    bool isDense(float threshold = 0.5) const;
    virtual bool isConnected() = 0;
    virtual bool isStronglyConnected() = 0;
    virtual bool isBipartite() = 0;
    bool empty();
    void clear();
    virtual void display() = 0;
    bool displayVertex(std::string id);
    bool twoVerticesPath(std::string id1, std::string id2);
    void graphSize();
    bool operator==(Graph& graph);

    friend class Prim<TV, TE>;
    friend class Kruskal<TV, TE>;
};


template<typename TV, typename TE>
bool Graph<TV, TE>::insertVertex(std::string id, TV vertex){
    if(this->vertexes.count(id))    return false;
    Vertex<TV, TE>* newVertex = new Vertex<TV, TE>(vertex);
    this->vertexes[id] = newVertex;
    return true;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::deleteVertex(std::string id){
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
bool Graph<TV, TE>::operator()(std::string start, std::string end){
    if(!this->vertexes.count(start) || !this->vertexes.count(end) || start == end){
        std::cout << "Invalid ids\n";
        return false;
    }    
    
    for(Edge<TV, TE>* edge : this->vertexes[start]->edges){
        if(edge->vertexes[1] == this->vertexes[end]){
            std::cout << "There is a path from " << this->vertexes[start]->data << " to " << this->vertexes[end]->data << " with a distance of " << edge->weight << "\n";
            return true;
        }
    }
    std::cout << "No path found\n";
    return false;
}

template<typename TV, typename TE>
float Graph<TV, TE>::density() const{
    float d = 0.0;
    if(this->vertexes.size() <= 1)  return d;
    int edges = 0;
    for(auto p : this->vertexes)  edges += p.second->edges.size();
    d = ((float)edges)/ this->vertexes.size() / (this->vertexes.size() - 1);
    return d;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::isDense(float threshold) const{
    return density() >= threshold;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::empty(){
    return this->vertexes.size() == 0;
}

template<typename TV, typename TE>
void Graph<TV, TE>::clear(){
    for(auto &v : this->vertexes)
        for(Edge<TV, TE>* &e : v.second->edges)
            e->killSelf();
    for(auto &v : this->vertexes)
        if(v.second)
            v.second->killSelf();
    this->vertexes.clear();
}

template<typename TV, typename TE>
bool Graph<TV, TE>::BFSisConnected(std::string id){
    if(!this->vertexes.count(id)) throw std::runtime_error("RUNTIME ERROR: No ID found.");

    Vertex<TV, TE>* curVertex = this->vertexes[id];
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

template<typename TV, typename TE>
bool Graph<TV, TE>::displayVertex(std::string id){
    if(!this->vertexes.count(id)){
        std::cout << "No ID found.\n";
        return false;
    }
    std::cout << id << " (" << this->vertexes[id]->data << "):  ";
    for(auto it = begin(this->vertexes[id]->edges); it != end(this->vertexes[id]->edges); ){
        std::cout << (*it)->vertexes[1]->data << "(" << (*it)->weight << ")";
        if(++it == end(this->vertexes[id]->edges))  break;
        std::cout << ", ";
    }
    std::cout << "\n";
    return true;
}

template<typename TV, typename TE>
void Graph<TV, TE>::graphSize(){
    int edges = 0;
    for(auto p : this->vertexes)  edges += p.second->edges.size();
    std::cout << "Graph size: " << this->vertexes.size() << " vertices - " << edges << " edges\n";
}

template<typename TV, typename TE>
bool Graph<TV, TE>::operator==(Graph& graph){
    if(this->vertexes.size() != graph.vertexes.size())return false;
    for(auto p : this->vertexes){
        std::string id = p.first;
        if(!graph.vertexes.count(id))  return false;
        if(p.second->data != graph.vertexes[id]->data) return false;
        if(p.second->edges.size() != graph.vertexes[id]->edges.size()) return false;
        for(auto e1 : p.second->edges){
            bool flag = false;
            for(auto e2 : graph.vertexes[id]->edges){
                if(e1->vertexes[1]->data == e2->vertexes[1]->data){
                    if(e1->weight == e2->weight)  flag = true;
                    break;
                }
            }
            if(!flag) return false;
        }
    }
    return true;
}

#endif