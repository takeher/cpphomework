main.cpp:
给定一个三角形矩阵，求出自上而下的最小路径和。
采用动态规划的算法，因为每个位置的最小路径只与上一层的两项有关，
同时采取自下而上的遍历方法，避免最后对底层遍历一次来求最小值。