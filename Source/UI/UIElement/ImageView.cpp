#include "../../Header/UI/UIElement/ImageView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Global/Config.h"

namespace UI
{
	namespace UIElement
	{
		
		using namespace Global;

		ImageView::ImageView() = default;
		

		ImageView::~ImageView() = default;
		

		void ImageView::Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position)
		{
			
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWIndow();
			SetTexture(texturePath);
			SetScale(imageWidth, imageHeight);
			SetPosition(position);

		}

		
		void ImageView::SetTexture(sf::String texturePath)
		{

			if (imageTexture.loadFromFile(texturePath))
			{

				imageSprite.setTexture(imageTexture);
				
			}
		}

		void ImageView::SetScale(float imageWidth, float imageHeight)
		{
			float scaleX = imageWidth / static_cast<float> (imageSprite.getTexture()->getSize().x);
			float scaleY = imageHeight / static_cast<float> (imageSprite.getTexture()->getSize().y);

			imageSprite.setScale(scaleX, scaleY);
		}

		void ImageView::SetPosition(sf::Vector2f position)
		{
			imageSprite.setPosition(position);
		}

		sf::Sprite& ImageView::GetImageSprite()
		{
			return imageSprite;
		}

		void ImageView::Render()
		{
			
			gameWindow->draw(imageSprite);

		}
	}



}