#include "GameModel.hpp"

#include "entities/LocalPlayer.hpp"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <memory>
#include <tuple>

/// <summary>
/// Sets up all systems and any objects that should be added at the beginning
/// </summary>
/// <param name="viewSize"></param>
/// <returns></returns>
bool GameModel::initialize(sf::Vector2f viewSize) 
{
    // Initialize systems
    m_systemRender = std::make_unique<systems::Renderer>();

    // Create and add entities
    addEntity(entities::createLocalPlayer("assets/crow.png", viewSize, sf::Vector2f(-0.25f, 0.0f), 1.0f, m_textures));

    return true;
}

void GameModel::signalKeyPressed(sf::Event::KeyEvent event) 
{
    // this should notify the keyboard system eventually
}

void GameModel::signalKeyReleased(sf::Event::KeyEvent event)
{
    // this should notify the keyboard system eventually
}

/// <summary>
/// Updates all systems
/// </summary>
/// <param name="elapsedTime"></param>
/// <param name="renderTarget"></param>
void GameModel::update(const std::chrono::milliseconds elapsedTime, std::shared_ptr<sf::RenderTarget> renderTarget)
{
    // Update non-render systems

    // Render
    m_systemRender->update(elapsedTime, renderTarget);
}


/// <summary>
/// Adds the entity given to the systems that want it
/// </summary>
/// <param name="entity"></param>
void GameModel::addEntity(std::shared_ptr<entities::Entity> entity)
{
    if (entity == nullptr)
        return;

    m_entities[entity->getId()] = entity;

    // Add to all systems
    m_systemRender->addEntity(entity);
}

/// <summary>
/// Removes the given entity from the systems
/// </summary>
/// <param name="entityId"></param>
void GameModel::removeEntity(decltype(entities::Entity().getId()) entityId)
{
    m_entities.erase(entityId);

    // Remove from all systems
    m_systemRender->removeEntity(entityId);
}