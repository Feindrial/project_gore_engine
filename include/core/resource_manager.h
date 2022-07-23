#ifndef GORE_RESOURCE_MANAGER_H
#define GORE_RESOURCE_MANAGER_H

#include "scene/material.h"
#include "scene/shader.h"

#include <string>
#include <vector>

namespace gore
{
    class resource_manager
    {
    public:
        [[nodiscard]] static inline resource_manager &get() { static resource_manager rm; return rm; }
        const material *create_material(const std::string &path, material::material_type type);
    private:
        inline auto  is_material_cached(const std::string &path);
        unsigned int load_texture(const std::string &path);
        std::vector<material> cached_materials_;
    };
}

#endif