#include<cstdio>
using namespace std;
const int N=5010;
int n,m,k,f[N][N];
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
		for(int j=1;j<=m;j++)
			if(s1[i]==s2[j])
				f[i][j]=f[i-1][j-1]+1;
			else
				f[i][j]=max(f[i-1][j],f[i][j-1]);
	int ans=n+m-2*f[n][m];
	if(ans>k)
		ans=-1;
	printf("%d\n",ans);
	return 0;
}
