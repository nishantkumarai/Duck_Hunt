#pragma once

namespace Player
{
	
	class PlayerModel
	{
	private:
		
		int maxPlayerAmmo = 5;
		int playerScore = 0;

	public:
		PlayerModel();
		~PlayerModel();

		void Initialize();
		
		int GetPlayerAmmo();
	
		
		static int playerAmmo;
		
		int GetPlayerScore();
		void SetPlayeScore(int score);

		static int playerLives;



	};
}
