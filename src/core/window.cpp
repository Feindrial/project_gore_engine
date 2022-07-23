#include "glad/glad.h"
#include "GLFW/glfw3.h"

#include "core/window.h"
#include "util/error_handler.h"
#include "signal/signal_types.h"

#include <utility>

namespace gore
{
    
    window *window::current_window_ = nullptr;

    window::window(signal_layer *layer) : should_close_{ false }, layer_ { layer }
    {
        if (!glfwInit())        
            error_handler::error(fatal::glfw_init);     
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
        glfwWindowHint(GLFW_MAXIMIZED, GLFW_FALSE);
        glfwWindowHint(GLFW_CENTER_CURSOR, GLFW_TRUE);
        glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
#ifdef GORE_DEBUG
        glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
#endif
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 5);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        GLFWmonitor* monitor = glfwGetPrimaryMonitor();
        const GLFWvidmode* mode = glfwGetVideoMode(monitor);
        width_ = mode->width;
        height_ = mode->height;
        window_ = glfwCreateWindow(width_ - 1000, height_ - 450, "Project Gore", nullptr, nullptr);
        if (!window_)
            error_handler::error(fatal::glfw_window);
        glfwMakeContextCurrent(window_);
	    glfwFocusWindow(window_);
        if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
            error_handler::error(fatal::glad_init);
        current_window_ = this;
        //setting up window specific constant(never changed) signal callback functions     
        layer_->add_handler(std::bind(&window::close_window, this, std::placeholders::_1), signal_category::window);
    }
    void window::update() const noexcept
    {
        glfwSwapBuffers(window_);
        glfwPollEvents();
    }    
}