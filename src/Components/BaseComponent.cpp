#include <Components/BaseComponent.h>

void BaseComponent::active()
{
	std::map<std::string, std::string> map;
	active(map);
}
