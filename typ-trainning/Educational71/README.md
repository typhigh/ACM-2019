# Educational Codeforces Round 71 (Rated for Div. 2)

------

题解与感受

### A. There Are Two Types Of Burgers
简单题，暴力

### B. Square Filling
反着做，枚举哪些点不能放矩阵，然后把能放矩阵的点放矩阵就行了，检查是否一致

### C. Gas Pipeline
简单的线性dp

### D. Number Of Permutations
真难则反，求不满足的排列即可
不满足的排列 = 不满足A + 不满足B - 不满足AB，容斥即可， 不满足AB需要特判是否有不可比的两个元素

### E. XOR Guessing
很有意思的一题，其实对于x我们二进制可以分为前7位和后7位，x = A6_____ A0 | B7 ______ B0
第一轮可以用 0000000|XXXXXXX 去试， 得到x前七位， 第二轮用 XXXXXXX|0000000去试，得到后七位

### F. Remainder Problem
经典套路题，其实就是分类讨论
如果对第二种查询维护val[x][y], 空间是*N * N*， 时间*是O(1)*
如果暴力遍历a合法的位置，求和，空间是N，时间是*O(N/x)*
我们完全可以根据*x*大小查询, *x* 大，就用第二种，小就用第一种，第一种取sqrt(N)即可，空间*O(N)*

感受：教育意义还行，套路性强
