main.cpp:
一个机器人位于一个m x n网格的左上角。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角。
问总共有多少条不同的路径
简单方法是考虑到一共要走m+n-2步，这里面必有m-1步向下，n-1步向右，
所以直接计算组合数(m+n-2,m-1)即可。
附上一个使用动态规划的解法，
注意状态转移方程f(i)(j)=f(i-1)(j)+f(i)(j-1)，在i和j为0的时候f(i)(j)单独赋值为1即可。
main2.cpp:
考虑在矩阵中放一个障碍物（假设矩阵用0和1表示，1代表有障碍物）
这里采用动态规划的方法，这里对之前的动归做出一个改进，
不再开辟一个m x n的二维数组存储状态，而是用一个长m的一维数组，
这样每一行计算完毕后，可以使用f(i)+=f(i-1) (f(i)代表上一层的第i个位置，f(i-1)就是左边的位置)
注意第一行和第一列都赋值1即可。
这就是一个经典的动态规划问题。
