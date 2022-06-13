#pragma once
#include "Views/PlayerView.h"
#include "box2d/box2d.h"

class Player
{
public:
	Player(b2World* gameWorld, sf::Vector2f startingPosition, b2Vec2 size);
	void draw(sf::RenderWindow& window) const;
	void handleCollision();
	void updatePosition(sf::Vector2f update) const;
	void keyPress(sf::Keyboard::Key key);
	sf::Vector2f getPosition() const;

	void setBodyVelocity(b2Vec2 vel);
	b2Vec2 getBodyVelocity();
	b2Vec2 getBodyPosition();


private:

	void buildBody(b2World* world, sf::Vector2f startingPosition, b2Vec2 size);

	b2BodyDef m_bodyDef;
	b2PolygonShape m_dynamicBox;
	b2FixtureDef m_fixtureDef;
	b2Body* m_body;

	std::unique_ptr<PlayerView> m_view;

	float m_playerSpeed;
};
