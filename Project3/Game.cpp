#include "Game.h"
#include<ctime>
#include<string>

sg::Game::Game() {
	//загрузка текстуры
	if (texture.loadFromFile("D:/#KSTU/#KSTU/С++/ООП/Лб/work/work/work/tiles.png")) {}
	//создание спрайта
	sprite.setTexture(texture);
	//вырезаем часть из текстуры размером 18,18
	sprite.setTextureRect(sf::IntRect(0, 0, 18, 18));

	//грани
	border.setSize(sf::Vector2f(215.f, 487.f));
	border.setFillColor(sf::Color(231, 237, 187));



	//заполнение фигур
	figures[0][0] = 1;
	figures[0][1] = 3;
	figures[0][2] = 5;
	figures[0][3] = 7;

	figures[1][0] = 2;
	figures[1][1] = 4;
	figures[1][2] = 5;
	figures[1][3] = 7;

	figures[2][0] = 3;
	figures[2][1] = 5;
	figures[2][2] = 4;
	figures[2][3] = 6;

	figures[3][0] = 3;
	figures[3][1] = 5;
	figures[3][2] = 4;
	figures[3][3] = 7;

	figures[4][0] = 2;
	figures[4][1] = 3;
	figures[4][2] = 5;
	figures[4][3] = 7;

	figures[5][0] = 3;
	figures[5][1] = 5;
	figures[5][2] = 7;
	figures[5][3] = 6;

	figures[6][0] = 2;
	figures[6][1] = 3;
	figures[6][2] = 4;
	figures[6][3] = 5;

	//игровое поле
	playingField[HEIGHT][WIDTH] = {  };

	dx = 0;
	rotate = false;
	colorNum = 1;
	beginGame = true;
	next = true;//след фигура
	//инициализация таймера и задержки
	timer = 0;
	DO = 0.3;

	level = 0;
	score = 0;

	//Надписи
	if (!font.loadFromFile("D:/#KSTU/#KSTU/С++/ООП/Курсовой проект/curs/tnr.ttf")) {}

	//След фигура
	text[0].setFont(font);
	text[0].setFillColor(sf::Color::Black);
	text[0].setString(L"Следующая\n     фигура ");
	text[0].setCharacterSize(20);
	text[0].setPosition(230, 50);

	//Счет
	text[1].setFont(font);
	text[1].setFillColor(sf::Color::Black);
	text[1].setString(L"Счет ");
	text[1].setCharacterSize(20);
	text[1].setPosition(267, 205);

	//Уровень
	text[2].setFont(font);
	text[2].setFillColor(sf::Color::Black);
	text[2].setString(L"Уровень ");
	text[2].setCharacterSize(20);
	text[2].setPosition(255, 290);

	text[3].setFont(font);
	text[3].setFillColor(sf::Color::Black);
	text[3].setString(std::to_wstring(level));
	text[3].setCharacterSize(20);
	text[3].setPosition(285, 240);

	text[4].setFont(font);
	text[4].setFillColor(sf::Color::Black);
	text[4].setString(std::to_wstring(score));
	text[4].setCharacterSize(20);
	text[4].setPosition(285, 315);	
	
	text[5].setFont(font);
	text[5].setFillColor(sf::Color::Red);
	text[5].setString(L"\t\t  Игра окончена!");
	text[5].setCharacterSize(30);
	text[5].setPosition(10, 105);

	text[6].setFont(font);
	text[6].setFillColor(sf::Color::Black);
	text[6].setString(L"\nНажмите-X чтобы выйти на главное меню.");
	text[6].setCharacterSize(19);
	text[6].setPosition(1, 150);
}

void sg::Game::borderGame(sf::RenderWindow & window) {
	window.draw(border);
}

void sg::Game::draw(sf::RenderWindow& window) {
	for (int i = 0; i < 5; i++) {
		window.draw(text[i]);
	}
}

//получение времени прошедшее с начала отсчета
void sg::Game::getTime() {
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;
}

//событии с клавишами
void sg::Game::isKeyPressed(sf::Event& event) {
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Up)
			rotate = true;
		else if (event.key.code == sf::Keyboard::Left)
			dx = -1;
		else if (event.key.code == sf::Keyboard::Right)
			dx = 1;
}

//ускорение падения фигруры
void sg::Game::speedTheFall() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		DO = 0.05;
}

//горизантальное перемещение
void sg::Game::horizontalMove() {
	for (int i = 0; i < 4; i++) {
		b[i] = a[i];
		a[i].x += dx;
	}
	returnOldCoordinates();
}

//вращение фигуры 
void sg::Game::rotation() {
	if (rotate) {
		Point p = a[1];//центр вращения
		for (int i = 0; i < 4; i++) {
			int x = a[i].y - p.y;//y - y0
			int y = a[i].x - p.x;//x - x0
			a[i].x = p.x - x;
			a[i].y = p.y + y;
		}
		returnOldCoordinates();
	}
}

//движение вниз
void sg::Game::downMove() {
	srand(time(0));
	if (timer > DO) {
		next = false;
		for (int i = 0; i < 4; i++) {
			b[i] = a[i];
			a[i].y += 1;
		}
		if (!chekBorder()) {
			for (int i = 0; i < 4; i++)
				playingField[b[i].y][b[i].x] = colorNum;
			colorNum = colorNumNext;
			n = nextFigure;
			for (int i = 0; i < 4; i++) {
				a[i].x = figures[n][i] % 2;
				a[i].y = figures[n][i] / 2;
			}
			next = true;
		}
		timer = 0;
	}
}

//уничтожение линий
void sg::Game::lineKilling() {
	line = HEIGHT - 1;
	for (int i = HEIGHT - 1; i > 0; i--) {
		int count = 0;
		for (int j = 0; j < WIDTH; j++) {	
			if (playingField[i][j]) 
				count++;
			playingField[line][j] = playingField[i][j];
		}
		if (count < WIDTH) {
			line--;		
		}
		else {
			score += 100;
			if (score == 1000 || score == 2000 || score == 3000 || score == 4000 || score == 5000 || score == 6000 || score == 7000 || score == 8000 || score == 9000)
				level++;
		}
	}
}

//установка каждого кусочка фигур
void sg::Game::setPieces(sf::RenderWindow& window) {
	srand(time(0));
	if (beginGame) {
		beginGame = false;
		n = nextFigure;
		for (int i = 0; i < 4; i++) {
			a[i].x = figures[n][i] % 2;
			a[i].y = figures[n][i] / 2;
		}
	}
	dx = 0;
	rotate = false;
	DO = 0.3;
}

//установка текстуры фигур
void sg::Game::setTexture(sf::RenderWindow& window) {
	for (int i = 0; i < HEIGHT; i++)
		for (int j = 0; j < WIDTH; j++) {
			if (playingField[i][j] == 0)
				continue;
			sprite.setTextureRect(sf::IntRect(playingField[i][j] * 18, 0, 18, 18));
			sprite.setPosition(j * 18, i * 18);
			window.draw(sprite);
		}
	for (int i = 0; i < 4; i++) {
		// Разукрашиваем фигуры
		sprite.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
		//установка позиции каждого тетрамино
		sprite.setPosition(a[i].x * 18, a[i].y * 18);
		window.draw(sprite);
	}
}

//проверка границ
bool sg::Game::chekBorder() {
	for (int i = 0; i < 4; i++) {
		if (a[i].x < 0 || a[i].x >= WIDTH || a[i].y >= HEIGHT)
			return 0;
		else if ((playingField[a[i].y][a[i].x]))
			return 0;
	}
	return 1;
}

//возвращаем старые координаты
void sg::Game::returnOldCoordinates() {
	// Если вышли за пределы поля после перемещения, то возвращаем старые координаты 
	if (!chekBorder()) {
		for (int i = 0; i < 4; i++)
			a[i] = b[i];
	}
}

//показать слдедующую фигуру
void sg::Game::showNextFigure() {
	if (next) {
		colorNumNext = 1 + rand() % 7;
		nextFigure = rand() % 7;
		for (int i = 0; i < 4; i++) {
			temp[i].x = figures[nextFigure][i] % 2;
			temp[i].y = figures[nextFigure][i] / 2;
		}
	}
}

//установка текстуры след фигуры
void sg::Game::setNextFigureTexture(sf::RenderWindow& window) {
	for (int i = 0; i < 4; i++) {
		sprite.setTextureRect(sf::IntRect(colorNumNext * 18, 0, 18, 18));
		sprite.setPosition(temp[i].x * 18, temp[i].y * 18);
		sprite.move(270, 110);
		window.draw(sprite);
	}
}

void sg::Game::levelGame(sf::RenderWindow& window) {
	text[3].setString(std::to_wstring(score));
	window.draw(text[3]);
}

void sg::Game::scoreGame(sf::RenderWindow& window) {
	text[4].setString(std::to_wstring(level));
	window.draw(text[4]);
	if (level >= 3 || level >=5 || level >= 7 || level >= 8 || level >= 9)
		DO -= 0.05;
}

//проверка на конец игры
void sg::Game::endGame(sf::RenderWindow& window) {
	for (int i = 0; i < WIDTH; i++) {
		if (playingField[1][i]) {
			window.clear();
			window.clear(sf::Color(224, 224, 224, 0));
			window.draw(text[5]);
			window.draw(text[6]);
		}
	}
}