#ifndef SCC_H
#define SCC_H

#include "graphAlgorithms.h"

template<typename TV, typename TE>
class SCC{
private:
    std::unordered_map<std::string, Vertex<TV, TE>*> vertexes;
    std::unordered_map<Vertex<TV, TE>*, bool> onStack;
    std::unordered_map<Vertex<TV, TE>*, int> idsDFS;
    std::unordered_map<Vertex<TV, TE>*, int> lowValues;
    std::stack<Vertex<TV, TE>*> st;
    int idDFS = 0;
    void SCCAlgorithm(std::string id);
public:
    SCC(Graph<TV, TE>* graph);
    returnSCCType apply();
};

template<typename TV, typename TE>
SCC<TV, TE>::SCC(Graph<TV, TE>* graph){
    UnDirectedGraph<TV, TE>* ug = dynamic_cast<UnDirectedGraph<TV, TE>*>(graph);
    if(ug) throw std::runtime_error("RUNTIME ERROR: Undirected graphs are not allowed.");
    
    DirectedGraph<TV, TE>* dg = dynamic_cast<DirectedGraph<TV, TE>*>(graph);
    if(!dg) throw std::runtime_error("RUNTIME ERROR: It is not a directed graph.");
    
    this->vertexes = dg->vertexes;
}

template<typename TV, typename TE>
void SCC<TV, TE>::SCCAlgorithm(std::string id){
    Vertex<TV, TE>* vertex = this->vertexes[id];

    this->st.push(vertex);
    this->onStack[vertex] = true;
    this->idsDFS[vertex] = this->lowValues[vertex] = this->idDFS++;

    for(Edge<TV, TE>* edge : vertex->edges){
        Vertex<TV, TE>* vertexTo = edge->vertexes[1];
        if(this->idsDFS[vertexTo] == -1)  
            SCCAlgorithm(vertexTo->id);
        if(this->onStack[vertexTo])    
            this->lowValues[vertex] = std::min(this->lowValues[vertex], this->lowValues[vertexTo]);
    }

    if(this->idsDFS[vertex] == this->lowValues[vertex]){
        while(!this->st.empty()){
            Vertex<TV, TE>* node = st.top();
            st.pop();
            this->onStack[node] = false;
            this->lowValues[node] = idsDFS[vertex];
            if(node == vertex)  break;
        }
    }

}

template<typename TV, typename TE>
returnSCCType SCC<TV, TE>::apply(){
    returnSCCType result;
    
    this->idDFS = 0;
    for(auto p : this->vertexes){
        this->onStack[p.second] = false;
        this->idsDFS[p.second] = -1;
        this->lowValues[p.second] = 0;
    }

    for(auto p : this->vertexes)
        if(this->idsDFS[p.second] == -1)
            SCCAlgorithm(p.first);
    
    std::unordered_set<int> groups;
    for(auto p : this->lowValues)   groups.insert(p.second);

    int index = 0;
    for(int g : groups){
        DirectedGraph<TV, TE>* dgraph = new DirectedGraph<TV, TE>;
        for(auto p : this->vertexes)
            if(this->lowValues[p.second] == g)  
                dgraph->insertVertex(p.second->id, p.second->data);
        for(auto p : this->vertexes)
            if(this->lowValues[p.second] == g)
                for(Edge<TV, TE>* edge : p.second->edges)
                    if(this->lowValues[edge->vertexes[1]] == g)
                        dgraph->createEdge(p.second->id, edge->vertexes[1]->id, edge->weight);
        result.push_back(dgraph);
    }
    
    std::cout << "\n---------Result of SCC algorithm---------\n";
    std::cout << "There are " << result.size() << " strongly connected components.\n";

    return result;
}

#endif