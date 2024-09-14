#include "../../Header/Sound/SoundService.h"
#include "../../Header/Global/Config.h"

namespace Sound
{
	using namespace Global;
	void SoundService::Initialize()
	{
		LoadSoundFromFile();
	}

	void SoundService::LoadSoundFromFile()
	{
		if (!bufferDuck.loadFromFile(Config::Duck_sound_path))
		{
			printf("Error Loading Sound Effect");

		}

		if (!buffeStart.loadFromFile(Config::music_path))
		{
			printf("Error Loading Sound Effect");

		}

		if (!bufferFailed.loadFromFile(Config::Failing_path))
		{
			printf("Error Loading Sound Effect");

		}

		if (!bufferWon.loadFromFile(Config::Winning_path))
		{
			printf("Error Loading Sound Effect");

		}

	}

	void SoundService::PlaySound(SoundType soundType)
	{

		switch (soundType)
		{
		case SoundType::DUCK_SOUND:
			soundEffect.setBuffer(bufferDuck);
			break;

		case SoundType::START_MUSIC:
			soundEffect.setBuffer(buffeStart);
			break;

		case SoundType::FAIL_SOUND:

			soundEffect.setBuffer(bufferFailed);
			break;

		case SoundType::WON_SOUND:

			soundEffect.setBuffer(bufferWon);
			break;

		default:
			printf("Invalid Sound");

		}
		soundEffect.play();
	}




}