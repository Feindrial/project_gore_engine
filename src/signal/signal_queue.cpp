#include "GLFW/glfw3.h"

#include "signal/signal_queue.h"
#include "signal/signal_layer.h"
#include "core/window.h"

#include <algorithm>

namespace gore
{
	signal_queue::signal_queue(signal_layer *layer) : layer_{ layer }
	{
		glfwSetWindowUserPointer(window::active().get(), reinterpret_cast<void*>(this));
		//setting glfw callback functions
		GLFWwindow *window = window::active().get();
		glfwSetWindowCloseCallback(window, [](GLFWwindow *window) {
			signal_queue *ptr{ reinterpret_cast<signal_queue*>(glfwGetWindowUserPointer(window)) };
			ptr->add_signal(new window_close_signal);
		});

	}
	void signal_queue::handle()
	{
		std::sort(signals_.begin(), signals_.end(), [](const auto &elem1, const auto &elem2)
		{ 
			return elem1->sc_ >= elem2->sc_ ? true : false; 
		});
		for (auto &signal : signals_)
		{
			layer_->invoke(signal);
		}
		clear(); //implement more abstract clearing in future
	}
}