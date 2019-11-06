#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const int N=10010;
int pw[20];
int n,m;
char s1[N],s2[N];
int a[N],b[N];
ll c[N];
void solve()
{
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	pw[0]=1;
	for(int i=1;i<=9;i++)
		pw[i]=pw[i-1]*10;
	for(int i=0;i<=n;i++)
		a[i]=0;
	for(int j=0;j<=m;j++)
		b[j]=0;
	for(int i=1;i<=n;i++)
		a[(n-i)/8]+=pw[(n-i)%8]*(s1[i]-'0');
	for(int i=1;i<=m;i++)
		b[(m-i)/8]+=pw[(m-i)%8]*(s2[i]-'0');
	n=(n+7)/8;
	m=(m+7)/8;
	for(int i=0;i<=n+m+10;i++)
		c[i]=0;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=m;j++)
			c[i+j]+=(ll)a[i]*b[j];
	for(int i=0;i<=n+m;i++)
	{
		c[i+1]+=c[i]/pw[8];
		c[i]%=pw[8];
	}
	int i;
	for(i=n+m+10;!c[i]&&i>=0;i--);
	if(i<0)
		printf("0");
	else
		printf("%lld",c[i]);
	for(i--;i>=0;i--)
		printf("%08lld",c[i]);
	printf("\n");
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
		solve();
	return 0;
}
