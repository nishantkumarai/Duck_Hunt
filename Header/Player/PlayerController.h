#pragma once
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Wave/WaveServices.h"


namespace Player
{
	class PlayerModel;
	class Eventservice;
	enum class Wave::WaveType;

	class PlayerController
	{
	private:
		Eventservice* eventService;
		PlayerModel* playerModel;
		sf::RenderWindow* gameWindow;
		

	public:
		PlayerController();
		~PlayerController();

		void Initialize();
		void Update();
		
	
		void ProcessPlayerInput();

		void DecreasePlayerAmmo();

		void Reset();

		void SetPlayerScore(int score);
		int GetPlayerScore();

		void DecreasePlayerLive();
		void ResetGame();
		

		

		



	};
}
