#pragma once
#include "ContactDecleare.h"
#include "Views/PlayerView.h"
#include "box2d/box2d.h"

class Player
{
public:
	Player(b2World* gameWorld, b2Vec2 startingPosition, b2Vec2 size);
	void draw(sf::RenderWindow& window) const;
	void updatePosition(sf::Vector2f update);
	b2Vec2 keyPress();
	sf::Vector2f getPosition() const;

	void update(sf::Time delta) const;
	
	void setBodyVelocity(b2Vec2 vel) const;
	b2Vec2 getBodyVelocity() const;
	b2Vec2 getBodyPosition() const;

	void startContact();
	void endContact();

	int getYAxisDirection() const;

private:

	void buildBody(b2World* world, b2Vec2 startingPosition, b2Vec2 size);

	bool m_contacting;

	b2BodyDef m_bodyDef;
	b2PolygonShape m_dynamicBox;
	b2FixtureDef m_fixtureDef;
	b2Body* m_body;

	std::unique_ptr<PlayerView> m_view;

	float m_playerSpeed;

	std::unique_ptr<ContactDecleare> m_contactDecleare;

	int contactCounter = 0;

	sf::Vector2f m_oldPosition;
};
