# Codeforces Round #576 (Div. 2 + Div. 1)

------
[http://codeforces.com/contest/1199][1]
题解与感受

### A. City Day
简单题，暴力枚举

### B. Water Lily
简单题， 列方程算一下就出来了

### C. MP3
有意思的一题，离散化 + 双指针， 能想到离散化处理就不难了

### D. Welfare State
我是直接线段树做的，网友还有思维型的做法
[https://blog.csdn.net/weixin_43847416/article/details/98080840][2]

### E. Matching vs Independent Set
有意思的一题，两个问题分别来看都是NP问题，但是合起来在这个条件下肯定可做，直接暴力扫一遍边，得到一个matchSet 如果边的数量x小于n，那么剩下的点一定 > 3n - x > n 并且两两不相连可以组成IntSet，否则相连的u-v会落到MatchSet

### F. Rectangle Painting 1
DP即可，为啥可以横竖分割是因为必定不会有相交的矩形

### G. Rectangle Painting 2
网络流 注意构图的优化，难点在于这个优化需要离散化处理

  [1]: http://codeforces.com/contest/1199
  [2]: https://blog.csdn.net/weixin_43847416/article/details/98080840
