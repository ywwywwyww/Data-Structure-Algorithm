#include <cstdio>
#include <cstring>
#include "pair.h"

typedef unsigned long long ull;

typedef pair<int, int> pii;

const int inf = 0x3fffffff;

ull mask(int len)
{
	return -1ull >> (64 - len);
}

int highest_bit(ull x)
{
	return 64 - __builtin_clzll(x);
}

ull shr(ull a, int b)
{
	if(b<64)
		return a>>b;
	return 0;
}

struct node
{
	pii pos;
	int len;
	ull s;
	int ch[2];
	node()
	{
		pos.first = pos.second = inf;
		ch[0] = ch[1] = 0;
	}
	int get_first(int pos)
	{
		return this->pos.first == pos ? this->pos.second : this->pos.first;
	}
};

node trie[1000001];
int cnt;
int root;

void insert(int &cur, ull val, int dep, int pos)
{
	if(!cur)
	{
		cur = ++cnt;
		trie[cur].len = dep;
		trie[cur].s = val & mask(dep);
		trie[cur].pos.first = pos;
		return;
	}
	ull temp = shr(val, (dep - trie[cur].len)) & mask(trie[cur].len);
	if(temp != trie[cur].s)
	{
		int highest = highest_bit(temp ^ trie[cur].s);
		int node2 = ++cnt;
		trie[node2].len = highest;
		trie[node2].s = trie[cur].s & mask(highest);
		trie[node2].ch[0] = trie[cur].ch[0];
		trie[node2].ch[1] = trie[cur].ch[1];
		trie[node2].pos = trie[cur].pos;
		trie[cur].ch[0] = trie[cur].ch[1] = 0;
		trie[cur].ch[shr(trie[cur].s, (highest - 1)) & 1] = node2;
		trie[cur].len -= highest;
		trie[cur].s = shr(trie[cur].s, highest);
	}
	trie[cur].pos.second = trie[cur].pos.first;
	trie[cur].pos.first = pos;
	if(dep == trie[cur].len)
		return;
	insert(trie[cur].ch[shr(val, (dep - trie[cur].len - 1)) & 1], val, dep - trie[cur].len, pos);
}

pii query(int cur, ull val, int dep, int pos, int last)
{
	if(dep == trie[cur].len)
		return trie[cur].pos;
	int next = trie[cur].ch[(shr(val, (dep - trie[cur].len - 1)) & 1) ^ 1];
	int next2 = trie[cur].ch[shr(val, (dep - trie[cur].len - 1)) & 1];
	if(trie[next].get_first(pos) > last && trie[next2].get_first(pos) <= last)
		next = next2;
	return query(next, val, dep - trie[cur].len, pos, last);
}

int main()
{
#ifdef yww
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
#endif

	int n,k;
	char str[65];
	static ull val[500001];
	static int ans[500001];
	
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str);
		for(int j=0;j<=63;j++)
			val[i] = (val[i] << 1) | (str[j] - '0');
	}
	
	for(int i=n;i>=n-k;i--)
		insert(root, val[i], 64, i);
	for(int i=n;i>=1;i--)
	{
		if(i-k-1>=1)
			insert(root, val[i-k-1], 64, i-k-1);
		pii temp = query(root, val[i], 64, i, i+k+1);
		ans[i] = (temp.first==i? temp.second: temp.first);
	}
	for(int i=1;i<=n;i++)
		printf("%d\n",ans[i]-1);
	return 0;
}
