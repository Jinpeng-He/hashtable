#ifndef _STRDUP_H
#define _STRDUP_H



#include <string.h>

char* strDup(char const* str);


char* strDupSize(char const* str);

char* strDupSize(char const* str, size_t& resultBufSize);


#endif

