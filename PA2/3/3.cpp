#include <cstdio>
#include <cstring>
#include "vector.h"
#include "utils.h"

template <int N>
struct Graph
{
	vector<int> edge[N+1];
	int n;
	void add_uni_edge(int x, int y) // add a unidirectional edge
	{
		edge[x].push_back(y);
	}
	void add_bi_edge(int x, int y) // add a bidirectional edge
	{
		add_uni_edge(x, y);
		add_uni_edge(y, x);
	}
};
Graph<100000> graph;
Graph<199999> cst; // Circle-Square-Tree

void dfs(int x, int fa)
{
	static int vis[100001], stack[100001], top, ti, dfn[100001], low[100001];
	dfn[x] = low[x] = ++ti;
	vis[x] = 1;
	stack[++top] = x;
	int subtree_cnt = 0;
	for(int i = 0; i < graph.edge[x].size(); i++)
	{
		int v = graph.edge[x][i];
		if(v != fa)
		{
			if(!vis[v])
			{
				dfs(v, x);
				low[x] = min(low[x], low[v]);
				if(low[v] >= dfn[x])
				{
					cst.n++;
					int u;
					do
					{
						u = stack[top--];
						cst.add_bi_edge(u, cst.n);
						vis[u]=2;
					}
					while(u != v);
					cst.add_bi_edge(x, cst.n);
				}
				subtree_cnt ++;
			}
			else if(vis[v] == 1)
			{
				low[x] = min(low[x], dfn[v]);
			}
			else
			{
			}
		}
	}
}

void tarjan()
{
	cst.n = graph.n;
	dfs(1,0);
}

void query(int x, int y)
{
	static int vis[200000], fa[200000], q[200000], head, tail;
	head=1, tail=0;
	q[++tail]=x;
	for(int i=1;i<=cst.n;i++)
		vis[i] = 0;
	vis[x]=1;
	fa[x]=0;
	while(tail>=head)
	{
		int front = q[head++];
		for(int i=0; i < cst.edge[front].size(); i++)
		{
			int v = cst.edge[front][i];
			if(!vis[v])
			{
				vis[v] = 1;
				fa[v] = front;
				q[++tail] = v;
			}
		}
	}
	static int ans[100001], cnt;
	cnt = 0;
	for(int i=y;i;i=fa[i])
		if(i<=graph.n)
			ans[++cnt] = i;
	sort(ans+1, ans+cnt+1);
	for(int i=1;i<=cnt;i++)
		printf("%d ",ans[i]);
	printf("\n");
}

int main()
{
	#ifdef yww
	freopen("3.in","r",stdin);
	freopen("3.out","w",stdout);
	#endif
	int m,q;
	scanf("%d%d",&graph.n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		graph.add_bi_edge(x,y);
	}
	tarjan();
//	for(int i=1;i<=graph.n;i++)
//	{
//		fprintf(stderr,"%d : ", i);
//		for(int j=0;j<cst.edge[i].size();j++)
//			fprintf(stderr,"%d ", cst.edge[i][j]);
//		fprintf(stderr,"\n");
//	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		query(x,y);
	}
	return 0;
}
