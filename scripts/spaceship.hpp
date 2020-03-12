#ifndef ASTEROIDS_SPACESHIP_HPP_INCLUDE
#define ASTEROIDS_SPACESHIP_HPP_INCLUDE

#include <core/types.hpp>
#include <core/class_macros.hpp>
#include <engine/ecs/jobs.hpp>
#include <engine/ecs/system.hpp>
#include <core/serialization/serialization.hpp>

namespace asteroids_game {
    using namespace anton_engine;

    class COMPONENT Spaceship {
    public:
        f32 fire_rate;
        f32 mass;
        f32 engine_thrust;
    };

    class Spaceship_System: public System {
    public:
        void update() override;
    };
} // namespace asteroids_game

ANTON_DEFAULT_SERIALIZABLE(asteroids_game::Spaceship);

#endif // !ASTEROIDS_SPACESHIP_HPP_INCLUDE
