#ifndef PRIM_H
#define PRIM_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class Prim{
private:
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    std::vector<Vertex<TV, TE>*> data;
    std::unordered_map<Vertex<TV, TE>*, bool> visited;
    void PrimAlgorithm(UnDirectedGraph<TV, TE>& result, std::string id, DisjoinSetArray<Vertex<TV, TE>*>& ds);
public:
    Prim(Graph<TV, TE>* graph);
    UnDirectedGraph<TV, TE> apply(std::string id);
    UnDirectedGraph<TV, TE> apply();
};

template<typename TV, typename TE>
Prim<TV, TE>::Prim(Graph<TV, TE>* graph){
    DirectedGraph<TV, TE>* dg = dynamic_cast<DirectedGraph<TV, TE>*>(graph);
    if(dg) throw std::runtime_error("RUNTIME ERROR: Directed graphs are not allowed.");
    
    UnDirectedGraph<TV, TE>* ug = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);
    if(!ug) throw std::runtime_error("RUNTIME ERROR: It is not an undirected graph.");
    
    this->vertexes = ug->vertexes;
    for(auto p : this->vertexes)
        this->data.push_back(p.second);
}

template<typename TV, typename TE>
void Prim<TV, TE>::PrimAlgorithm(UnDirectedGraph<TV, TE>& result, std::string id, DisjoinSetArray<Vertex<TV, TE>*>& ds){
    std::priority_queue<Edge<TV, TE>*, std::vector<Edge<TV, TE>*>, CompareEdge<TV, TE>> pq;
    
    for(auto e : this->vertexes[id]->edges)   pq.push(e);
    this->visited[this->vertexes[id]] = true;

    while(!pq.empty()){
        Edge<TV, TE>* cur = pq.top();
        pq.pop();
        if(ds.FindT(cur->vertexes[0]) != ds.FindT(cur->vertexes[1])){
            Vertex<TV, TE>* vertex1 = cur->vertexes[0];
            Vertex<TV, TE>* vertex2 = cur->vertexes[1];
            if(!result.vertexes.count(vertex1->id))
                result.insertVertex(vertex1->id, vertex1->data);
            if(!result.vertexes.count(vertex2->id))
                result.insertVertex(vertex2->id, vertex2->data);

            result.createEdge(vertex1->id, vertex2->id, cur->weight);
            ds.Union(vertex1, vertex2);

            this->visited[cur->vertexes[0]] = true;
            if(!this->visited[cur->vertexes[1]]){
                for(Edge<TV, TE>* e : cur->vertexes[1]->edges)
                    if(!this->visited[e->vertexes[1]])
                        pq.push(e);
                this->visited[cur->vertexes[1]] = true;
            }
        }
    }
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> Prim<TV, TE>::apply(std::string id){
    UnDirectedGraph<TV, TE> result;

    if(!this->vertexes.count(id)){
        std::cout << "ERROR: ID not found.\n";
        return result;
    }
    
    std::cout << "Prim from vertex: " << this->vertexes[id]->data << "\n";

    for(auto p : this->vertexes)
        this->visited[p.second] = false;

    DisjoinSetArray<Vertex<TV, TE>*> ds(data);
    ds.MakeSet();
    
    PrimAlgorithm(result, id, ds);

    for(auto p : this->vertexes){
        if(!this->visited[p.second]){
            std::cout << "WARNING: Some vertex was not visited.\n";
            break;
        }
    }
    return result;
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> Prim<TV, TE>::apply(){
    for(auto p : this->vertexes)
        this->visited[p.second] = false;

    UnDirectedGraph<TV, TE> result;
    DisjoinSetArray<Vertex<TV, TE>*> ds(data);
    ds.MakeSet();
    
    for(auto p : this->vertexes)
        if(!this->visited[p.second])
            PrimAlgorithm(result, p.first, ds);

    return result;
}

#endif