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

    void DrawAirport(double longitude, double latitude, sf::RenderWindow* window, int color){
        sf::CircleShape circle(4);
        
        if(color == 0)  circle.setFillColor(sf::Color::Cyan);
        else if(color == 1) circle.setFillColor(sf::Color::Magenta);

        circle.setPosition(longitude, latitude);
        circle.setOrigin(4, 4);
        window->draw(circle);
    }

    void DrawConnection (double longitudeA, double latitudeA, double longitudeB, double latitudeB, sf::RenderWindow* window, int color){
        if(color == 0){
            sf::Vertex line[] = 
            {
                sf::Vertex(sf::Vector2f(longitudeA, latitudeA), sf::Color::Black),
                sf::Vertex(sf::Vector2f(longitudeB, latitudeB), sf::Color::Black)
            };
            window->draw(line, 2, sf::Lines);
        }else if(color == 1){
            sf::Vertex line[] = 
            {
                sf::Vertex(sf::Vector2f(longitudeA, latitudeA), sf::Color::Red),
                sf::Vertex(sf::Vector2f(longitudeB, latitudeB), sf::Color::Red)
            };
            window->draw(line, 2, sf::Lines);
        }
        
    }

public: 

void RenderAirportGraph(UnDirectedGraph<Airport, double> &tempGraph);
void RenderGraphResult(UnDirectedGraph<Airport, double> &graph, UnDirectedGraph<Airport, double> &result);

};

void GUI::RenderAirportGraph(UnDirectedGraph<Airport, double> &tempGraph){
    sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode(1600,1000), "Graph Display");
    window->clear(sf::Color(255,255, 255, 255));
    for(auto vertex : tempGraph.vertexes){
        for(auto edge : vertex.second->edges){
            double correctedLonA = TransformLon(edge->vertexes[0]->data.getLongitude());
            double correctedLatA = TransformLat(edge->vertexes[0]->data.getLatitude());

            double correctedLonB = TransformLon(edge->vertexes[1]->data.getLongitude());
            double correctedLatB = TransformLat(edge->vertexes[1]->data.getLatitude());

            DrawConnection (correctedLonA, correctedLatA, correctedLonB, correctedLatB, window, 0);
        }
    }

    for(auto vertex : tempGraph.vertexes){
        double correctedLon = TransformLon(vertex.second->data.getLongitude());
        double correctedLat = TransformLat(vertex.second->data.getLatitude());

        DrawAirport(correctedLon, correctedLat, window, 0);
    }
    window->display();
    sf::sleep(sf::Time(sf::milliseconds(4900)));
}

void GUI::RenderGraphResult(UnDirectedGraph<Airport, double> &graph, UnDirectedGraph<Airport, double> &result){
    sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode(1600,1000), "Graph Display");
    window->clear(sf::Color(255,255, 255, 255));
    
    for(auto vertex : graph->vertexes){
        for(auto edge : vertex.second->edges){
            Vertex<TV, TE>* vertex1 = edge->vertexes[0];
            Vertex<TV, TE>* vertex2 = edge->vertexes[1];
            double correctedLonA = TransformLon(vertex1->data.getLongitude());
            double correctedLatA = TransformLat(vertex1->data.getLatitude());

            double correctedLonB = TransformLon(vertex2->data.getLongitude());
            double correctedLatB = TransformLat(vertex2->data.getLatitude());

            if(result.vertexes.count(vertex1->id) && result.vertexes.count(vertex2->id))
                DrawConnection (correctedLonA, correctedLatA, correctedLonB, correctedLatB, window, 1);
            else
                DrawConnection (correctedLonA, correctedLatA, correctedLonB, correctedLatB, window, 0);
        }
    }
    
    for(auto vertex : graph.vertexes){
        if(result.vertexes.count(vertex.first))    continue;
        double correctedLon = TransformLon(vertex.second->data.getLongitude());
        double correctedLat = TransformLat(vertex.second->data.getLatitude());

        DrawAirport(correctedLon, correctedLat, window, 0);
    }

    for(auto vertex : result.vertexes){
        double correctedLon = TransformLon(vertex.second->data.getLongitude());
        double correctedLat = TransformLat(vertex.second->data.getLatitude());

        DrawAirport(correctedLon, correctedLat, window, 1);
    }
    window->display();
    sf::sleep(sf::Time(sf::milliseconds(4900)));
}
