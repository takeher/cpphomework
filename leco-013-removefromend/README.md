main.cpp:
删除链表的倒数第n个节点，暴力方法就是遍历两次，
一次获取长度，第二次删节点
附上使用双指针的一次遍历方法，两个指针一前一后相差n个位置，
当后指针指向尾节点的时候删除前节点就可以了