#pragma once
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>


namespace Enemy
{
	class EnemyView;
	class EnemyModel;
	enum class EnemyType;

	enum class MovementDirection;

	class EnemyController
	{
	protected:
		EnemyView* enemyView;
		EnemyModel* enemyModel;
		void HandleOutOfBounds();
		MovementDirection currentDirection;
		sf::Clock directionChangeClock;


	public:
		EnemyController(EnemyType type);
		virtual ~EnemyController();

		virtual void Move() = 0;

		virtual void Initialize();
		void Update();
		void Render();

		sf::Vector2f GetEnemyPosition();
		MovementDirection GetRandomMovementDirection();

		sf::Sprite& GetEnemySprite();
		EnemyType GetEnemyType();

		void MoveRight(int verticalSpeed, sf::Vector2f position);
		

		void MoveInDirection(MovementDirection direction, float speed);
	};
}
