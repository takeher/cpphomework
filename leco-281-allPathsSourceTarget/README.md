main.cpp:
797.所有可能的路径
给一个有 n 个节点的 有向无环图（DAG），请找出所有从节点 0 到节点 n-1 的路径并输出（不要求按特定顺序）
二维数组的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些节点，空就是没有下一个结点了。
注:有向图是有方向的，即规定了 a→b 你就不能从 b→a 。

DFS。
