#include <SFML/Graphics.hpp>
#include"startWindow.h"//��� ������� �������� ����

using namespace sf;

int main() {
	// ������, �������, ����������, �������� ������� ����� ����������
	RenderWindow mainWindow(VideoMode(360, 330), L"������� ����!", sf::Style::Titlebar);

	startMainWindow(mainWindow);
	return 0;
}