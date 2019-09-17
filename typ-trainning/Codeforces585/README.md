# Codeforces Round #585 (Div. 2)

------
[http://codeforces.com/contest/1215][1]
题解与感受

### A. Yellow Cards
分情况讨论即可，注意各种边界

### B. The Number of Products
类似前缀和思想，再扫描过程中记录已有前缀和中正数、负数数量即可

### C. Swap Letters
比较简单，相同的不管，不相同的才管。
比如A B
0011
1100
我们发现相同的
00
11
可以交换一次就成功
11
00
同理
10
01
就需要两次，所以贪心交换相同，最后处理剩下不同的。

### D. Ticket Game
稍微看一下，这个博弈有结论，是Bash博弈的思想，具体可以看题解，证明以及推理就不赘述了

### E. Marbles
这道题需要状压DP，顶多20种排列，但不能直接这么搞。我们知道[1112223] 插入4其实4的贡献就是1、2、3与4swap到前面，先用calc[i][j]表示颜色i全部排到j前面时需要与j交换的次数，
DP[mask | (1 << i)] = min (DP[mask] + SUM{calc[i][j] | j 在mask中}）

### F. Radio Stations
这道题有一定的思维和难度，平时对2-SAT接触不多，建模较少，所以这题没有太好的思路。
这题做法是这样的:除了station本身是节点外，为了把f也建模在图中，需要[1...M]这些节点，2表示f >= 2
[1...M]自己需要建边，同时station与[1...M]也要建边即可。


  [1]: http://codeforces.com/contest/1215
