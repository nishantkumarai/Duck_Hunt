#include "../../Header/Global/ServiceLocator.h"

namespace Global
{
	using namespace Graphics;
	using namespace Event;
	using namespace Gameplay;
	using namespace Enemy;
	using namespace Time;
	using namespace Player;
	using namespace Wave;
	using namespace Sound;

	ServiceLocator::ServiceLocator()
	{
		CreateServices();
	}

	ServiceLocator::~ServiceLocator()
	{
		ClearAllServices();
	}
	
	void ServiceLocator::CreateServices()
	{
		graphicService = new GraphicService();
		eventService = new EventService();
		gameplayService = new GameplayService();
		waveService = new WaveService();
		enemyService = new EnemyService();
		timeService = new TimeService();
		playerService = new PlayerService();
		soundService = new SoundService();

	}

	void ServiceLocator::ClearAllServices()
	{
		delete(graphicService);
		delete(eventService);
		delete(gameplayService);
		delete(enemyService);
		delete(timeService);
		delete(playerService);
		delete(waveService);
		delete(soundService);

	}

	ServiceLocator* ServiceLocator::GetInstance()
	{
		static ServiceLocator instance;
		return &instance;
	}

	void ServiceLocator::Initialize()
	{
		graphicService->Initialize();
		eventService->Initialize();
		timeService->Initialize();
		soundService->Initialize();
		waveService->Initialize();
		enemyService->Initialize();
		gameplayService->Initialize();
		playerService->Initialize();
	}
	void ServiceLocator::Update()
	{
		eventService->Update();
		timeService->Update();
		enemyService->Update();
		gameplayService->Update();
		playerService->Update();

	}
	void ServiceLocator::Render()
	{
		enemyService->Render();
		gameplayService->Render();

	}
	Graphics::GraphicService* ServiceLocator::GetGraphicService()
	{
		return graphicService;
	}
	Event::EventService* ServiceLocator::GetEventService()
	{
		return eventService;
	}

	Gameplay::GameplayService* ServiceLocator::GetGameplayService()
	{
		return gameplayService;
	}
	Enemy::EnemyService* ServiceLocator::GetEnemyService()
	{
		return enemyService;
	}
	Time::TimeService* ServiceLocator::GetTimeService()
	{
		return timeService;
	}
	Player::PlayerService* ServiceLocator::GetPlayerService()
	{
		return playerService;
	}
	Wave::WaveService* ServiceLocator::GetWaveService()
	{
		return waveService;
	}
	Sound::SoundService* ServiceLocator::GetSoundService()
	{
		return soundService;
	}
}