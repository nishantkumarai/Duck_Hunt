#pragma once

namespace Enemy
{
	enum class MovementDirection
	{
		LEFT,
		RIGHT,
		DOWN,
		UP,
		DIAGONAL_LEFT_UP,
		DIAGONAL_RIGHT_UP,
		DIAGONAL_LEFT_DOWN,
		DIAGONAL_RIGHT_DOWN,
	};

	enum class EnemyType
	{
		GREEN_DUCK,
		RED_DUCK,
	};
	enum class EnemyState
	{
		DEAD,
		PATROLLING,
	};
}