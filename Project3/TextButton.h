#pragma once
#include<SFML/Graphics.hpp>

namespace tb {
	class TextButton {
	protected:
		sf::Font font;
		sf::Text text[7];
		int mainMenu;
	public:
		TextButton();
		virtual void draw(sf::RenderWindow& window);
		void click(sf::RenderWindow& window); 
	};
}