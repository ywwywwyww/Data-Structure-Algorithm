#include<cstdio>
using namespace std;
const int N=1000010;
typedef long long ll;
ll f[N];
int l[N],r[N],t[N];
int n;
ll min(ll a,ll b)
{
	return a<b?a:b;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<n;i++)
		scanf("%d%d%d",&l[i],&r[i],&t[i]);
	for(int i=n-1;i>=1;i--)
	{
		f[i]=0x3ffffffffffffffll;
		for(int j=l[i];j<=r[i];j++)
			f[i]=min(f[i],f[j]+t[i]);
	}
	printf("%lld\n",f[1]);
	return 0;
}
