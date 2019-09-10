# Educational Codeforces Round 72 (Rated for Div. 2)

------
[http://codeforces.com/contest/1217][1]

题解与感受

### A. Creating a Character
简单题，分情况讨论即可

### B. Zmei Gorynich
贪心即可，选一个最大的伤害的，再选一个最大的持续伤害的即可

### C. The Number Of Good Substrings
有意思的一题，我的做法：先找规律，发现
1
10
011
0100
00101
000110
发现1左边的0顶多比1右边的个数少1个，根据前面0的个数暴力枚举没问题，可以减枝

### D. Coloring Edges
很有意思的一题，如果没环一个颜色就够了，有环的话，一个不够，2个够了，因为对于u->v
如果把u>v 和 u<v 分别图成不同颜色就可以了，这个很巧妙

### E. Sum Queries?
如果3个数满足，那么必定是里面的2个数满足,可以看下面的做法
[https://www.cnblogs.com/buerdepepeqi/p/11496022.html][2]


  [1]: http://codeforces.com/contest/1217
  [2]: https://www.cnblogs.com/buerdepepeqi/p/11496022.html
