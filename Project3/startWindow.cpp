#include"startWindow.h"
#include"TextButton.h"
#include"TextAbout.h"
#include"Game.h"

using namespace sf;

//������� ����
void startMainWindow(RenderWindow& window) {
	Texture back;
	back.loadFromFile("D:/#KSTU/#KSTU/�++/���/�������� ������/curs/back.jpg");
	Sprite sprite(back);
	sprite.move(-80, -20);

	tb::TextButton button;

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen()) {
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event)) {
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
			//���� �� ������
			button.click(window);
		}
		window.draw(sprite);
		//������������ ������ � ��������
		button.draw(window);
		// ��������� ����	
		window.display();
	}
}

//�� ����
void startAboutTheGameWindow(sf::RenderWindow& window) {

	ta::TextAbout textAbout;
	
	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen()) {
		// ������������ ������� ������� � �����
		Event event;
		while (window.pollEvent(event)) {
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == Event::Closed)
				// ����� ��������� ���
				window.close();
			//���� �� ������
		}
		window.clear(Color(205, 205, 205, 0));
		//������������ ������
		textAbout.draw(window);
		// ��������� ����	
		window.display();
	}
}

//����
void startGameWindow(sf::RenderWindow& window) {
	sg::Game game;

	// ������� ���� ����������. �����������, ���� ������� ����
	while (window.isOpen()) {
		game.getTime();
		// ������������ ������� ������� � �����
		sf::Event event;
		while (window.pollEvent(event)) {
			// ������������ ����� �� �������� � ����� ������� ����?
			if (event.type == sf::Event::Closed) {
				// ����� ��������� ���
				window.close();
			}
			game.isKeyPressed(event);
		} 
		game.showNextFigure();
		game.speedTheFall();
		game.horizontalMove();
		game.rotation();
		game.downMove();
		game.lineKilling();
		game.setPieces(window);
		window.clear(sf::Color(224, 224, 224, 0));
		game.borderGame(window);
		game.draw(window);
		game.setNextFigureTexture(window);
		game.setTexture(window);
		game.levelGame(window);
		game.scoreGame(window);
		game.endGame(window);

		// ��������� ����	
		window.display();
	}
}