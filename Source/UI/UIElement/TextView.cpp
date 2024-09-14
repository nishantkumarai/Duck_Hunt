#include "../../Header/UI/UIElement/TextView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;

		sf::Font TextView::fontBubbleBobble;
		sf::Font TextView::fontDSDIGIB;

		TextView::TextView() = default;
		


		TextView::~TextView() = default;

		void TextView::Initialize(sf::String textValue, sf::Vector2f position, FontType fontType, int fontSize, sf::Color color)
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
			LoadFont();

			setText(textValue);
			SetTextPosition(position);
			SetFont(fontType);
			SetFontSize(fontSize);
			SetTextColor(color);

		}

		

		void TextView::Render()
		{
			gameWindow->draw(text);
		}

		void TextView::setText(sf::String textValue)
		{
			text.setString(textValue);
		}

		void TextView::setTextcentreAligned()
		{
			float xPosition = (gameWindow->getSize().x - text.getLocalBounds().width) / 2;
			float yPosition = text.getGlobalBounds().getPosition().y;

			text.setPosition(xPosition, yPosition);
		}


		 void TextView::LoadFont()
		 {
			 fontBubbleBobble.loadFromFile(Config::bubble_bobble_font_path);
			 fontDSDIGIB.loadFromFile(Config::DS_DIGIB_font_path);
		 }

		 void TextView::SetFont(FontType fontType)
		 {
			 switch (fontType)
			 {
			 case FontType::BUBBLE_BOBBLE:
				 text.setFont(fontBubbleBobble);
				 break;

			 case FontType::DS_DIGIB:
				 text.setFont(fontDSDIGIB);
				 break;
			 }
		 }
		 void TextView::SetFontSize(int fontSize)
		 {

			 text.setCharacterSize(fontSize);

		 }
		 void TextView::SetTextPosition(sf::Vector2f position)
		 {
			 text.setPosition(position);

		 }
		 void TextView::SetTextColor(sf::Color color)
		 {
			 text.setFillColor(color);

		 }
	}
}
