main.cpp:
787.K 站中转内最便宜的航班
有 n 个城市通过一些航班连接。给你一个数组 flights ，
其中 flights[i] = [fromi, toi, pricei] ，
表示该航班都从城市 fromi 开始，以价格 pricei 抵达 toi。
现在给定所有的城市和航班，以及出发城市 src 和目的地 dst，
任务是找到出一条最多经过 k 站中转的路线，
使得从 src 到 dst 的 价格最便宜 ，并返回该价格。 
如果不存在这样的路线，则输出 -1。

动态规划。
