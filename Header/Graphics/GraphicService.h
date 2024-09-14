#pragma once
#include <SFML/Graphics.hpp>

namespace Graphics
{
	class GraphicService
	{
	private:
		sf::String gameWindowTitle = "Duck Hunt";
		int gameWindowWidth = 1920;
		int gameWindowHeight = 1080;
		sf::Color gameWindowColor = sf::Color::Cyan;
		int frameRate = 60;

		sf::Texture bgTexture;
		sf::Sprite bgSprite;

		sf::VideoMode* videoMod;
		sf::RenderWindow* gameWindow;

		void SetVideoMod();
		void OnDestroy();


	public:

		GraphicService();
		~GraphicService();

		void Initialize();
	

		bool IsGameWindowOpen();

		sf::RenderWindow* CreateGameWindow();
		sf::RenderWindow* GetGameWIndow();
		sf::Color GetWindowColor();

		void ChangeWindowColor(sf::Color color);

		
	};
}
