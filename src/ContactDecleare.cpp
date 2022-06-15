#include "ContactDecleare.h"

#include <cstdint>

#include "Player.h"
#include "Floor.h"
#include "../include/Floor.h"
#include "../include/Player.h"

ContactDecleare::ContactDecleare(void(*updateFloor)(int)): m_updateFloor(updateFloor){}

void ContactDecleare::BeginContact(b2Contact* contact)
{
	auto fixtureA = contact->GetFixtureA()->GetUserData().pointer;
	auto fixtureB = contact->GetFixtureB()->GetUserData().pointer;

	if (fixtureA)
	{
		if (reinterpret_cast<Floor*>(fixtureA))
		{
			Floor* f = reinterpret_cast<Floor*>(fixtureA);

			int level = f->getLevel();
			m_updateFloor(level);
		}
		if (reinterpret_cast<Player*>(fixtureA))
		{
			reinterpret_cast<Player*>(fixtureA)->startContact();
		}
	}
	if (fixtureB)
	{
		if (reinterpret_cast<Floor*>(fixtureB))
		{
			Floor* f = reinterpret_cast<Floor*>(fixtureB);

			int level = f->getLevel();
			m_updateFloor(level);
		}
		if (reinterpret_cast<Player*>(fixtureB))
		{
			reinterpret_cast<Player*>(fixtureB)->startContact();
		}
	}
	
	//A - floor
	//B - player

	/*uintptr_t floor = contact->GetFixtureA()->GetUserData().pointer;
	
	if (floor && reinterpret_cast<Floor*>(floor))
	{
		Floor* f = reinterpret_cast<Floor*>(floor);
		
		int level = f->getLevel();
		m_updateFloor(level);
	}
	uintptr_t fixtureBBodyData = contact->GetFixtureB()->GetUserData().pointer;

	if (fixtureBBodyData && reinterpret_cast<Player*>(fixtureBBodyData))
	{
		reinterpret_cast<Player*>(fixtureBBodyData)->startContact();
	}*/
}

void ContactDecleare::EndContact(b2Contact* contact)
{
	auto fixtureA = contact->GetFixtureA()->GetUserData().pointer;
	auto fixtureB = contact->GetFixtureB()->GetUserData().pointer;

	if (fixtureA)
	{
		/*if (reinterpret_cast<Floor*>(fixtureA))
		{
			Floor* f = reinterpret_cast<Floor*>(floor);

			int level = f->getLevel();
			m_updateFloor(level);
		}*/
		if (reinterpret_cast<Player*>(fixtureA))
		{
			reinterpret_cast<Player*>(fixtureA)->endContact();
		}
	}
	if (fixtureB)
	{
		/*if (reinterpret_cast<Floor*>(fixtureB))
		{
			Floor* f = reinterpret_cast<Floor*>(floor);

			int level = f->getLevel();
			m_updateFloor(level);
		}*/
		if (reinterpret_cast<Player*>(fixtureB))
		{
			reinterpret_cast<Player*>(fixtureB)->endContact();
		}
	}
	//A - floor
	//B - player
	
	/*uintptr_t fixtureBBodyData = contact->GetFixtureB()->GetUserData().pointer;

	if (fixtureBBodyData && reinterpret_cast<Player*>(fixtureBBodyData))
	{
		reinterpret_cast<Player*>(fixtureBBodyData)->endContact();
	}*/
}

void ContactDecleare::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}

void ContactDecleare::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}
