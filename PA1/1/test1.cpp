#include<cstdio>
#include<cstring>
using namespace std;
int len,ccnt;
char str[1000010];
int rd()
{
	int s=0,c;
	while((c=str[++ccnt])<'0'||c>'9');
	do
	{
		s=s*10+c-'0';
	}
	while((c=str[++ccnt])>='0'&&c<='9');
	return s;
}
typedef long long ll;
const int p=998244353;
const int D=14;
const int W=1<<D;
ll fp(ll a,ll b)
{
	ll s=1;
	for(;b;b>>=1,a=a*a%p)
		if(b&1)
			s=s*a%p;
	return s;
}
int rev[300010];
int b[300010];
int a[300010];
int *w[D+1];
int add(int a,int b){a+=b;return a>=p?a-p:a;}
//int del(int a,int b){a-=b;return a<0?a+p:a;}
int del(int a,int b){return add(a,p-b);}
void swap(int &a,int &b)
{
	int c=a;
	a=b;
	b=c;
}
void reverse(int *a,int *b)
{
	b--;
	while(b>a)
	{
		swap(*a,*b);
		a++;
		b--;
	}
}
void ntt(int *a,int n,int t)
{
	for(int i=1;i<n;i++)
	{
		rev[i]=(rev[i>>1]>>1)|(i&1?n>>1:0);
		if(rev[i]>i)
			swap(a[i],a[rev[i]]);
	}
	for(int i=2,s=1;i<=n;i<<=1,s++)
		for(int j=0;j<n;j+=i)
		{
			int *p1=a+j;
			int *p2=a+j+(i>>1);
			int *p3=w[s];
			for(int k=0;k<(i>>1);k++,p1++,p2++,p3++)
			{
				int u=*p1;
				int v=(ll)*p2**p3%p;
				*p1=add(u,v);
				*p2=del(u,v);
			}
		}
	if(t==2)
	{
		reverse(a+1,a+n);
		ll inv=fp(n,p-2);
		for(int i=0;i<n;i++)
			a[i]=a[i]*inv%p;
	}
}
char str1[100010],str2[100010];
int main()
{
	freopen("1.in","r",stdin);
	freopen("fft.out","w",stdout);
	str[len+1]=0;
	str[len+2]=0;
	w[D]=new int[1<<(D-1)];
	ll s=fp(3,(p-1)/W);
	w[D][0]=1;
	for(int i=1;i<1<<(D-1);i++)
		w[D][i]=w[D][i-1]*s%p;
	for(int i=D-1;i>=1;i--)
	{
		w[i]=new int[1<<(i-1)];
		for(int j=0;j<1<<(i-1);j++)
			w[i][j]=w[i+1][j<<1];
	}
	int n,m;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		fprintf(stderr,"%d\n",t);
		scanf("%s%s",str1+1,str2+1);
		n=strlen(str1+1);
		m=strlen(str2+1);
		int k=1;
		while(k<=n+m)
			k<<=1;
		for(int i=0;i<=k;i++)
			a[i]=b[i]=0;
		for(int i=0;i<n;i++)
			a[i]=str1[n-i]-'0';
		for(int i=0;i<m;i++)
			b[i]=str2[m-i]-'0';
		ntt(b,k,1);
		ntt(a,k,1);
		for(int *p1=a,*p2=b;p1<a+k;p1++,p2++)
			*p1=(ll)*p1**p2%p;
		ntt(a,k,2);
		for(int i=0;i<k;i++)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
		}
		int i=k-1;
		for(;i>=0&&!a[i];i--);
		if(i<0)
			printf("0\n");
		else
		{
			for(;i>=0;i--)
				printf("%d",a[i]);
			printf("\n");
		}
	}
	return 0;
}
