#pragma once
#include <SFML/System/Clock.hpp>

namespace Wave
{
	class PlayerModel;
	
	
	enum class WaveType
	{
		FIRSTWAVE,
		SECONDWAVE,
		THIRDWAVE,
		FINISHED,
	};
	class WaveService
	{
		PlayerModel* playerModel;
	private:
		int waveTimer = 7;
		sf::Clock clock;

	public:
		WaveService();
		~WaveService();

		void Initialize();
	

		void ResetTime();

		bool checkTimeForChange();


		int speed;
		int ammo;
		int EnemiesToBeKilled;

	

		WaveType currentWave;
		int GetEnemiesToBeKilled();



		WaveType GetCurrentWave();
		void SetCurrentWave(WaveType wave);
		void RestartClock();
	};
}
