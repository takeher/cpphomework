main.cpp:
最长回文字符，自己写的方法思想是把每一个（除了首和尾）的字符当做一个回文串的中间
长度为1或者2，依次试探是否可以往左往右扩展，本地测试无问题
和注释1的答案思路一样，但是我这个超时了。。。是因为它只记录首尾指针，而我反复操作字符串
学习了pair的用法
注释2是一个动态规划的做法