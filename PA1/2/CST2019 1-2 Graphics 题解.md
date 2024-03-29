# CST2019 1-2 Graphics 题解

## 题目大意

　　$x$ 轴的正半轴和 $y$ 轴的正半轴上分别有 $n$ 个点。然后把 $x$ 轴上的点与 $y$ 轴上的点一一连接形成 $n$ 条线段，并且任意两条线段不相交。

　　随后有 $m$ 次询问，每次给一个点 $Q(qx,qy)$，问 $OQ$ 这条线段和多少条线段有交点？

　　$n,m\leq 2\times {10}^5$

## 题解

　　先把 $x$ 轴上的点的坐标从小到大排序，再把 $y$ 轴上的点的坐标从小到大排序。那么这些线段肯定是 $(x_1,0)$ 连向 $(0,y_1)$，$(x_2,0)$ 连向 $(0,y_2)$，以此类推，否则这些线段就会相交。

　　因为 $n$ 很大，所以要用归并排序。

　　归并排序的原理：

　　对于一个区间 $[l,r]$，记 $mid=\lfloor\frac{l+r}{2}\rfloor$。先把 $[l,mid]$ 内的数排序，再把 $[mid+1,r]$ 内的数排序。合并的时候由于两个子序列都是有序的，所以只需要每次取出两个子序列中的第一个数中较小的那个数。

　　对于询问，可以使用二分查找：如果 $OQ$ 与一条线段 $(x_i,0)\sim (0,y_i)$ 相交，那么 $OQ$ 就一定与 $(x_j,0)\sim (0,y_j)(j<i)$ 相交；否则 $OQ$ 一定不与 $(x_j,0)\sim (0,y_j)(j>i)$ 相交。

　　对于一个区间 $[l,r]$，通过查询 $OQ$ 和 $(x_{\frac{l+r}{2}},0)\sim (0,y_{\frac{l+r}{2}})$ 是否相交，就可以确定区间内一般的线段的相交情况。这样在 $\Theta(\log n)$ 次查询后就可以得到答案。

　　那么如何判断两条线段是否相交呢？

　　可以通过叉积判断。我们可以计算 $(Q-(x_i,0))\times (-x_i,y_i)$。如果结果 $\geq 0$ 则说明两条线段相交，否则就不相交。

　　归并排序的复杂度：$T(n)=2T(\frac{n}{2})+\Theta(n)$ 解得 $T(n)=\Theta(n\log n)$

　　二分查找的复杂度：$\Theta(m\log n)$

　　总的复杂度为 $\Theta((n+m)\log n)$

　　空间复杂度：$\Theta(n)$