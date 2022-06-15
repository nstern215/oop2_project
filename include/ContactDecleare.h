#pragma once

#include <string>

#include "box2d/box2d.h"

class ContactDecleare: public b2ContactListener
{
public:
	ContactDecleare();

	void BeginContact(b2Contact* contact) override;
	void EndContact(b2Contact* contact) override;
	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold) override;
	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse) override;

private:
	std::string owner;

	void(*m_updateFloor)(int);
};