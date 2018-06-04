#include <stdio.h>
#include <string.h>
#include "encode.h"
#include "iconv.h"

int encode_convert(const char *from_charset, const char *to_charset, const char *inbuf, size_t inlen, char *outbuf, size_t outlen)
{
    iconv_t cd;
    #ifdef WIN32
    const char **pin = &inbuf;
    #else
    char **pin = (char **)&inbuf;
    #endif
    char **pout = &outbuf;
    cd = iconv_open(to_charset, from_charset);
    if (NULL == cd)
    {
        return -1;
    }
    memset(outbuf, 0, outlen);
    if (iconv(cd, pin, &inlen, pout, &outlen) == (size_t)-1)
    {
        iconv_close(cd);
        return -1;
    }
    iconv_close(cd);
    return 0;
}
