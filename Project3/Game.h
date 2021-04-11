#pragma once
#include<SFML/Graphics.hpp>
#include"TextButton.h"
#include<time.h>

namespace sg {
#define HEIGHT 22 //������ �������� ����
#define WIDTH 12  //������ �������� ����

	struct Point { int x, y; };

	class Game:public tb::TextButton {
	private:
		sf::Texture texture;					//��� �������� ��������
		sf::Sprite sprite;						//��� ������������� ��������
		sf::RectangleShape border;				//�������
		int figures[7][4];						//������ 7 ���-�� �����, ������ ������ ���-� �� 4-� ���������
		int playingField[HEIGHT][WIDTH] = { 0 };//������� ����
		int n;									//��� ���������
		int dx;									//��� ��������������� ����������� 
		bool rotate;							//��� �������� ������
		Point a[4], b[4], temp[4];
		int nextFigure;							//���� ������
		float timer;							//������
		float DO;								//��������
		sf::Clock clock;						//������
		int colorNum;							//����
		int colorNumNext;						//���� ���� ������
		bool beginGame;							//������ ����
		bool next;								//����� ������� ���� ������
		int line;								//�����
		int level;								//�������
		int score;								//����
		bool chekBorder();						//�������� ����� �� ������� �������� ����
	public:
		Game();
		void draw(sf::RenderWindow&);						//��������������� ������������ ������
		void setTexture(sf::RenderWindow& window);			//��������� ��������
		void setPieces(sf::RenderWindow& window);			//����������� �����
		void isKeyPressed(sf::Event& event);				//�������� �� ������� ������
		void speedTheFall();								//��������� �������
		void horizontalMove();								//����������� �� �����������
		void returnOldCoordinates();						//���� ����� �� ������� �������� ����, �� ���������� ������ ����������
		void rotation();									//�������� 
		void getTime();										//��������� �������
		void downMove();									//�������� ����
		void lineKilling();									//����������� �����
		void showNextFigure();								//������� ���� ������
		void setNextFigureTexture(sf::RenderWindow& window);//����� �������� ���� �������
		void borderGame(sf::RenderWindow& window);			//������� ����
		void levelGame(sf::RenderWindow& window);			//������� ����
		void scoreGame(sf::RenderWindow& window);			//���� ����
		void endGame(sf::RenderWindow& window);				//����� ����
	};
}