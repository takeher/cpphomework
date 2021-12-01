main.cpp:
856.括号的分数
给定一个平衡括号字符串 S，按下述规则计算该字符串的分数：
() 得 1 分。
AB 得 A + B 分，其中 A 和 B 是平衡括号字符串。
(A) 得 2 * A 分，其中 A 是平衡括号字符串。

使用栈的实现
在栈里插入是对应的分数，按照不同字符串，有如下的情况
'(' : 直接插入0
')' : 弹出上一个 分数 * 2 (这里要考虑 () 情况，所以取一个最大值)， 然后和继续弹出上一个 '(' 对应分数来求和后重新入栈
栈顶的结果就是计算后的总分数