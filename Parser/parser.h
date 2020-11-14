#ifndef PARSER_H
#define PARSER_H

#include "../lib.h"
#include "../Graph/UndirectedGraph.h"
#include "../Graph/DirectedGraph.h"

template<typename TV, typename TE>
class Parser{
private:    
    //Atributes:

public:
    Parser(){}
    ~Parser(){}
    void clear(); // Clears parser saved atributes
    void readJSON(); // Parses JSON file and saves data into class
    // NOTE: each derived class has its own readJSON method
    void uGraphMake(UnDirectedGraph<std::string, double> &tempGraph); // Adds the parsed data into the specified undirected graph
    void dGraphMake(DirectedGraph<std::string, double> &tempGraph); // Adds the parsed data into the specified directed graph
};

#endif