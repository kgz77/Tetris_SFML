#pragma once
#include<SFML/Graphics.hpp>

namespace tb {
	class TextButton {
	protected: 
		sf::Font font;	 //шрифт
		sf::Text text[7];//текст надписи
		int mainMenu;	 //меню для игры
	public:
		TextButton();
		virtual void draw(sf::RenderWindow& window);//виртуальный метод для отображения текста в окне
		void click(sf::RenderWindow& window);		//обработчик события на нажатия кнопок меню
	};
} 