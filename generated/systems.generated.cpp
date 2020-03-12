#include <core/stl/vector.hpp>
#include <engine/ecs/system.hpp>

#include <asteroid.hpp>
#include <projectile.hpp>
#include <spaceship.hpp>

namespace anton_engine {
    extern "C" GAME_API anton_stl::Vector<System*> create_systems() {
        anton_stl::Vector<System*> systems(anton_stl::reserve, 3);
        systems.push_back(new asteroids_game::Asteroid_System);
        systems.push_back(new asteroids_game::Spaceship_System);
        systems.push_back(new asteroids_game::Projectile_System);
        return systems;
    }
} // namespace anton_engine
