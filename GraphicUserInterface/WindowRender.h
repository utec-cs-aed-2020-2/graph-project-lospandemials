#ifndef GUI_H
#define GUI_H

#include <SFML/Graphics.hpp>
#include "../Graph/UndirectedGraph.h"
#include "../Airport/airport.h"

using namespace std;

class GUI{
private:
    double TransformLon(double longitude){
        return (3.88888*longitude + 800);
    }

    double TransformLat(double latitude){
        return (-4.44444*latitude + 500);
    }

    void DrawAirport(double longitude, double latitude, sf::RenderWindow* window, sf::Color color, int diameter){
        sf::CircleShape circle(diameter);
        
        circle.setFillColor(color);

        circle.setPosition(longitude, latitude);
        circle.setOrigin(diameter, diameter);
        window->draw(circle);
    }

    void DrawConnection (double longitudeA, double latitudeA, double longitudeB, double latitudeB, sf::RenderWindow* window, sf::Color color){
        sf::Vertex line[] = 
        {
            sf::Vertex(sf::Vector2f(longitudeA, latitudeA), color),
            sf::Vertex(sf::Vector2f(longitudeB, latitudeB), color)
        };
        window->draw(line, 2, sf::Lines);
    }

public: 

void RenderAirportGraph(Graph<Airport, double>* tempGraph);
void RenderGraphResult(Graph<Airport, double>* graph, UnDirectedGraph<Airport, double> &result);
void RenderGraphPath(Graph<Airport, double>* graph, std::list<Airport> path);
};

void GUI::RenderAirportGraph(Graph<Airport, double>* tempGraph){
    sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode(1600,1000), "Graph Display");
    window->clear(sf::Color(255,255, 255, 255));
    for(auto vertex : tempGraph->vertexes){
        for(auto edge : vertex.second->edges){
            double correctedLonA = TransformLon(edge->vertexes[0]->data.getLongitude());
            double correctedLatA = TransformLat(edge->vertexes[0]->data.getLatitude());

            double correctedLonB = TransformLon(edge->vertexes[1]->data.getLongitude());
            double correctedLatB = TransformLat(edge->vertexes[1]->data.getLatitude());
            
            DrawConnection (correctedLonA, correctedLatA, correctedLonB, correctedLatB, window, sf::Color::Black);
        }
    }

    for(auto vertex : tempGraph->vertexes){
        double correctedLon = TransformLon(vertex.second->data.getLongitude());
        double correctedLat = TransformLat(vertex.second->data.getLatitude());
        
        DrawAirport(correctedLon, correctedLat, window, sf::Color::Cyan, 4);
    }
    window->display();
    sf::sleep(sf::Time(sf::milliseconds(4900)));
}
          
void GUI::RenderGraphResult(Graph<Airport, double>* graph, UnDirectedGraph<Airport, double> &result){
    sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode(1600,1000), "Graph Display");
    window->clear(sf::Color(255,255, 255, 255));
    
    for(auto vertex : result.vertexes){
        for(auto edge : vertex.second->edges){
            auto vertex1 = edge->vertexes[0];
            auto vertex2 = edge->vertexes[1];
            
            double correctedLonA = TransformLon(vertex1->data.getLongitude());
            double correctedLatA = TransformLat(vertex1->data.getLatitude());

            double correctedLonB = TransformLon(vertex2->data.getLongitude());
            double correctedLatB = TransformLat(vertex2->data.getLatitude());
            
            DrawConnection (correctedLonA, correctedLatA, correctedLonB, correctedLatB, window, sf::Color::Red);
        }
    }
    for(auto vertex : graph->vertexes){
        if(result.vertexes.count(vertex.first))    continue;
        double correctedLon = TransformLon(vertex.second->data.getLongitude());
        double correctedLat = TransformLat(vertex.second->data.getLatitude());
        DrawAirport(correctedLon, correctedLat, window, sf::Color::Cyan, 4);
    }
    for(auto vertex : result.vertexes){
        double correctedLon = TransformLon(vertex.second->data.getLongitude());
        double correctedLat = TransformLat(vertex.second->data.getLatitude());
        DrawAirport(correctedLon, correctedLat, window, sf::Color::Blue, 4);
    }
    window->display();
    sf::sleep(sf::Time(sf::milliseconds(4900)));
}

void GUI::RenderGraphPath(Graph<Airport, double>* graph, std::list<Airport> path){
    sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode(1600,1000), "Graph Display");
    window->clear(sf::Color(255,255, 255, 255));
    double correctedLon, correctedLat;
    for(auto vertex : graph->vertexes){
        correctedLon = TransformLon(vertex.second->data.getLongitude());
        correctedLat = TransformLat(vertex.second->data.getLatitude());
        DrawAirport(correctedLon, correctedLat, window, sf::Color::Yellow, 4);
    }
    auto it1 = begin(path);
    auto it2 = begin(path);
    it2++;
    while(it2 != end(path)){
        double correctedLonA = TransformLon((*it1).getLongitude());
        double correctedLatA = TransformLat((*it1).getLatitude());

        double correctedLonB = TransformLon((*it2).getLongitude());
        double correctedLatB = TransformLat((*it2).getLatitude());
        
        DrawConnection (correctedLonA, correctedLatA, correctedLonB, correctedLatB, window, sf::Color::Black);
        it1++; it2++;
    }
    for(auto airport : path){
        correctedLon = TransformLon(airport.getLongitude());
        correctedLat = TransformLat(airport.getLatitude());
        DrawAirport(correctedLon, correctedLat, window, sf::Color::Black, 5);
    }
    it1 = begin(path);
    correctedLon = TransformLon((*it1).getLongitude());
    correctedLat = TransformLat((*it1).getLatitude());
    DrawAirport(correctedLon, correctedLat, window, sf::Color::Green, 10);
    it2 = end(path); it2--;
    correctedLon = TransformLon((*it2).getLongitude());
    correctedLat = TransformLat((*it2).getLatitude());
    DrawAirport(correctedLon, correctedLat, window, sf::Color::Red, 10);

    window->display();
    sf::sleep(sf::Time(sf::milliseconds(4900)));
}
#endif