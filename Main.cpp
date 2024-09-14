#include <iostream>
#include "../../Header/Main/GameService.h"
#include <SFML/Graphics.hpp>

int main()
{
	using namespace Main;

	GameService* game = new GameService();

	game->Ignite();

	while (game->IsRunning())
	{
		game->Update();
		game->Render();

	}

	return 0;
}