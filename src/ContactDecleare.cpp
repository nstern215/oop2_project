#include "ContactDecleare.h"
#include "Player.h"
#include "Floor.h"

void ContactDecleare::BeginContact(b2Contact* contact)
{
	//check if fixture A was a Player
	Player* bodyUserData = (Player*)contact->GetFixtureA()->GetBody()->GetUserData().pointer;

	if (bodyUserData)
		bodyUserData->startContact();

	//check if fixture B was a Floor
	/*bodyUserData = &contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData)
		static_cast<Floor*>(bodyUserData)->startContact();*/
}

void ContactDecleare::EndContact(b2Contact* contact)
{
	//check if fixture A was a Player

	Player* bodyUserData = (Player*)contact->GetFixtureA()->GetBody()->GetUserData().pointer;

	if (bodyUserData)
		bodyUserData->endContact();

	/*void* bodyUserData = &contact->GetFixtureA()->GetBody()->GetUserData();
	if (bodyUserData)
		if (static_cast<Floor*>(bodyUserData))
			static_cast<Player*>(bodyUserData)->endContact();*/

	//check if fixture B was a Floor
	/*bodyUserData = &contact->GetFixtureB()->GetBody()->GetUserData();
	if (bodyUserData)
		if (static_cast<Floor*>(bodyUserData))
			static_cast<Floor*>(bodyUserData)->endContact();*/
}

void ContactDecleare::PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{

}

void ContactDecleare::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{

}
