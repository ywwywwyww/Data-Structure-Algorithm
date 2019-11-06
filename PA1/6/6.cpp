#include<cstdio>
#include<cstring>
using namespace std;
const int N=3200000+4000000+1;
struct FakeList
{
	int head,tail;
	char ch[2*N];
	int rev;
	FakeList()
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
	void insertLeft(int v)
	{
		if(!rev)
			i_left(v);
		else
			i_right(v);
	}
	void insertRight(int v)
	{
		if(!rev)
			i_right(v);
		else
			i_left(v);
	}
	int eraseLeft()
	{
		if(!rev)
			return e_left();
		else
			return e_right();
	}
	int eraseRight()
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



void putF()
{
	putchar('F');
	putchar('\n');
}
void putT()
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


int stack1[N],stack2[N],top1,top2;
int flag=1; //1 代表左光标在右光标左边， 0 代表左光标在右光标右边 

void moveLeft()
{
	int pos=get();
	char ch;
	if(pos=='L')
	{
		if(list.empty())
			flag=1;
		if(flag)
		{
			if(top1)
			{
				putT();
				ch=stack1[top1--];
				list.insertLeft(ch);
			}
			else
				putF();
		}
		else
		{
			putT();
			ch=list.eraseRight();
			stack2[++top2]=ch;
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
				putT();
				ch=stack1[top1--];
				list.insertLeft(ch);
			}
			else
				putF();
		}
		else
		{
			putT();
			ch=list.eraseRight();
			stack2[++top2]=ch;
		}
	}
}

void moveRight()
{
	int pos=get();
	char ch;
	if(pos=='R')
	{
		if(list.empty())
			flag=1;
		if(flag)
		{
			if(top2)
			{
				putT();
				ch=stack2[top2--];
				list.insertRight(ch);
			}
			else
				putF();
		}
		else
		{
			putT();
			ch=list.eraseLeft();
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
				putT();
				ch=stack2[top2--];
				list.insertRight(ch);
			}
			else
				putF();
		}
		else
		{
			
			putT();
			ch=list.eraseLeft();
			stack1[++top1]=ch;
		}
	}
}

void insert()
{
	int pos=get();
	char ch=get();
	putT();
	if(pos=='L')
	{
		if(flag||list.empty())
			stack1[++top1]=ch;
		else
			list.insertRight(ch);
	}
	else
	{
		if(!flag||list.empty())
			stack1[++top1]=ch;
		else
			list.insertRight(ch);
	}
}

void del()
{
	int pos=get();
	if(pos=='L')
	{
		if(list.empty())
			flag=0;
		if(!flag)
		{
			if(top2)
			{
				putT();
				top2--;
			}
			else
				putF();
		}
		else
		{
			putT();
			list.eraseLeft();
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
				putT();
				top2--;
			}
			else
				putF();
		}
		else
		{
			putT();
			list.eraseLeft();
		}
	}
}

void reverse()
{
	if(list.empty())
		flag=0;
	if(flag)
	{
		putT();
		list.reverse();
	}
	else
		putF();
}

void show()
{
	for(int j=1;j<=top1;j++)
		putchar(stack1[j]);
	list.show();
	for(int j=top2;j>=1;j--)
		putchar(stack2[j]);
	putchar('\n');
}

int main()
{
#ifdef DEBUG
	freopen("6.in","r",stdin);
	freopen("6.out","w",stdout);
#endif
	static char str[N];
	int n;
	
	scanf("%s",str+1);
	int len=strlen(str+1);
	for(int i=1;i<=len;i++)
		list.insertRight(str[i]);
	
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int op=get();
		if(op=='<')
			moveLeft();
		else if(op=='>')
			moveRight();
		else if(op=='I')
			insert();
		else if(op=='D')
			del();
		else if(op=='R')
			reverse();
		else if(op=='S')
			show();
	}
	return 0;
}
