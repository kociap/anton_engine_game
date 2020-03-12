#include <asteroid.hpp>

#include <engine/components/static_mesh_component.hpp>
#include <engine/components/transform.hpp>
#include <engine/ecs/ecs.hpp>
#include <core/random.hpp>
#include <engine/time.hpp>

namespace asteroids_game {
    void Asteroid_System::start() {
        last_spawn_time = get_time();
    }

    void Asteroid_System::update() {
        f32 const current_time = get_time();
        f32 const spawn_delay = 1 / spawn_frequency;
        ECS& ecs = get_ecs();
        // while (current_time - last_spawn_time >= spawn_delay) {
        //     last_spawn_time += spawn_delay;
        //     Entity const entity = ecs.create();
        //     Asteroid asteroid;
        //     asteroid.rotation_speed = math::radians(random_f32(5.0f, 80.0f));
        //     asteroid.speed = 1.0f;
        //     ecs.add_component<Asteroid>(entity, asteroid);
        //     Transform transform;
        //     transform.local_position = Vector3(0, 5, 0);
        //     ecs.add_component<Transform>(entity, transform);
        //     Static_Mesh_Component mesh;
        // }

        spawn_frequency = math::max(4.0, spawn_frequency + spawn_frequency_change * get_delta_time());
    }
} // namespace asteroids_game
