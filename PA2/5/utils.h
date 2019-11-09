#ifndef yww_utils
#define yww_utils

template<typename T>
T min(const T &a, const T &b)
{
	return a<b?a:b;
}

template<typename T>
T max(const T &a, const T &b)
{
	return a>b?a:b;
}

template<typename T>
bool upmin(T &a, const T &b)
{
	return b < a? a = b, 1: 0;
}

template<typename T>
bool upmax(T &a, const T &b)
{
	return b > a? a = b, 1: 0;
}

template<typename T>
void swap(T &a, T &b)
{
	T c=a;
	a=b;
	b=c;
}

template<typename T>
bool less(const T &a, const T &b)
{
	return a < b;
}

#endif
