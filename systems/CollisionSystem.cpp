#include "CollisionSystem.hpp"

#include "entities/Entity.hpp"

namespace systems
{
    void CollisionSystem::update(std::chrono::milliseconds elapsedTime)
    {
        (void)elapsedTime; // Compiler warning ignore since we don't care about elapsedTime yet...

        // Draw Background
        sf::RectangleShape square({1.0f, 1.0f});
        square.setFillColor(sf::Color::Blue);
        square.setPosition({-0.5f, -0.5f});

        renderTarget->clear(sf::Color::Black);
        renderTarget->draw(square);

        // Render each entity
        for (auto&& [id, entity] : m_entities)
        {
            auto position = entity->getComponent<components::Position>();
            auto sprite = entity->getComponent<components::Sprite>();

            sprite->get()->setPosition(position->get());
            sprite->get()->setRotation(sf::degrees(position->getRotation()));

            renderTarget->draw(*sprite->get());
            
        }
    }
}