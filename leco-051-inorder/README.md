main.cpp:
二叉树的中序遍历。迭代版本。
Morris 遍历算法整体步骤如下（假设当前遍历到的节点为 xx）：
如果 xx 无左孩子，先将 xx 的值加入答案数组，再访问 xx 的右孩子，即 x = x.right。
如果 xx 有左孩子，则找到 xx 左子树上最右的节点（即左子树中序遍历的最后一个节点，xx 在中序遍历中的前驱节点），我们记为predecessor。
根据 predecessor 的右孩子是否为空，进行如下操作。
如果 predecessor 的右孩子为空，则将其右孩子指向 xx，然后访问 xx 的左孩子，即 x = x.left。
如果 predecessor 的右孩子不为空，则此时其右孩子指向 xx，说明我们已经遍历完 xx 的左子树，
我们将 predecessor 的右孩子置空，将 xx 的值加入答案数组，然后访问 xx 的右孩子，即 x=x.right。
重复上述操作，直至访问完整棵树。
