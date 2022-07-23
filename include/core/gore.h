#ifndef GORE_GORE_H
#define GORE_GORE_H

#ifndef __GORE_DEBUG
	
#endif

#if defined(_WIN32) || defined(__WIN64)
	#define __GORE_WINDOWS
#elif defined(__linux__)
	#define __GORE_LINUX
#else 
	#define __GORE_MAC

#endif