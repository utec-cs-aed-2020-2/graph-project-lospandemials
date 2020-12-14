#include <SFML/Graphics.hpp>
#include "../UndirectedGraph.h"


using namespace std;

double TransformLon(double longitude){
    return (3.88888*longitude + 800);
}

double TransformLat(double latitude){
    return (-4.44444*longitude + 500);
}

void DrawAirport(double longitude, double latitude, sf::RenderWindow* window){
    sf::CircleShape circle(10);
    circle.setFillColor(sf::Color::Cyan);
    circle.setPosition(longitude, latitude);
    circle.setOrigin(10, 10);
    window->draw(circle);
}

void DrawConnection (double longitudeA, double latitudeA, double longitudeB, double latitudeB, sf::RenderWindow* window){
    sf::Vertex line[] = 
	{
		sf::Vertex(sf::Vector2f(longitudeA, latitudeA), sf::Color::Black),
		sf::Vertex(sf::Vector2f(longitudeB, latitudeB), sf::Color::Black)
	};

    window->draw(line, 2, sf::Lines);
}


void RenderAirportGraph(UnDirectedGraph<Airport, double> &tempGraph){
sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode(1000,1600), "Graph Display");
window->clear(sf::Color(255,255, 255, 255));

for(auto vertex : tempGraph->vertexes){
    double correctedLon = TransformLon(vertex->data->longitude);
    double correctedLat = TransformLat(vertex->data->latitude);

    DrawAirport(correctedLon, correctedLat);
}


sf::Event event;
bool close = 1;
while (close){
    window->display();
    {
        if (event.type == sf::Event::Closed)
            window->close();
            close = 0;
    }
    sf::sleep(sf::Time(sf::milliseconds(10000)));
    }

}