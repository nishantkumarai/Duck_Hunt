#include "../../Header/Player/PlayerModel.h"

namespace Player
{
	int PlayerModel::playerAmmo = 0;
	int PlayerModel::playerLives = 3;

	PlayerModel::PlayerModel() = default;
	
	PlayerModel::~PlayerModel() = default;

	
	void PlayerModel::Initialize()
	{
		playerAmmo = maxPlayerAmmo;
	}


	int PlayerModel::GetPlayerAmmo()
	{
		return playerAmmo;
	}

	int PlayerModel::GetPlayerScore()
	{
		return playerScore;
	}

	void PlayerModel::SetPlayeScore(int score)
	{
		playerScore = score;
	}
	

}