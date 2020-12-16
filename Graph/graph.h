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
template<typename TV, typename TE>
class BFS;
template<typename TV, typename TE>
class DFS;
template<typename TV, typename TE>
class SCC;
template<typename TV, typename TE>
class Dijkstra;
template<typename TV, typename TE>
class FloydWarshall;
template<typename TV, typename TE>
class AStar;
template<typename TV, typename TE>
class BellmanFord;

class GUI;
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
    std::string id;
    std::list<Edge<TV, TE>*> edges;
    Vertex(TV data, std::string id){
        this->data = data;
        this->id = id;
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
    virtual ~Graph(){
        this->clear();
    }
    bool insertVertex(std::string id, TV vertex);
    virtual bool createEdge(std::string id1, std::string id2, TE w) = 0;
    bool deleteVertex(std::string id);
    virtual bool deleteEdge(std::string id1, std::string id2) = 0;
    bool operator()(std::string start, std::string end);
    bool operator()(std::string start, std::string end, int n); //For GUI
    bool operator()(std::string id);
    float density() const;
    bool isDense(float threshold = 0.5) const;
    virtual bool isConnected() = 0;
    virtual bool isStronglyConnected() = 0;
    virtual bool isBipartite() = 0;
    virtual bool isWeaklyConnected() = 0;
    bool empty();
    void clear();
    virtual void display() = 0;
    void graphSize();
    int numberOfVertexes();
    bool operator==(Graph& graph);

    friend class Prim<TV, TE>;
    friend class Kruskal<TV, TE>;
    friend class BFS<TV, TE>;
    friend class DFS<TV, TE>;
    friend class SCC<TV, TE>;
    friend class Dijkstra<TV, TE>;
    friend class FloydWarshall<TV, TE>;
    friend class AStar<TV,TE>;
    friend class BellmanFord<TV,TE>;
    
    friend class GUI;

};


template<typename TV, typename TE>
bool Graph<TV, TE>::insertVertex(std::string id, TV vertex){
    if(this->vertexes.count(id)){
        std::cout << "\n--- ERROR: " << id << " already exists\n";
        return false;
    }    
    Vertex<TV, TE>* newVertex = new Vertex<TV, TE>(vertex, id);
    this->vertexes[id] = newVertex;
    return true;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::deleteVertex(std::string id){
    if(!this->vertexes.count(id)){
        std::cout << "\n--- ERROR: Vertex was not deleted\n";
        return false;
    }
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
bool Graph<TV, TE>::operator()(std::string start, std::string end, int n){
    //For GUI
    if(!this->vertexes.count(start) || !this->vertexes.count(end) || start == end){
        return false;
    }    
    for(Edge<TV, TE>* edge : this->vertexes[start]->edges)
        if(edge->vertexes[1] == this->vertexes[end])
            return true;
    return false;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::operator()(std::string id){
    if(!this->vertexes.count(id)){
        std::cout << "Invalid id\n";
        return false;
    }    
    std::cout << id << " (" << this->vertexes[id]->data << "): <" << this->vertexes[id]->edges.size() << ">:\n";
    for(auto it = begin(this->vertexes[id]->edges); it != end(this->vertexes[id]->edges); ++it)
        std::cout << "\t" << (*it)->vertexes[1]->data << " (" << (*it)->weight << ")\n";
    std::cout << "\n";
    return true;
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
    if(empty()){
        std::cout << "Empty Graph\n";
        return;
    }
    for(auto p : this->vertexes){
        std::cout << p.first << " (" << p.second->data << ") <" << p.second->edges.size() << ">:\n";
        for(auto it = begin(p.second->edges); it != end(p.second->edges); ++it)
            std::cout << "\t" << (*it)->vertexes[1]->data << " (" << (*it)->weight << ")\n";
        std::cout << "\n";
    }
}

template<typename TV, typename TE>
void Graph<TV, TE>::graphSize(){
    int edges = 0;
    for(auto p : this->vertexes)  edges += p.second->edges.size();
    std::cout << "Graph size: " << this->vertexes.size() << " vertices - " << edges << " edges\n";
}

template<typename TV, typename TE>
int Graph<TV, TE>::numberOfVertexes(){
    return this->vertexes.size();
}

template<typename TV, typename TE>
bool Graph<TV, TE>::operator==(Graph& graph){
    if(this->vertexes.size() != graph.vertexes.size())return false;
    for(auto p : this->vertexes){
        std::string id = p.first;
        if(!graph.vertexes.count(id))  return false;
        if(p.second->id != graph.vertexes[id]->id) return false;
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