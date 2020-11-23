#ifndef KRUSKAL_H
#define KRUSKAL_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class Kruskal{
private:
    std::unordered_map<Vertex<TV, TE>*, std::string> ids;
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    std::vector<Vertex<TV, TE>*> data;
public:
    Kruskal(Graph<TV, TE>* graph);
    UnDirectedGraph<TV, TE> apply();
};

template<typename TV, typename TE>
Kruskal<TV, TE>::Kruskal(Graph<TV, TE>* graph){
    DirectedGraph<TV, TE>* dg = dynamic_cast<DirectedGraph<TV, TE>*>(graph);
    if(dg) throw std::runtime_error("RUNTIME ERROR: Directed graphs are not allowed.");
    
    UnDirectedGraph<TV, TE>* ug = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);
    if(!ug) throw std::runtime_error("RUNTIME ERROR: It is not an undirected graph.");
    this->vertexes = ug->vertexes;
    for(auto p : this->vertexes){
        this->ids[p.second] = p.first;
        this->data.push_back(p.second);
    }
}

template<typename TV, typename TE>
UnDirectedGraph<TV, TE> Kruskal<TV, TE>::apply(){
    UnDirectedGraph<TV, TE> result;
    std::priority_queue<Edge<TV, TE>*, std::vector<Edge<TV, TE>*>, CompareEdge<TV, TE>> pq;
    for(auto p : this->vertexes)  for(auto e : p.second->edges)   pq.push(e);
    
    DisjoinSetArray<Vertex<TV, TE>*> ds(data);
    ds.MakeSet();
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        if(ds.FindT(cur->vertexes[0]) != ds.FindT(cur->vertexes[1])){
            Vertex<TV, TE>* vertex1 = cur->vertexes[0];
            Vertex<TV, TE>* vertex2 = cur->vertexes[1];
            if(!result.vertexes.count(ids[vertex1]))
                result.insertVertex(ids[vertex1], vertex1->data);
            if(!result.vertexes.count(ids[vertex2]))
                result.insertVertex(ids[vertex2], vertex2->data);

            result.createEdge(ids[vertex1], ids[vertex2], cur->weight);
            ds.Union(vertex1, vertex2);
        }
    }
    return result;
}

#endif