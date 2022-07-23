#ifndef GORE_SIGNAL_LAYER_H
#define GORE_SIGNAL_LAYER_H

#include "signal/signal_types.h"
#include "signal/signal_queue.h"

#include <array>
#include <vector>
#include <functional>

namespace gore
{
    class signal_layer
    {
    public:
        using signal_handler = std::function<void(signal*)>;
        signal_layer();
        void add_handler(const signal_handler &handler, signal_category category);
        void delete_handler(signal_handler handler);
        void invoke(signal *sgnl);
    private:
        std::array<std::vector<signal_handler>, static_cast<size_t>(signal_category::capacity)> handlers_;
    };

    inline void signal_layer::add_handler(const signal_handler &handler, signal_category category)
    {        
        handlers_[static_cast<size_t>(category)].push_back(handler);
    }
    inline void signal_layer::delete_handler(signal_handler handler)
    {

    }
}

#endif