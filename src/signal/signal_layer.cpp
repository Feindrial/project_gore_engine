#include "signal/signal_layer.h"

namespace gore
{
	signal_layer::signal_layer()
	{
		
	}
	void signal_layer::invoke(signal *sgnl)
	{
		for (auto &handle : handlers_[static_cast<size_t>(sgnl->sc_)])
		{
			if (sgnl->handled_)
				return;
			handle(sgnl);
		}
	}
}