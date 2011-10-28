#ifndef compatibility_h_
#define compatibility_h_

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "gol.h"

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32

typedef char sockopt_t;
typedef int socklen_t;

# ifndef strncasecmp
#  define strncasecmp strnicmp
# endif

GOL_INLINE char*
strndup(const char* src, size_t n) {
  const size_t srclen = strlen(src);
  n = n < srclen ? n : srclen;
  char* ptr = (char*) malloc(n + 1);
  *(ptr + n) = 0;
  memcpy(ptr, src, n);
  return ptr;
}

#else // _WIN32

# define closesocket(x) close(x)

typedef int sockopt_t;

# ifndef SD_BOTH
#  define SD_BOTH SHUT_RDWR
# endif

#endif // _WIN32

#ifdef __cplusplus
}
#endif

#endif // compatibility_h_

