#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Enemy/EnemyConfig.h"


namespace Enemy
{
	using namespace Global;

	EnemyController::EnemyController(EnemyType type)
	{
		enemyView = new EnemyView();
		enemyModel = new EnemyModel(type);
		std::srand(static_cast<unsigned int>(std::time(nullptr)));
		currentDirection = GetRandomMovementDirection();
	}

	EnemyController::~EnemyController()
	{
		delete(enemyView);
		delete(enemyModel);
	}

	void EnemyController::Initialize()
	{
		enemyModel->Initialize();
		enemyView->Initialize(this);
	}

	void EnemyController::Update()
	{
		enemyView->Update();
		Move();
		HandleOutOfBounds();
	}

	void EnemyController::HandleOutOfBounds()
	{
		sf::Vector2f enemyPosition = GetEnemyPosition();
		sf::Vector2u windowSize = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow()->getSize();

		if (enemyPosition.x<0 || enemyPosition.x >windowSize.x ||
			enemyPosition.y<0 || enemyPosition.y >windowSize.y)
		{
			ServiceLocator::GetInstance()->GetEnemyService()->DestroyEnemy(this);

		}

	}

	void EnemyController::Render()
	{
		enemyView->Render();
	}

	sf::Vector2f EnemyController::GetEnemyPosition()
	{
		return enemyModel->GetEnemyPosition();;
	}

	MovementDirection EnemyController::GetRandomMovementDirection()
	{
		int randomType = std::rand() % 8;
		return static_cast<Enemy::MovementDirection>(randomType);

	}

	sf::Sprite& EnemyController::GetEnemySprite()
	{

		return enemyView->GetEnemySprite();
	}

	EnemyType EnemyController::GetEnemyType()
	{
		return enemyModel->GetCurrentEnemyType();
	}

	void EnemyController::MoveInDirection(MovementDirection direction, float speed)
	{
		float deltaTime = ServiceLocator::GetInstance()->GetTimeService()->GetDeltaTime();
		sf::Vector2f currentPosition = enemyModel->GetEnemyPosition();
		float finalSpeed = speed * deltaTime;

		if (directionChangeClock.getElapsedTime().asSeconds() >= 1.0f)
		{
			currentDirection = GetRandomMovementDirection();
			directionChangeClock.restart();
		}


		switch (direction)
		{
		case MovementDirection::LEFT:
			currentPosition.x -= finalSpeed;
			
			break;
		case MovementDirection::RIGHT:
			currentPosition.x += finalSpeed;
			break;

		case MovementDirection::UP:
			currentPosition.y -= finalSpeed;
			break;

		case MovementDirection::DOWN:
			currentPosition.y += finalSpeed;
			break;

		case MovementDirection::DIAGONAL_LEFT_UP:
			currentPosition.x -= finalSpeed;
			currentPosition.y -= finalSpeed;
			break;
		case MovementDirection::DIAGONAL_LEFT_DOWN:
			currentPosition.x -= finalSpeed;
			currentPosition.y += finalSpeed;
			break;
		case MovementDirection::DIAGONAL_RIGHT_UP:

			currentPosition.x += speed * finalSpeed;
			currentPosition.y -= speed * finalSpeed;

			
			break;
		case MovementDirection::DIAGONAL_RIGHT_DOWN:

			currentPosition.x += speed * finalSpeed;
			currentPosition.y += speed * finalSpeed;

			break;
		}

		if (currentPosition.y >= enemyModel->BottomMostPosition ||
			currentPosition.x <= enemyModel->LeftMostPosition||
			currentPosition.y <= enemyModel->TopMostPosition ||
			currentPosition.x >= enemyModel->RightMostPosition)
		{
			currentDirection = GetRandomMovementDirection();
			directionChangeClock.restart();
		}
		else
		{
			enemyModel->SetEnemyPosition(currentPosition);
		}

	}
}