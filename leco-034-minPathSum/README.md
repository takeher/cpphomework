main.cpp:
给定一个矩阵，每个元素代表这个位置的权重，求从矩阵左上角到右下角的最小权重和的路径，
返回这条路径的权重和，只能向右或向下移动。
和33一样采用动态规划的做法，因为某位置的最小权重和路径一定是上边或左边中较小的一个，
也就是f(i)(j) = grid(i)(j)+min(f(i-1,j),f(i,j-1))（i和j为0的时候只加存在的那项即可）。
经典dp。
