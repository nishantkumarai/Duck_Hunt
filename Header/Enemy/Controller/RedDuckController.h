#pragma once
#pragma once
#include "../../Header/Enemy/EnemyController.h"
#include <SFML/System/Clock.hpp>
#include <SFML/Graphics.hpp>

namespace Enemy
{
	enum class EnemyType;
	namespace Controller
	{
		class RedDuckController : public EnemyController
		{
		private:

		public:
			RedDuckController();
			~RedDuckController() override;


			void Initialize() override;

			void Move() override;


			float verticalSpeed = 1000.f;
			float HorizontalSpeed = 500.f;
			float diagonalLeftSpeed = 600.f;
			float diagonalRightSpeed = 700.f;

			



		};
	}
}