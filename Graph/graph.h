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
protected:    
    std::unordered_map<std::string, Vertex<TV, TE>*>  vertexes;
    
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
      
    void displayVertex(std::string id);
    bool findById(std::string id);
    virtual void display() = 0;
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
void Graph<TV, TE>::displayVertex(std::string id){
    return;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::findById(std::string id){
    return this->vertexes.count(id);
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


/*
    void displayVertex(int id){
        if(!findById(id))   throw "Invalid id";
        cout << vertexes[id]->data << ":   ";
        for(auto it = vertexes[id]->edges.begin(); it != vertexes[id]->edges.end(); ){
            if((*it)->vertexes[0]->data == vertexes[id]->data)     
                cout << (*it)->vertexes[1]->data << "(" << (*it)->weight << ")";
            else                                                            
                cout << (*it)->vertexes[0]->data << "(" << (*it)->weight << ")";
            if(++it == vertexes[id]->edges.end())  break;
            cout << ", ";
        }
        cout << endl;
    }
    
    /*algorithms
    Graph<TV, TE> execKruskal();
    Graph<TV, TE> execDFS();
    Graph<TV, TE> execBFS();
    bool isConnected();
};

template<typename TV, typename TE>
struct CompareEdge { 
    bool operator()(Edge<TV, TE>* const& e1, Edge<TV, TE>* const& e2) { 
        return e1->weight > e2->weight; 
    } 
};

template<typename TV, typename TE>
Graph<TV, TE> Graph<TV, TE>::execKruskal(){
    Graph<TV, TE> mst;
    priority_queue<Edge<TV, TE>*, vector<Edge<TV, TE>*>, CompareEdge<TV, TE>> pq;

    for(auto v : vertexes)  for(auto e : v.second->edges)   pq.push(e);
    
    vector<Vertex<TV, TE>*> data;
    for(auto v : vertexes)  data.push_back(v.second);
    DisjoinSetArray<Vertex<TV, TE>*> ds(data);
    ds.MakeSet();

    int i = 1;
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();

        if(ds.FindT(cur->vertexes[0]) != ds.FindT(cur->vertexes[1])){
            if(!mst.findIndexByData(cur->vertexes[0]->data)){
                mst.insertVertex(i, cur->vertexes[0]->data);
                ++i;
            }   
            if(!mst.findIndexByData(cur->vertexes[1]->data)){
                mst.insertVertex(i, cur->vertexes[1]->data);
                ++i;
            }   
            mst.createEdge(mst.findIndexByData(cur->vertexes[0]->data), mst.findIndexByData(cur->vertexes[1]->data), cur->weight);
            ds.UnionT(cur->vertexes[0], cur->vertexes[1]);
        }
    }

    return mst;
}

template<typename TV, typename TE>
void DFS(Graph<TV, TE> &dfs, unordered_map<Vertex<TV, TE>*, bool> &visited, Vertex<TV, TE>* vertex, Vertex<TV, TE>* parent = nullptr){
    visited[vertex] = true;
    if(!dfs.findIndexByData(vertex->data))
        dfs.insertVertex(dfs.nodes() + 1, vertex->data);

    if(parent){
        for(auto e : parent->edges){
        if((e->vertexes[0]->data == parent->data && e->vertexes[1]->data == vertex->data) || (e->vertexes[1]->data == parent->data && e->vertexes[0]->data == vertex->data) )
            dfs.createEdge(dfs.findIndexByData(parent->data), dfs.findIndexByData(vertex->data), e->weight);
        }
    }
    for(auto e : vertex->edges){
        Vertex<TV, TE>* adj;
        if(e->vertexes[0]->data == vertex->data)  adj = e->vertexes[1];
        else  adj = e->vertexes[0];
        if(!visited[adj])
        DFS(dfs, visited, adj, vertex);
    }
}

template<typename TV, typename TE>
Graph<TV, TE> Graph<TV, TE>::execDFS(){
    Graph<TV, TE> dfs;
    unordered_map<Vertex<TV, TE>*, bool> visited;
    for(auto v : vertexes)  visited[v.second] = false;
    for(int i=1; i<=visited.size(); ++i)  if(!visited[vertexes[i]]) DFS(dfs, visited, vertexes[i]);
    return dfs;
}

template<typename TV, typename TE>
void BFS(Graph<TV, TE> &bfs, unordered_map<Vertex<TV, TE>*, bool> &visited, Vertex<TV, TE>* vertex){
    queue<pair<Vertex<TV, TE>*, Vertex<TV, TE>*>> q;
    visited[vertex] = true;
    q.push({vertex, nullptr});

    while(!q.empty()){
        pair<Vertex<TV, TE>*, Vertex<TV, TE>*> cur = q.front();
        q.pop();
        Vertex<TV, TE>* vertex = cur.first;
        Vertex<TV, TE>* parent = cur.second;
        if(!bfs.findIndexByData(vertex->data))
        bfs.insertVertex(bfs.nodes() + 1, vertex->data);
        
        if(parent){
            for(auto e : parent->edges){
                if((e->vertexes[0]->data == parent->data && e->vertexes[1]->data == vertex->data) || (e->vertexes[1]->data == parent->data && e->vertexes[0]->data == vertex->data) )
                bfs.createEdge(bfs.findIndexByData(parent->data), bfs.findIndexByData(vertex->data), e->weight);
            }
        }
    
        for(auto e : vertex->edges){
            Vertex<TV, TE>* adj;
            if(e->vertexes[0]->data == vertex->data)  adj = e->vertexes[1];
            else  adj = e->vertexes[0];
            if(!visited[adj]){
                visited[adj] = true;
                q.push({adj, vertex});
            }
        }
    }
}

template<typename TV, typename TE>
Graph<TV, TE> Graph<TV, TE>::execBFS(){
    Graph<TV, TE> bfs;
    unordered_map<Vertex<TV, TE>*, bool> visited;
    for(auto v : vertexes)  visited[v.second] = false;
    for(int i=1; i<=visited.size(); ++i) if(!visited[vertexes[i]]) BFS(bfs, visited, vertexes[i]);
    return bfs;
}

template<typename TV, typename TE>
bool Graph<TV, TE>::isConnected(){
    Graph<TV, TE> bfs;
    unordered_map<Vertex<TV, TE>*, bool> visited;
    for(auto v : vertexes)  visited[v.second] = false;
    BFS(bfs, visited, vertexes[1]);
    return nodes() == bfs.nodes();
}
*/