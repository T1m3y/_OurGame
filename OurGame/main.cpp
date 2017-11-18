#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f, 50);
	shape.setFillColor(sf::Color::Green);

	sf::Font txtFont;
	txtFont.loadFromFile("../../../res/fonts/hemi_head_bd_it.ttf");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				if (event.key.code == sf::Keyboard::A)
				{
					if (shape.getFillColor() != sf::Color::Green)
						shape.setFillColor(sf::Color::Green);
					else shape.setFillColor(sf::Color::Red);
				}
				else if (event.key.code == sf::Keyboard::S)
				{
					if (shape.getPointCount() > 3)
					{
						shape.setPointCount(shape.getPointCount() - 1);
					}
				}
				else if (event.key.code == sf::Keyboard::W)
				{
					shape.setPointCount(shape.getPointCount() + 1);
				}
		}

		sf::Text circlePointCount(std::to_string(shape.getPointCount()), txtFont, 3000);
		circlePointCount.setCharacterSize(24);

		window.clear();
		window.draw(shape);
		window.draw(circlePointCount);
		window.display();
	}


	return 0;
}