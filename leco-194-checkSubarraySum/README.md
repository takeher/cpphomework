main.cpp:
给一个整数数组 nums 和一个整数 k ，
编写一个函数来判断该数组是否含有同时满足下述条件的连续子数组：
子数组大小至少为2 ，且
子数组元素总和为k的倍数。
如果存在，返回 true；否则，返回false。
如果存在一个整数n，令整数x符合x=n*k，则称x是k的一个倍数。0始终视为k的一个倍数。
使用前缀和+哈希表的算法
