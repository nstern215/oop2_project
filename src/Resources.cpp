#include "Resources.h"

//
//namespace
//{
//    AnimationData playerData()
//    {
//        const auto size = sf::Vector2i(40, 40);
//        const auto initSpace = sf::Vector2i(1, 2);
//        const auto middleSpace = sf::Vector2i(0, 10);
//
//        auto player = AnimationData{};
//        auto currentStart = initSpace;
//
//        auto nextStart = [&]()
//        {
//            currentStart += middleSpace;
//            currentStart.y += size.y;
//            return currentStart;
//        };
//
//        player.m_data[Direction::Right].emplace_back(currentStart, size);
//        player.m_data[Direction::Right].emplace_back(nextStart(), size);
//        player.m_data[Direction::Down].emplace_back(nextStart(), size);
//        player.m_data[Direction::Down].emplace_back(nextStart(), size);
//        player.m_data[Direction::Left].emplace_back(nextStart(), size);
//        player.m_data[Direction::Left].emplace_back(nextStart(), size);
//        player.m_data[Direction::Up].emplace_back(nextStart(), size);
//        player.m_data[Direction::Up].emplace_back(nextStart(), size);
//
//        return player;
//    }
//}
//
//Resources& Resources::instance()
//{
//    static Resources instance;
//    return instance;
//}
//
//Resources::Resources()
//{
//    if (!m_texture.loadFromFile("Icy Tower - Harold the Homeboy.png"))
//    {
//        throw std::runtime_error("Can't load file");
//    }
//
//    m_data = playerData();
//}


//Resources::Resources()
//{
//	loadResources();
//}
//
//Resources::~Resources()
//{
//	
//}
//
//void Resources::loadResources()
//{
//
//}
//
//void Resources::loadAudio()
//{
//	
//}
//
//void Resources::loadFonts()
//{
//	
//}
//
//void Resources::loadImages()
//{
//	
//}
//
//void Resources::loadSpritesheet()
//{
//	
//}