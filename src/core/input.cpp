#include "GLFW/glfw3.h"

#include "core/input.h"
#include "core/window.h"

#include <algorithm>

namespace gore
{
    bool input::is_key_in_state(interrupt intrp) 
    {
        int state = glfwGetKey(window::active().get(), intrp);
        return state == GLFW_PRESS || state == GLFW_REPEAT; 
    }
    bool is_mouse_button_in_state(interrupt intrp)
    {
        int state = glfwGetMouseButton(window::active().get(), intrp);
        return state == GLFW_PRESS || state == GLFW_REPEAT; 
    }
}