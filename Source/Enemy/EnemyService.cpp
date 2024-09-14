#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Time/TimeService.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/Controller/GreenDuckController.h"
#include "../../Header/Enemy/Controller/RedDuckController.h"
#include "../../Header/Player/PlayerModel.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Sound/SoundService.h"

namespace Enemy
{
	using namespace Global;
	using namespace Controller;
	using namespace Wave;

	EnemyService::EnemyService()
	{
		wave = new WaveService();
		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i] = nullptr;
		}
	}

	EnemyService::~EnemyService()
	{

		Destroy();
	}

	void EnemyService::Initialize()
	{
		spawnTimer = 0;
		ServiceLocator::GetInstance()->GetSoundService()->PlaySound(Sound::SoundType::START_MUSIC);
		SpawnEnemy();
	}


	void EnemyService::SpawnEnemy()
	{
		EnemyController* enemyController = CreateEnemy(GetRandomEnemyType());
		enemyController->Initialize();

		enemyList.push_back(enemyController);
		EnemyModel::enemyCount++;
		ServiceLocator::GetInstance()->GetGraphicService()->ChangeWindowColor(sf::Color::Cyan);


	}

	EnemyController* EnemyService::CreateEnemy(EnemyType enemyType)
	{

		switch (enemyType)
		{

		case EnemyType::GREEN_DUCK:
			return new GreenDuckController();
		case EnemyType::RED_DUCK:
			return new RedDuckController();
		}

	}

	EnemyType EnemyService::GetRandomEnemyType()
	{
		int randomType = std::rand() % 2;
		return static_cast<Enemy::EnemyType>(randomType);
	}

	void EnemyService::Update()
	{

		UpdateSpawnTimer();
		ProcessSpawnEnemy();

		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i]->Update();

		}
		DestroyFlaggedEnemyList();
	}

	void EnemyService::UpdateSpawnTimer()
	{
		spawnTimer += ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
	}

	void EnemyService::ProcessSpawnEnemy()
	{
		if (spawnTimer > spawnInterval)
		{
			if (ServiceLocator::GetInstance()->GetWaveService()->checkTimeForChange())
			{
				if (EnemyModel::enemiesKilled < ServiceLocator::GetInstance()->GetWaveService()->GetEnemiesToBeKilled())
				{
					ServiceLocator::GetInstance()->GetPlayerService()->SetCurrentStatus(Player::PlayerStatus::FAILED);
					ServiceLocator::GetInstance()->GetWaveService()->RestartClock();
					Reset();
					spawnTimer = 0;
				}
				else
				{
					ServiceLocator::GetInstance()->GetPlayerService()->SetCurrentStatus(Player::PlayerStatus::WON);

				}

			}

			if (EnemyModel::enemyCount < EnemyModel::NumberOfEnemies)
			{
				
				SpawnEnemy();
				spawnTimer = 0;
			}
		}
	}

	void EnemyService::Render()
	{
		for (int i = 0;i < enemyList.size();i++)
		{
			enemyList[i]->Render();
		}
	}


	bool EnemyService::DestroyEnemyAtMousePosition(sf::Vector2f mousePosition)
	{
		for (int i = 0; i < enemyList.size(); i++)
		{
			sf::FloatRect bounds = enemyList[i]->GetEnemySprite().getGlobalBounds();

			//printf("Checking enemy %d with bounds: left=%f, top=%f, width=%f, height=%f\n", i, bounds.left, bounds.top, bounds.width, bounds.height);

			if (bounds.contains(mousePosition))
			{

				ServiceLocator::GetInstance()->GetSoundService()->PlaySound(Sound::SoundType::DUCK_SOUND);

				Enemy::EnemyModel::enemiesKilled++;

				IncreaseScore(enemyList[i]);
				DestroyEnemy(enemyList[i]);

				return true;
				break;

			}

		}
	}

	void EnemyService::DestroyEnemy(EnemyController* controller)
	{
		flaggedEnemyList.push_back(controller);
		enemyList.erase(std::remove(enemyList.begin(), enemyList.end(), controller), enemyList.end());
	}


	void EnemyService::Reset()
	{
		Destroy();
		Enemy::EnemyModel::enemyCount = 0;
		Enemy::EnemyModel::enemiesKilled = 0;
	}

	void EnemyService::Destroy()
	{
		for (int i = 0;i < enemyList.size();i++)
		{
			delete(enemyList[i]);
		}
		enemyList.clear();
	}

	void EnemyService::IncreaseScore(EnemyController* controller)
	{
		switch (controller->GetEnemyType())
		{

		case EnemyType::GREEN_DUCK:
			ServiceLocator::GetInstance()->GetPlayerService()->IncreasePlayerScore(1);
			break;

		case EnemyType::RED_DUCK:
			ServiceLocator::GetInstance()->GetPlayerService()->IncreasePlayerScore(2);
			break;
		}
	}

	

	void EnemyService::DestroyFlaggedEnemyList()
	{
		for (int i = 0;i < flaggedEnemyList.size();i++)
		{
			delete(flaggedEnemyList[i]);
		}
		flaggedEnemyList.clear();
	}


}
