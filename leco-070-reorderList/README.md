main.cpp:
给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
注意到目标链表即为将原链表的左半端和反转后的右半端合并后的结果。
这样我们的任务即可划分为三步：
1.找到原链表的中点。
使用快慢指针来 O(N) 地找到链表的中间节点。
2.将原链表的右半端反转。
使用迭代法实现链表的反转。
3.将原链表的两端合并。
因为两链表长度相差不超过1，因此直接合并即可。
