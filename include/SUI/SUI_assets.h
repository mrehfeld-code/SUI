#ifndef _SUI_ASSETS_H
#define _SUI_ASSETS_H

#ifndef SDL_h
#include <SDL3/SDL.h>
#endif // ! _SDL_h

#ifdef __cplusplus
#define SUI_CALL 
extern "C" {
#else
#define SUI_CALL extern
#endif

typedef enum SUI_LogType {
	SUI_LOGTYPE_ERROR = 0xA,
	SUI_LOGTYPE_FATAL = 0xB,
	SUI_LOGTYPE_INFORMATION = 0xC,
	SUI_LOGTYPE_WARNING = 0xD,
	SUI_LOGTYPE_NONE = 0xE,
	SUI_LOGTYPE_NOTE = SUI_LOGTYPE_NONE,
} SUI_LogType;

SUI_CALL int SUI_LogPrint(SDL_bool exit, SDL_bool exclude_SDL_Log, SUI_LogType logtype, const char* msg, ...);
#ifdef SUI_LOGGER_EXCLUDE_SDL_LOG
	#define SUI_LOG_ERROR(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_TRUE, SUI_LOGTYPE_ERROR, msg, __VA_ARGS__)
	#ifdef SUI_LOGGER_NO_EXIT_ON_FATAL_ERROR
		#define SUI_LOG_FATAL(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_TRUE, SUI_LOGTYPE_FATAL, msg, __VA_ARGS__)
	#else
		#define SUI_LOG_ERROR(msg, ...) SUI_LogPrint(SDL_TRUE, SDL_TRUE, SUI_LOGTYPE_ERROR, msg, __VA_ARGS__)
	#endif
	#define SUI_LOG_INFORMATION(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_TRUE, SUI_LOGTYPE_INFORMATION, msg, __VA_ARGS__)
	#define SUI_LOG_WARNING(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_TRUE, SUI_LOGTYPE_WARNING, msg, __VA_ARGS__)
	#define SUI_LOG_NOTE(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_TRUE, SUI_LOGTYPE_NOTE, msg, __VA_ARGS__)
#else	
	#define SUI_LOG_ERROR(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_FALSE, SUI_LOGTYPE_ERROR, msg, __VA_ARGS__)
	#ifdef SUI_LOGGER_NO_EXIT_ON_FATAL_ERROR
		#define SUI_LOG_FATAL(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_FALSE, SUI_LOGTYPE_FATAL, msg, __VA_ARGS__)
	#else
		#define SUI_LOG_ERROR(msg, ...) SUI_LogPrint(SDL_TRUE, SDL_FALSE, SUI_LOGTYPE_ERROR, msg, __VA_ARGS__)
	#endif
	#define SUI_LOG_INFORMATION(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_FALSE, SUI_LOGTYPE_INFORMATION, msg, __VA_ARGS__)
	#define SUI_LOG_WARNING(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_FALSE, SUI_LOGTYPE_WARNING, msg, __VA_ARGS__)
	#define SUI_LOG_NOTE(msg, ...) SUI_LogPrint(SDL_FALSE, SDL_FALSE, SUI_LOGTYPE_NOTE, msg, __VA_ARGS__)
#endif 

SUI_CALL int SUI_PrintVersion(SDL_version* ver);

#ifdef __cplusplus
}
#endif

#endif // _SUI_ASSETS_H
