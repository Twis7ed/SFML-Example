#include "headers.h"

// Funcs
int main()
{	
	sf::RenderWindow window(sf::VideoMode(1280, 720), "Game", sf::Style::Titlebar | sf::Style::Close | sf::Style::Resize);
	sf::Event evnt;

	sf::Texture playerTexture;
	playerTexture.loadFromFile("Textures/player.png");

	Player player(&playerTexture, sf::Vector2u(9, 4), 0.3f, 100.0f);
	
	float deltaTime = 0.0f;
	sf::Clock clock;
	

	while (window.isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		while (window.pollEvent(evnt)) 
		{
			switch (evnt.type)
			{
			case sf::Event::Closed :
				window.close();
				break;
			}
		}

		player.Update(deltaTime);

		window.clear(sf::Color(50, 50, 50));
		player.Draw(window);
		window.display();
	}

	return 0;
}