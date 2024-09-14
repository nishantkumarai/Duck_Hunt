#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Global/Config.h"


namespace Graphics
{

	GraphicService::GraphicService()
	{
		gameWindow = nullptr;
		videoMod = nullptr;
	}

	GraphicService::~GraphicService()
	{
		OnDestroy();
	}

	void GraphicService::Initialize()
	{
		gameWindow = CreateGameWindow();
		
		gameWindow->setFramerateLimit(frameRate);
	}

	sf::RenderWindow* GraphicService::CreateGameWindow()
	{
		SetVideoMod();
		return new sf::RenderWindow(*videoMod, gameWindowTitle, sf::Style::Fullscreen);
	}

	void GraphicService::SetVideoMod()
	{
		videoMod = new sf::VideoMode(gameWindowWidth, gameWindowHeight, sf::VideoMode::getDesktopMode().bitsPerPixel);
	}

	void GraphicService::OnDestroy()
	{
		delete(gameWindow);
		delete(videoMod);
	}

	bool GraphicService::IsGameWindowOpen()
	{
		return gameWindow->isOpen();
	}

	sf::RenderWindow* GraphicService::GetGameWIndow()
	{
		return gameWindow;
	}

	sf::Color GraphicService::GetWindowColor()
	{
		return gameWindowColor;
	}

	void GraphicService::ChangeWindowColor(sf::Color color)
	{
		gameWindowColor = color;
	}


}