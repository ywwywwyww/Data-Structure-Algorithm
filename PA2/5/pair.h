#ifndef yww_pair

#define yww_pair

template <typename T1, typename T2>
struct pair
{
	T1 first;
	T2 second;
	pair()
	{
	}
	pair(T1 _first, T2 _second):first(_first), second(_second){}
};

template <typename T1, typename T2>
pair <T1, T2> make_pair(T1 first, T2 second)
{
	return pair <T1, T2> (first, second);
}

template <typename T1, typename T2>
pair <T1, T2> mp(T1 first, T2 second)
{
	return make_pair(first, second);
}

#endif
