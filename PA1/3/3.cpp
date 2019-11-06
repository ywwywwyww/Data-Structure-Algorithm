#include<cstdio>
using namespace std;
const int N=501001;
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
	static int n,m,k,f[N];
	static char str1[N],str2[N];
	scanf("%d%d%d",&n,&m,&k);
	scanf("%s%s",str1+1,str2+1);
	
	
	for(int i=1;i<=n;i++)
	{
		int last=(i-k>1?f[i-k-1]:0);
		for(int j=max(1,i-k);j<=m&&j<=i+k;j++)
		{
			int x=f[j];
			if(str1[i]==str2[j])
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
