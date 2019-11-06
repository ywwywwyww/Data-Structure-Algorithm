#include<cstdio>
using namespace std;
typedef long long ll;
struct PLL
{
	ll x,y;
	PLL(ll a=0,ll b=0):x(a),y(b){}
};

const int N=1000001;

void input(int &n,int *l,int *r,int *t)
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&l[i],&r[i],&t[i]);
}

int main()
{
	int n;
	static int l[N],r[N],t[N];
	static PLL q[N];
	int head,tail;
	static ll f[N];
	
	input(n,l,r,t);
	
	
	head=1,tail=0;
	q[++tail]=PLL(0,n);
	l[n]=n+1;
	
	for(int i=n-1;i>=1;i--)
	{
		for(int j=l[i+1]-1;j>=l[i];j--)
		{
			while(tail>=head&&q[tail].x>f[j])
				tail--;
			q[++tail]=PLL(f[j],j);
		}
		while(tail>=head&&q[head].y>r[i])
			head++;
		f[i]=t[i]+q[head].x;
	}
	printf("%lld\n",f[1]);
	
	return 0;
}
