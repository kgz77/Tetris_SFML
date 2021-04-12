#pragma once
#include"TextButton.h"//класс кнопки
using namespace tb;

namespace ta {
	class TextAbout :public TextButton {
	public:
		TextAbout();
		void draw(sf::RenderWindow&);//перепределение вирт метода
	};
}