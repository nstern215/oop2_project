#include "ContactDecleare.h"

#include <cstdint>

#include "Player.h"
#include "Floor.h"

void ContactDecleare::BeginContact(b2Contact* contact)
{
	//A - floor
	//B - player
	
	uintptr_t fixtureBBodyData = contact->GetFixtureB()->GetUserData().pointer;

	if (fixtureBBodyData && reinterpret_cast<Player*>(fixtureBBodyData))
	{
		reinterpret_cast<Player*>(fixtureBBodyData)->startContact();
	}
}

void ContactDecleare::EndContact(b2Contact* contact)
{
	//A - floor
	//B - player
	
	uintptr_t fixtureBBodyData = contact->GetFixtureB()->GetUserData().pointer;

	if (fixtureBBodyData && reinterpret_cast<Player*>(fixtureBBodyData))
	{
		reinterpret_cast<Player*>(fixtureBBodyData)->endContact();
	}
}

void ContactDecleare::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}

void ContactDecleare::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}
