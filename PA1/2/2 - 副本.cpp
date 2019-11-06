#include<cstdio>
using namespace std;
void sort(int *a,int l,int r)
{
	if(l>=r)
		return;
	int _l=l,_r=r,x=a[l];
	while(_l<_r)
	{
		while(_l<_r&&a[_r]>x)
			_r--;
		if(_l<_r)
		{
			a[_l]=a[_r];
			_l++;
		}
		while(_l<_r&&a[_l]<x)
			_l++;
		if(_l<_r)
		{
			a[_r]=a[_l];
			_r--;
		}
	}
	a[_l]=x;
	sort(a,l,_l-1);
	sort(a,_l+1,r);
}
const int N=200010;
int n,x[N],y[N];
typedef long long ll;
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
			if((ll)x[mid]*qy+(ll)y[mid]*qx>=(ll)x[mid]*y[mid])
				l=mid;
			else
				r=mid-1;
		}
		printf("%d\n",l);
	}
	return 0;
}
