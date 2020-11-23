#ifndef DS_H
#define DS_H

#include "../lib.h"

template <typename T>
class DisjoinSet // interface
{
public:
    virtual void MakeSet() = 0;
    virtual int Find(int x) = 0;
    virtual int FindT(T t) = 0;
    virtual void Union(T t, T u) = 0;
    virtual void print() = 0;
};

#endif