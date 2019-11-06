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

template<typename T>
void _sort(T **first, T **last, T **temp, bool cmp(const T &, const T &))
{
	if(last - first <=1)
		return;
	T **mid = first + (last - first) / 2;
	_sort(first, mid, temp, cmp);
	_sort(mid, last, temp, cmp);
	T **t = temp;
	T **t1 = first;
	T **t2 = mid;
	while(t1 < mid || t2 < last)
	{
		if(t2 == last || (t1 < mid && cmp(**t1, **t2)))
			*(t++) = *(t1++);
		else
			*(t++) = *(t2++);
	}
	for(int it = 0; it < t - temp; it++)
		*(first + it) = *(temp + it);
}

template<typename T>
void sort(T *first, T *last, bool cmp(const T &, const T &) = less<T>)
{
	int len = last - first;
	T **temp1 = new T*[len];
	for(int i=0;i<len;i++)
		temp1[i] = new T(first[i]);
	T **temp2 = new T*[len];
	_sort(temp1, temp1 + len, temp2, cmp);
	for(int i=0;i<len;i++)
		first[i] = *temp1[i];
}

template<typename T>
T *lower_bound(T *first, T *last, T target)
{
	while(first < last)
	{
		T *mid = first + (last - first) / 2;
		if(*mid < target)
			first = mid + 1;
		else
			last = mid;
	}
	return first;
}

template<typename T>
T *unique(T *first, T *last)
{
	int len = last - first;
	T *temp = new T[len];
	int cnt = 0;
	for(int i=0;i<len;i++)
		if(i == 0 || first[i] != first[i-1])
			temp[cnt++] = first[i];
	for(int i=0;i<cnt;i++)
		first[i]=temp[i];
	return first+cnt;
}
#endif
