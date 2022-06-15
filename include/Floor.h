#pragma once
#include "Views/FloorView.h"
#include "ContactDecleare.h"
#include "box2d/box2d.h"

class Floor
{
public:
	Floor(b2World* world, float width, float x, float y, float floorLevel);

	void draw(sf::RenderWindow& window) const;
	void handleCollision();
	void repositionFloor(b2Vec2 newPosition);

	b2Vec2 getBodyPosition();
	void updatePosition(sf::Vector2f update) const;

	sf::Vector2f getPosition() const;

	void startContact() { m_contacting = true; }
	void endContact() { m_contacting = false; }

private:

	void buildFloorBody(float width, float x, float y, float floorLevel);

	bool m_contacting;

	b2BodyDef m_bodyDef;
	b2PolygonShape m_staticBox;
	b2FixtureDef m_fixtureDef;
	b2Body* m_body;
	b2World* m_gameWorld;

	std::unique_ptr<ContactDecleare> m_contactDecleare;

	std::unique_ptr<FloorView> m_view;
};