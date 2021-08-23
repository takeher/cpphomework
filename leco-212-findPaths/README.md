main.cpp:
给一个大小为 m x n 的网格和一个球。
球的起始坐标为 [startRow, startColumn] 。
可以将球移到在四个方向上相邻的单元格内（可以穿过网格边界到达网格之外）。
最多可以移动 maxMove 次球。
给五个整数 m、n、maxMove、startRow 以及 startColumn ，
找出并返回可以将球移出边界的路径数量。
因为答案可能非常大，返回对 109 + 7 取余 后的结果。

使用动态规划加递归的方法。
