#include<cstdio>
using namespace std;
typedef long long ll;
const int N=200001;

struct Point
{
	int x,y;
	Point(int a=0,int b=0):x(a),y(b){}
};
Point operator -(Point a,Point b)
{
	return Point(a.x-b.x,a.y-b.y);
}
ll cross(Point a,Point b)
{
	return (ll)a.x*b.y-(ll)a.y*b.x;
}


void sort(int *a,int l,int r)
{
	static int b[N];
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

void input(int &n,int *x,int *y)
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)
		scanf("%d",&y[i]);
}

int binarySearch(int n,int *x,int *y,int qx,int qy)
{
	int l=0,r=n;
	while(l<r)
	{
		int mid=(l+r+1)>>1;
		if(cross(Point(qx,qy)-Point(x[mid],0),Point(0,y[mid])-Point(x[mid],0))>=0)
			l=mid;
		else
			r=mid-1;
	}
	return l;
}

void solve(const int n,int *x,int *y)
{
	int q,qx,qy;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d",&qx,&qy);
		int ans=binarySearch(n,x,y,qx,qy);
		printf("%d\n",ans);
	}
}

int main()
{
#ifdef DEBUG
	freopen("2.in","r",stdin);
	freopen("2.out","w",stdout);
#endif
	
	int n;
	static int x[N],y[N];
	
	input(n,x,y);
	
	sort(x,1,n);
	sort(y,1,n);
	
	solve(n,x,y);
	
	return 0;
}
