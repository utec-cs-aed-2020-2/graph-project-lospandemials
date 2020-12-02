#ifndef BFS_H
#define BFS_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class BFS{
private:
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    std::unordered_map<Vertex<TV, TE>*, bool> visited;
    void BFSAlgorithm(UnDirectedGraph<TV, TE>& result, std::string id);
    bool isUndirectedGraph;
public:
    BFS(Graph<TV, TE>* graph);
    UnDirectedGraph<TV, TE> apply(std::string id);
    UnDirectedGraph<TV, TE> apply();
};

template<typename TV, typename TE>
BFS<TV, TE>::BFS(Graph<TV, TE>* graph){
    DirectedGraph<TV, TE>* dg = dynamic_cast<DirectedGraph<TV, TE>*>(graph);
    if(dg){
        isUndirectedGraph = false;
        this->vertexes = dg->vertexes;
        return;
    }
    
    UnDirectedGraph<TV, TE>* ug = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);
    if(ug){
        isUndirectedGraph = true;
        this->vertexes = ug->vertexes;
        return;
    }
    throw std::runtime_error("RUNTIME ERROR: No graph.");
}

template<typename TV, typename TE>
void BFS<TV, TE>::BFSAlgorithm(UnDirectedGraph<TV, TE>& result, std::string id){
    std::queue<std::pair<Vertex<TV, TE>*, Vertex<TV, TE>*>> q;
    this->visited[this->vertexes[id]] = true;
    q.push({this->vertexes[id], nullptr});

    while(!q.empty()){
        std::pair<Vertex<TV, TE>*, Vertex<TV, TE>*> cur = q.front();
        q.pop();
        Vertex<TV, TE>* vertex = cur.first;
        Vertex<TV, TE>* parent = cur.second;
        
        if(!result.vertexes.count(vertex->id))
            result.insertVertex(vertex->id, vertex->data);
                
        if(parent){
            for(Edge<TV, TE>* edge : this->vertexes[parent->id]->edges){
                if(edge->vertexes[1] == vertex){
                    result.createEdge(parent->id, vertex->id, edge->weight);
                    break;
                }
            }
        }
    
        for(Edge<TV, TE>* edge : vertex->edges){
            if(!this->visited[edge->vertexes[1]]){
                this->visited[edge->vertexes[1]] = true;
                q.push({edge->vertexes[1], vertex});
            }
        }
    }
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> BFS<TV, TE>::apply(std::string id){
    if(!this->vertexes.count(id)) throw std::runtime_error("RUNTIME ERROR: Invalid id.");
    
    std::cout << "\nBFS from vertex: " << this->vertexes[id]->data << "\n";

    for(auto p : this->vertexes)
        this->visited[p.second] = false;

    UnDirectedGraph<TV, TE> result;
        
    BFSAlgorithm(result, id);

    for(auto p : this->vertexes){
        if(!this->visited[p.second]){
            std::cout << "WARNING: Some vertex was not visited.\n";
            break;
        }
    }
    return result;
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> BFS<TV, TE>::apply(){
    for(auto p : this->vertexes)
        this->visited[p.second] = false;

    UnDirectedGraph<TV, TE> result;
    
    for(auto p : this->vertexes)
        if(!this->visited[p.second])
            BFSAlgorithm(result, p.first);

    return result;
}

#endif