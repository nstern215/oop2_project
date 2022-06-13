#include "Animation.h"
#include "Resources.h"

#include <iostream>

const auto AnimationTime = sf::seconds(0.2f);

Animation::Animation(const AnimationData& data, Direction dir, sf::Sprite& sprite)
	: m_data(data), m_dir(dir), m_sprite(sprite)
{
	m_sprite.setTexture(*Resources::instance()->getTexture("game_sprite"));
	m_sprite.setPosition(500, 100);
	
	update();

	const auto bound = m_sprite.getGlobalBounds();
	
	const auto midX = m_sprite.getGlobalBounds().width / 2;
	const auto midY = m_sprite.getGlobalBounds().height / 2;

	m_sprite.setOrigin(midX, midY);
}

void Animation::direction(Direction dir)
{
	if (m_dir == dir)
	{
		return;
	}

	m_dir = dir;
	update();
}

void Animation::update(sf::Time delta)
{
	m_elapsed += delta;
	if (m_elapsed >= AnimationTime)
	{
		m_elapsed -= AnimationTime;
		++m_index;
		m_index %= m_data.m_data.find(m_dir)->second.size();
		update();
	}
}

void Animation::update()
{
	if (m_data.m_data.find(m_dir)->second.size() <= m_index)
		m_index %= m_data.m_data.find(m_dir)->second.size();
	
	m_sprite.setTextureRect(m_data.m_data.find(m_dir)->second[m_index]);
}
