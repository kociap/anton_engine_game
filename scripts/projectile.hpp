#ifndef ASTEROIDS_PROJECTILE_HPP_INCLUDE
#define ASTEROIDS_PROJECTILE_HPP_INCLUDE

#include <core/types.hpp>
#include <core/class_macros.hpp>
#include <engine/ecs/jobs.hpp>
#include <engine/ecs/system.hpp>
#include <core/serialization/serialization.hpp>

namespace asteroids_game {
    using namespace anton_engine;

    class COMPONENT Projectile {
    public:
        f32 speed;
    };

    class Projectile_System: public System {
    public:
        void update() override;
    };
} // namespace asteroids_game

ANTON_DEFAULT_SERIALIZABLE(asteroids_game::Projectile);

#endif // !ASTEROIDS_PROJECTILE_HPP_INCLUDE
