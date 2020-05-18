#include <core/atl/array.hpp>
#include <engine/ecs/system.hpp>

#include <asteroid.hpp>
#include <projectile.hpp>
#include <spaceship.hpp>

namespace anton_engine {
    extern "C" GAME_API atl::Array<System*> create_systems() {
        atl::Array<System*> systems(atl::reserve, 3);
        systems.push_back(new asteroids_game::Asteroid_System);
        systems.push_back(new asteroids_game::Spaceship_System);
        systems.push_back(new asteroids_game::Projectile_System);
        return systems;
    }
} // namespace anton_engine
