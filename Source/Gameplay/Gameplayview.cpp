#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyModel.h"
#include "../../Header/Player/PlayerModel.h"

namespace Gameplay
{
	using namespace UI::UIElement;
	using namespace Global;
	using namespace Player;
	using namespace Enemy;

	GameplayView::GameplayView()
	{
		gameplayImage = new ImageView();
		enemiesKilledText = new TextView();
		playerAmmo = new TextView();
		playerScore = new TextView();
		playerLive = new TextView();
	}

	GameplayView::~GameplayView()
	{
		delete(gameplayImage);
		delete(enemiesKilledText);
		delete(playerAmmo);
		delete(playerScore);
		delete(playerLive);

	}

	void GameplayView::Initialize()
	{

		InitializeBackgroundImage();
		InitializeEnemiesKilledText();
		InitializePlayerAmmo();
		InitializePlayerScore();
		InitializePlayerLive();



	
	}

	void GameplayView::Update()
	{
		
		UpdateEnemiesKilledText();
		UpdatePlayerAmmoText();
		UpdatePlayerScore();
		UpdatePlayerLive();
	}
	void GameplayView::Render()
	{
		gameplayImage->Render();
		enemiesKilledText->Render();
		playerAmmo->Render();
		playerScore->Render();
		playerLive->Render();
	}

	void GameplayView::UpdateEnemiesKilledText()
	{
		sf::String enemiesKilledString = "Enemies Killed :" + std::to_string(EnemyModel::enemiesKilled);
		enemiesKilledText->setText(enemiesKilledString);
	}

	void GameplayView::UpdatePlayerAmmoText()
	{
		sf::String enemiesKilledString = "Player Ammo :" + std::to_string(PlayerModel::playerAmmo);
		playerAmmo->setText(enemiesKilledString);
	}

	void GameplayView::UpdatePlayerScore()
	{
		int score = ServiceLocator::GetInstance()->GetPlayerService()->GetPlayerScore();
		sf::String enemiesKilledString = "Player Score : " + std::to_string(score);
		playerScore->setText(enemiesKilledString);
	
	}

	void GameplayView::UpdatePlayerLive()
	{
		
		sf::String enemiesKilledString = "Player Health : " + std::to_string(PlayerModel::playerLives);
		playerLive->setText(enemiesKilledString);
	}

	void GameplayView::InitializeBackgroundImage()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
		gameplayImage->Initialize(Config::Duck_Hunt_BG_Texture_Path,
			gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0, 0));
	}

	void GameplayView::InitializeEnemiesKilledText()
	{
		enemiesKilledText->Initialize("Enemies Killed : 0", sf::Vector2f(enemiesKilledTextXPosition, textYPosition),
			FontType::BUBBLE_BOBBLE, fontSize, textColor);
	}

	void GameplayView::InitializePlayerAmmo()
	{
		playerAmmo->Initialize("Player Ammo : 0", sf::Vector2f(playerAmmoTextXPosition, textYPosition),
			FontType::BUBBLE_BOBBLE, fontSize, textColor);
	}

	void GameplayView::InitializePlayerLive()
	{
		playerLive->Initialize("Player Health : 0", sf::Vector2f(playerLiveTextXposition, 1000.f),
			FontType::BUBBLE_BOBBLE, fontSize, textColor);
	}

	void GameplayView::InitializePlayerScore()
	{
		playerScore->Initialize("Player Score : 0", sf::Vector2f(textXPosition, playerScoreTextYPosition),
			FontType::BUBBLE_BOBBLE, fontSize, textColor);
	}

}