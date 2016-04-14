#include "Currency.h"
#include <string>
using namespace std;

template < class T >
Currency<T>::Currency()
{
	wholeName = fracName = "Generic";
	whole = frac = 0;
}
template < class T >
Currency<T>::Currency(string wn, string fn, int w, int f)
{
	wholeName = wn;
	fracName = fn;
	whole = w;
	frac = f;
}
template < class T >
void Currency<T>::setWhole(int w)
{
	whole = w;
}
template < class T >
void Currency<T>::setFrac(int f)
{
	frac = f;
}
template < class T >
void Currency<T>::setWholeName(string wn)
{
	wholeName = wn;
}
template < class T >
void Currency<T>::setFracName(string fn)
{
	fracName = fn;
}

//gets
template < class T >
int Currency<T>::getWhole()
{
	return whole;
}
template < class T >
int Currency<T>::getFrac()
{
	return frac;
}
template < class T >
string Currency<T>::getWholeName()
{
	return wholeName;
}
template < class T >
string Currency<T>::getFracName()
{
	return fracName;
}
template < class T >
Currency<T> &Currency::operator = (const Currency & C1)
{
	return 0;
}
template < class T >
Currency<T>::~Currency()
{
}


