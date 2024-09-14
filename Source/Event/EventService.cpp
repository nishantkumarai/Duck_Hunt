#include "../../Header/Event/EventService.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Event
{
	using namespace Global;

	EventService::EventService()
	{
		leftMouseButtonState = ButtonState::RELEASED;
		gameWindow = nullptr;
	}
	EventService::~EventService() = default;
	

	void EventService::Initialize()
	{
		gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
	}

	void EventService::Update()
	{
		UpdateMouseButtonState(leftMouseButtonState, sf::Mouse::Left);
	}

	void EventService::UpdateMouseButtonState(ButtonState& currentButtonState, sf::Mouse::Button mouseButton)
	{
		if (sf::Mouse::isButtonPressed(mouseButton))
		{
			switch (currentButtonState)
			{
			case ButtonState::RELEASED:
				currentButtonState = ButtonState::PRESSED;
				break;
			case ButtonState::PRESSED:
				currentButtonState = ButtonState::HELD;
				break;
			}
		}
		else
		{
			currentButtonState = ButtonState::RELEASED;
		}
	}

	void EventService::ProcessEvent()
	{
		if (ISGameWindowOpen())
		{
			while (gameWindow->pollEvent(gameEvent))
			{
				if (GameWindowWasClosed() || HasQuitGame())
				{
					gameWindow->close();
				}

				/*if (gameEvent.type == sf::Event::MouseButtonPressed && gameEvent.mouseButton.button == sf::Mouse::Left)
				{
					
					printf("Left mouse button pressed at (%d, %d)\n", gameEvent.mouseButton.x, gameEvent.mouseButton.y);
				}*/
			}
		}
	}

	bool EventService::HasQuitGame()
	{
		return (ISKeyBoardEvent() && PressedEscapeKey());
	}

	bool EventService::ISKeyBoardEvent()
	{
		return gameEvent.type == sf::Event::KeyPressed;
	}

	bool EventService::PressedEscapeKey()
	{
		return gameEvent.key.code == sf::Keyboard::Escape;

	}

	

	bool EventService::PressedLeftMouseButton()
	{
		return leftMouseButtonState == ButtonState::PRESSED;
		

	}

	bool EventService::ISGameWindowOpen()
	{
		return gameWindow != nullptr;
	}

	bool EventService::GameWindowWasClosed()
	{
		return gameEvent.type == sf::Event::Closed;
	}
	
	
}