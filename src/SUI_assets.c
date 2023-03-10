#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

#ifdef _WIN32
#include <Windows.h>
#endif // _WIN32

#include <SUI/SUI_assets.h>


int SUI_LogPrint(SDL_bool exit, SDL_bool exclude_SDL_Log, SUI_LogType logtype, const char* msg, ...) {
#ifdef _WIN32
	if (logtype == SUI_LOGTYPE_ERROR) {
	}
#elif __linux__ || __APPLE__

#endif 
}
