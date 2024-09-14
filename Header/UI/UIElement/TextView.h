#pragma once
#include <SFML/Graphics.hpp>

namespace UI
{
	namespace UIElement
	{
		enum class FontType
		{

			BUBBLE_BOBBLE,
			DS_DIGIB,
		};
		class TextView
		{
		private:
			sf::RenderWindow* gameWindow;
			static const int defualtFontSize = 55;

			static sf::Font fontBubbleBobble;
			static sf::Font fontDSDIGIB;

			sf::Text text;

			static void LoadFont();

			void SetFont(FontType fontType);
			void SetFontSize(int fontSize);
			void SetTextPosition(sf::Vector2f position);
			void SetTextColor(sf::Color color);


		public:
			TextView();
			~TextView();

			

			void Initialize(sf::String textValue, sf::Vector2f position,
				FontType fontType = FontType::BUBBLE_BOBBLE, int fontSize = defualtFontSize,
				sf::Color color = sf::Color::White);
		
			void Render();

			void setText(sf::String textValue);
			void setTextcentreAligned();
		};
	}
}
