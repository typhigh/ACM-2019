# Codeforces Round #581 (Div. 2)

------
[http://codeforces.com/contest/1204][1]

题解与感受

### A. BowWow and the Timetable
简单题，根据最高位判断，注意特判（1<<k)的情况

### B. Mislove Has Lost an Array
贪心即可，一种是能放1就放1，另一种是能放大的就放大的

### C. Anna, Svyatoslav and Maps
Floyed 求出两两之间最短路，拿个栈维护一下， 只要st1-st2-x 不等于 st1-x 距离就可以把st2弹出，重复这个过程

### D2. Kirk and a Binary String (hard version)
这道题比较复杂，但是很好玩，这篇文章讲得很清楚
[https://www.cnblogs.com/yyf0309/p/11389504.html][2]

### E. Natasha, Sasha and the Prefix Sums
其实是DP， 枚举第一个选什么就行了，中间会有一个小的容斥，内容对应卡特兰数

题目还行，好玩


  [1]: http://codeforces.com/contest/1204
  [2]: https://www.cnblogs.com/yyf0309/p/11389504.html
