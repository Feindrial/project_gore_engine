#ifndef GORE_INPUT_H
#define GORE_INPUT_H

#include "core/interrupts.h"

namespace gore
{
    class input 
    {
    public:
        static bool is_key_in_state(interrupt intrp);
        static bool is_mouse_button_in_state(interrupt intrp);
    private:
    };
}

#endif