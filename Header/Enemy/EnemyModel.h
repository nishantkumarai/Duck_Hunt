#pragma once
#include <SFML/System/Vector2.hpp>


namespace Enemy
{
	enum class EnemyType;
	class EnemyModel
	{
	private:
		sf::Vector2f referencePosition = sf::Vector2f(900.f, 880.f);
		sf::Vector2f enemyPosition;


	public:
		EnemyModel(EnemyType type);
		~EnemyModel();

		void Initialize();


		sf::Vector2f GetEnemyPosition();
		void SetEnemyPosition(sf::Vector2f position);

		float LeftMostPosition = 50.f;
		float RightMostPosition = 1800.f;
		float TopMostPosition = 0.f;
		float BottomMostPosition = 880.f;

		EnemyType currentEnemyType;
		EnemyType GetCurrentEnemyType();

		static int NumberOfEnemies;
		static int enemiesKilled;
		static int enemyCount;



	};
}