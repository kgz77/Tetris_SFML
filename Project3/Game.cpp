#include "Game.h"
#include<ctime>

sg::Game::Game() {
	//�������� ��������
	if (texture.loadFromFile("D:/#KSTU/#KSTU/�++/���/��/work/work/work/tiles.png")) {}
	//�������� �������
	sprite.setTexture(texture);
	//�������� ����� �� �������� �������� 18,18
	sprite.setTextureRect(sf::IntRect(0, 0, 18, 18));

	//���������� �����
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

	//������� ����
	playingField[HEIGHT][WIDTH] = {  };

	dx = 0;
	rotate = false;
	colorNum = 1;
	beginGame = true;
	next = true;//���� ������
	//������������� ������� � ��������
	timer = 0;
	DO = 0.3;

	level = 0;
	score = 0;
}

//��������� ������� ��������� � ������ �������
void sg::Game::getTime() {
	float time = clock.getElapsedTime().asSeconds();
	clock.restart();
	timer += time;
}

//������� � ���������
void sg::Game::isKeyPressed(sf::Event& event) {
	if (event.type == sf::Event::KeyPressed)
		if (event.key.code == sf::Keyboard::Up)
			rotate = true;
		else if (event.key.code == sf::Keyboard::Left)
			dx = -1;
		else if (event.key.code == sf::Keyboard::Right)
			dx = 1;
}

//��������� ������� �������
void sg::Game::speedTheFall() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		DO = 0.05;
}

//�������������� �����������
void sg::Game::horizontalMove() {
	for (int i = 0; i < 4; i++) {
		b[i] = a[i];
		a[i].x += dx;
	}
	returnOldCoordinates();
}

//�������� ������ 
void sg::Game::rotation() {
	if (rotate) {
		Point p = a[1];//����� ��������
		for (int i = 0; i < 4; i++) {
			int x = a[i].y - p.y;//y - y0
			int y = a[i].x - p.x;//x - x0
			a[i].x = p.x - x;
			a[i].y = p.y + y;
		}
		returnOldCoordinates();
	}
}

//�������� ����
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

//����������� �����
void sg::Game::lineKilling() {
	line = HEIGHT - 1;
	for (int i = HEIGHT - 1; i > 0; i--) {
		int count = 0;
		for (int j = 0; j < WIDTH; j++) {
			if (playingField[i][j])
				count++;
			playingField[line][j] = playingField[i][j];
			level++;
		}
		if (count < WIDTH)
			line--;
	}
}

//��������� ������� ������� �����
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

//��������� �������� �����
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
		// ������������� ������
		sprite.setTextureRect(sf::IntRect(colorNum * 18, 0, 18, 18));
		//��������� ������� ������� ���������
		sprite.setPosition(a[i].x * 18, a[i].y * 18);
		window.draw(sprite);
	}
}

//�������� ������
bool sg::Game::chekBorder() {
	for (int i = 0; i < 4; i++) {
		if (a[i].x < 0 || a[i].x >= WIDTH || a[i].y >= HEIGHT)
			return 0;
		else if ((playingField[a[i].y][a[i].x]))
			return 0;
	}
	return 1;
}

//���������� ������ ����������
void sg::Game::returnOldCoordinates() {
	// ���� ����� �� ������� ���� ����� �����������, �� ���������� ������ ���������� 
	if (!chekBorder()) {
		for (int i = 0; i < 4; i++)
			a[i] = b[i];
	}
}

//�������� ���������� ������
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

//��������� �������� ���� ������
void sg::Game::setNextFigureTexture(sf::RenderWindow& window) {
	for (int i = 0; i < 4; i++) {
		sprite.setTextureRect(sf::IntRect(colorNumNext * 18, 0, 18, 18));
		sprite.setPosition(temp[i].x * 18, temp[i].y * 18);
		sprite.move(250, 80);
		window.draw(sprite);
	}
}

//�������� �� ����� ����
void sg::Game::endGame(sf::RenderWindow& window) {
	for (int i = 0; i < WIDTH; i++) {
		if (playingField[1][i]) {
			window.clear();
			window.clear(sf::Color(224, 224, 224, 0));
		}
	}
}