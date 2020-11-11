#ifndef DSARRAY_H
#define DSARRAY_H

#include "ds.h"

template <typename T>
class DisjoinSetArray: public DisjoinSet<T>
{
private:
    // define the structures
    int sz;
    std::vector<T> data;
    std::vector<int> parent, rank;
    std::unordered_map<T, int> ind;
public:
    DisjoinSetArray(vector<T> d) : DisjoinSet<T>() {
        this->sz = d.size();
        this->data = d;
        this->parent.resize(sz);
        this->rank.resize(sz);
    }
    // implement all functions
    ~DisjoinSetArray(){
        this->data.clear();
        this->parent.clear();
        this->rank.clear();
        this->sz = 0;
    }
    //MakseSet the element with index x
    void MakeSet(int x){
        if(x < 0 || x >= this->sz) throw("Invalid index");
        this->parent[x] = x;
        this->rank[x] = 0;
        this->ind[data[x]] = x;
    }
    //MakseSet all elements
    void MakeSet(){
        for(int i=0; i<this->sz; i++){
            this->parent[i] = i;
            this->rank[i] = 0;
            this->ind[data[i]] = i;
        }  
    }
    //Find the root of x
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
    //Union two sets represented by x and y (apply rank)
    void Union(int x, int y){
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
    void UnionT(T t, T u){
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
    
    //check whether there is a path between x and y
    bool isConnected(int x, int y){
        return Find(x) == Find(y);
    }
    //total number of elements
    int size(){
        return this->sz;
    }
    //number of sets
    int sets(){
        std::set<int> s;
        for(int i=0; i<this->sz; i++)    s.insert(Find(i));
        return s.size();
    }
    //total number of elements that belong to the set of x
    int size(int x){
        int res = 0;
        int _parent = Find(x);
        for(auto e : parent)    if(e == _parent)    res++;
        return res;
    }
    //add the element to the set of x
    void Add(T element, int x){
        sz++;
        data.push_back(element);
        parent.push_back(sz-1);
        rank.push_back(0);
        
        Union(x, sz-1);
    }
    //return all elements that belong to the set of x
    std::vector<T> getElementsSet(int x){
        std::vector<T> res;
        int _parent = Find(x);
        for(int i=0; i<sz; i++)    if(Find(i) == _parent)    res.push_back(data[i]);
        return res;
    }

    void print(){
        std::cout << endl;
        std::cout << "Indx: "; for(int i=0; i<this->sz; i++)    std::cout << i << " "; std::cout << std::endl;
        std::cout << "Data: "; for(auto e : data)    std::cout << e << " "; std::cout << std::endl;
        std::cout << "Pare: "; for(auto e : parent)    std::cout << e << " "; std::cout << std::endl;
        std::cout << "Rank: "; for(auto e : rank)    std::cout << e << " "; std::cout << std::endl;
    }
};

#endif