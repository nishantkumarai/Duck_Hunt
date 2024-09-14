#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "../../Header/Wave/WaveServices.h"

namespace Enemy
{
	enum class EnemyType;
	class EnemyController;
	
	class EnemyService
	{
	private:
		std::vector<EnemyController*> enemyList;
		std::vector<EnemyController*> flaggedEnemyList;

		Wave::WaveService* wave;

		const float spawnInterval = 2.f;
		float spawnTimer = spawnInterval;

		EnemyController* CreateEnemy(EnemyType enemyType);
		EnemyType GetRandomEnemyType();
		
		void UpdateSpawnTimer();
		void SpawnEnemy();
		void ProcessSpawnEnemy();

		void Destroy();

		void IncreaseScore(EnemyController* controller);

	public:
		EnemyService();
		~EnemyService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		bool DestroyEnemyAtMousePosition(sf::Vector2f mousePosition);
		void DestroyFlaggedEnemyList();
		void DestroyEnemy(EnemyController* controller);


		

	};
}

