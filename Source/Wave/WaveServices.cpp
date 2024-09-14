#include "../../Header/Wave/WaveServices.h"
#include "../../Header/Player/PlayerController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Enemy/EnemyModel.h"
#include <iostream>

namespace Wave
{
	using namespace Player;
	using namespace Global;

	WaveService::WaveService() = default;
	

	WaveService::~WaveService() = default;
	

	void WaveService::Initialize()
	{
		currentWave = WaveType::FIRSTWAVE;
		EnemiesToBeKilled = 2;
	}


	void WaveService::ResetTime()
	{

		waveTimer = 0;
		clock.restart();

	}

	bool WaveService::checkTimeForChange()
	{
		return clock.getElapsedTime().asSeconds() >= waveTimer;
	}

	void WaveService::SetCurrentWave(WaveType wave)
	{

		switch (wave)
		{

		case WaveType::FIRSTWAVE:
			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::FIRSTWAVE;

			waveTimer = 7;
			Player::PlayerModel::playerAmmo = 5;
			Enemy::EnemyModel::NumberOfEnemies = 4;
			EnemiesToBeKilled = 3;
			break;

		case WaveType::SECONDWAVE:
			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::SECONDWAVE;

			waveTimer = 25;
			Player::PlayerModel::playerAmmo = 10;
			Enemy::EnemyModel::NumberOfEnemies = 6;
			EnemiesToBeKilled = 5;
			break;

		case WaveType::THIRDWAVE:
			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			currentWave = WaveType::THIRDWAVE;

			waveTimer = 30;
			Player::PlayerModel::playerAmmo = 15;
			Enemy::EnemyModel::NumberOfEnemies = 10;
			EnemiesToBeKilled = 10;
			break;

		case WaveType::FINISHED:

			RestartClock();
			ServiceLocator::GetInstance()->GetEnemyService()->Reset();
			ServiceLocator::GetInstance()->GetPlayerService()->ResetGame();
			currentWave = WaveType::FIRSTWAVE;

		}
	}

	int WaveService::GetEnemiesToBeKilled()
	{
		return EnemiesToBeKilled;
	}

	WaveType WaveService::GetCurrentWave()
	{
		return currentWave;
	}

	void WaveService::RestartClock()
	{
		clock.restart();

	}




}