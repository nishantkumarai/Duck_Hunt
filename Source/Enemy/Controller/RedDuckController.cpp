#include "../../Header/Enemy/Controller/RedDuckController.h"
#include "../../Header/Enemy/EnemyConfig.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Enemy
{
	namespace Controller
	{
		using namespace Global;

		RedDuckController::RedDuckController() : EnemyController(EnemyType::RED_DUCK)
		{
			std::srand(static_cast<unsigned int>(std::time(nullptr)));
			currentDirection = GetRandomMovementDirection();
		}

		RedDuckController::~RedDuckController() = default;


		void RedDuckController::Initialize()
		{
			EnemyController::Initialize();

		}

		void Enemy::Controller::RedDuckController::Move()
		{
			

			switch (currentDirection)
			{

			case MovementDirection::LEFT:
				MoveInDirection(MovementDirection::LEFT, verticalSpeed);
				break;

			case MovementDirection::RIGHT:
				MoveInDirection(MovementDirection::RIGHT, verticalSpeed);
				break;

			case MovementDirection::UP:
				MoveInDirection(MovementDirection::UP, HorizontalSpeed);
				break;

			case MovementDirection::DOWN:
				MoveInDirection(MovementDirection::DOWN, HorizontalSpeed);
				break;

			case MovementDirection::DIAGONAL_LEFT_UP:
				MoveInDirection(MovementDirection::DIAGONAL_LEFT_UP, diagonalLeftSpeed);
				break;

			case MovementDirection::DIAGONAL_LEFT_DOWN:
				MoveInDirection(MovementDirection::DIAGONAL_LEFT_DOWN, diagonalLeftSpeed);
				break;

			case MovementDirection::DIAGONAL_RIGHT_UP:
				MoveInDirection(MovementDirection::DIAGONAL_RIGHT_UP, diagonalRightSpeed);
				break;

			case MovementDirection::DIAGONAL_RIGHT_DOWN:
				MoveInDirection(MovementDirection::DIAGONAL_RIGHT_DOWN, diagonalRightSpeed);
				break;
			}
		}

	}
}

