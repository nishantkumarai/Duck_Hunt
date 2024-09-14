#pragma once
#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/UI/UIElement/TextView.h"

namespace Gameplay
{
	class GameplayView
	{
	private:

		UI::UIElement::ImageView* gameplayImage;
		UI::UIElement::TextView* enemiesKilledText;
		UI::UIElement::TextView* playerAmmo;
		UI::UIElement::TextView* playerScore;
		UI::UIElement::TextView* playerLive;

		sf::RenderWindow* gameWindow;

		const float textYPosition = 15.f;
		const float textXPosition = 60.f;

		const float enemiesKilledTextXPosition = 60.f;
		const float playerAmmoTextXPosition = 1600.f;

		const float playerScoreTextYPosition = 1000.f;
		const float playerLiveTextXposition = 1600.;

		const float fontSize = 40.f;

		const sf::Color textColor = sf::Color::White;


	public:
		GameplayView();
		~GameplayView();

		void Initialize();
		void Update();
		void Render();

		void UpdateEnemiesKilledText();
		void UpdatePlayerAmmoText();
		void UpdatePlayerScore();
		void UpdatePlayerLive();


		void InitializeBackgroundImage();
		void InitializeEnemiesKilledText();
		void InitializePlayerAmmo();
		void InitializePlayerLive();
		void InitializePlayerScore();



	};
}