#ifndef DSARRAY_H
#define DSARRAY_H

#include "ds.h"

template <typename T>
class DisjoinSetArray: public DisjoinSet<T>
{
private:
    int sz;
    std::vector<T> data;
    std::vector<int> parent, rank;
    std::unordered_map<T, int> ind; //for indx
public:
    DisjoinSetArray(std::vector<T> d) : DisjoinSet<T>() {
        this->sz = d.size();
        this->data = d;
        this->parent.resize(sz);
        this->rank.resize(sz);
    }
    ~DisjoinSetArray(){
        this->data.clear();
        this->parent.clear();
        this->rank.clear();
        this->sz = 0;
    }
    void MakeSet(){
        for(int i=0; i<this->sz; i++){
            this->parent[i] = i;
            this->rank[i] = 0;
            this->ind[data[i]] = i;
        }  
    }
    int Find(int x){
        if(parent[x] == x)  return x;
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    int FindT(T t){
        int x = this->ind[t];
        if(parent[x] == x)  return x;
        parent[x] = Find(parent[x]);
        return parent[x];
    }
    void Union(T t, T u){
        int x = this->ind[t];
        int y = this->ind[u];
        int xRoot = Find(x);
        int yRoot = Find(y);

        if(xRoot == yRoot)  return;
        if(rank[xRoot] < rank[yRoot])       parent[xRoot] = yRoot;
        else if(rank[xRoot] > rank[yRoot])  parent[yRoot] = xRoot;
        else{
            parent[yRoot] = xRoot;
            rank[xRoot]++;
        }
    }
    
    void print(){
        std::cout << std::endl;
        std::cout << "Indx: "; for(int i=0; i<this->sz; i++)    std::cout << i << " "; std::cout << std::endl;
        std::cout << "Data: "; for(auto e : data)    std::cout << e << " "; std::cout << std::endl;
        std::cout << "Pare: "; for(auto e : parent)    std::cout << e << " "; std::cout << std::endl;
        std::cout << "Rank: "; for(auto e : rank)    std::cout << e << " "; std::cout << std::endl;
    }
};

#endif