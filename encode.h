#ifndef __ENCODE_H__
#define __ENCODE_H__

#include <stdint.h>

#ifdef __cplusplus
extern "C"
{
#endif

int encode_convert(const char *from_charset, const char *to_charset, const char *inbuf, size_t inlen, char *outbuf, size_t outlen);
    
#ifdef __cplusplus
}
#endif

#endif
