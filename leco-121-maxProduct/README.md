main.cpp:
最长单词长度的乘积,且两个单词不含重复字母。
总体思路很简单
遍历每个单词，然后去找序号比它大的单词是否不存在公共字母，无则计算是否是最大值。一直保存最大的即可
优化：
如何比较是否有公共字母
用位操作
这里只有小写字母，所以一个int就可以保存了，对于字符 c-'a'就是对应的bit的位数
预先计算好每个字符的结果
mask1 & mask2 == 0 就表示没有公共字母
快速判断
如果发现目前字母组合的长度小于当前最大值，可以直接忽略，无需再计算
