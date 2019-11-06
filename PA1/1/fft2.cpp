/*
Author: yww
Language: C++
Mail: weeerrr720@qq.com
*/
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#include<ctime>
#include<functional>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ldb;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
void open(const char *s){
#ifndef ONLINE_JUDGE
    char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
void open2(const char *s){
#ifdef DEBUG
    char str[100];sprintf(str,"%s.in",s);freopen(str,"r",stdin);sprintf(str,"%s.out",s);freopen(str,"w",stdout);
#endif
}
template <class T>
int upmin(T &a, const T &b){return (b<a?a=b,1:0);}
template <class T>
int upmax(T &a, const T &b){return (b>a?a=b,1:0);}
namespace io
{
    const int SIZE=(1<<20)+1;
    char ibuf[SIZE],*iS,*iT;
    char obuf[SIZE],*oS=obuf,*oT=oS+SIZE-1;
    int getc()
    {
        (iS==iT?iS=ibuf,iT=ibuf+fread(ibuf,1,SIZE,stdin):0);
        return iS==iT?EOF:*(iS++);
    }
    int f;
    char c;
    template <class T>
    void get(T &x)
    {
        f=1;
        for(c=getc();(c<'0'||c>'9')&&c!='-';c=getc());
        (c=='-'?f=-1,c=getc():0);
        x=0;
        for(;c>='0'&&c<='9';c=getc())
            x=x*10+c-'0';
        x*=f;
    }
    void flush()
    {
        fwrite(obuf,1,oS-obuf,stdout);
        oS=obuf;
    }
    void putc(char x)
    {
        *(oS++)=x;
        if(oS==oT)
            flush();
    }
    int a[55],t;
    template <class T>
    void put(T x)
    {
        if(!x)
            putc('0');
        x<0?putc('-'),x=-x:0;
        while(x)
        {
            a[++t]=x%10;
            x/=10;
        }
        while(t)
            putc(a[t--]+'0');
    }
    void space()
    {
        putc(' ');
    }
    void enter()
    {
        putc('\n');
    }
    struct flusher
    {
        ~flusher()
        {
            flush();
        }
    }
    io_flusher;
}
const int infi=0x3fffffff;
const ll infll=0x3fffffffffffffffll;
const int N=20010;
int rev[N];
struct cp
{
	db x,y;
	cp(db a=0,db b=0):x(a),y(b){}
};
cp operator +(cp a,cp b)
{
	return cp(a.x+b.x,a.y+b.y);
}
cp operator -(cp a,cp b)
{
	return cp(a.x-b.x,a.y-b.y);
}
cp operator *(cp a,cp b)
{
	return cp(a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);
}
cp operator /(cp a,db b)
{
	return cp(a.x/b,a.y/b);
}
cp a[N],b[N];
int c[N];
const int W=16384;
cp w[W];
void fft(cp *a,int n,int t)
{
	for(int i=1;i<n;i++)
	{
		rev[i]=(rev[i>>1]>>1)|(i&1?n>>1:0);
		if(rev[i]>i)
			swap(a[i],a[rev[i]]);
	}
	for(int i=2;i<=n;i<<=1)
		for(int j=0;j<n;j+=i)
			for(int k=0;k<i/2;k++)
			{
				cp u=a[j+k];
				cp v=a[j+k+i/2]*w[W/i*k];
				a[j+k]=u+v;
				a[j+k+i/2]=u-v;
			}
	if(t==-1)
	{
		reverse(a+1,a+n);
		for(int i=0;i<n;i++)
			a[i]=a[i]/n;
	}
}

char s1[N],s2[N];
int n,m;
void solve()
{
	scanf("%s%s",s1+1,s2+1);
	n=strlen(s1+1);
	m=strlen(s2+1);
	int k=1;
	while(k<=n+m)
		k<<=1;
	for(int i=0;i<k;i++)
		a[i]=b[i]=cp();
	for(int i=0;i<=n;i++)
		a[i]=s1[n-i]-'0';
	for(int i=0;i<=m;i++)
		b[i]=s2[m-i]-'0';
	fft(a,k,1);
	fft(b,k,1);
	for(int i=0;i<k;i++)
		a[i]=a[i]*b[i];
	fft(a,k,-1);
	for(int i=0;i<k;i++)
		c[i]=a[i].x+0.5;
	for(int i=0;i<k;i++)
	{
		c[i+1]+=c[i]/10;
		c[i]%=10;
	}
	int i=k-1;
	for(;i>=0&&!c[i];i--);
	if(i<0)
		printf("0\n");
	else
	{
		for(;i>=0;i--)
			printf("%d",c[i]);
		printf("\n");
	}
}
int main()
{
	const db pi=acos(-1);
	for(int i=0;i<W;i++)
		w[i]=cp(cos(2*pi/W*i),sin(2*pi/W*i));
	freopen("1.in","r",stdin);
	freopen("fft2.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		fprintf(stderr,"%d\n",t);
		solve();
	}
	return 0;
}
