#ifndef yww_vector

#define yww_vector

#include "utils.h"

template <typename T>
struct vector
{
public:
	vector()
	{
		max_length = 1;
		a = new T[max_length];
		length = 0;
	}
	~vector()
	{
		delete []a;
	}
	void insert(int pos, const T &x)
	{
		push_back(x);
		for(int i=length - 2;i>=pos;i--)
			a[i + 1] = a[i];
		a[pos] = x;
	}
	void erase(const int &pos)
	{
		for(int i = pos; i <= length - 2; i++)
			a[i] = a[i+1];
		pop_back();
	}
	void push_back(const T &x)
	{
		if(length == max_length)
			expand();
		a[length++] = x;
	}
	void pop_back()
	{
		length--;
		if(max_length > 1 && length <= max_length / 4)
			shrink();
	}
	T &operator [](const int &pos)
	{
		return a[pos];
	}
	int size()
	{
		return length;
	}
	void reverse()
	{
		for(int i=0, j=length - 1; i < j; i++, j--)
			swap(a[i], a[j]);
	}
	void clean()
	{
		length=0;
	}
	T *operator +(int pos)
	{
		return a + pos;
	}
private:
	T *a;
	int max_length;
	int length;
	void reserve(int num)
	{
		T *b = new T[num];
		memcpy(b, a, sizeof(T) * min(num, length));
		delete []a;
		a = b;
		max_length = num;
	}
	void expand()
	{
		reserve(max_length << 1);
	}
	void shrink()
	{
		reserve(max_length >> 1);
	}
};

#endif
