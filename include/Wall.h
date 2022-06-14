#pragma once
#include "Views/WallView.h"
#include "box2d/box2d.h"

class Wall
{
public:
	Wall(b2World* world, sf::Vector2u windowSize, int wallNum);

	void draw(sf::RenderWindow& window) const;

	b2Vec2 getBodyPosition();
	void updatePosition(sf::Vector2f update) const;

private:

	void buildWallBody(sf::Vector2u windowSize, int wallNum);

	b2BodyDef m_bodyDef;
	b2PolygonShape m_staticBox;
	b2FixtureDef m_fixtureDef;
	b2Body* m_body;
	b2World* m_gameWorld;

	std::unique_ptr<WallView> m_view;
};