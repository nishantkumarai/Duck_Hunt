#pragma once

namespace Player
{
	class PlayerController;
	enum class PlayerStatus
	{
		WON,
		FAILED,
		STATIC,
	};
	class PlayerService
	{
	private:
		PlayerController* playerController;

	public:
		PlayerService();
		~PlayerService();

		void Initialize();
		void Update();
		
		void Reset();

		int GetPlayerScore();

		void IncreasePlayerScore(int score);
		
		PlayerStatus currentStatus;
		void SetCurrentStatus(PlayerStatus status);
		PlayerStatus GetCurrentStatus();

		void CheckForChange();

		void DecreasePlayerLive();
		void ResetGame();
	};
}
