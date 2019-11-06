# CST2019 1-3 filename 题解 

## 题目大意

　　有一个字符串 $A$，你可以进行很多次修改，每次可以在某一个位置插入一个字符或删除一个字符，最后要变成字符串 $B$，求最小操作次数。特别的，如果最小操作次数 $>k$，则输出 $-1$。

　　$\lvert A\rvert,\lvert B\rvert \leq 5\times {10}^5+1000,k\leq 100$

## 题解

　　如果 $\lvert A\rvert $ 和 $\lvert B\rvert $ 的差 $>k$，那么肯定无解。

　　显然操作顺序对答案是没有影响。

　　考虑先删掉一些字符，再添加一些字符。

　　假设删掉一些字符后还有 $s$ 个字符，那么答案就是 $\lvert A\rvert + \lvert B\rvert -2s$。那么就是要让 $s$ 尽可能的大。那么 $s=\lvert LCS(A,B)\rvert $。问题就转换成了求两个串的 $LCS$。

　　考虑最简单的DP：$f_{i,j}$ 表示第一个串的前 $i$ 位和第二个串的前 $j$ 位的 $LCS$。转移的时候，如果 $A_i=B_j$，那么 $f_{i,j}=f_{i-1,j-1}+1$；否则 $f_{i,j}=\max\{f_{i-1,j},f_{i,j-1}\}$。

　　但是这么做会TLE。考虑限制 $k$：如果DP的时候 $i,j$ 两维差了至少 $k+1$，那么 $i+j-2f_{i,j}$ 就一定 $>k$ 了。这样这个状态就是没用的了。另外，还需要把 DP 数组压到一维以减少空间。

　　时间复杂度：因为DP过程中 $\lvert i-j\rvert \leq k$，所以复杂度就是 $\Theta(\lvert A\rvert k)$。

　　空间复杂度为 $\Theta(\lvert A\rvert)$