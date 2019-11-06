#include<cstdio>
#include<cstring>
using namespace std;
const int N=1010;
int b[N],q[N];
int n,m;
int head,tail;
int x;
int main()
{
	scanf("%d%d",&n,&m);
	head=1,tail=0;
	int ans=0;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&x);
		if(!b[x])
		{
			if(tail-head+1>=n)
				b[q[head++]]=0;
			b[q[++tail]=x]=1;
			ans++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
