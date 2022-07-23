#ifndef GORE_MATERIAL_H
#define GORE_MATERIAL_H

#include <string>
#include <vector>

namespace gore
{
    enum class material_type : char
    {
        normal,
        base_color
    };
    class material
    {
    public:
        material(const std::string &path, material_type type, unsigned int id);
    private:
        struct texture
        {
            std::string path_;
            material_type type_;
            unsigned int id_;
        };
        texture texture_;
    };
}

#endif