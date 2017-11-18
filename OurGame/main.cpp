#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f, 500);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::A)
					if(shape.getFillColor() != sf::Color::Green)
						shape.setFillColor(sf::Color::Red);
					else shape.setFillColor(sf::Color::Green);


		}

		window.clear();
		window.draw(shape);
		window.display();
	}


	return 0;
}