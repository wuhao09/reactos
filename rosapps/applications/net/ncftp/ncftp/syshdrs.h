/* syshdrs.h
 *
 * Copyright (c) 1992-2001 by Mike Gleason.
 * All rights reserved.
 *
 */

#if defined(HAVE_CONFIG_H)
#	include <config.h>
#endif

#	define SELECT_TYPE_ARG1 int
#	define SELECT_TYPE_ARG234 (fd_set *)
#	define SELECT_TYPE_ARG5 (struct timeval *)
#	define STDC_HEADERS 1
#	define HAVE_GETHOSTNAME 1
#	define HAVE_MKTIME 1
#	define HAVE_SOCKET 1
#	define HAVE_STRSTR 1
#	define HAVE_MEMMOVE 1
#	define HAVE_LONG_FILE_NAMES 1
#	include <winsock2.h>	/* Includes <windows.h> */
//#	include <shlobj.h>
#	ifdef HAVE_UNISTD_H
#		include <unistd.h>
#	else
#		include <process.h>
#	endif
#	include <errno.h>
#	include <stdio.h>
#	include <string.h>
#	ifdef HAVE_STRINGS_H
#		include <strings.h>
#	endif
#	include <stddef.h>
#	include <stdlib.h>
#	include <ctype.h>
#	include <stdarg.h>
#	include <time.h>
#	include <io.h>
#	include <sys/types.h>
#	include <sys/stat.h>
#	include <fcntl.h>
#	include <signal.h>
#	include <assert.h>
#	include <utime.h>
#	include <direct.h>
#	undef strcasecmp
#	define strcasecmp stricmp
#	undef strncasecmp
#	define strncasecmp strnicmp
#	define sleep WinSleep
#	ifndef S_ISREG
#		define S_ISREG(m)      (((m) & _S_IFMT) == _S_IFREG)
#		define S_ISDIR(m)      (((m) & _S_IFMT) == _S_IFDIR)
#	endif
#	ifndef open
#		define open _open
#		define write _write
#		define read _read
#		define close _close
#		define lseek _lseek
#		define stat _stat
#		define lstat _stat
#		define fstat _fstat
#		define dup _dup
#		define utime _utime
#		define utimbuf _utimbuf
#		define chdir _chdir
#		define rmdir _rmdir
#		define getpid _getpid
#		define popen _popen
#		define pclose _pclose
#	endif
#	ifndef unlink
#		define unlink remove
#	endif
#	define uid_t int
#	define NO_SIGNALS 1
#	define USE_SIO 1
#	ifndef FOPEN_READ_TEXT
#		define FOPEN_READ_TEXT "rt"
#		define FOPEN_WRITE_TEXT "wt"
#		define FOPEN_APPEND_TEXT "at"
#	endif

#ifndef STDIN_FILENO
#	define STDIN_FILENO    0
#	define STDOUT_FILENO   1
#	define STDERR_FILENO   2
#endif

#define NDEBUG 1			/* For assertions. */

#if defined(HAVE_LONG_LONG) && defined(HAVE_OPEN64)
#	define Open open64
#else
#	define Open open
#endif

#if defined(HAVE_LONG_LONG) && defined(HAVE_STAT64) && defined(HAVE_STRUCT_STAT64)
#	define Stat stat64
#	ifdef HAVE_FSTAT64
#		define Fstat fstat64
#	else
#		define Fstat fstat
#	endif
#	ifdef HAVE_LSTAT64
#		define Lstat lstat64
#	else
#		define Lstat lstat
#	endif
#else
#	define Stat stat
#	define Fstat fstat
#	define Lstat lstat
#endif

#if defined(HAVE_LONG_LONG) && defined(HAVE_LSEEK64)
#	define Lseek(a,b,c) lseek64(a, (longest_int) b, c)
#elif defined(HAVE_LONG_LONG) && defined(HAVE_LLSEEK)
#	if 1
#		if defined(LINUX) && (LINUX <= 23000)
#			define Lseek(a,b,c) lseek(a, (off_t) b, c)
#		else
#			define Lseek(a,b,c) llseek(a, (longest_int) b, c)
#		endif
#	else
#		define Lseek(a,b,c) lseek(a, (off_t) b, c)
#	endif
#else
#	define Lseek(a,b,c) lseek(a, (off_t) b, c)
#endif


#include "Strn/Strn.h"			/* Library header. */
#include "libncftp/ncftp.h"			/* Library header. */
