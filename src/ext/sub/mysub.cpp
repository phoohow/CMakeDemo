#include "mysub.h"
#include "myadd.h"

int mysub(int v1, int v2)
{
    return myadd(v1, -v2);
}