main.cpp:
根据有序链表，转换为平衡二叉树。
根据中位数的性质，
链表中小于中位数的元素个数与大于中位数的元素个数要么相等，
要么相差1。
此时，小于中位数的元素组成了左子树，
大于中位数的元素组成了右子树，
它们分别对应着有序链表中连续的一段。
在这之后，我们使用分治的思想，
继续递归地对左右子树进行构造，找出对应的中位数作为根节点，以此类推。
