main.cpp:
旋转链表，给一个数k，对链表做k次循环移位，
思路是先遍历一次得到长度，然后把尾节点指向头节点，
遍历第二次，返回新的尾节点的下一个作为新的头节点，
然后把新尾节点的next赋为nullptr（断开环）。
