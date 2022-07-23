#include "util/error_handler.h"

#include "util/logger.h"

namespace gore
{
	void error_handler::error(non_fatal err)
	{
		
	}
	void error_handler::error(fatal err)
	{
		switch (err)
		{
			case fatal::glfw_init:
				logger::log("failed to initialize glfw");
				break;
			case fatal::glfw_window:
				logger::log("couldn't create window");
				break;
			case fatal::glad_init:
				logger::log("failed to initialize glad");
				break;
		}
		std::exit(EXIT_FAILURE); //implement more correct exit rather than shutting the program
		//cleaning, saving, closing etc...
	}
}