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
    std::unordered_map<std::string, std::vector<std::string>> countries;
public:
    Parser(std::string path){
        this->path = path;
    }
    ~Parser(){}
    void clear();
    void readJSON();
    void uGraphMake(UnDirectedGraph<Airport, double> &tempGraph);
    void dGraphMake(DirectedGraph<Airport, double> &tempGraph);
    void showIDs();
    void showCountries();
    std::vector<std::string> airportsCountry(std::string id);
};

void Parser::clear(){
    this->data.clear();
    this->conexions.clear();
    this->countries.clear();
}

void Parser::readJSON(){
    std::ifstream datafile(this->path);
    json j = json::parse(datafile);
    
    std::cout << "\nThere are " << j.size() << " airpoirts in the jsonfile.\n";
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
        this->countries[p["Country"].get<std::string>()].push_back(p["Airport ID"].get<std::string>());
    }
}

void Parser::uGraphMake(UnDirectedGraph<Airport, double> &tempGraph){
    tempGraph.clear();
    for(auto p : this->data)
        tempGraph.insertVertex(p.first, p.second);
    for(auto p : this->conexions)
        for(auto e : p.second)
            if(this->data.count(e))
                tempGraph.createEdge(p.first, e, this->data[p.first] - this->data[e]);
    std::cout << "\n" << this->data.size() << " airports created.\n\n";
}

void Parser::dGraphMake(DirectedGraph<Airport, double> &tempGraph){
    tempGraph.clear();
    for(auto p : this->data)
        tempGraph.insertVertex(p.first, p.second);
    for(auto p : this->conexions)
        for(auto e : p.second)
            tempGraph.createEdge(p.first, e, this->data[p.first] - this->data[e]);
    std::cout << "\n" << this->data.size() << " airports created.\n\n";
}

void Parser::showIDs(){
    std::cout << "ID's in parser (" << this->data.size() << "):\n";
    for(auto p : this->data)
        std::cout << "\t" << p.first << " -> " << p.second << "\n";
}

void Parser::showCountries(){
    std::cout << "Countries's in parser (" << this->countries.size() << "):\n";
    for(auto p : this->countries)
        std::cout << "\t" << p.first << ": " << p.second.size() << " airports\n";
}

std::vector<std::string> Parser::airportsCountry(std::string id){
    std::vector<std::string> result;
    if(!this->countries.count(id)){
        std::cout << "\nEra: " << id << "\n";
        std::cout << "Country doesn't exist.\n";
    }
    else{
        result = this->countries[id];
    }
    return result;
}

#endif