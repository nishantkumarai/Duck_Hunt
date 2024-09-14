#pragma once
#include "SFML/Audio.hpp"

namespace Sound
{
	enum class SoundType
	{
		START_MUSIC,
		DUCK_SOUND,
		FAIL_SOUND,
		WON_SOUND,
	};
	class SoundService

	{

	private:
		

		
		sf::Sound soundEffect;
		sf::SoundBuffer bufferDuck;
		sf::SoundBuffer buffeStart;
		sf::SoundBuffer bufferWon;
		sf::SoundBuffer bufferFailed;


		
		void LoadSoundFromFile();

	public:


		void Initialize();

		
		void PlaySound(SoundType soundType);
	};
}