# $\qquad \qquad \qquad \qquad\qquad \qquad \qquad \qquad \qquad $meixiuxiu学图论
$Time\quad Limit :\quad 2000ms \quad Memory \quad Limit: \quad 65536K$

###$Description$
>$\quad\quad$$meixiuxiu$是一个不喜欢图论的孩纸，但是比赛碰到图论的题目怎么办呢,所以她准备怒刷图论500道$\to \_\to$。
>$\quad\quad$这一天，她刚学完有关最小生成树的算法，碰到了$RunningPhoton$，$RunningPhoton$碰到了一个图论的问题，作为和数学和dp选手，他是百思不得解，于是就向$meixiuxiu$请教。
$\quad\quad$这个问题是这样的：给定一个有$n$个点$m$条边的有权连通图,图中可能会存在一些环，对于任意一个环$C$，定义$f(C) = max(w(i,j)|(i,j) \in C)$，对于所有的环而言，我们要求的是$min(f(C))$。
$\quad\quad$她一下就看出了解法，于是就更加认为$RunningPhoton$是一个$sd$，因此不接受他的问题，并把问题扔给了你，你们会么？

###$Input$
>输入第一行有一个$T$，表示样例个数。
每个样例开始一行有两个整数，$n$，$m$ $(n \le 5e5, m \le 2e6)$，表示图中节点数和边数。
接下来$m$行，每一行有三个整数$u$,$v$,$c$，表示每一条边的起点，终点和权值。$(u \le n, v \le n, w \le 5000)$

###$Output$
>每一个样例输出一行。
如果问题有解则输出解，否则输出"No solution!"。（不包含引号）

###$Sample\quad Input$
>2
3&#160;2
1&#160;2&#160;3
2&#160;3&#160;4
5&#160;6
1&#160;2&#160;1
2&#160;3&#160;2
1&#160;3&#160;4
3&#160;4&#160;5
3&#160;6&#160;2
5&#160;6&#160;8

###$Sample \quad Output$
>No solution!
4

###$Hint$
>第一个样例，没有环，所以无解
第二个样例有两个环，分别是$1 \to 2 \to 3 \to 1$ 和 $3 \to 4 \to 5 \to 3$，第一个环里的最大值是$4$，第二个是$8$，所以答案是4。

