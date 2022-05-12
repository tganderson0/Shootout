#pragma once

#include "System.hpp"
#include "components/Position.hpp"
#include "components/Collider.hpp"

#include <chrono>
#include <memory>

namespace systems
{
    class CollisionSystem : public System
    {
      public:
        CollisionSystem() :
            System({ctti::unnamed_type_id<components::Position>(),
                    ctti::unnamed_type_id<components::Collider>(),
                    })
        {
        }

        void update(std::chrono::milliseconds elapsedTime);

      private:
    };
}