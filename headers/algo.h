#ifndef yww_algo
#define yww_algo

#include "utils.h"
#include "pair.h"

template<typename T>
void _sort(T **first, T **last, T **temp, bool cmp(const T &, const T &) = less<T>)
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
void sort(T *first, T *last, bool cmp(const T &, const T &) = less<T> = less<T>)
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
	int cnt = 0;
	for(int i=0;i<len;i++)
		if(i == 0 || first[i] != first[i-1])
			first[cnt++] = first[i];
	return first + cnt;
}

template<typename T>
void _bubble_sort(T **first, T **last, bool cmp(const T &, const T &) = less<T>)
{
	for(T **i=first;i<last;i++)
		for(T **j=first+1, **k=first;j<last;j++, k++)
			if(cmp(**j, **k))
				swap(*j, *k);
}

template<typename T>
void _nth_element(T **first, T **nth, T **last, bool cmp(const T &, const T &) = less<T>)
{
	int len = last - first;
	int n = nth - first;
	if(len <= 10)
	{
		_bubble_sort(first, last, cmp);
		return;
	}
	T **temp = new T*[len];
	for(int i=0;i<len;i+=5)
	{
		int _first = i;
		int _last = min(i+5, len);
		_bubble_sort(first + _first, first + _last, cmp);
		temp[i/5] = first[_first + (_last - _first) / 2];
	}
	_nth_element(temp, temp + (len + 4) / 10, temp + (len + 4) / 5, cmp);
	T *pivot = temp[(len + 4) / 10];
	T **p1 = temp;
	T **p2 = temp + len;
	for(int i=0;i<len;i++)
		if(cmp(*first[i], *pivot))
			*(p1++) = first[i];
		else if(cmp(*pivot, *first[i]))
			*(--p2) = first[i];
	*(p1++) = pivot;
	for(int i=0;i<len;i++)
		first[i] = temp[i];
	int pos = 0;
	for(int i=0;i<len;i++)
		if(first[i] == pivot)
		{
			pos = i;
			break;
		}
	fflush(stdout);
	if(n < pos)
		return _nth_element(first, nth, first + pos, cmp);
	else if(n > pos)
		return _nth_element(first + pos, nth, last, cmp);
}

// 要求数组元素两两不同 
template<typename T>
void nth_element(T *first, T *nth, T *last, bool cmp(const T &, const T &) = less<T>)
{
	int len = last - first;
	int n = nth - first;
	T **temp1 = new T*[len];
	for(int i=0;i<len;i++)
		temp1[i] = new T(first[i]);
	_nth_element(temp1, temp1+n, temp1+len, cmp);
	for(int i=0;i<len;i++)
		first[i] = *temp1[i];
}

#endif
