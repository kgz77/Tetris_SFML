#include "TextButton.h"
#include"startWindow.h"//для функции startAboutTheGameWindow()

tb::TextButton::TextButton() {
	if (!font.loadFromFile("D:/#KSTU/#KSTU/С++/ООП/Курсовой проект/curs/tnr.ttf")) {}

	//play
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Black);
	text[0].setString(L"Играть ");
	text[0].setCharacterSize(30);
	text[0].setPosition(27, 30);

	//options
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Black);
	text[1].setString(L"Об игре ");
	text[1].setCharacterSize(30);
	text[1].setPosition(27, 90);

	//exit
	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Black);
	text[2].setString(L"Выход ");
	text[2].setCharacterSize(30);
	text[2].setPosition(27, 150);

	mainMenu = 0;
}

void tb::TextButton::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 3; i++) {
		window.draw(text[i]);
	}
}

void tb::TextButton::click(sf::RenderWindow& window) {
		if (sf::IntRect(27, 30, 100, 30).contains(sf::Mouse::getPosition(window))) {
			text[0].setFillColor(sf::Color::Green);
			
			mainMenu = 1;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (mainMenu == 1) {
					sf::RenderWindow windGame(sf::VideoMode(360, 450), L"Тетрис");
					window.close();
					startGameWindow(windGame);
				}
			}
		}
		else if (sf::IntRect(27, 90, 100, 30).contains(sf::Mouse::getPosition(window))) {
			text[1].setFillColor(sf::Color::Green);
			mainMenu = 2;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (mainMenu == 2) {
					sf::RenderWindow windATG(sf::VideoMode(380, 330), L"Об игре");
					startAboutTheGameWindow(windATG);
				}
			}
		}
		else if (sf::IntRect(27, 150, 100, 30).contains(sf::Mouse::getPosition(window))) {
			text[2].setFillColor(sf::Color::Green);
			mainMenu = 3;
			if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				if (mainMenu == 3)
					window.close();
			}
		}
		else {
			for (int i = 0; i < 3; i++)
				text[i].setFillColor(sf::Color::Black);
		}
}