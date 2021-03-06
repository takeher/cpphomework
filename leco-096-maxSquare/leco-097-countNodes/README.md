main.cpp:
计算完全二叉树的节点个数。
使用二分查找的思想。
对于任意二叉树，都可以通过广度优先搜索或深度优先搜索计算节点个数，
时间复杂度和空间复杂度都是O(n)，其中n是二叉树的节点个数。
这道题规定了给出的是完全二叉树，因此可以利用完全二叉树的特性计算节点个数。
规定根节点位于第0层，完全二叉树的最大层数为h。
根据完全二叉树的特性可知，完全二叉树的最左边的节点一定位于最底层，
因此从根节点出发，每次访问左子节点，直到遇到叶子节点，
该叶子节点即为完全二叉树的最左边的节点，经过的路径长度即为最大层数h。
具体做法是，根据节点个数范围的上下界得到当前需要判断的节点个数k，如果第k个节点存在，
则节点个数一定大于或等于k，如果第k个节点不存在，
则节点个数一定小于k，由此可以将查找的范围缩小一半，
直到得到节点个数。
如何判断第k个节点是否存在呢？如果第k个节点位于第h层，
则k的二进制表示包含h+1位，其中最高位是1，
其余各位从高到低表示从根节点到第k个节点的路径，0表示移动到左子节点，
1表示移动到右子节点。通过位运算得到第k个节点对应的路径，
判断该路径对应的节点是否存在，即可判断第k个节点是否存在。
