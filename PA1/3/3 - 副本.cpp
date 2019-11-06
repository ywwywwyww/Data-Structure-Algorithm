#include<cstdio>
using namespace std;
const int N=501010;
int n,m,k,f[N];
char s1[N],s2[N];
int max(int a,int b)
{
	return a>b?a:b;
}
int abs(int x)
{
	return x>0?x:-x;
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",s1+1,s2+1);
	for(int i=1;i<=n;i++)
	{
		int last=(i-k>1?f[i-k-1]:0);
		for(int j=max(1,i-k);j<=m&&j<=i+k;j++)
		{
			int x=f[j];
			if(s1[i]==s2[j])
				f[j]=last+1;
			else
				f[j]=max(f[j],f[j-1]);
			last=x;
		}
	}
	int ans=n+m-2*f[m];
	if(abs(n-m)>k)
		ans=-1;
	if(ans>k)
		ans=-1;
	printf("%d\n",ans);
	return 0;
}
