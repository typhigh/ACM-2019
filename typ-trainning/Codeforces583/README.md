# Codeforces Round #583 (Div. 1 + Div. 2, based on Olympiad of Metropolises)

------
[http://codeforces.com/contest/1214][1]

题解与感受

### A. Optimal Currency Exchange
简单题，我没有用暴力的办法。
首先第一种取1， 第二种取5个，就是e = e*5
其实就是min{n-d*i-e*j | i,j为正整数，且n >= d*i+e*j}
取g = gcd(d, e) 
如果 n >= lcm(d,e) 则答案为n % g
否则小范围暴力即可

### B. Badges
瞎暴力就行了

### C. Bad Sequence
用栈维护一下就行了，发现第一个不合法的)需要移到最后面

### D. Treasure Island
这道题做法非常多。
首先肉眼判断答案不超过2
（1）从网络流的角度，这个就是求割点数目，也就是求有几条不相交流，可以dfs2次，做法很简洁有力，原理同限最大流的网络流[https://blog.csdn.net/qq_41603898/article/details/100561496][2]
（2）dp判割点，需要一定的hash做法[https://blog.csdn.net/z472421519/article/details/100567224][3]
（3）这是在平面图上求网络流，用平面图最小割转最短路的思想，也就是从左下角能否到右上角，一次BFS就够了，需要提前预处理不可达的位置，把他们用'#'代替，这个是我的做法.

### E. Petya and Construction Set
这道题的构造相对比较巧妙，其实每一对我们水平放在一条链上，按d[i]递减排序即可，另一个配偶就一次安排，如果d很大放不了中间链上，直接放在链末尾开新的节点，总之很简单

### F. Employment
这道题需要算贡献，但是是a,b分开算贡献的，这就有意思了，通过分类计算，会发现固定a，相同的贡献在b上具有一定的连续性，可以用区间类的数据结构维护，这里用差分数组维护，也可以用线段树吧

### G. Feeling Good
这题非常巧妙，真的很难想到正解，需要用到bitset，然后把题目给的信息推理成一种集合包含的偏序关系，这就很巧妙了，具体需要维护set，以及链表

### H. Tiles Placement
这题非常巧妙，我已经想到了做法，但是中间有一步尚不清楚，首先需要求直径，这一点很有意思，给直径涂色，然后沿着直径进行DFS,涂色，只需要判断支路和主路（直径）是否矛盾就行了。

这套题目质量很高，可做行高，思维性强，具有一定的代码量，与真实赛场的题目风格相似，对选手编程、思维要求较高，是一场难得不错的好题。


  [1]: http://codeforces.com/contest/1214
  [2]: https://blog.csdn.net/qq_41603898/article/details/100561496
  [3]: https://blog.csdn.net/z472421519/article/details/100567224
