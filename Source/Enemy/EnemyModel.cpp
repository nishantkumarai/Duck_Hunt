#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy
{
	int EnemyModel::NumberOfEnemies = 10;
	int EnemyModel::enemiesKilled = 0;
	int EnemyModel::enemyCount = 0;

	EnemyModel::EnemyModel(EnemyType type)
	{
		currentEnemyType = type;
	}

	EnemyModel::~EnemyModel() = default;
	
	void EnemyModel::Initialize()
	{
		enemyPosition = referencePosition;
	}


	sf::Vector2f EnemyModel::GetEnemyPosition()
	{
		return enemyPosition;
	}

	void EnemyModel::SetEnemyPosition(sf::Vector2f position)
	{
		enemyPosition = position;
	}

	EnemyType EnemyModel::GetCurrentEnemyType()
	{
		return currentEnemyType;
	}
	
}