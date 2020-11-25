#ifndef PARSER_H
#define PARSER_H

#include "../lib.h"
#include "../Graph/UndirectedGraph.h"
#include "../Graph/DirectedGraph.h"
#include "../Airport/airport.h"
#include "nlohmann/json.hpp"
using json = nlohmann::json;
//https://github.com/nlohmann/json

class Parser{
private:    
    //Atributes:
    std::unordered_map<std::string, Airport> data;
    std::unordered_map<std::string, std::vector<std::string>> conexions;
    std::string path;

public:
    Parser(std::string path){
        this->path = path;
    }
    ~Parser(){}
    void clear(); // Clears parser saved atributes
    void readJSON(); // Parses JSON file and saves data into class
    // NOTE: each derived class has its own readJSON method
    void uGraphMake(UnDirectedGraph<Airport, double> &tempGraph); // Adds the parsed data into the specified undirected graph
    void dGraphMake(DirectedGraph<Airport, double> &tempGraph); // Adds the parsed data into the specified directed graph
};

void Parser::clear(){
    this->data.clear();
    this->conexions.clear();
}

void Parser::readJSON(){
    std::ifstream datafile(this->path);
    json j = json::parse(datafile);
    for(auto p : j){
        double longitude = 0.0, latitude = 0.0;
        std::string strLongitude = p["Longitude"].get<std::string>();
        std::string strLatitude = p["Latitude"].get<std::string>();
        if(strLongitude != "GVNP") longitude = atof(strLongitude.c_str());
        if(strLatitude != "GVNP") latitude = atof(strLatitude.c_str());
        Airport airport(p["City"].get<std::string>(), 
                        p["Name"].get<std::string>(), 
                        p["Country"].get<std::string>(), 
                        longitude, 
                        latitude);
        std::string id = p["Airport ID"].get<std::string>();
        this->data[id] = airport;
        for(auto e : p["destinations"])
            this->conexions[id].push_back(e.get<std::string>());
    }
}

void Parser::uGraphMake(UnDirectedGraph<Airport, double> &tempGraph){
    tempGraph.clear();
    for(auto p : this->data)
        tempGraph.insertVertex(p.first, p.second);
    for(auto p : this->conexions)
        for(auto e : p.second)
            tempGraph.createEdge(p.first, e, this->data[p.first] - this->data[e]);
}

void Parser::dGraphMake(DirectedGraph<Airport, double> &tempGraph){
    tempGraph.clear();
    for(auto p : this->data)
        tempGraph.insertVertex(p.first, p.second);
    for(auto p : this->conexions)
        for(auto e : p.second)
            tempGraph.createEdge(p.first, e, this->data[p.first] - this->data[e]);
}
#endif