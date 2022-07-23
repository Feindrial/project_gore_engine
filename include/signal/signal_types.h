#ifndef GORE_SIGNAL_TYPES_H
#define GORE_SIGNAL_TYPES_H

namespace gore
{
	enum class signal_category : char
	{
		window,
		capacity
	};
	struct signal
	{
		signal(signal_category sc) : sc_{ sc }, handled_{ false } {}
		signal_category sc_;
		bool handled_;
	};
	struct window_close_signal final : public signal
	{
		window_close_signal() : signal{ signal_category::window } {}
	};
	struct window_resize_signal final : public signal
	{
		window_resize_signal(int width, int height) : signal{ signal_category::window }, width_{ width }, height_{ height } {}
		int width_, height_;
	};
}

#endif