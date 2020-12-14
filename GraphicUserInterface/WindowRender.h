#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

using namespace sf;


int main(){
sf::RenderWindow* window = new sf::RenderWindow (sf::VideoMode(1000,1000), "Graph Display");
window->clear(sf::Color(255,255, 255, 255));

sf::Vertex line2[] = 
	{
		sf::Vertex(sf::Vector2f(200, 200), sf::Color::Black),
		sf::Vertex(sf::Vector2f(100, 200), sf::Color::Black)
	};


window->draw(line2, 2, sf::Lines);

int x1 = 100;
int y1 = 200;
sf::CircleShape circle(25);
circle.setFillColor(sf::Color::Cyan);
circle.setPosition(x1, y1);
circle.setOrigin(25, 25);
window->draw(circle);

int x2 = 200;
int y2 = 200;
sf::CircleShape circle2(25);
circle2.setFillColor(sf::Color::Cyan);
circle2.setPosition(x2, y2);
circle2.setOrigin(25, 25);
window->draw(circle2);

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