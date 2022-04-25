#pragma once

#include <SFML/System/Vector2.hpp>

namespace components
{
  class Position
  {
    public:
      Position(sf::Vector2f position, float rotation = 0.0f) :
        m_position(position),
        m_rotation(rotation)
      {
      }

      auto get() { return m_position; }
      auto set(sf::Vector2f position) { m_position = position; }
      auto getRotation() { return m_rotation; }
      void setRotation(float rotation) { m_rotation = rotation; }
    
    private:
      sf::Vector2f m_position;
      float m_rotation;
  }
}