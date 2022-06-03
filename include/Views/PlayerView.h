#pragma once
#include "BaseView.h"
#include "box2d/box2d.h"

class PlayerView : public BaseView
{
public:
	PlayerView(int windowHeight);

	void buildPlayer();
	void draw(sf::RenderWindow& window) override;
	void setPosition(sf::Vector2f position) override;
	void move(sf::Vector2f move) override;
	void buildBody(b2World &world);

	void setBodyVelocity(b2Vec2 vel);
	b2Vec2 getBodyVelocity();
	b2Vec2 getBodyPosition();

private:

	b2BodyDef m_bodyDef;
	b2PolygonShape m_dynamicBox;
	b2FixtureDef m_fixtureDef;
	b2Body* m_body;
	
	sf::Sprite m_sprite;

	sf::RectangleShape m_shape;
}; 