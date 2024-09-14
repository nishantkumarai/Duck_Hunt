#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Graphics/GraphicService.h"
#include "../../Header/Event/EventService.h"
#include "../../Header/Gameplay/GameplayService.h"
#include "../../Header/Enemy/EnemyService.h"
#include "../../Header/Time/TimeService.h"
#include "../../Header/Player/PlayerService.h"
#include "../../Header/Wave/WaveServices.h"
#include "../../Header/Sound/SoundService.h"

namespace Global
{
	class ServiceLocator
	{
	private:

		Graphics::GraphicService* graphicService;
		Event::EventService* eventService;
		Gameplay::GameplayService* gameplayService;
		Enemy::EnemyService* enemyService;
		Time::TimeService* timeService;
		Player::PlayerService* playerService;
		Wave::WaveService* waveService;
		Sound::SoundService* soundService;

		ServiceLocator();
		~ServiceLocator();

		void CreateServices();
		void ClearAllServices();


	public:

		static ServiceLocator* GetInstance();

		void Initialize();
		void Update();
		void Render();

		Graphics::GraphicService* GetGraphicService();
		Event::EventService* GetEventService();
		Gameplay::GameplayService* GetGameplayService();
		Enemy::EnemyService* GetEnemyService();
		Time::TimeService* GetTimeService();
		Player::PlayerService* GetPlayerService();
		Wave::WaveService* GetWaveService();
		Sound::SoundService* GetSoundService();
	
	};
}
