#include<cstdio>
using namespace std;
typedef long long ll;
struct pll
{
	ll x,y;
	pll(ll a=0,ll b=0):x(a),y(b){}
};
const int N=1000010;
pll q[N];
int head,tail;
ll f[N];
int n;
int l[N],r[N],t[N];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&l[i],&r[i],&t[i]);
	head=1,tail=0;
	q[++tail]=pll(0,n);
	l[n]=n+1;
	for(int i=n-1;i>=1;i--)
	{
		for(int j=l[i+1]-1;j>=l[i];j--)
		{
			while(tail>=head&&q[tail].x>f[j])
				tail--;
			q[++tail]=pll(f[j],j);
		}
		while(tail>=head&&q[head].y>r[i])
			head++;
		f[i]=t[i]+q[head].x;
	}
	printf("%lld\n",f[1]);
	return 0;
}
