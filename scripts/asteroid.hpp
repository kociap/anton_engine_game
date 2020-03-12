#ifndef ASTEROIDS_ASTEROID_HPP_INCLUDE
#define ASTEROIDS_ASTEROID_HPP_INCLUDE

#include <core/types.hpp>
#include <core/class_macros.hpp>
#include <engine/ecs/jobs.hpp>
#include <engine/ecs/system.hpp>
#include <core/serialization/serialization.hpp>

namespace asteroids_game {
    using namespace anton_engine;

    class COMPONENT Asteroid {
    public:
        f32 rotation_speed;
        f32 speed;
    };

    class Asteroid_System: public System {
    public:
        void start() override;
        void update() override;

    private:
        f32 spawn_frequency = 3.0f;
        f32 spawn_frequency_change = 0.5f;
        f32 last_spawn_time = 0.0f;
    };
} // namespace asteroids_game

ANTON_DEFAULT_SERIALIZABLE(asteroids_game::Asteroid);

#endif // !ASTEROIDS_ASTEROID_HPP_INCLUDE
