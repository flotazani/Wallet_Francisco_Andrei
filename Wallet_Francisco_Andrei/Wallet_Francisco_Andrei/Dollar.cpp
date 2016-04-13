#include "Dollar.h"


Dollar::Dollar() : Currency("Dollar","Cent",0 , 0)
{
}

Dollar::Dollar(int w, int f ) : Currency("Dollar", "Cent", w, f)
{
}

Dollar::~Dollar()
{
}
