#include"startWindow.h"
#include"TextButton.h"
#include"TextAbout.h"

using namespace sf;

//������� ����
void startMainWindow(RenderWindow& window) {
	Texture back;
	back.loadFromFile("D:/#KSTU/#KSTU/�++/���/�������� ������/curs/back.jpg");
	Sprite sprite(back);
	sprite.move(-70, -20);

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