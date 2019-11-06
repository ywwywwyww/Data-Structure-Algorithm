#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
struct point
{
	int x,y;
	point(int a=0,int b=0):x(a),y(b){}
};
point operator -(point a,point b)
{
	return point(a.x-b.x,a.y-b.y);
}
ll operator *(point a,point b)
{
	return a.x*b.y-a.y*b.x;
}
const int N=200010;
int x[N],y[N];
void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
void sort(int *a,int n)
{
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(a[j]<a[i])
				swap(a[j],a[i]);
}
int main()
{
	int n,q,qx,qy;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&y[i]);
	sort(x,n);
	sort(y,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int s=0;
		scanf("%d%d",&qx,&qy);
		for(int j=1;j<=n;j++)
			if((point(qx,qy)-point(x[j],0))*(point(0,y[j])-point(x[j],0))>=0)
				s++;
		printf("%d\n",s);
	}
	return 0;
}
