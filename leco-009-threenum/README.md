main.cpp:
寻找一维向量里所有不重复的和为零的三元组，
经典的暴力循环必超时
因为只需要返回具体的三元组，不需要保持下标
所以官方直接sort()了。。。
然后双指针收缩法
去重逻辑就是遇到重复的数就开始移动指针
直到下一个不重复为止
