#include "../../Header/Time/TimeService.h"


namespace Time
{
	void TimeService::Initialize()
	{
		previousTime = std::chrono::steady_clock::now();
		deltaTime = 0;
	}

	void TimeService::Update()
	{
		UpdateDeltaTime();
	}

	float TimeService::GetDeltaTime()
	{
		return deltaTime;
	}

	void TimeService::UpdateDeltaTime()
	{
		deltaTime = CalculateDeltaTime();
		UpdatePreviousTime();

	}

	float TimeService::CalculateDeltaTime()
	{
		int delta = std::chrono::duration_cast<std::chrono::microseconds>
			(std::chrono::steady_clock::now() - previousTime).count();

		return static_cast<float>(delta) / static_cast<float>(1000000);
	}

	void TimeService::UpdatePreviousTime()
	{
		previousTime = std::chrono::steady_clock::now();
	}
}