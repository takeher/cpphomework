main.cpp:
z字形遍历输出字符串，自己的思路是按顺序打印，先确定有多少个完整的一个下->上形状
然后判一下不完整的最后一个（也可能没有）的下上形状是否有可以打印的
和官方答案思路一致，不过它直接判是否到尾，不用分两次判
相比一下，性能一样，但是自己的代码略显冗长
PS：简单条件下的特殊情况可以直接输出，可以有效避免超时
