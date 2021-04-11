#include <SFML/Graphics.hpp>
#include"startWindow.h"//для функции открытии окна

using namespace sf;

int main() {
	// Объект, который, собственно, является главным окном приложения
	RenderWindow mainWindow(VideoMode(380, 330), L"Главное окно!", sf::Style::Titlebar);

	startMainWindow(mainWindow);
	return 0;
}