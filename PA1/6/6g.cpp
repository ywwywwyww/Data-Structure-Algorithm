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
#include<windows.h>
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
int main()
{
	freopen("6.in","w",stdout);
	srand(GetTickCount());
	int n=rand()%100+1;
//	int n=3200000;
	for(int i=1;i<=n;i++)
		putchar(rand()%10+'0');
	putchar('\n');
	int q=rand()%100+1;
//	int q=4000000;
	printf("%d\n",q);
	for(int i=1;i<=q;i++)
	{
		int op=rand()%5+1;
		if(op==1)
			printf("< %c\n","LR"[rand()&1]);
		else if(op==2)
			printf("> %c\n","LR"[rand()&1]);
		else if(op==3)
			printf("I %c %c\n","LR"[rand()&1],rand()%10+'0');
		else if(op==4)
			printf("D %c\n","LR"[rand()&1]);
		else if(op==5)
			printf("R\n");
		else
			printf("S\n");
	}
	return 0;
}
