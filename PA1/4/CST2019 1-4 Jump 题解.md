# CST2019 1-4 Jump 题解

## 题目大意

　　有 $n$ 个格子，你要从 $1$ 跳到 $n$。当你在第 $i$ 个格子上时，你可以花费 $t_i$ 的时间跳到 $l_i\sim r_i$ 中间的任意一个格子上。求你最快多久能跳完。

　　$n\leq {10}^6,i<l_i\leq  l_{i+1},l_i\leq r_i\leq r_{i+1}$

## 题解

　　考虑最朴素的 DP：从后往前 DP，$f_i$当前你在第 $i$ 个格子上，你还需要多久才能到达第 $n$ 个格子。

　　那么就是 $f_i=t_i+\min_{l_i\leq j\leq r_i} f_j$。

　　考虑怎么优化这个算法。

　　注意到 $l_i\leq l_{i+1},r_i\leq r_{i+1}$，可以用单调队列（Queap）优化这个问题。

　　维护一个队列，当 DP 到 $i$ 的时候维护 $l_i\sim r_i$ 中间的一些信息：位置 $j$ 以及 DP 值 $f_j$

　　因为每次的 $l_i,r_i$ 都会向左移，所以只会在队列的左端插入、右端删除信息。

　　当我们准备插入一个二元组的时候，观察当前队列最左端的二元组的 DP 值是否小于即将插入的二元组的 DP 值。如果前者小，就说明队列最左端的二元组是没用的，因为它会比即将插入的二元组小，而且比后者先删除。这样就可以把前者从队列里面删掉了。

　　队列中的最大值一定是最右边的那个元素。

　　当队列最右边的二元组的位置 $>r_i$ 时，就把它删掉。

　　时间复杂度为 $\Theta(n)$，因为每个元素只会被插入删除一次。

　　空间复杂度也是 $\Theta(n)$。