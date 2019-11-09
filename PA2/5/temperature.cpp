#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "temperature.h"
#include "algo.h"
#include "pair.h"
#include "utils.h"
//#include <algorithm>
//#include <utility>
//using namespace std;

const int inf = 0x7fffffff;
typedef pair<int,int> pii;

struct KDTree
{
	int ch[2];
	int id;
	int x, y, t;
	int mint, maxt;
	int minx, maxx, miny, maxy;
};

struct Point
{
	int x, y, t, id;
};

Point point[600001];
KDTree node[600001];
int root;

bool cmp1(const Point &a, const Point &b)
{
	if(a.x!=b.x)
		return a.x<b.x;
	return a.id < b.id;
}
bool cmp2(const Point &a, const Point &b)
{
	if(a.y!=b.y)
		return a.y<b.y;
	return a.id < b.id;
}

int build(int l, int r, int dep)
{
	int mid = (l+r)/2;;
	if(dep & 1)
		nth_element(point+l, point+mid, point+r+1, cmp1);
	else
		nth_element(point+l, point+mid, point+r+1, cmp2);
	int cur = (l+r)/2;
	node[cur].mint = node[cur].maxt = node[cur].t = point[cur].t;
	node[cur].minx = node[cur].maxx = node[cur].x = point[cur].x;
	node[cur].miny = node[cur].maxy = node[cur].y = point[cur].y;
	if(l<cur)
	{
		int &lc = node[cur].ch[0];
		lc = build(l, cur-1, dep+1);
		node[cur].mint = min(node[cur].mint, node[lc].mint);
		node[cur].maxt = max(node[cur].maxt, node[lc].maxt);
		node[cur].minx = min(node[cur].minx, node[lc].minx);
		node[cur].maxx = max(node[cur].maxx, node[lc].maxx);
		node[cur].miny = min(node[cur].miny, node[lc].miny);
		node[cur].maxy = max(node[cur].maxy, node[lc].maxy);
	}
	if(r>cur)
	{
		int &rc = node[cur].ch[1];
		rc = build(cur+1, r, dep+1);
		node[cur].mint = min(node[cur].mint, node[rc].mint);
		node[cur].maxt = max(node[cur].maxt, node[rc].maxt);
		node[cur].minx = min(node[cur].minx, node[rc].minx);
		node[cur].maxx = max(node[cur].maxx, node[rc].maxx);
		node[cur].miny = min(node[cur].miny, node[rc].miny);
		node[cur].maxy = max(node[cur].maxy, node[rc].maxy);
	}
	return cur;
}

pii res;
void update(pii temp)
{
	res.first=min(res.first, temp.first);
	res.second=max(res.second, temp.second);
}

void query(int cur, int x1, int x2, int y1, int y2)
{
	if(x2 < node[cur].minx || x1 > node[cur].maxx || y2 < node[cur].miny || y1 > node[cur].maxy)
		return;
	if(res.first <= node[cur].mint && res.second >= node[cur].maxt)
		return;
	if(x1 <= node[cur].minx && x2 >= node[cur].maxx && y1 <= node[cur].miny && y2 >= node[cur].maxy)
	{
		update(pii(node[cur].mint, node[cur].maxt));
		return;
	}
	if(x1 <= node[cur].x && x2 >= node[cur].x && y1 <= node[cur].y && y2 >= node[cur].y)
		update(pii(node[cur].t, node[cur].t));
	if(node[cur].ch[0])
		query(node[cur].ch[0], x1, x2, y1, y2);
	if(node[cur].ch[1])
		query(node[cur].ch[1], x1, x2, y1, y2);
}

void init(int n, const int *x, const int *y, const int *t)
{
	for(int i=1;i<=n;i++)
	{
		point[i].x = x[i-1];
		point[i].y = y[i-1];
		point[i].t = t[i-1];
		point[i].id = i;
	}
	root = build(1,n,1);
}

void query(int x1, int x2, int y1, int y2, int *tmin, int *tmax)
{
	res.first = inf;
	res.second = -1;
	query(root, x1, x2, y1, y2);
	if(res.second != -1)
	{
	    *tmin = res.first;
		*tmax = res.second;
	}
	else
		*tmin = *tmax = -1;
}
