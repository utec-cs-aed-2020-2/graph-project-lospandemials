#ifndef DFS_H
#define DFS_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class DFS{
private:
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    std::unordered_map<Vertex<TV, TE>*, bool> visited;
    void DFSAlgorithm(Graph<TV, TE>& result, std::string id, std::string idParent = "");
    bool isUndirectedGraph;
public:
    DFS(Graph<TV, TE>* graph);
    UnDirectedGraph<TV, TE> u_apply(std::string id);
    UnDirectedGraph<TV, TE> u_apply();
    DirectedGraph<TV, TE> d_apply(std::string id);
    DirectedGraph<TV, TE> d_apply();
};

template<typename TV, typename TE>
DFS<TV, TE>::DFS(Graph<TV, TE>* graph){
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
void DFS<TV, TE>::DFSAlgorithm(Graph<TV, TE>& result, std::string id, std::string idParent){
    Vertex<TV, TE>* vertex = this->vertexes[id];
    Vertex<TV, TE>* parent = idParent != "" ? this->vertexes[idParent] : nullptr;

    this->visited[vertex] = true;
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
    
    for(Edge<TV, TE>* edge : vertex->edges)
        if(!this->visited[edge->vertexes[1]])
            DFSAlgorithm(result, edge->vertexes[1]->id, vertex->id);
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> DFS<TV, TE>::u_apply(std::string id){
    UnDirectedGraph<TV, TE> result;
    
    if(!isUndirectedGraph){
        std::cout << "ERROR: It isn't an undirected graph.\n";
        return result;
    }
    if(!this->vertexes.count(id)){
        std::cout << "ERROR: ID not found.\n";
        return result;
    }

    std::cout << "\nDFS from vertex: " << this->vertexes[id]->data << "\n";
    for(auto p : this->vertexes)
        this->visited[p.second] = false;
        
    DFSAlgorithm(result, id);

    for(auto p : this->vertexes){
        if(!this->visited[p.second]){
            std::cout << "WARNING: Some vertex was not visited.\n";
            break;
        }
    }
    return result;
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> DFS<TV, TE>::u_apply(){
    UnDirectedGraph<TV, TE> result;
    if(!isUndirectedGraph){
        std::cout << "ERROR: It isn't an undirected graph.\n";
        return result;
    }

    for(auto p : this->vertexes)
        this->visited[p.second] = false;
    
    auto it = begin(this->vertexes);
    std::cout << "\nDFS from vertex: " << (*it).second->data << "\n";
    DFSAlgorithm(result, (*it).first);

    for(auto p : this->vertexes)
        if(!this->visited[p.second])
            DFSAlgorithm(result, p.first);

    return result;
}

template<typename TV, typename TE>
DirectedGraph<TV, TE> DFS<TV, TE>::d_apply(std::string id){
    DirectedGraph<TV, TE> result;
    
    if(isUndirectedGraph){
        std::cout << "ERROR: It isn't a directed graph.\n";
        return result;
    }
    if(!this->vertexes.count(id)){
        std::cout << "ERROR: ID not found.\n";
        return result;
    }

    std::cout << "\nDFS from vertex: " << this->vertexes[id]->data << "\n";
    for(auto p : this->vertexes)
        this->visited[p.second] = false;
        
    DFSAlgorithm(result, id);

    for(auto p : this->vertexes){
        if(!this->visited[p.second]){
            std::cout << "WARNING: Some vertex was not visited.\n";
            break;
        }
    }
    return result;
}

template<typename TV, typename TE>
DirectedGraph<TV, TE> DFS<TV, TE>::d_apply(){
    DirectedGraph<TV, TE> result;
    if(isUndirectedGraph){
        std::cout << "ERROR: It isn't a directed graph.\n";
        return result;
    }

    for(auto p : this->vertexes)
        this->visited[p.second] = false;
    
    auto it = begin(this->vertexes);
    std::cout << "\nDFS from vertex: " << (*it).second->data << "\n";
    DFSAlgorithm(result, (*it).first);

    for(auto p : this->vertexes)
        if(!this->visited[p.second])
            DFSAlgorithm(result, p.first);

    return result;
}

#endif