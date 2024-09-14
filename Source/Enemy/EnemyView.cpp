#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyController.h"
#include "../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{
	using namespace UI::UIElement;
	using namespace Global;

	EnemyView::EnemyView()
	{
		enemyImage = new ImageView();
		
	}

	EnemyView::~EnemyView()
	{
		delete(enemyImage);
	}

	void EnemyView::Initialize(EnemyController* controller)
	{
		enemyController = controller;
		InitializeEnemySprite(controller);
	}

	void EnemyView::InitializeEnemySprite(EnemyController* controller)
	{
		
		enemyImage->Initialize(GetEnemyTexturePath(),
			enemySpriteWidth, enemySpriteHeight, enemyController->GetEnemyPosition() );

	}

	void EnemyView::Update()
	{
		enemyImage->SetPosition(enemyController->GetEnemyPosition());
		

	}

	void EnemyView::Render()
	{
		enemyImage->Render();
	}
	sf::Sprite& EnemyView::GetEnemySprite()
	{
		return enemyImage->GetImageSprite();
	}
	sf::String EnemyView::GetEnemyTexturePath()
	{
		switch (enemyController->GetEnemyType())
		{

		case Enemy::EnemyType::GREEN_DUCK:
			return Config::Green_Duck_Enemy;


		case Enemy::EnemyType::RED_DUCK:

			return Config::Red_Duck_Enemy;

		}
	}
}