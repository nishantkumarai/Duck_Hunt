#pragma once
#include "../../Header/UI/UIElement/ImageView.h"


namespace Enemy
{
	class EnemyModel;
	class EnemyController;
	class EnemyView
		
	{
	private:
		EnemyModel* enemyModel;
		EnemyController* enemyController;
		UI::UIElement::ImageView* enemyImage;

	public:
		EnemyView();
		~EnemyView();
		
		const float enemySpriteHeight = 150.f;
		const float enemySpriteWidth = 150.f;

		void InitializeEnemySprite(EnemyController* controller);

		void Initialize(EnemyController* controller);
		void Update();
		void Render();

		sf::Sprite& GetEnemySprite();
		sf::String GetEnemyTexturePath();

	};
}