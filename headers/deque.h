#ifndef yww_deque

#define yww_deque

#include "vector.h"

template <typename T>
struct deque
{
	vector<T> _front;
	vector<T> _back;
	
	int size()
	{
		return _front.size()+_back.size();
	}
	T &operator [](const int &pos)
	{
		pos<=_front.size()
			?return _front[front.size()-pos-1]
			:return _back[pos-front.size()];
	}
	T &front()
	{
		return (*this)[0];
	}
	T &back()
	{
		return (*this)[size()-1];
	}
	void push_front(const T &x)
	{
		_front.push_back(x);
	}
	void push_back(const T &x)
	{
		_back.push_back(x);
	}
	void pop_front()
	{
		if(_front.size()==0)
		{
			T val = _back;
			_back.clean();
			for(int i=(val.size()+1)/2-1;i>=0;i--)
				_front.push_back(val[i]);
			for(int i=(val.size()+1)/2;i<val.size();i++)
				_back.push_back(val[i]);
		}
		_front.pop_back();
	}
	void pop_back()
	{
		if(_back.size()==0)
		{
			T val = _front;
			_front.clean();
			for(int i=(val.size()+1)/2-1;i>=0;i--)
				_back.push_back(val[i]);
			for(int i=(val.size()+1)/2;i<val.size();i++)
				_front.push_back(val[i]);
		}
		_back.pop_back();
	}
	void clear()
	{
		_front.clear();
		_back.clear();
	}
};

#endif
