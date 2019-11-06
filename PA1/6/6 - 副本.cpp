#include<cstdio>
#include<cstring>
using namespace std;
const int N=10000010;
struct fake_list
{
	int head,tail;
	int ch[2*N];
	int rev;
	fake_list()
	{
		head=N+1;
		tail=N;
		rev=0;
	}
	void i_left(int v)
	{
		ch[--head]=v;
	}
	void i_right(int v)
	{
		ch[++tail]=v;
	}
	int e_left()
	{
		return ch[head++];
	}
	int e_right()
	{
		return ch[tail--];
	}
	void show()
	{
		if(!rev)
			for(int i=head;i<=tail;i++)
				putchar(ch[i]);
		else
			for(int i=tail;i>=head;i--)
				putchar(ch[i]);
	}
	int empty()
	{
		return tail<head;
	}
	void insert_left(int v)
	{
		if(!rev)
			i_left(v);
		else
			i_right(v);
	}
	void insert_right(int v)
	{
		if(!rev)
			i_right(v);
		else
			i_left(v);
	}
	int erase_left()
	{
		if(!rev)
			return e_left();
		else
			return e_right();
	}
	int erase_right()
	{
		if(!rev)
			return e_right();
		else
			return e_left();
	}
	void reverse()
	{
		rev^=1;
	}
} list;
//struct list
//{
//	int head,tail;
//	int left[N],right[N],ch[N];
//	int cnt;
//	int rev;
//	list()
//	{
//		head=tail=cnt=rev=0;
//	}
//	void i_left(int v)
//	{
//		cnt++;
//		ch[cnt]=v;
//		if(!head)
//		{
//			head=tail=cnt;
//			left[cnt]=right[cnt]=0;
//		}
//		else
//		{
//			right[cnt]=head;
//			left[cnt]=0;
//			left[head]=cnt;
//			head=cnt;
//		}
//	}
//	void i_right(int v)
//	{
//		cnt++;
//		ch[cnt]=v;
//		if(!tail)
//		{
//			head=tail=cnt;
//			left[cnt]=right[cnt]=0;
//		}
//		else
//		{
//			left[cnt]=tail;
//			right[cnt]=0;
//			right[tail]=cnt;
//			tail=cnt;
//		}
//	}
//	int e_left()
//	{
//		int res=ch[head];
//		if(head==tail)
//			head=tail=0;
//		else
//		{
//			head=right[head];
//			left[head]=0;
//		}
//		return res;
//	}
//	int e_right()
//	{
//		int res=ch[tail];
//		if(head==tail)
//			head=tail=0;
//		else
//		{
//			tail=left[tail];
//			right[tail]=0;
//		}
//		return res;
//	}
//	void show()
//	{
//		if(!rev)
//			for(int i=head;i;i=right[i])
//				putchar(ch[i]);
//		else
//			for(int i=tail;i;i=left[i])
//				putchar(ch[i]);
//	}
//	int empty()
//	{
//		return !head;
//	}
//	void insert_left(int v)
//	{
//		if(!rev)
//			i_left(v);
//		else
//			i_right(v);
//	}
//	void insert_right(int v)
//	{
//		if(!rev)
//			i_right(v);
//		else
//			i_left(v);
//	}
//	int erase_left()
//	{
//		if(!rev)
//			return e_left();
//		else
//			return e_right();
//	}
//	int erase_right()
//	{
//		if(!rev)
//			return e_right();
//		else
//			return e_left();
//	}
//	void reverse()
//	{
//		rev^=1;
//	}
//} list;
char str[N];
int n;
int stack1[N],st2[N],top1,top2;
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
int get()
{
	int ch;
	for(ch=getchar();ch==' '||ch=='\n'||ch=='\r';ch=getchar());
	return ch;
}
int main()
{
#ifdef DEBUG
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
#endif
	scanf("%s",str+1);
	int len=strlen(str+1);
	for(int i=1;i<=len;i++)
		list.insert_right(str[i]);
	scanf("%d",&n);
	int op,x,ch;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		op=get();
		if(op=='<')
		{
			x=get();
			if(x=='L')
			{
				if(list.empty())
					flag=1;
				if(flag)
				{
					if(top1)
					{
						T();
						ch=stack1[top1--];
						list.insert_left(ch);
					}
					else
						F();
				}
				else
				{
					T();
					ch=list.erase_right();
					st2[++top2]=ch;
				}
			}
			else
			{
				if(list.empty())
					flag=0;
				if(!flag)
				{
					if(top1)
					{
						T();
						ch=stack1[top1--];
						list.insert_left(ch);
					}
					else
						F();
				}
				else
				{
					T();
					ch=list.erase_right();
					st2[++top2]=ch;
				}
			}
		}
		else if(op=='>')
		{
			x=get();
			if(x=='R')
			{
				if(list.empty())
					flag=1;
				if(flag)
				{
					if(top2)
					{
						T();
						ch=st2[top2--];
						list.insert_right(ch);
					}
					else
						F();
				}
				else
				{
					T();
					ch=list.erase_left();
					stack1[++top1]=ch;
				}
			}
			else
			{
				if(list.empty())
					flag=0;
				if(!flag)
				{
					if(top2)
					{
						T();
						ch=st2[top2--];
						list.insert_right(ch);
					}
					else
						F();
				}
				else
				{
					
					T();
					ch=list.erase_left();
					stack1[++top1]=ch;
				}
			}
		}
		else if(op=='I')
		{
			x=get();
			ch=get();
			T();
			if(x=='L')
			{
				if(flag||list.empty())
					stack1[++top1]=ch;
				else
					list.insert_right(ch);
			}
			else
			{
				if(!flag||list.empty())
					stack1[++top1]=ch;
				else
					list.insert_right(ch);
			}
		}
		else if(op=='D')
		{
			x=get();
			if(x=='L')
			{
				if(list.empty())
					flag=0;
				if(!flag)
				{
					if(top2)
					{
						T();
						top2--;
					}
					else
						F();
				}
				else
				{
					T();
					list.erase_left();
				}
			}
			else
			{
				if(list.empty())
					flag=1;
				if(flag)
				{
					if(top2)
					{
						T();
						top2--;
					}
					else
						F();
				}
				else
				{
					T();
					list.erase_left();
				}
			}
		}
		else if(op=='R')
		{
			if(list.empty())
				flag=0;
			if(flag)
			{
				T();
				list.reverse();
			}
			else
				F();
		}
		else if(op=='S')
		{
			for(int j=1;j<=top1;j++)
				putchar(stack1[j]);
			list.show();
			for(int j=top2;j>=1;j--)
				putchar(st2[j]);
			putchar('\n');
		}
//		printf("%d ",i);
//		for(int j=1;j<=top1;j++)
//			putchar(stack1[j]);
//		list.show();
//		for(int j=top2;j>=1;j--)
//			putchar(st2[j]);
//		putchar('\n');
	}
	return 0;
}
