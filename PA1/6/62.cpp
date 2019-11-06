#include<cstdio>
#include<cstring>
using namespace std;
int get()
{
	int ch;
	for(ch=getchar();ch==' '||ch=='\n'||ch=='\r';ch=getchar());
	return ch;
}
void F()
{
	putchar('F');
	putchar('\n');
}
void T()
{
	putchar('T');
	putchar('\n');
}
void swap(char &a,char &b)
{
	char c=a;
	a=b;
	b=c;
}
void reverse(char *p1,char *p2)
{
	while(p1<p2)
	{
		swap(*p1,*p2);
		p1++;
		p2--;
	}
}
const int N=10000010;
char str[N];
int n;
int c1,c2;
int q;
void insert(int x,int ch)
{
	x++;
	for(int i=n;i>=x;i--)
		str[i+1]=str[i];
	n++;
	str[x]=ch;
}
void erase(int x)
{
	x++;
	for(int i=x;i<n;i++)
		str[i]=str[i+1];
	n--;
}
int main()
{
#ifdef DEBUG
	freopen("6.in","r",stdin);
	freopen("62.out","w",stdout);
#endif
	scanf("%s",str+1);
	n=strlen(str+1);
	c1=0;
	c2=n;
	int op,x,ch;
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		op=get();
		if(op=='<')
		{
			x=get();
			if(x=='L')
			{
				if(c1)
				{
					c1--;
					T();
				}
				else
					F();
			}
			else
			{
				if(c2)
				{
					c2--;
					T();
				}
				else
					F();
			}
		}
		else if(op=='>')
		{
			x=get();
			if(x=='L')
			{
				if(c1<n)
				{
					c1++;
					T();
				}
				else
					F();
			}
			else
			{
				if(c2<n)
				{
					c2++;
					T();
				}
				else
					F();
			}
		}
		else if(op=='I')
		{
			x=get();
			ch=get();
			T();
			if(x=='L')
			{
				insert(c1,ch);
				if(c2>=c1)
					c2++;
				c1++;
			}
			else
			{
				insert(c2,ch);
				if(c1>=c2)
					c1++;
				c2++;
			}
		}
		else if(op=='D')
		{
			x=get();
			if(x=='L')
			{
				if(c1==n)
					F();
				else
				{
					T();
					erase(c1);
					if(c2>=c1)
						c2--;
				}
			}
			else
			{
				if(c2==n)
					F();
				else
				{
					T();
					erase(c2);
					if(c1>=c2)
						c1--;
				}
			}
		}
		else if(op=='R')
		{
			if(c1<c2)
			{
				T();
				reverse(str+c1+1,str+c2);
			}
			else
				F();
		}
		else if(op=='S')
		{
			str[n+1]=0;
			printf("%s\n",str+1);
		}
//		str[n+1]=0;
//		printf("%d %s\n",i,str+1);
	}
	return 0;
}
