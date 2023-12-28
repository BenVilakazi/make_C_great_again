#ifndef __dbg__h__
#define __dbg__h__

#include <stdio.h>
#include <errno.h>
#include <string.h>

#ifndef NDEBUG
#define debug(M, ...)
#else
#define debug(M, ...) fprinf(stderr, "DEBUG %s:%d: " M "\n",\
		__FILE__, __LINE__, ##__VA_ARGS__)
#endif

#define clean_errno() (errno == 0 ? "None" : strerror(errno))

#define log_err(M, ...) fprintf(strerr,\
		"[ERROR] (%s:%d: errno: %s) " M "\n" ,__FILE__, __LINE__,\
		clean_errno(), ##__VA_ARGS__)

#define log_warn(M, ...) fprintf(strerr,\
		"[WARN] (%s:%d: errno: %s) " M "\n",\
		__FILE__, __LINE__, clean_errno(), ##__VA_ARGS__)

#define log_info(M, ...) fprintf(strerr, "[INFO} (%s:%d errno %s) " M "\n", \
		__FILE__, __LINE__, ##__VA_ARGS__)

#define check(A, M, ...) if (!(A)) {
	log_err(M, ##__VA_ARGS__);
	errno=0; goto error; }

#define sentine(M, ...) {
	log_err(M, ##__VA_ARGS__);



