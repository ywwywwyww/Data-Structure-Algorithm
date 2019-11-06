#include <cstdio>
#include <cstring>

#include "utils.h"

typedef long long ll;

namespace seg
{
	ll tag[400000 << 2];
	ll sum[400000 << 2];
	ll *pos;
	#define mid ((L+R)>>1)
	#define lc (cur<<1)
	#define rc ((cur<<1)|1)
	void build(int cur, int L, int R)
	{
		tag[cur] = sum[cur] = 0;
		if(L==R)
			return;
		build(lc, L, mid);
		build(rc, mid+1, R);
	}
	void add(int cur, int l, int r, ll val, int L, int R)
	{
		sum[cur] += val * (pos[min(r, R) + 1] - pos[max(l, L)]);
		if(l<=L && r>=R)
		{
			tag[cur] += val;
			return;
		}
		if(l<=mid)
			add(lc, l, r, val, L, mid);
		if(r>mid)
			add(rc, l, r, val, mid+1, R);
	}
	ll query(int cur, int l, int r, int L, int R)
	{
		if(l<=L && r>=R)
			return sum[cur];
		ll res = tag[cur] * (pos[min(r, R) + 1] - pos[max(l, L)]);
		if(l<=mid)
			res += query(lc, l, r, L, mid);
		if(r>mid)
			res += query(rc, l, r, mid+1, R);
		return res;
	}
	#undef mid
	#undef lc
	#undef rc
}

int main()
{
	#ifdef yww
	freopen("4-2.in","r",stdin);
	freopen("4-2.out","w",stdout);
	#endif
	ll n;
	int m;
	scanf("%lld%d",&n,&m);
	static ll endpoints[400001], qx[200001], qy[200001], op[200001];
	static int endpoints_cnt;
	for(int i=1;i<=m;i++)
	{
		char str[10];
		scanf("%s%lld%lld",str,&qx[i],&qy[i]);
		if(str[0] == 'H')
			op[i] = 1;
		else
			op[i] = 2;
		endpoints[++endpoints_cnt] = qx[i];
		endpoints[++endpoints_cnt] = qy[i] + 1;
	}
	
	sort(endpoints+1, endpoints+endpoints_cnt+1);
	endpoints_cnt = unique(endpoints+1, endpoints+endpoints_cnt+1) - endpoints - 1;
	for(int i=1;i<=m;i++)
	{
		qx[i] = lower_bound(endpoints+1, endpoints+endpoints_cnt+1, qx[i]) - endpoints;
		qy[i] = lower_bound(endpoints+1, endpoints+endpoints_cnt+1, qy[i]+1) - endpoints - 1;
	}
	int maxlen = endpoints_cnt - 1;
	seg::pos = endpoints;
	seg::build(1, 1, maxlen);
	for(int i=1;i<=m;i++)
		if(op[i]==1)
			seg::add(1,qx[i],qy[i],1,1,maxlen);
		else
			printf("%lld\n",seg::query(1,qx[i],qy[i],1,maxlen));
	return 0;
}
