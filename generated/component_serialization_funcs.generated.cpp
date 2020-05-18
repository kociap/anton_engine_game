#include <core/atl/array.hpp>
#include <core/typeid.hpp>
#include <engine/ecs/component_container.hpp>
#include <engine/ecs/component_serialization.hpp>

// clang-format off

#include <asteroid.hpp>
#include <projectile.hpp>
#include <spaceship.hpp>
#include <engine/components/camera.hpp>
#include <engine/components/directional_light_component.hpp>
#include <engine/components/entity_name.hpp>
#include <engine/components/hierarchy.hpp>
#include <engine/components/line_component.hpp>
#include <engine/components/point_light_component.hpp>
#include <engine/components/spot_light_component.hpp>
#include <engine/components/static_mesh_component.hpp>
#include <engine/components/transform.hpp>
#include <scripts/camera_movement.hpp>
#include <scripts/debug_hotkeys.hpp>

// Editor Components
#if ANTON_WITH_EDITOR
#include <level_editor/viewport_camera.hpp>
#endif // ANTON_WITH_EDITOR

namespace anton_engine {
    extern "C" GAME_API atl::Array<Component_Serialization_Funcs>& get_component_serialization_functions() {
        static atl::Array<Component_Serialization_Funcs> serialization_funcs{atl::variadic_construct,
            Component_Serialization_Funcs{type_identifier<asteroids_game::Asteroid>(), &Component_Container<asteroids_game::Asteroid>::serialize, &Component_Container<asteroids_game::Asteroid>::deserialize},
            Component_Serialization_Funcs{type_identifier<asteroids_game::Projectile>(), &Component_Container<asteroids_game::Projectile>::serialize, &Component_Container<asteroids_game::Projectile>::deserialize},
            Component_Serialization_Funcs{type_identifier<asteroids_game::Spaceship>(), &Component_Container<asteroids_game::Spaceship>::serialize, &Component_Container<asteroids_game::Spaceship>::deserialize},
            Component_Serialization_Funcs{type_identifier<Camera>(), &Component_Container<Camera>::serialize, &Component_Container<Camera>::deserialize},
            Component_Serialization_Funcs{type_identifier<Directional_Light_Component>(), &Component_Container<Directional_Light_Component>::serialize, &Component_Container<Directional_Light_Component>::deserialize},
            Component_Serialization_Funcs{type_identifier<Entity_Name>(), &Component_Container<Entity_Name>::serialize, &Component_Container<Entity_Name>::deserialize},
            Component_Serialization_Funcs{type_identifier<Hierarchy>(), &Component_Container<Hierarchy>::serialize, &Component_Container<Hierarchy>::deserialize},
            Component_Serialization_Funcs{type_identifier<Line_Component>(), &Component_Container<Line_Component>::serialize, &Component_Container<Line_Component>::deserialize},
            Component_Serialization_Funcs{type_identifier<Point_Light_Component>(), &Component_Container<Point_Light_Component>::serialize, &Component_Container<Point_Light_Component>::deserialize},
            Component_Serialization_Funcs{type_identifier<Spot_Light_Component>(), &Component_Container<Spot_Light_Component>::serialize, &Component_Container<Spot_Light_Component>::deserialize},
            Component_Serialization_Funcs{type_identifier<Static_Mesh_Component>(), &Component_Container<Static_Mesh_Component>::serialize, &Component_Container<Static_Mesh_Component>::deserialize},
            Component_Serialization_Funcs{type_identifier<Transform>(), &Component_Container<Transform>::serialize, &Component_Container<Transform>::deserialize},
            Component_Serialization_Funcs{type_identifier<Camera_Movement>(), &Component_Container<Camera_Movement>::serialize, &Component_Container<Camera_Movement>::deserialize},
            Component_Serialization_Funcs{type_identifier<Debug_Hotkeys>(), &Component_Container<Debug_Hotkeys>::serialize, &Component_Container<Debug_Hotkeys>::deserialize},
            // Editor Components
            #if ANTON_WITH_EDITOR
            // Component_Serialization_Funcs{type_identifier<Viewport_Camera>(), &Component_Container<Viewport_Camera>::serialize, &Component_Container<Viewport_Camera>::deserialize}
            #endif // ANTON_WITH_EDITOR
		};
        return serialization_funcs;
    }
} // namespace anton_engine
// clang-format on
