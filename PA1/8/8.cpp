#include<cstdio>
using namespace std;
typedef long long ll;

struct pii
{
	int x,y;
	pii(int a=0,int b=0):x(a),y(b){}
};
const int N=1000010;
pii q[N];
int head,tail;
int n;
int main()
{
	scanf("%d",&n);
	ll ans=0;
	int cnt1=0,cnt2=0;
	head=1,tail=0;
	int days,x;
	for(int i=1;i<=2*n;i++)
	{
		scanf("%d",&days);
		if(tail>=head)
			ans+=(ll)days*q[head].x;
		if(getchar()==' ')
		{
			scanf("%d",&x);
			cnt1++;
			while(tail>=head&&q[tail].x<x)
				tail--;
			q[++tail]=pii(x,cnt1);
		}
		else
		{
			cnt2++;
			while(tail>=head&&q[head].y==cnt2)
				head++;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
