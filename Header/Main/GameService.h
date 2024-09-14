#pragma once
#include "../../Header/Global/ServiceLocator.h"

namespace Main
{
	class GameService
	{
	private:

		sf::RenderWindow* gameWindow;
		Global::ServiceLocator* serviceLocator;

		void InitializeVariable();
		
	public:
		GameService();
		~GameService();

		void Ignite();

		void Initialize();


		void Update();
		void Render();
		bool IsRunning();

	};
}
