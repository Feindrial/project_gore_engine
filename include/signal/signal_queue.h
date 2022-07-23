#ifndef GORE_SIGNAL_QUEUE
#define GORE_SIGNAL_QUEUE

#include "signal/signal_types.h"

#include <vector>
#include <array>

namespace gore
{
	class signal_layer;

	class signal_queue
	{
	public:	
		signal_queue(signal_layer *layer);
		void add_signal(signal *sgnl);
		void handle();
	private:
		void clear();
		//run time polymorphism for now maybe implement dod-like design in the future, so many cache miss will occur in that design
		std::vector<signal*> signals_; 
		signal_layer *layer_;
	};

	inline void signal_queue::add_signal(signal *sgnl)
	{
		signals_.push_back(sgnl);
	}
	inline void signal_queue::clear()
	{
		signals_.resize(0);
	}
}

#endif