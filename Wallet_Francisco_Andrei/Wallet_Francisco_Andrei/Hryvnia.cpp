#include "Hryvnia.h"


Hryvnia::Hryvnia() : Currency("Hryvnia", "Kopeika", 0, 0)
{
}
Hryvnia::Hryvnia(int w, int f) : Currency("Hryvnia", "Kopeika", w, f)
{
}


Hryvnia::~Hryvnia()
{
}
