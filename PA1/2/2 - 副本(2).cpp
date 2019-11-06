#include<cstdio>
using namespace std;
typedef long long ll;
const int N=200010;
int b[N];
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
void sort(int *a,int l,int r)
{
	if(l>=r)
		return;
	int mid=(l+r)>>1;
	sort(a,l,mid);
	sort(a,mid+1,r);
	int t=l;
	int t1=l;
	int t2=mid+1;
	while(t<=r)
	{
		if(t2>r||(t1<=mid&&a[t1]<a[t2]))
			b[t++]=a[t1++];
		else
			b[t++]=a[t2++];
	}
	for(int i=l;i<=r;i++)
		a[i]=b[i];
}
int n,x[N],y[N];
int q,qx,qy;
int main()
{
//	freopen("2.in","r",stdin);
//	freopen("2.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&y[i]);
	sort(x,1,n);
	sort(y,1,n);
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&qx,&qy);
		int l=0,r=n;
		while(l<r)
		{
			int mid=(l+r+1)>>1;
			if((point(qx,qy)-point(x[mid],0))*(point(0,y[mid])-point(x[mid],0))>=0)
				l=mid;
			else
				r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
