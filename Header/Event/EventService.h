#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace Event
{
	enum class ButtonState
	{
		PRESSED,
		HELD,
		RELEASED,
	};

	class EventService
	{
	private:

		sf::Event gameEvent;
		sf::RenderWindow* gameWindow;

		bool ISGameWindowOpen();
		bool GameWindowWasClosed();
		bool HasQuitGame();

		bool ISKeyBoardEvent();
		bool PressedEscapeKey();
		
		ButtonState	leftMouseButtonState;

		void UpdateMouseButtonState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton);


	public:
		EventService();
		~EventService();

		void ProcessEvent();

		void Initialize();
		void Update();

		bool PressedLeftMouseButton();
		bool leftMouseButtonPressed = false;


	};
}