# <font face="楷体">动态规划指南</font>

### <font face="宋体" color=green>$398B$ - $            probabilities\ \&\ dp $</font>

#### <font face="宋体" color=blue>题意</font>

​	给出$n$和$m$，表示在一个的平面上有$n^2$个方格，其中有$m$块已经涂色。现在随机选中一块进行涂色（如果已经涂色跳过，也消耗时间），消耗$1$个步骤。终止条件为每行每列都有至少有一块瓷砖被涂色。问说涂成满意的情况需要时间的期望。

#### <font face="宋体" color=blue>题解</font>

​	设$dp[i][j]$表示还剩下$i$行和$j$列没有被画，显然$dp[0][0] = 0$，即剩下零行零列没有画的时候，需要的期望步数为$0$。

##### <font face="宋体" size=4 >概率$dp$通式</font>

$$
dp[i][j] = 1 + k
$$

​	<font color=red>$1$</font>表示无论如何都需要走的一步,是期望的步数，<font color = red>$k$</font>表示之前求得的状态的期望$*$概率的**累加和**。

##### <font face="宋体" size=4 >本题$dp$公式</font>


$$
{\color {red} dp[i][j]} = 1+\frac{dp[i-1][j-1]*i*j}{n^2}+\frac{dp[i-1][j]*i*(j-1)}{n^2}+\\\frac{dp[i][j-1]*(n-i)*j}{n^2}+{\color{red}\frac{dp[i][j]*(n-i)*(n-j)}{n^2}}
$$

​	概率$dp$转移公式中$k$中存在其本身，即$dp[i][j] = x + m*dp[i][j]$需要进行**化简**

$$
dp[i][j] = \frac{n^2+dp[i-1][j-1]*i* j+dp[i-1][j] * i * (j-1)+dp[i][j-1] * (n-i) * j}{n^2-(n-i) * (n-j)}
$$

##### <font face="宋体" size=4 >示例图</font>

![](img\398B.png)

---

### <font face="宋体" color=green>$30C$ - $probabilities\ \&\ dp$</font>

#### <font face="宋体" color=blue>题意</font>

​	给出二维平面内的$n$个点，每个点有$4$个属性$(x_i,y_i,t_i,p_i)$分别表示这个点的横纵坐标和它出现的时刻$t_i$，此时击中他的概率$p_i$。零时刻时，准星可以出现在任何位置，以后准星以每时刻1单位距离的速度移动，当$t_i$时刻准星移动到位置$(x_i,y_i)$时，便有$p_i$的概率击中这个目标。问最终击中点个数的期望。

$(1 \leq n \leq 1000,-1000\leq x_i,y_i\leq1000,0\leq t_i \leq10^9,0\leq p_i\leq1)$

#### <font face="宋体" color=blue>题解</font>

​	由于$n$个点有出现的时间先后关系，所以首先按照**$t_i$的大小排序**。如果打完第$j$个目标后想要击中第$i$个目标时，必须要满足$dist(i,j) \leq t_i-t_j$。

​	设$dp[i]$表示准星最后一个打的是第$i$个点时获得的期望。

​	显然有$dp[0]=p_0$，并且有转移
$$
dp[i] = max(dp[j]+p_i)\ dist(i,j)\leq t_i-t_j\ \&\ j<i
$$
​	最终的最大期望即为
$$
ans= max(dp[i]) \ 0\leq i <n
$$

#### <font face="宋体" color=blue>注意</font>

- 距离计算需要使用$long long$，使用浮点数存在浮点误差。
- 对于任意$dp[i]$，初始状态应是将第$i$个点作为第$1$次的射击。

---

### <font face="宋体" color=green>$392B$ - $dp$</font>

#### <font face="宋体" color=blue>题意</font>

​	$Hanoi Tower$汉若塔问题的原型是$n$个盘子从第$1$根柱子移动到第$3$根柱子，每次只能移动一个盘子，且移动过程中不改变盘子的排列关系，需要的步数至少为${\color{red}2^n-1}$。

​	同样的问题，不过现在每次盘子从第$i$根柱子移动到第$j$根柱子将会耗费$t_{ij}$单位的钱（$1\leq i,j\leq3$），问将$n$个盘子从第$1$根柱子移动到第$3$根柱子的最小花费是多少。

​	$1\leq t_{ij}\leq10000,i \neq j;\ \ 1\leq n \leq40$

#### <font face="宋体" color=blue>题解</font>

##### $HanoiTower$原问题$dp$转移

​	$dp[n]$:表示求解$n$盘$3$塔问题的最小步数：
$$
dp[n] = 2*dp[n-1]+1
$$
​	即把前$n-1$个盘子从$A$柱移动到$B$柱，然后把第$n$个盘子从$A$柱移动到$C$柱，最后把前$n-1$个盘子从$B$柱移动到$C$柱。

​	显然$dp[1] = 1$，$dp[n] = 2^n+1$。

​	如下图所示：

<img src="img\392B_1.png" alt="392B_1" style="zoom: 33%;" />

##### 现最小花费问题

​	由于柱子间的移动是不一样的，即花费不同，就需要增加新的状态。

​	设$dp[n][l][r],1\leq l,r\leq3$，表示将$n$盘从$l$柱移动到$r$柱的最小费用。

$\quad dp[0][l][r]=0\\
\quad dp[1][1][1]=0$

$\quad {\color{red}way_1} = dp[n-1][l][c]+dp[n-1][c][r]+t_{lr}\\
\quad {\color{red}way_2} = dp[n-1][l][r]+t_{lc}+dp[n-1][r][l]+t_{cr}+dp[n-1][l][r]\\
\quad {\color{red}dp[n][l][r]} = min(way_1,way_2)$

$\quad (1\leq l,r,c\leq3,l\neq r\neq c)$

​	共有两种转移的方式$way_1,way_2$，如下图所示。

​	$way_1$：

<img src="img\392B_1.png" alt="392B_1" style="zoom: 33%;" />

​	$way_2$：

<img src="img\392B_2.png" style="zoom:33%;" />

