#include "common.h"

/*.text*/

/*800B5970*/
void __assert(const char *msg, const char *file, int line)
{
#if TARGET_N64 && MODERN
    while (1);
#endif
}
