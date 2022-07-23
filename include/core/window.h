#ifndef GORE_WINDOW_H
#define GORE_WINDOW_H

#include "GLFW/glfw3.h"

#include "signal/signal_layer.h"
#include "signal/signal_types.h"

#include <vector>

namespace gore
{
    class window 
    {
    public:
        window(signal_layer *layer);
        void update() const noexcept;
        bool should_close() const noexcept;
        [[nodiscard]] static window& active() noexcept;
        [[nodiscard]] GLFWwindow* get() const noexcept;
    protected:
    private:
        void close_window(signal *st);
        signal_layer *layer_;
        GLFWwindow *window_;
        static window *current_window_;
        short width_;
        short height_;
        bool should_close_;
    };

    inline bool window::should_close() const noexcept 
    {
        return should_close_; 
    }
    [[nodiscard]] inline window& window::active() noexcept
    { 
        return *current_window_; 
    }
    [[nodiscard]] inline GLFWwindow* window::get() const noexcept 
    {
        return window_; 
    }
    inline void window::close_window(signal *st) 
    {
        st->handled_ = true;
        should_close_ = true; 
    }
}

#endif