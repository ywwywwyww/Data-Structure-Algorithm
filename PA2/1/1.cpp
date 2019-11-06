#include <cstdio>
#include <cstring>
#include "vector.h"

const int rt = 1;

int get_height(int);

struct node
{
private:
	void _update_height(int pos)
	{
		for(int i=pos; i < child.size(); i++)
		{
			height[i] = ::get_height(child[i])+1;
			if(i)
				height[i] = max(height[i-1], height[i]);
		}
	}
	vector<int> child;
	vector<int> height;
public:
	void update_height()
	{
		_update_height(0);
	}
	void update_height(int pos)
	{
		_update_height(size()-pos-1);
	}
	int get_height()
	{
		if(size())
			return height[size()-1];
		return 0;
	}
	int size()
	{
		return child.size();
	}
	int &operator [](int pos)
	{
		return child[size()-pos-1];
	}
	void insert(int pos, int x)
	{
		int _size=size();
		child.insert(size()-pos, x);
		height.push_back(0);
		_update_height(_size-pos);
	}
	void erase(int pos)
	{
		int _size=size();
		child.erase(size()-pos-1);
		height.pop_back();
		_update_height(_size-pos-1);
	}
	int find(int val)
	{
		for(int i=0;i<size();i++)
			if((*this)[i]==val)
				return i;
		return -1;
	}
	void read()
	{
		int num, x;
		scanf("%d",&num);
		for(int i=1;i<=num;i++)
		{
			scanf("%d",&x);
			child.push_back(x);
			height.push_back(0);
		}
		child.reverse();
		_update_height(0);
	}
};
node child[1000001];
int fa[1000001];
int size[1000001];

int get_height(int x)
{
	return child[x].get_height();
}

int find_node()
{
	static int list[1000001];
	int len;
	scanf("%d",&len);
	for(int i=1;i<=len;i++)
		scanf("%d",&list[i]);
	int cur = rt;
	for(int i=1;i<=len;i++)
	{
		if(list[i] < child[cur].size())
			cur = child[cur][list[i]];
		else
			return cur;
	}
	return cur;
}

void del(int x)
{
	child[fa[x]].erase(child[fa[x]].find(x));
	for(int i=fa[x];i;i=fa[i])
		size[i] -= size[x];
	for(int i=fa[x]; fa[i]; i = fa[i])
		child[fa[i]].update_height(child[fa[i]].find(i));
}

void insert(int target, int x, int num)
{
	child[target].insert(num, x);
	fa[x]=target;
	for(int i=target;i;i=fa[i])
		size[i] += size[x];
	for(int i=x; fa[i]; i = fa[i])
		child[fa[i]].update_height(child[fa[i]].find(i));
}

void move()
{
	int subtree = find_node();
	del(subtree);
	int target = find_node();
	int num;
	scanf("%d", &num);
	insert(target, subtree, num);
}

void query(int type)
{
	int subtree = find_node();
	if(type==1)
		printf("%d\n",child[subtree].get_height());
	else
		printf("%d\n",size[subtree]);
}

void dfs(int x)
{
	size[x]=1;
	for(int i=0;i<child[x].size();i++)
	{
		dfs(child[x][i]);
		fa[child[x][i]]=x;
		size[x]+=size[child[x][i]];
	}
	child[x].update_height();
}

void read_tree(int n)
{
	for(int i=1;i<=n;i++)
		child[i].read();
	dfs(rt);
}

int main()
{
#ifdef yww
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	int n,m;
	scanf("%d%d",&n,&m);
	read_tree(n);
	int op;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&op);
		if(op==0)
			move();
		else
			query(op);
	}
	return 0;
}
