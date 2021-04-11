#pragma once
#include<SFML/Graphics.hpp>
#include"TextButton.h"
#include<time.h>

namespace sg {
#define HEIGHT 22 //высота игрового поля
#define WIDTH 12  //ширина игрового поля

	struct Point { int x, y; };

	class Game:public tb::TextButton {
	private:
		sf::Texture texture;					//для загрузки текстуры
		sf::Sprite sprite;						//для использования текстуры
		sf::RectangleShape border;				//граница
		int figures[7][4];						//фигуры 7 кол-во фигур, каждая фигура сос-т из 4-х квадратов
		int playingField[HEIGHT][WIDTH] = { 0 };//игровое поле
		int n;									//тип тетрамино
		int dx;									//для горизантального перемещения 
		bool rotate;							//для вращения фигуры
		Point a[4], b[4], temp[4];
		int nextFigure;							//след фигура
		float timer;							//таймер
		float DO;								//задержка
		sf::Clock clock;						//таймер
		int colorNum;							//цвет
		int colorNumNext;						//цвет след фигуры
		bool beginGame;							//начало игры
		bool next;								//чтобы вывести след фигуру
		int line;								//линия
		int level;								//уровень
		int score;								//счет
		bool chekBorder();						//проверка выход за границы игрового поля
	public:
		Game();
		void draw(sf::RenderWindow&);						//переопределение виртуального метода
		void setTexture(sf::RenderWindow& window);			//установка текстуры
		void setPieces(sf::RenderWindow& window);			//образование фигур
		void isKeyPressed(sf::Event& event);				//проверка на нажатие клавищ
		void speedTheFall();								//ускорение падения
		void horizontalMove();								//перемещение по горизантали
		void returnOldCoordinates();						//если вышли за пределы игрового поля, то возвращаем старые координаты
		void rotation();									//вращение 
		void getTime();										//получение времени
		void downMove();									//движение вниз
		void lineKilling();									//уничтожение линии
		void showNextFigure();								//вывести след фигуру
		void setNextFigureTexture(sf::RenderWindow& window);//вывод текстуры след ффигуры
		void borderGame(sf::RenderWindow& window);			//граница игры
		void levelGame(sf::RenderWindow& window);			//уровень игры
		void scoreGame(sf::RenderWindow& window);			//счет игры
		void endGame(sf::RenderWindow& window);				//конец игры
	};
}