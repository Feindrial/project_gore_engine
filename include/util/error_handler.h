#ifndef GORE_ERROR_HANDLER_H
#define GORE_ERROR_HANDLER_H

#include <iostream>
#include <string_view>

namespace gore
{
    enum class fatal : char
    {
        glfw_init,
        glfw_window,
        glad_init
    };
    enum class non_fatal : char
    {
        assimp_model,
        load_texture,
        opengl_error,
        vertex_compile,
        fragment_compile,
        geometry_compile,
        program_link
    };
    class error_handler
    {
    public:
        static void error(non_fatal err);
        static void error(fatal err);
    protected:
    private:                
    };

    
}

#endif