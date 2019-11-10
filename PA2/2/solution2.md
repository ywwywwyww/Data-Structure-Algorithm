# Circuit 题解

## 题目大意

　　有 $n$ 个二进制数，对于所有 $i$，求 $\max_{i-k-1\leq j\leq i+k+1,j\neq i} a_i\oplus a_j$ 其中 $\oplus$ 为按位异或。

　　$n\leq 500000$

## 题解

　　考虑用 trie。时间复杂度为 $\Theta(nw)$，空间复杂度约为 $\Theta(n(w-\log n)+n)$，其中 $w$ 为 $\max_i \log_2 a_i$。直接这样做会 MLE，考虑把一些边压缩到一起。

　　具体来说，对于一个节点 $x$，如果它的一个孩子 $y$ 只有一个孩子 $z$，就把 $x\to y,y\to z$ 这两条边压缩成一条边 $x\to z$。

　　最开始插入第一个二进制数的时候会新建一条边。

　　之后每次插入都会正常地在 trie 上查找插入的位置，如果一条边（本质上是一条链）的中间要新建一个分支，就把这条边拆成两条再新建分支。

　　这样空间复杂度就降到了 $\Theta(n)$。时间复杂度为 $O(nw)$。
