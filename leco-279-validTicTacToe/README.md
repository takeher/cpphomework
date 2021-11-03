main.cpp:
794.有效的井字游戏
用字符串数组作为井字游戏的游戏板 board。
当且仅当在井字游戏过程中，玩家有可能将字符放置成游戏板所显示的状态时，才返回 true。
该游戏板是一个 3 x 3 数组，由字符 " "，"X" 和 "O" 组成。字符 " " 代表一个空位。
以下是井字游戏的规则：
玩家轮流将字符放入空位（" "）中。
第一个玩家总是放字符 “X”，且第二个玩家总是放字符 “O”。
“X” 和 “O” 只允许放置在空位中，不允许对已放有字符的位置进行填充。
当有 3 个相同（且非空）的字符填充任何行、列或对角线时，游戏结束。
当所有位置非空时，也算为游戏结束。
如果游戏结束，玩家不允许再放置字符。

分析true的条件

先手获胜，则x数量等于o的数量+1；后手获胜，则x的数量等于o的数量
先手x数量不小于o的数量
获胜只有一个连续三个就成功并结束，所以不会出现两个连续3的情况
我们判断就是去找它们的反例即可