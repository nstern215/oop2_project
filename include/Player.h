#pragma once
#include "Views/PlayerView.h"
#include "box2d/box2d.h"

class Player
{
public:
	Player(b2World* gameWorld, b2Vec2 startingPosition, b2Vec2 size);
	void draw(sf::RenderWindow& window) const;
	void handleCollision();
	void updatePosition(sf::Vector2f update) const;
	b2Vec2 keyPress();
	sf::Vector2f getPosition() const;

	void update(sf::Time delta) const;
	
	void setBodyVelocity(b2Vec2 vel) const;
	b2Vec2 getBodyVelocity() const;
	b2Vec2 getBodyPosition() const;


private:

	void buildBody(b2World* world, b2Vec2 startingPosition, b2Vec2 size);

	bool m_inContact

	b2BodyDef m_bodyDef;
	b2PolygonShape m_dynamicBox;
	b2FixtureDef m_fixtureDef;
	b2Body* m_body;

	std::unique_ptr<PlayerView> m_view;

	float m_playerSpeed;
};
