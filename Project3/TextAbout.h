#pragma once
#include"TextButton.h"//����� ������
using namespace tb;

namespace ta {
	class TextAbout :public TextButton {
	public:
		TextAbout();
		void draw(sf::RenderWindow&);//�������������� ���� ������
	};
}