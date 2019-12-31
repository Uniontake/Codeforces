# <font face="楷体">动态规划算法</font>

### <font face="宋体" size=5 color=blue>$398B$ - 概率$dp$</font>

#### <font face="宋体" size=5 color=blue>题意</font>

​	给出$n$和$m$，表示在一个的平面上有$n^2$个方格，其中有$m$块已经涂色。现在随机选中一块进行涂色（如果已经涂色跳过，也消耗时间），消耗$1$个步骤。终止条件为每行每列都有至少有一块瓷砖被涂色。问说涂成满意的情况需要时间的期望。

#### <font face="宋体" size=5 color=blue>题解</font>

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

​	概率$dp$转移公式中$k$中存在其本身，即$dp[i][j] = x + m*dp[i][j] $需要进行**化简**
$$
dp[i][j] = \frac{n^2+dp[i-1][j-1]*i*j+dp[i-1][j]*i*(j-1)+dp[i][j-1]*(n-i)*j}{n^2-(n-i)*(n-j)}
$$

##### <font face="宋体" size=4 >示例图</font>

![image-20191231155759404](C:\Users\admin\AppData\Roaming\Typora\typora-user-images\image-20191231155759404.png)