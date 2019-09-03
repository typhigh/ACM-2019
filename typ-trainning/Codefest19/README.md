# Educational Codeforces Round 71 (Rated for Div. 2)
[http://codeforces.com/contest/1208][1]
------

题解与感受

### A. XORinacci
简单题，暴力

### B. Uniqueness
双指针l, r 标识[l,r]是要删的，l=0确定r,然后l右移，r随之变动

### C. Magic Grid
令 n = 4k， 把正方形分成k * k 这么对块， 每一块有4个元素，第一块顺时针转是0123，第二颗是4567...以此类推

### D. Restore Permutation
线段树维护，具体。。。

### E. Let Them Slide
不考虑负数
分两种情况讨论，要么所谓的w 大于等于 2l，要么小于 2l,分类讨论：
w >= 2l : 两头维护前缀中最大数，中间就是a[1...l]最大数
w < 2l: 会有弹出的情况，需要用优先队列
确定最大数，可以用差分维护最终答案

### F. Bits And Pieces
没看懂，不会

### G. Polygons
有意思的结论题，具体的一个推导是：phi[x] > phi[one of divisors(x)]

感受：代码量少，但是思路牛逼，需要好好消化


  [1]: http://codeforces.com/contest/1208
