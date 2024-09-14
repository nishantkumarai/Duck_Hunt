#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class EnemyType;
	namespace Controller
	{
		class GreenDuckController : public EnemyController
		{
		private:

		public:
			GreenDuckController();
			~GreenDuckController() override;


			void Initialize() override;
			
			void Move() override;


			float verticalSpeed = 1000.f;
			float HorizontalSpeed = 500.f;
			float diagonalLeftSpeed = 600.f;
			float diagonalRightSpeed = 800.f;

		

		

		};
	}
}