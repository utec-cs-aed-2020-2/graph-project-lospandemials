#include <SFML/Graphics.hpp>
#include "../lib.h"

using namespace std;

double TransformLat(double latitude){
    return (3.88888*latitude + 800);
}

double TransformLon(double longitude){
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


void RenderAirportGraph(){
sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode(1000,1600), "Graph Display");
window->clear(sf::Color(255,255, 255, 255));





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