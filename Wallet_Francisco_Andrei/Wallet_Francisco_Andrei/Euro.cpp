#include "Euro.h"


Euro::Euro() : Currency("Euro", "Cent", 0, 0)
{
}
Euro::Euro(int w, int f) : Currency("Euro", "Cent", w, f)
{
}


Euro::~Euro()
{
}
