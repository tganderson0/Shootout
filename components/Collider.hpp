#pragma once

#include "Component.hpp"
#include <SFML/System/Vector2.hpp>


// --------------------------------------------------------------
//
// Holds details regarding movement properties.
//
// --------------------------------------------------------------
namespace components
{
    class Collider : public Component
    {
      public:
        Collider(sf::Vector2i size) :
            m_size(size)
        {
        }

        auto get() { return m_size; }
        auto set(sf::Vector2i size) { m_size = size; }

        auto setOffset(sf::Vector2i offset) { m_offset = offset; }
        auto getOffset() { return m_offset; }


      private:
        sf::Vector2i m_size;
        sf::Vector2i m_offset;
    };
} // namespace components