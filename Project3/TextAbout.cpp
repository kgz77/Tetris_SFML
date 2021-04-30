#include "TextAbout.h"
#include"TextButton.h"

using namespace tb;

ta::TextAbout::TextAbout() {
	if (!font.loadFromFile("C:/Users/User/source/repos/Project3/tnr.ttf")) {}

	//Об игре

	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Red);
	text[0].setString(L"\t\t\t\tКраткая история\n");
	text[0].setCharacterSize(23);
	text[0].setPosition(0, 2);

	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Black);
	text[1].setString(L"Тетрис (производное от «тетрамино») — компьютерная\n игра, первоначально изобретённая и разработанная\n советским программистом Алексеем Пажитновым.\n Игра была выпущена 6 июня 1984 года\n");
	text[1].setCharacterSize(15);
	text[1].setPosition(0, 27);

	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Red);
	text[2].setString(L"\t\t\t\tИнтересный факт :)\n");
	text[2].setCharacterSize(23);
	text[2].setPosition(0, 95);

	text[3].setFont(font);
	text[3].setFillColor(sf::Color::Black);
	text[3].setString(L"Известно состояние, называемое эффектом или\nсиндромом тетриса. Оно заставляет человека оценивать\nобъекты реального мира как фигуры игры или видеть\nих во сне. Такое происходит, если долго сидеть за\nголоволомкой :).\n");
	text[3].setCharacterSize(15);
	text[3].setPosition(0, 125);

	text[4].setFont(font);
	text[4].setFillColor(sf::Color::Red);
	text[4].setString(L"\t\t\t\t\tУправление\n");
	text[4].setCharacterSize(23);
	text[4].setPosition(0, 210);

	text[5].setFont(font);
	text[5].setFillColor(sf::Color::Black);
	text[5].setString(L"► Сдвиг фигуры вправо\n◄ Сдвиг фигуры влево\n▲ Поворот фигуры на 90°\n▼ Ускорение падения фигуры\n");
	text[5].setCharacterSize(15);
	text[5].setPosition(0, 235);

	text[6].setFont(font);
	text[6].setFillColor(sf::Color::Black);
	text[6].setString(L"\t\tРазработчик\nnurbekov741@gmail.com");
	text[6].setCharacterSize(15);
	text[6].setPosition(218, 290);

}

void ta::TextAbout::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 7; i++) {
		window.draw(text[i]);
	}
}