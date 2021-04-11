#include"startWindow.h"
#include"TextButton.h"
#include"TextAbout.h"
#include"Game.h"

using namespace sf;

//Главное окно
void startMainWindow(RenderWindow& window) {
	Texture back;
	back.loadFromFile("D:/#KSTU/#KSTU/С++/ООП/Курсовой проект/curs/back.jpg");
	Sprite sprite(back);
	sprite.move(-80, -20);

	tb::TextButton button;

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen()) {
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event)) {
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			//клик по кнопке
			button.click(window);
		}
		window.draw(sprite);
		//расположение кнопок и свойства
		button.draw(window);
		// Отрисовка окна	
		window.display();
	}
}

//Об игре
void startAboutTheGameWindow(sf::RenderWindow& window) {

	ta::TextAbout textAbout;
	
	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen()) {
		// Обрабатываем очередь событий в цикле
		Event event;
		while (window.pollEvent(event)) {
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed)
				// тогда закрываем его
				window.close();
			//клик по кнопке
		}
		window.clear(Color(205, 205, 205, 0));
		//расположение текста
		textAbout.draw(window);
		// Отрисовка окна	
		window.display();
	}
}

//игра
void startGameWindow(sf::RenderWindow& window) {
	sg::Game game;

	// Главный цикл приложения. Выполняется, пока открыто окно
	while (window.isOpen()) {
		game.getTime();
		// Обрабатываем очередь событий в цикле
		sf::Event event;
		while (window.pollEvent(event)) {
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == sf::Event::Closed) {
				// тогда закрываем его
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

		// Отрисовка окна	
		window.display();
	}
}